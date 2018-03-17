/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:57:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/16 11:57:00 by abutok           ###   ########.fr       */
/* ************************************************************************** */

#include "figure.h"

static double	get_solve(double a, double b, double d, t_ray ray)
{
	double x1;
	double x2;

	x1 = (-b + sqrt(d))/(2 * a);
	x2 = (-b - sqrt(d))/(2 * a);
	return ((x1 < x2) && x2 >= ray.v.z ? x1 : x2);
}

double			check_sphere_intersection(t_ray ray, t_figure figure)
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
	if (d <= 0)
		return (-1);
	else
		return (get_solve(a, b, d, ray));
}

t_vector		get_sphere_normale(t_vector p, t_figure f)
{
	return (vector_normalize(vector_sub(p, f.center)));
}

t_figure		sphere_init(t_vector center, double r, int color)
{
	t_figure new_figure;

	new_figure.type = sphere;
	new_figure.center = center;
	new_figure.radius = r;
	new_figure.color = color;
	new_figure.reflection = 41;
	return (new_figure);
}
