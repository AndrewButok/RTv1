/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fcylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:07:00 by abutok            #+#    #+#             */
/*   Updated: 2018/04/13 19:07:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define PARAM_NUM 6

static t_figure	*set_default_cylinder(void)
{
	t_figure *cylinder;

	cylinder = cylinder_init(ray_init((t_vector){0, 0, 0},
			(t_vector){0, -1, 0}), 1, 0xffffff, 0);
	return (cylinder);
}

void			parse_fcylinder(char **params, t_view *view)
{
	t_figure	*cylinder;
	double		d;

	if (!ft_strequ("f_cylinder", params[0]))
		return ;
	if (!check_paramnum(params, PARAM_NUM))
	{
		ft_putendl_fd("Wrong cylinder paremeters numbers. Figure skipped",
				STDERR_FILENO);
		return ;
	}
	cylinder = set_default_cylinder();
	cylinder->center = parse_vector(params[1], cylinder->center);
	cylinder->axis = vnormalize(parse_vector(params[2], cylinder->center));
	d = get_double_param(params[3], "radius");
	cylinder->radius = isnan(d) ? cylinder->radius : d;
	cylinder->color = check_hex(params[4]) ? ft_hexatoi(params[4]) :
			cylinder->color;
	d = get_double_param(params[5], "reflection");
	cylinder->reflection = isnan(d) ? cylinder->reflection : d;
	add_figure(cylinder, view);
}
