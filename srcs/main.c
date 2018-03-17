/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 01:11:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/03/16 01:11:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <color.h>

static void	view_init(t_view **view_ptr)
{
	t_view		*view;
	t_figure	f;
	t_ray		r;
	int			x;
	int			y;
	double 		k;
	t_vector	buf;
	t_vector	l;
	t_light		light;
	t_color		color;
	double		nsl;
	double 		i;

	errno = 0;
	view = (t_view*)malloc(sizeof(t_view));
	if (errno != 0)
	{
		perror("View malloc error");
	}
	*view_ptr = view;
	view->mlx = mlx_init();
	view->win = mlx_new_window(view->mlx, WIN_WIDTH, WIN_HEIGHT, "RTv1");
	view->img = mlx_new_image(view->mlx, WIN_WIDTH, WIN_HEIGHT);
	view->scene = (int*)mlx_get_data_addr(view->img, &view->bits_per_pixel, &view->size_line, &view->endian);
	color.color = 0xff00;
	f = sphere_init(vector_init(0, -1, 30), 1.0, color);
	r.o = vector_init(0, 0, 0);
	r.v = vector_init(0, 0, 1);
	y = 0;
	color.color = 0xffffff;
	light = light_init(point, vector_init(20, 1, 0), 0.6, color);
	while (y < WIN_HEIGHT)
	{
		r.v.y = (WIN_HEIGHT / 2.0 - y) / WIN_WIDTH;
		x = 0;
		while (x < WIN_WIDTH)
		{
			r.v.x = (x - WIN_WIDTH / 2.0) / WIN_WIDTH;
			if ((k = check_intersection(r,f)) > 0.0)
			{
				i = 0;
				buf = get_intersection(r, k);
				l = vector_sub(light.o, buf);
				buf = get_sphere_normale(buf, f);
				if ((nsl = vscalar_multiple(buf, l)) > 0)
					i += (light.intencity * nsl) / (vector_len(l));
				if (i > 1)
					i = 1;
				color = f.color;
				color.spectrum.red = (unsigned char)(color.spectrum.red * i);
				color.spectrum.green = (unsigned char)(color.spectrum.green * i);
				color.spectrum.blue = (unsigned char)(color.spectrum.blue * i);
				view->scene[y * WIN_WIDTH + x] = color.color;
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	mlx_destroy_image(view->mlx, view->img);
}

int			main()
{
	t_view *view;

	view_init(&view);
	mlx_loop(view->mlx);
	//system("leaks RTv1");
	return 0;
}