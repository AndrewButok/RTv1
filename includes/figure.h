/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:48:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/16 11:48:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURE_H
# define FIGURE_H
# include "vector.h"
# include "color.h"

typedef struct	s_ray
{
	t_vector	o;
	t_vector	v;
}				t_ray;

enum e_figure
{
	no_figure = -1,
	pane = 0,
	sphere = 1,
	cylinder = 2,
	cone = 3
};

typedef struct	s_figure
{
	char			type;
	t_vector		center;
	double			radius;
	t_vector		axis;
	double 			angle;
	int				color;
	double			reflection;
}				t_figure;

double			check_sphere_intersection(t_ray ray, t_figure figure);
t_vector		get_sphere_normale(t_vector p, t_figure f);
t_figure		sphere_init(t_vector center, double r, int color);
double			check_intersection(t_ray ray, t_figure figure);
int				check_intersections(t_ray ray, t_figure *figures);
t_vector		get_intersection(t_ray ray, double k);
t_ray			ray_init(t_vector start, t_vector end);

#endif