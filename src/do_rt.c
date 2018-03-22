/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 10:40:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/22 20:25:35 by abutok           ###   ########.fr       */
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

int			do_lightrt(t_space *space, t_ray *ray, t_figure *figure, double k)
{
	t_light		*light;
	t_vector	intersection;
	t_vector	normale;
	t_vector	vlight;
	t_ray		*buf;
	double		brightness;
	double		w_brightness;
	double		nl_s;

	light = space->lights;
	intersection = get_intersection(ray, k);
	normale = get_normale(intersection, figure);
	brightness = 0;
	w_brightness = 0;
	while (light != NULL)
	{
		if (light->type == LIGHT_TYPE_AMBIENT)
			brightness += light->intencity;
		else
		{
			vlight = vsub(light->o, intersection);
			buf = ray_init(intersection, vlight);
			if (!check_intersections(buf, space->figures))
			{
				if ((nl_s = vscalar_multiple(normale, vlight)) > 0)
					brightness += light->intencity * nl_s / vlen(vlight);
				if (figure->reflection != -1)
					w_brightness += rt_lightr(vlight,normale,
							vsub(ray->o, ray->v),
					vector_init(light->intencity,figure->reflection, 0));
			}
			free(buf);
		}
		light = light->next;
	}
	return (set_brightness(figure->color, brightness, w_brightness));
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
