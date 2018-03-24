/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:12:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/16 10:12:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "libft.h"
# include "get_next_line.h"
# include <errno.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define LIGHT_TYPE_AMBIENT 0
# define LIGHT_TYPE_POINT 1
# define FIGURE_TYPE_PANE 0
# define FIGURE_TYPE_SPHERE 1
# define FIGURE_TYPE_CYLINDER 2
# define FIGURE_TYPE_CONE 3

typedef union			u_color
{
	int		color;
	struct
	{
		unsigned char	blue;
		unsigned char	green;
		unsigned char	red;
		unsigned char	alpha;
	}		spectrum;
}						t_color;

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef struct	s_light
{
	char			type;
	double			inten;
	t_vector		o;
	struct s_light	*next;
}				t_light;


typedef struct	s_ray
{
	t_vector	o;
	t_vector	v;
}				t_ray;

typedef struct	s_figure
{
	char			type;
	t_vector		center;
	double			radius;
	t_vector		axis;
	double 			angle;
	int				color;
	double			reflection;
	struct s_figure	*next;
}				t_figure;

typedef struct	s_space
{
	t_figure	*figures;
	t_light		*lights;
	t_ray		*cam;
	t_vector	cam_angle;
}				t_space;

typedef	struct	s_lrt
{
	t_light		*light;
	t_vector	intersection;
	t_vector	normale;
	t_vector	vlight;
	t_ray		*buf;
	double		bright;
	double		reflected;
	double		nl_s;
}				t_lrt;

typedef struct	s_view
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*scene;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_space	*space;

}				t_view;

void			do_rt(t_view *view);
int				set_brightness(int color, double brightness, double bbrightness);
t_vector		vector_init(double x, double y, double z);
double			vscalar_multiple(t_vector a, t_vector b);
t_vector		vk_multiple(t_vector vector, double k);
t_vector		vsum(t_vector a, t_vector b);
t_vector		vsub(t_vector a, t_vector b);
t_vector		vnormalize(t_vector a);
double			vlen(t_vector a);
t_light			*light_init(char type,t_vector o, double intencity);
double			check_sphere_intersection(t_ray *ray, t_figure *figure);
t_vector		get_normale(t_vector ray, t_figure *f);
t_vector		get_sphere_normale(t_vector p, t_figure *f);
t_figure		*sphere_init(t_vector center, double r, int color,
		double reflection);
double			check_intersection(t_ray *ray, t_figure *figure);
int				check_intersections(t_ray *ray, t_figure *figures);
t_vector		get_intersection(t_ray *ray, double k);
t_ray			*ray_init(t_vector start, t_vector end);
t_space			*space_init(char *filename);
void			space_destroy(t_space *space);
void			cam_rotate(t_ray *ray, t_vector vector);
void			rotate_x(t_vector *ps, t_vector *p0, double l);
void			rotate_y(t_vector *ps, t_vector *p0, double l);
void			rotate_z(t_vector *ps, t_vector *p0, double l);

#endif
