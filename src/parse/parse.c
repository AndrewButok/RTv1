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

int				check_paramnum(char **param, size_t n)
{
	int c;

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
	return ;
}

void			parse_scene(char *filename, t_view *view)
{
	char	*str;
	char	**params;
	int		e;
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
