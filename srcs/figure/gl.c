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
#include "figure.h"

t_ray		ray_init(t_vector start, t_vector end)
{
	t_ray ray;

	ray.o = start;
	ray.v = end;
	return (ray);
}

t_vector	get_intersection(t_ray ray, double k)
{
	return (vector_sum(vk_multiple(vector_sub(ray.v, ray.o), k), ray.o));
}

double		check_intersection(t_ray ray, t_figure figure)
{
	if (figure.type == sphere)
		return (check_sphere_intersection(ray, figure));
}

int			check_intersections(t_ray ray, t_figure *figures)
{
	size_t i;

	i = 0;
	while (figures[i].type != no_figure)
	{
		if (check_intersection(ray, figures[i]) < 1 && check_intersection(ray, figures[i]) > 0)
			return (1);
		i++;
	}
	return (0);
}
