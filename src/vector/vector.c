/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:19:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/16 10:19:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	vector_init(double x, double y, double z)
{
	t_vector	new_vector;

	new_vector.x = x;
	new_vector.y = y;
	new_vector.z = z;
	return (new_vector);
}

double		vscalar_multiple(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	vk_multiple(t_vector vector, double k)
{
	return ((t_vector){vector.x * k, vector.y * k, vector.z * k});
}
