/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:57:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/16 11:57:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "figure.h"

double		get_solve(double a, double b, double d, t_ray ray)
{
	double x1;
	double x2;

	if (d == 0)
		return ((-b)/(2 * a));
	x1 = (-b + sqrt(d))/(2 * a);
	x2 = (-b - sqrt(d))/(2 * a);
	return ((x1 > x2) && x1 > ray.v.z ? x1 : x2);
}

double		check_spere_intersection(t_ray ray, t_figure figure)
{
	t_vector	buf;
	double		a;
	double		b;
	double		c;
	double		d;

	a = vscalar_multiple(ray.v, ray.v);
	buf = vector_sub(ray.o, figure.center);
	b = 2 * (vscalar_multiple(buf, ray.v));
	c = vscalar_multiple(buf, buf) - (figure.radius * figure.radius);
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	else
		return (get_solve(a, b, d, ray));
}
