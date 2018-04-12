/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 22:49:00 by abutok            #+#    #+#             */
/*   Updated: 2018/04/09 22:49:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	null_str_error(t_view *view)
{
	ft_putendl_fd("Null pointer found.",
			STDERR_FILENO);
	exit_x(view);
}

void	q_up_error(t_view *view)
{
	ft_putendl_fd("Unpaired quotes found. Please check your input.",
			STDERR_FILENO);
	exit_x(view);
}

void	fb_up_error(t_view *view)
{
	ft_putendl_fd("Unpaired figure brace found. Please check your input.",
			STDERR_FILENO);
	exit_x(view);
}

void	sb_up_error(t_view *view)
{
	ft_putendl_fd("Unpaired square brace found. Please check your input.",
			STDERR_FILENO);
	exit_x(view);
}

void	read_error(t_view *view)
{
	perror("File read error");
	exit_x(view);
}
