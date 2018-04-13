/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fsphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:51:00 by abutok            #+#    #+#             */
/*   Updated: 2018/04/13 18:51:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define PARAM_NUM 5

static t_figure	*set_default_sphere(t_view *view)
{
	t_figure *sphere;

	sphere = sphere_init(vector_init(0, 0, 0), 1, 0xffffff, 0);
	return (sphere);
}

void			parse_fsphere(char **params, t_view *view)
{
	t_figure	*sphere;
	double		d;

	if (!ft_strequ("f_sphere", params[0]))
		return ;
	if (!check_paramnum(params, PARAM_NUM))
		return ;
	sphere = set_default_sphere(view);
	sphere->center = parse_vector(params[1], sphere->center);
	d = ft_atod(params[2]);
	sphere->radius = isnan(d) ? sphere->radius : d;
	if (isnan(d))
		ft_putendl_fd("Invalid radius parameter. Default applied.",
				STDERR_FILENO);
	sphere->color = check_hex(params[3]) ? ft_hexatoi(params[3]) :
			sphere->color;
	d = ft_atod(params[4]);
	sphere->reflection = isnan(d) ? sphere->reflection : d;
	if (isnan(d))
		ft_putendl_fd("Invalid reflection. Default applied.", STDERR_FILENO);
	add_figure(sphere, view);
}
