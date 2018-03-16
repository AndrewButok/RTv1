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

#include "vector.h"

double		vscalar_multiple(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	vk_multiple(t_vector vector, double k)
{
	return ((t_vector){vector.x * k, vector.y * k, vector.z * k});
}

t_vector	vvector_multiple(t_vector a, t_vector b)
{
	return ((t_vector){a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x });
}
