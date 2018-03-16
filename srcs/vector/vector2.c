/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:16:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/16 15:16:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_sum(t_vector a, t_vector b)
{
	return ((t_vector){a.x + b.x,
			a.y + b.y,
			a.z + b.z});
}

t_vector	vector_sub(t_vector a, t_vector b)
{
	return ((t_vector){a.x - b.x,
			a.y - b.y,
			a.z - b.z});
}

double		vector_len(t_vector a)
{
	return (sqrt(vscalar_multiple(a, a)));
}

t_vector	vector_normalize(t_vector a)
{
	double	vlen;

	vlen = vector_len(a);
	return ((t_vector){a.x / vlen,
			a.y / vlen,
			a.z / vlen});
}
