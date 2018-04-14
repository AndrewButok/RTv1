/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fplane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:23:00 by abutok            #+#    #+#             */
/*   Updated: 2018/04/13 16:23:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define PARAM_NUM 5

static t_figure	*set_default_plane(void)
{
	t_figure *plane;

	plane = plane_init(vector_init(0, -1, 0), -3, 0xffff00, 0);
	return (plane);
}

void			parse_fplane(char **params, t_view *view)
{
	t_figure	*plane;
	double		d;

	if (!ft_strequ("f_plane", params[0]))
		return ;
	if (!check_paramnum(params, PARAM_NUM))
	{
		ft_putendl_fd("Wrong plane paremeters numbers. Figure missed", STDERR_FILENO);
		return;
	}
	plane = set_default_plane();
	plane->center = vnormalize(parse_vector(params[1], plane->center));
	d = ft_atod(params[2]);
	plane->radius = isnan(d) ? plane->radius : d;
	if (isnan(d))
		ft_putendl_fd("Invalid d parameter. Default applied.", STDERR_FILENO);
	plane->color = check_hex(params[3]) ? ft_hexatoi(params[3]) : plane->color;
	d = ft_atod(params[4]);
	plane->reflection = isnan(d) ? plane->reflection : d;
	if (isnan(d))
		ft_putendl_fd("Invalid reflection. Default applied.", STDERR_FILENO);
	add_figure(plane, view);
}
