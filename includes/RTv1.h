

#ifndef RTV1_H
# define RTV1_H
# include "libft.h"
# include "get_next_line.h"
# include <errno.h>
# include <stdio.h>
# include <mlx.h>
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef double t_vector[3];

enum e_axis
{
	x = 0,
	y = 1,
	z = 2
};

typedef struct	s_view
{

	void	*mlx;
	void	*win;
	void	*img;
	int 	*scene;
	int 	bits_per_pixel;
	int 	size_line;
	int 	endian;

}				t_view;

#endif
