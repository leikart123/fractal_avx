#include "fractol.h"

void	iter_change(int key, c_image_data *img_d)
{
	if (key == 0x003d)
		img_d->maxIter += 64;
	if (key == 0x002d)
		img_d->maxIter -= 64;
	if (img_d->maxIter <= 0)
		img_d->maxIter = 64;
}

void	move(c_mlx_data *cmd, int key, c_image_data *img_d)
{
		double step = 64;
		if (key == 0x0069)
			img_d->y_pos += step;
		if (key == 0x006b)
			img_d->y_pos -= step;
		if (key == 0x006a)
			img_d->x_pos += step;
		if (key == 0x006c)
			img_d->x_pos -= step;
}

void	img_changes(int key, c_mlx_data *cmd, c_image_data *img_d)
{
	if (key == 0x003d || key == 0x002d)
		iter_change(key, img_d);
	if (key == 0x0069 || key == 0x006b || key == 0x006a || key == 0x006c)
		move(cmd, key, img_d);
	if (key == 0x0031 || key == 0x0032 || key == 0x0033 || key == 0x0034 || key == 0x0035 || key == 0x0036)
		change_fractal(key, img_d);
	if (key == 0x0071 || key == 0x0077 || key == 0x0065 || key == 0x0072)
		choose_color(key, img_d);
}