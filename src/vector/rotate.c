/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 12:32:00 by abutok            #+#    #+#             */
/*   Updated: 2018/02/23 15:28:09 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rotate_x(t_vector *ps, t_vector *p0, double l)
{
	double ny;
	double nz;

	l *= M_PI / 180;
	ny = ((ps->y - p0->y) * cos(l) + (ps->z - p0->z) * sin(l) + p0->y);
	nz = ((ps->z - p0->z) * cos(l) - (ps->y - p0->y) * sin(l) + p0->z);
	ps->y = ny;
	ps->z = nz;
}

void	rotate_y(t_vector *ps, t_vector *p0, double l)
{
	double nx;
	double nz;

	l *= M_PI / 180;
	nx = ((ps->x - p0->x) * cos(l) + (ps->z - p0->z) * sin(l) + p0->x);
	nz = ((ps->z - p0->z) * cos(l) - (ps->x - p0->x) * sin(l) + p0->z);
	ps->x = nx;
	ps->z = nz;
}
void	rotate_z(t_vector *ps, t_vector *p0, double l)
{
	double ny;
	double nx;

	l *= M_PI / 180;
	nx = ((ps->x - p0->x) * cos(l) - (ps->y - p0->y) * sin(l) + p0->x);
	ny = ((ps->y - p0->y) * cos(l) + (ps->x - p0->x) * sin(l) + p0->y);
	ps->x = nx;
	ps->y = ny;
}
