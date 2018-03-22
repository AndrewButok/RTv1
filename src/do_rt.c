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
	double		d;

	r = vk_multiple(vk_multiple(normale, 2), vscalar_multiple(normale, l));
	r = vsub(r, l);
	d = vscalar_multiple(r, view);
	if (d >= 0)
		return (buf.x * pow(d /
			(vlen(r) * vlen(view)), buf.y));
	else
		return (0);
}

//int			do_lightrt(t_space *space, t_ray ray, t_figure *figure, double k)
//{
//	t_ray		buf;
//	t_vector	l;
//	t_light		*iterator;
//	double		brightness;
//	double 		bbrightness;
//	double		sc_nl;
//
//	brightness = 0;
//	bbrightness = 0;
//	buf.v = get_intersection(ray, k);
//	buf.o = get_sphere_normale(buf.v, figure);
//	iterator = space->lights;
//	while (iterator != NULL)
//	{
//		if (iterator->type == LIGHT_TYPE_AMBIENT)
//		{
//			brightness += iterator->intencity;
//			iterator = iterator->next;
//			continue ;
//		}
//		l = vsub(iterator->o, buf.v);
//		if ((sc_nl = vscalar_multiple(buf.o, l)) > 0 &&
//				!check_intersections(ray_init(buf.v, l), space->figures))
//			brightness += (iterator->intencity * sc_nl) / vlen(l);
//		if (figure->reflection != -1 &&
//				!check_intersections(ray_init(buf.v, l), space->figures))
//		{
//			bbrightness += rt_lightr(l, buf.o, vsub(ray.o, ray.v),
//					vector_init(iterator->intencity,
//							figure->reflection, 0));
//		}
//		iterator = iterator->next;
//	}
//	return (set_brightness(figure->color, brightness, bbrightness));
//}
int			do_lightrt(t_space *space, t_ray *ray, t_figure *figure, double k)
{
	return (0);
}

int			rt(t_space *space, t_ray *ray)
{
	t_figure	*iterator;
	t_figure	*closest;
	double		len;
	double		lbuf;

	len = INFINITY;
	iterator = space->figures;
	while (iterator != NULL)
	{
		lbuf = check_intersection(ray, iterator);
		if (lbuf < len && lbuf >= ray->v.z)
		{
			len = lbuf;
			closest = iterator;
		}
		iterator = iterator->next;
	}
	if (len == INFINITY)
		return (0);
	else
		return (do_lightrt(space, ray, closest, len));
}

void		do_rt(t_view *view)
{
	t_space		*space;
	t_ray		*ray;
	int			x;
	int			y;

	space = space_init(NULL);
	y = -1;
	ray = ray_init(vector_init(0, 0, 0), vector_init(0, 0, 1));
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		ray->v.y = (WIN_HEIGHT / 2.0 - y) / WIN_WIDTH;
		while (++x < WIN_WIDTH)
		{
			ray->v.x = (x - WIN_WIDTH / 2.0) / WIN_WIDTH;
			view->scene[y * WIN_WIDTH + x] = rt(space, ray);
		}
	}
	space_destroy(space);
	free(ray);
}
