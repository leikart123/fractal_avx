#include "fractol.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sched.h>

typedef struct {
    c_image_data *img_d;
	int tid;
} ThreadArgs;

void    draw_julia(c_image_data *img_d, int x, int y, int max_y, void *p)
{
	y = max_y - img_d->thread_size;
	while (y++ < max_y)
	{
		while (x++ < hei)
			julia_calc(img_d, x, y, max_y, p);
		x = 0;
	}
}

void    draw_mandelbrod(c_image_data *img_d, int x, int y, int max_y, void *p)
{
	y = max_y - img_d->thread_size;
	while (y++ < max_y)
	{
		while (x++ < hei)
			mandel_calc(img_d, x, y, max_y, p);
		x = 0;
	}
}

void drawfractal(threadArgs *args)
{
	int max_y;
	void *p;

	max_y = args->img_d->thread_size * args->tid;
	p = args->img_d->pixels_arr + ((args->tid - 1) * wid * hei / thread_num);

	set_minimum(args->img_d);
	if (args->img_d->fractal_num == 1)
		draw_julia(args->img_d, 0, 0, max_y, p);
	if (args->img_d->fractal_num == 2)
		draw_mandelbrod(args->img_d, 0, 0, max_y, p);
}