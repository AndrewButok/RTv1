/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:53:00 by abutok            #+#    #+#             */
/*   Updated: 2018/04/13 11:53:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	opening_error(t_view *view)
{
	if (errno != 0)
	{
		perror("File opening error");
		exit_x(view);
	}
}

void	vector_error(void)
{
	ft_putendl_fd("Invalid vector. Default applied.",
			STDERR_FILENO);
}
