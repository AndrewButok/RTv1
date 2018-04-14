/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:00:00 by abutok            #+#    #+#             */
/*   Updated: 2018/04/13 13:00:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define PARAM_NUM 3

static	t_vector	check_nan(t_vector d, t_vector def)
{
	if (isnan(d.x) || isnan(d.y) || isnan(d.z))
	{
		ft_putendl_fd("Invalid vector. Default applied.", STDERR_FILENO);
		return (def);
	}
	return (d);
}

t_vector			parse_vector(char *str, t_vector vector)
{
	char		*trimmed;
	char		**doubles;
	t_vector	def;

	if (str[0] != '(' && str[ft_strlen(str) - 1] != ')')
	{
		vector_error();
		return (vector_init(0, 0, 0));
	}
	trimmed = ft_strsub(str, 1, ft_strlen(str) - 2);
	doubles = ft_strsplit(trimmed, ' ');
	ft_strdel(&trimmed);
	if (check_paramnum(doubles, 3))
		vector = vector_init(ft_atod(doubles[0]),
				ft_atod(doubles[1]),
				ft_atod(doubles[2]));
	else
	{
		vector_error();
		vector = vector_init(0, 0, 0);
	}
	def = vector_init(0, 0, 0);
	vector = check_nan(vector, def);
	del_strs(&doubles);
	return (vector);
}

void				parse_cam(char **params, t_view *view)
{
	if (!ft_strequ("cam", params[0]))
		return ;
	if (!check_paramnum(params, PARAM_NUM))
	{
		ft_putendl_fd("Invalid number of camera params.", STDERR_FILENO);
		if (view->space->cam == NULL)
			view->space->cam = ray_init((t_vector){0, 0, 0},
					(t_vector){0, 0, 0});
		return ;
	}
	if (view->space->cam == NULL)
		view->space->cam = ray_init(parse_vector(params[1],
				(t_vector){0, 0, 0}),
			parse_vector(params[2], (t_vector){0, 0, 0}));
}
