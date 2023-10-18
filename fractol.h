#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <stdint.h>
#include "minilibx-linux/mlx.h"
#include <pthread.h>
#include <fcntl.h>
#include <errno.h>
#include <immintrin.h>
#include <time.h>

# define DEFAULT_THREAD_NUM 1
# define Pi 3.1415
# define E 2.71828

extern int thread_num;
extern int wid;
extern int hei;

typedef	struct		s_cmplx
{
	double			re;
	double			im;
}					t_complex_double;

typedef	struct		s_mouse_pos
{
	int			x;
	int			y;
}					t_mouse_pos;

typedef struct 					image_data
{
	double      				x_pos;
	double      				y_pos;
	int         				scale;
	double      				zoom;
	int							*pixels_arr;
	int							fractal_num;
	int							maxIter;
	int							palett_type;
	int							max_y;
	int							thread_size;
	t_complex_double			min;
	t_complex_double			max;
	t_mouse_pos					mouse_pos;
	t_complex_double			julia_k;
}								c_image_data;

typedef struct 
{
    c_image_data  *img_d;
    int			   tid;
} 	threadArgs;

typedef struct  	mlx_data
{
	void        	*mlx;
	void        	*win;
	void        	*img;
	int         	bpp;
	int				size_line;
	int				endian;
	int				mouse_locked;
	c_image_data	*img_data;
}               	c_mlx_data;

//DRAW
void 				drawfractal(threadArgs *args);
void    			draw_julia(c_image_data *img_d, int x, int y, int thread_size, void *p);

//CALC
void    			julia_calc(c_image_data *img_d, int x, int y, int thread_size, int *pixels_arr);
void    			mandel_calc(c_image_data *img_d, int x, int y, int thread_size, int *pixels_arr);

int					key_mouse_control(c_mlx_data *cmd);
void    			init_mlx(c_mlx_data *cmd);
void				img_data_init(c_image_data *img_d, c_mlx_data *cmd);
int					key_control(int key, c_mlx_data *cmd);
int					mouse_press(int button, int x, int y, c_mlx_data *cmd);
void				img_changes(int key, c_mlx_data *cmd, c_image_data *img_d);
void    			get_new_image(c_mlx_data *cmd);
int					get_color(double maxIter, double i, int palett_type);
int     			args_parse(int argc, char **argv, c_mlx_data *cmd);
int					mouse_move(int x, int y, c_mlx_data *cmd);
void				change_julia_k(c_image_data *img_d, int x, int y);
void    			choose_color(int key, c_image_data *img_d);
void    			thread_init(c_mlx_data *cmd, c_image_data *img_d);
void    			set_minimum(c_image_data *img_d);
void				change_fractal(int key, c_image_data *img_d);

#endif
