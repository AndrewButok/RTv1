/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fcone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:34:00 by abutok            #+#    #+#             */
/*   Updated: 2018/04/13 19:34:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define PARAM_NUM 6

static t_figure	*set_default_cone(t_view *view)
{
	t_figure *cone;

	cone = cone_init(ray_init((t_vector){0, 0, 0}, (t_vector){0, -1, 0}),
			1, 0xffffff, 0);
	return (cone);
}

void			parse_fcone(char **params, t_view *view)
{
	t_figure	*cone;
	double		d;

	if (!ft_strequ("f_cone", params[0]))
		return ;
	if (!check_paramnum(params, PARAM_NUM))
		return	;
	cone = set_default_cone(view);
	cone->center = parse_vector(params[1], cone->center);
	cone->axis = vnormalize(parse_vector(params[2], cone->center));
	d = ft_atod(params[3]);
	cone->radius = isnan(d) ? cone->radius : d;
	if (isnan(d))
		ft_putendl_fd("Invalid tan parameter. Default applied.",
				STDERR_FILENO);
	cone->color = check_hex(params[4]) ? ft_hexatoi(params[4]) :
			cone->color;
	d = ft_atod(params[5]);
	cone->reflection = isnan(d) ? cone->reflection : d;
	if (isnan(d))
		ft_putendl_fd("Invalid reflection. Default applied.", STDERR_FILENO);
	add_figure(cone, view);

}
