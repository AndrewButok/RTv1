/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:38:00 by abutok            #+#    #+#             */
/*   Updated: 2018/04/13 19:38:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_light	*set_default_light(void)
{
	t_light *light;

	light = light_init(LIGHT_TYPE_AMBIENT, vector_init(0, 0, 0), 0.8);
	return (light);
}

static double	check_intensivity(double d)
{
	if (d < 0)
	{
		d = 0;
		ft_putendl_fd("Intensivity is too low. Default 0 applied",
				STDERR_FILENO);
	}
	if (d > 1)
	{
		d = 1;
		ft_putendl_fd("Intensivity is too high. Default 1 applied",
				STDERR_FILENO);
	}
	return (d);
}

void			parse_light(char **params, t_view *view)
{
	t_light	*light;
	double	d;
	char	type;

	if (ft_strequ("l_ambient", params[0]))
		type = LIGHT_TYPE_AMBIENT;
	else if (ft_strequ("l_point", params[0]))
		type = LIGHT_TYPE_POINT;
	else
		return ;
	if (!check_paramnum(params, ft_strequ("l_ambient", params[0]) ? 2 : 3))
	{
		ft_putendl_fd("Wrong light paremeters numbers. Light skipped",
				STDERR_FILENO);
		return ;
	}
	light = set_default_light();
	light->type = type;
	if (ft_strequ("l_point", params[0]))
		light->o = parse_vector(params[1], light->o);
	d = check_intensivity(get_double_param((params[ft_strequ("l_point",
			params[0]) ? 2 : 1]),
			"intensivity"));
	light->inten = isnan(d) ? light->inten : d;
	add_light(light, view);
}
