/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 10:40:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/17 10:40:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double			rt_lightr(t_vector l, t_vector normale, t_vector view, t_vector buf)
{
	t_vector	r;

	r = vk_multiple(vk_multiple(normale, -2), vscalar_multiple(normale, l));
	r = vector_sub(r, l);
	return (buf.x * pow(vscalar_multiple(r,view) /
			(vector_len(r) * vector_len(view)), buf.y));
}

int			rt_light(t_space space, t_ray ray, size_t figure_id, double k)
{
	t_ray		buf;
	t_vector	l;
	size_t		i;
	double		brightness;
	double		sc_nl;

	brightness = 0;
	buf.v = get_intersection(ray, k);
	buf.o = get_sphere_normale(buf.v, space.figures[figure_id]);
	i = 0;
	while (space.lights[i].type != no_light)
	{
		if (space.lights[i].type == ambient)
		{
			brightness += space.lights[i++].intencity;
			continue ;
		}
		l = vector_sub(space.lights[i].o, buf.v);
		if ((sc_nl = vscalar_multiple(buf.o, l)) > 0 &&
				!check_intersections(ray_init(buf.v, l), space.figures))
		{
			brightness += (space.lights[i].intencity * sc_nl) / vector_len(l);
			if (space.figures[figure_id].reflection != -1)
				brightness += rt_lightr(l, buf.o, vector_sub(ray.v, ray.o),
						vector_init(space.lights[i].intencity,
								space.figures[figure_id].reflection, 0));
		}
		i++;
	}
	return (set_brightness(space.figures[figure_id].color, brightness));
}

int			rt(t_space space, t_ray ray)
{
	size_t	i;
	size_t	figure_id;
	double	len;
	double	lbuf;

	i = 0;
	len = INFINITY;
	figure_id = 0;
	while (space.figures[i].type != no_figure)
	{
		lbuf = check_intersection(ray, space.figures[i]);
		if (lbuf < len && lbuf >= ray.v.z)
		{
			len = lbuf;
			figure_id = i;
		}
		i++;
	}
	if (len == INFINITY)
		return (0);
	else
		return (rt_light(space, ray, figure_id, len));
}

void		do_rt(t_view *view)
{
	t_space		space;
	t_ray		ray;
	int			x;
	int			y;
	//TODO: parse
	space.figures = malloc(sizeof(t_figure) * 4);
	space.figures[0] = sphere_init(vector_init(0, 0, 10), 1, 0xffff);
	space.figures[1] = sphere_init(vector_init(10, 10, 100), 20, 0xffff);
	space.figures[2] = sphere_init(vector_init(2, 0, 10), 1, 0xff00ff);
	space.figures[3].type = no_figure;
	space.lights = malloc(sizeof(t_light) * 3);
	space.lights[0] = light_init(point, vector_init(0, 0, 2), 0.7, 0xffffff);
	space.lights[1] = light_init(ambient, vector_init(0, 0, 0), 0.1, 0xffffff);
	space.lights[2].type = no_light;
	//
	y = -1;
	ray = ray_init(vector_init(0, 0, 0), vector_init(0, 0, 1));
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		ray.v.y = (WIN_HEIGHT / 2.0 - y) / WIN_WIDTH;
		while (++x < WIN_WIDTH)
		{
			ray.v.x = (x - WIN_WIDTH / 2.0) / WIN_WIDTH;
			view->scene[y * WIN_WIDTH + x] = rt(space, ray);
		}
	}
	free(space.figures);
	free(space.lights);
}
