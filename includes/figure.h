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
	pane = 0,
	sphere = 1,
	cylinder = 2,
	cone = 3
};

typedef struct	s_figure
{
	char			figure;
	t_vector		center;
	double			radius;
	t_vector		axis;
	double 			angle;
	t_color			color;
}				t_figure;

double		check_spere_intersection(t_ray ray, t_figure figure);
double		check_intersection(t_ray ray, t_figure figure);

#endif