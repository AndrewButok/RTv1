/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:58:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/16 11:58:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "rtv1.h"

t_ray		*ray_init(t_vector start, t_vector end)
{
	t_ray *ray;

	ray = (t_ray*)malloc(sizeof(t_ray));
	ray->o = start;
	ray->v = end;
	return (ray);
}

t_vector	get_intersection(t_ray *ray, double k)
{
	return (vsum(vk_multiple(vsub(ray->v, ray->o), k), ray->o));
}

double		check_intersection(t_ray *ray, t_figure *figure)
{
	if (figure->type == FIGURE_TYPE_SPHERE)
		return (check_sphere_intersection(ray, figure));
	else return -1;
}

int			check_intersections(t_ray *ray, t_figure *figures)
{
	t_figure	*it;

	it = figures;
	while (it != NULL)
	{
		if (check_intersection(ray, it) < 1 && check_intersection(ray, it) > 1e-11)
			return (1);
		it = it->next;
	}
	return (0);
}
