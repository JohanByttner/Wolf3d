/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlxutil.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:31:21 by jbyttner          #+#    #+#             */
/*   Updated: 2016/05/19 11:23:30 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBMLXUTIL_H
# define FT_LIBMLXUTIL_H
# include "libft.h"
# include "xheader.h"
# define MLX_MAX_WINDOW_COUNT 2
# define MLX_IMAGES_BUFF_SIZE 5
# define MLX_DEFAULT_CAMERA_MODE 2
# ifndef MLX_BASE_FOCUS
#  define MLX_BASE_FOCUS 1000.0
# endif

typedef struct		s_fmatrix
{
	size_t			width;
	size_t			height;
	double			*value;
}					t_fmatrix;

typedef struct		s_colour
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	char			endian;
}					t_colour;

typedef t_colour	t_color;

typedef enum		e_camera_mode
{
	UNINITIALIZED = 0,
	MLX_CAMERA_CENTRIC = 1,
	MLX_WORLD_CENTRIC = 2,
}					t_camera_mode;

typedef struct		s_mlx_camera
{
	t_fmatrix		*ext_matrix;
	t_fmatrix		*int_matrix;
	t_camera_mode	mode;
	double			view_frustrum_start;
	double			view_frustrum_end;
	int				size_x;
	int				size_y;
	double			*pixel_render_depth;
	int				overwriting_render;
}					t_mlx_camera;

typedef struct		s_mlx_world
{
	t_list			*lline;
	t_list			*llline;
	t_mlx_camera	*camera;
}					t_mlx_world;

typedef struct		s_mlx_image
{
	void			*image;
	int				size_x;
	int				size_y;
	int				size_line;
	int				endian;
	int				bits_per_pixel;
	char			*data;
	t_mlx_world		*world;
}					t_mlx_image;

typedef struct		s_mlx_window
{
	void			*window;
	int				size_x;
	int				size_y;
	char			*title;
}					t_mlx_window;

typedef struct		s_mlx_handler
{
	void			*init;
	t_mlx_window	windows[MLX_MAX_WINDOW_COUNT];
	t_mlx_image		*images;
	int				image_count;
}					t_mlx_handler;

typedef struct		s_3dpoint
{
	double			i;
	double			j;
	double			k;
}					t_3dpoint;

typedef struct		s_point
{
	double			i;
	double			j;
}					t_point;

typedef t_point		t_complex;

typedef struct		s_3dline
{
	t_3dpoint		*start;
	t_3dpoint		*end;
	t_colour		*colour;
	t_colour		*colour2;
}					t_3dline;

typedef struct		s_line
{
	t_point			*start;
	t_point			*end;
	t_colour		*colour;
}					t_line;

typedef struct		s_3dbasis
{
	t_3dpoint		n;
	t_3dpoint		l;
	t_3dpoint		m;
}					t_3dbasis;

/*
** Points can be freed directly with free
*/

t_3dpoint			*mlx_get_point(int i, int j, int k);

int					mlx_cmp_points(t_3dpoint *p1, t_3dpoint *p2);

t_3dpoint			*mlx_copy_point(t_3dpoint *copy, t_3dpoint *input);

t_3dpoint			*mlx_dup_point(t_3dpoint *point);

t_3dpoint			*mlx_eqnormalize_point(t_3dpoint *point);

double				mlx_abs_point(t_3dpoint *point);

t_3dpoint			*mlx_eqsub_point(t_3dpoint *res, t_3dpoint *sub);

t_3dpoint			*mlx_eqadd_point(t_3dpoint *res, t_3dpoint *add);

t_3dpoint			*mlx_eqmul_point(t_3dpoint *res, double mul);

double				mlx_distance_points(t_3dpoint *p1, t_3dpoint *p2);

t_fmatrix			*mlx_eqpoint_to_cameraview(t_fmatrix *point,
						t_mlx_camera *camera);

t_fmatrix			*mlx_eqpoint_to_coneview(t_fmatrix *point,
						t_mlx_camera *camera);

t_point				*mlx_eqpoint_to_point2d(t_point *p1, t_3dpoint *p2);

t_point				*mlx_copy_point2d(t_point *restrict copy,
						t_point *restrict point);

double				mlx_sqabs_point2d(t_point *p);

double				mlx_abs_point2d(t_point *p);

int					mlx_cmp_points2d(t_point *p1, t_point *p2);

t_point				*mlx_eqadd_point2d(t_point *restrict p1,
						t_point *restrict p2);

t_3dline			*mlx_new_line(t_3dpoint *p1, t_3dpoint *p2);

t_3dline			*mlx_init_line(t_3dline *line, t_3dpoint *p1,
						t_3dpoint *p2);

t_3dline			*mlx_set_line_colours(t_3dline *line,
						t_colour *c1, t_colour *c2);

void				mlx_render_lline(t_list *lline, t_mlx_camera *camera,
						t_mlx_image *img);

void				mlx_renderl_lline(t_list *llist, t_mlx_camera *camera,
						t_mlx_image *img);

t_3dline			*mlx_eqget_line_cone_intersect(t_3dline *line);

double				mlx_distance_points2d(t_point *p1, t_point *p2);

t_mlx_handler		*mlx_get_handler(void);

t_mlx_window		*mlx_get_window(int wd);

t_mlx_window		*mlx_set_window(int wd, int size_x,
						int size_y, char *title);

t_mlx_image			*mlx_set_image(int id, int size_x, int size_y);

t_mlx_image			*mlx_get_image(int id);

void				mlx_render_image(t_mlx_image *img);

void				mlx_clear_image(t_mlx_image *img);

t_mlx_world			*mlx_new_world(t_mlx_camera *camera, t_mlx_image *img);

int					mlx_loadl_lline(t_mlx_image *img, t_list *llist);

t_mlx_camera		*mlx_new_camera(int focus, int size_x, int size_y);

t_mlx_camera		*mlx_translate_camera(t_mlx_camera *camera, t_3dpoint *t);

t_mlx_camera		*mlx_rotate_camera(t_mlx_camera *camera, t_fmatrix *rot);

t_mlx_camera		*mlx_rotatei_camera(t_mlx_camera *camera, double angle);

t_mlx_camera		*mlx_rotatej_camera(t_mlx_camera *camera, double angle);

t_mlx_camera		*mlx_rotatek_camera(t_mlx_camera *camera, double angle);

t_mlx_camera		*mlx_translate_camera(t_mlx_camera *camera, t_3dpoint *t);

int					mlx_camera_record_pixel_depth(t_3dpoint *pos,
						t_mlx_camera *camera);

t_fmatrix			*mlx_new_fmatrix(size_t width, size_t height);

t_fmatrix			*mlx_eqmul_fmatrix(t_fmatrix *res, t_fmatrix *a,
						t_fmatrix *b);

t_fmatrix			*mlx_eqtranspose_fmatrix(t_fmatrix *res, t_fmatrix *input);

t_point				*mlx_eqfmatrix_to_point2d(t_point *restrict p,
						t_fmatrix *restrict m);

t_3dpoint			*mlx_eqfmatrix_to_point(t_3dpoint *p, t_fmatrix *m);

t_fmatrix			*mlx_eqpoint_to_fmatrix(t_fmatrix *m, t_3dpoint *p);

void				mlx_put_point_to_image(t_3dpoint *p, t_mlx_camera *c,
						t_mlx_image *im, t_colour *colour);

void				mlx_render_point_to_image(t_3dpoint *p, t_mlx_camera *c,
						t_mlx_image *im, t_colour *colour);

void				mlx_put_point2d_to_image(t_point *pt, t_mlx_image *im,
						t_colour *colour);

void				mlx_put_line_to_image(t_3dline *line, t_mlx_camera *c,
						t_mlx_image *im);

void				mlx_render_line_to_image(t_3dline *line, t_mlx_camera *c,
						t_mlx_image *im);

void				mlx_put_line2d_to_image(t_line *line, t_mlx_image *im,
						t_colour *colour);

void				mlx_set_image_pixel(t_mlx_image *im, t_colour *colour,
						size_t pixel);

t_colour			*mlx_new_colour(unsigned char red, unsigned char green,
						unsigned char blue, char endian);

t_colour			*mlx_dup_colour(t_colour *colour);

t_colour			*mlx_copy_colour(t_colour *res, t_colour *colour);

int					mlx_cmp_colours(t_colour *c1, t_colour *c2);

t_colour			*mlx_gradient_colours(t_colour *res, t_colour *c1,
						t_colour *c2, double grade);

int					mlx_get_colour_int(t_colour *restrict colour,
						t_mlx_image *restrict im);

t_complex			*mlx_eqmul_complex(t_complex *res, t_complex *c1,
						t_complex *c2);

#endif
