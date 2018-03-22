/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 01:11:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/03/16 01:11:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void	view_init(t_view **view_ptr)
{
	t_view		*view;

	errno = 0;
	view = (t_view*)malloc(sizeof(t_view));
	if (errno != 0)
	{
		perror("View malloc error");
	}
	*view_ptr = view;
	view->mlx = mlx_init();
	view->win = mlx_new_window(view->mlx, WIN_WIDTH, WIN_HEIGHT, "RTv1");
	view->img = mlx_new_image(view->mlx, WIN_WIDTH, WIN_HEIGHT);
	view->scene = (int*)mlx_get_data_addr(view->img, &view->bits_per_pixel, &view->size_line, &view->endian);
	do_rt(view);
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	mlx_destroy_image(view->mlx, view->img);
	system("leaks RTv1");
}

int			main()
{
	t_view *view;

	view_init(&view);
	mlx_loop(view->mlx);
	//system("leaks RTv1");
	return 0;
}