#include "fractol.h"

void    mlx(c_mlx_data *cmd, c_image_data *img_d)
{
    cmd->mlx = mlx_init();
	cmd->win = mlx_new_window(cmd->mlx, wid, hei, "fractol");
	cmd->img = mlx_new_image(cmd->mlx, wid, hei);
	img_d->pixels_arr = (int *)mlx_get_data_addr(cmd->img, &cmd->bpp, \
		&cmd->size_line, &cmd->endian);
	img_d->zoom = 1;
    img_d->x_pos = 0;
    img_d->y_pos = 0;
	img_d->fractal_num = 1;
}

int		key_mouse_control(c_mlx_data *cmd)
{
	mlx_hook(cmd->win, 2, (1L << 0), key_control, cmd);
	mlx_hook(cmd->win, 4, (1L << 2), mouse_press, cmd);
	return (0);
}
