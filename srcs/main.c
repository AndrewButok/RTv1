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
	f.figure = sphere;
	f.center.x = 0.0;
	f.center.y = 0.0;
	f.center.z = 250.0;
	f.radius = 25.3;
	f.color.color = 0xFFAA99;
	r.o.x = 0;
	r.o.y = 0;
	r.o.z = 0;
	r.v.z = 1.0;
	y = 0;
	light.intencity = 0.5;
	light.o.x = 100;
	light.o.y = -100;
	light.o.z = 1000;
	while (y < WIN_HEIGHT)
	{
		r.v.y = (y - WIN_HEIGHT / 2.0) / WIN_WIDTH;
		x= 0;
		while (x < WIN_WIDTH)
		{
			r.v.x = (x - WIN_WIDTH / 2.0) / WIN_WIDTH;
			if ((k = check_intersection(r,f)) > 0.0)
			{
				i = 0.1;
				buf = vector_sum(vk_multiple(vector_sub(r.v, r.o), k), r.o);
				l = vector_sub(light.o, buf);
				buf = vector_normalize(vector_sub(f.center, buf));
				if ((nsl = vscalar_multiple(buf, l)) > 0)
					i += (light.intencity * nsl) / (vector_len(buf) * vector_len(l));
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