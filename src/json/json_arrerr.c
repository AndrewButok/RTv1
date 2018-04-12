/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_arrerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 21:45:00 by abutok            #+#    #+#             */
/*   Updated: 2018/04/10 21:45:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	figures_arr_error(t_view *view)
{
	ft_putendl_fd("A non-empty figures array must be presented.",
			STDERR_FILENO);
	exit_x(view);
}

void	lights_arr_error(t_view *view)
{
	ft_putendl_fd("A non-empty lights array must be presented",
			STDERR_FILENO);
	exit_x(view);
}

void	cam_class_error(t_view *view)
{
	ft_putendl_fd("A camera must be class.",
			STDERR_FILENO);
	exit_x(view);
}
