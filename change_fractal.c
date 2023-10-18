#include "fractol.h"

void	change_fractal(int key, c_image_data *img_d)
{
	if (key == 0x0031)
	{
		img_d->fractal_num = 1;
		img_d->zoom = 240;
		img_d->x_pos = 0;
		img_d->y_pos = 0;
		img_d->maxIter = 640000;
	}
	if (key == 0x0032)
	{
		img_d->fractal_num = 2;
		img_d->zoom = 260;
		img_d->x_pos = 160;
		img_d->y_pos = 0;
		img_d->maxIter = 64;
	}
}
