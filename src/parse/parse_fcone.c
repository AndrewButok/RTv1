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

static t_figure	*set_default_cone(void)
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
	{
		ft_putendl_fd("Wrong cone paremeters numbers. Figure skipped",
				STDERR_FILENO);
		return ;
	}
	cone = set_default_cone();
	cone->center = parse_vector(params[1], cone->center);
	cone->axis = vnormalize(parse_vector(params[2], cone->center));
	d = get_double_param(params[3], "tan");
	cone->radius = isnan(d) ? cone->radius : d;
	cone->color = check_hex(params[4]) ? ft_hexatoi(params[4]) :
			cone->color;
	d = get_double_param(params[5], "reflection");
	cone->reflection = isnan(d) ? cone->reflection : d;
	add_figure(cone, view);
}
