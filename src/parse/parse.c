/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:47:00 by abutok            #+#    #+#             */
/*   Updated: 2018/04/13 11:47:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double			get_double_param(char *str, char *name)
{
	double d;

	d = ft_atod(str);
	if (isnan(d))
	{
		ft_putstr_fd("Invalid ", STDERR_FILENO);
		ft_putstr_fd(name, STDERR_FILENO);
		ft_putendl_fd(" parameter. Default applied.", STDERR_FILENO);
	}
	return (d);
}

int				check_paramnum(char **param, size_t n)
{
	size_t c;

	if (param == NULL)
		return (0);
	c = 0;
	while (param[c] != NULL)
		c++;
	if (c != n)
		return (0);
	return (1);
}

static	void	get_obj(char **params, t_view *view)
{
	parse_cam(params, view);
	parse_fplane(params, view);
	parse_fsphere(params, view);
	parse_fcylinder(params, view);
	parse_fcone(params, view);
	parse_light(params, view);
}

void			parse_scene(char *filename, t_view *view)
{
	char	*str;
	char	**params;
	int		fd;

	fd = open(filename, O_RDONLY);
	opening_error(view);
	while (get_next_line(fd, &str) > 0)
	{
		if (ft_strcmp(str, "") == 0)
		{
			ft_strdel(&str);
			continue;
		}
		params = ft_strsplit(str, '\t');
		get_obj(params, view);
		del_strs(&params);
		ft_strdel(&str);
	}
	ft_strdel(&str);
}
