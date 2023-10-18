#include "fractol.h"

void    init_mlx(c_mlx_data *cmd)
{
	cmd->mlx = mlx_init();
	if (!(cmd->img = mlx_new_image(cmd->mlx, wid, hei)))
        printf("Error: cannot create image errno %d\n", errno);
	cmd->img_data = (c_image_data *)malloc(sizeof(c_image_data));
	cmd->mouse_locked = 0;
}

void	fractal_settings_norme(c_image_data *img_d)
{
	if (img_d->fractal_num == 1)
	{
		img_d->zoom = 240;
		img_d->x_pos = 0;
		img_d->y_pos = 0;
	}
	if (img_d->fractal_num == 2)
	{
		img_d->zoom = 260;
		img_d->x_pos = 160;
		img_d->y_pos = 0;
	}
}

void	img_data_init(c_image_data *img_d, c_mlx_data *cmd)
{
	if (!(cmd->win = mlx_new_window(cmd->mlx, wid, hei, "fractol")))
		printf("Error: cannot create windown errno %d\n", errno);
	img_d->pixels_arr = (int *)mlx_get_data_addr(cmd->img, &cmd->bpp, \
		&cmd->size_line, &cmd->endian);
	img_d->min.re = ((img_d->x_pos + (wid >> 1)) / (img_d->zoom / 2)) / -2;
	img_d->min.im = ((img_d->y_pos + (hei >> 1)) / (img_d->zoom / 2)) / -2;
	img_d->palett_type = 1;
	img_d->thread_size = wid / thread_num;
	fractal_settings_norme(img_d);
	img_d->maxIter = 64;
}

int		key_mouse_control(c_mlx_data *cmd)
{
	mlx_hook(cmd->win, 2, (1L << 0), key_control, cmd);
	mlx_hook(cmd->win, 4, (1L << 2), mouse_press, cmd);
	return (0);
}
