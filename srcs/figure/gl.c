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

#include "figure.h"

t_vector	get_intersection(t_ray ray, double k)
{
	return (vector_sum(vk_multiple(vector_sub(ray.v, ray.o), k), ray.o));
}

double		check_intersection(t_ray ray, t_figure figure)
{
	if (figure.figure == sphere)
		return (check_sphere_intersection(ray, figure));
}