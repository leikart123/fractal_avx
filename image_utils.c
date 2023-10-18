#include "fractol.h"

void    get_new_image(c_mlx_data *cmd)
{
    if (cmd->img)
                mlx_destroy_image(cmd->mlx, cmd->img);
    cmd->img = mlx_new_image(cmd->mlx, wid, hei);
    cmd->img_data->pixels_arr = (int *)mlx_get_data_addr(cmd->img, \
        &cmd->bpp, &cmd->size_line, &cmd->endian);
}

void    set_minimum(c_image_data *img_d)
{
    img_d->min.re = ((img_d->x_pos + (wid >> 1)) / (img_d->zoom / 2)) / -2;
	img_d->min.im = ((img_d->y_pos + (hei >> 1)) / (img_d->zoom / 2)) / -2;
}

void    choose_color(int key, c_image_data *img_d)
{
    	if (key == 0x0071)
            img_d->palett_type = 1;
        if (key == 0x0077)
            img_d->palett_type = 2;
        if (key == 0x0065)
            img_d->palett_type = 3;
        if (key == 0x0072)
            img_d->palett_type = 4;
}