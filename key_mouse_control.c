#include "fractol.h"

void	scroll(int key, c_mlx_data *cmd)
{
	double scale;

	if (key == 4 || key == 1 || key == 2)
		scale = 1.1;
	if (key == 5)
		scale = 0.9;
	cmd->img_data->x_pos = round((cmd->img_data->x_pos + ((wid >> 1) - cmd->img_data->mouse_pos.x)) * scale);
	cmd->img_data->y_pos = round((cmd->img_data->y_pos + ((hei >> 1) - cmd->img_data->mouse_pos.y)) * scale);
	cmd->img_data->zoom *= scale;
}

int		mouse_press(int button, int x, int y, c_mlx_data *cmd)
{
	get_new_image(cmd);
	cmd->img_data->mouse_pos.x = x;
	cmd->img_data->mouse_pos.y = y;
	scroll(button, cmd);
	img_changes(button, cmd, cmd->img_data);
	thread_init(cmd, cmd->img_data);
	mlx_put_image_to_window(cmd->mlx, cmd->win, cmd->img, 0, 0);
	return (0);
}

int		key_control(int key, c_mlx_data *cmd)
{
	if (key == 65307)
	{
		mlx_destroy_window(cmd->mlx, cmd->win);
		exit(0);
	}
	if (key == 0xffe1)
		cmd->mouse_locked = cmd->mouse_locked ? 0 : 1;
	if (key == 0x0031 || key == 0x0032 || key == 0x0033 || key == 0xff51 || \
		key == 0xff52 || key == 0xff53 || key == 0xff54 || \
		key == 0x0077 || key == 0x0073 || key == 0x002d || key == 0x003d || \
		key == 0x0061 || key == 0x0064 || key == 0x0069 || key == 0x006b || \
		key == 0x006a || key == 0x006c || key == 0x007a || key == 0x0078 || \
		key == 0x0071 || key == 0x0077 || key == 0x0065 || key == 0x0072 || \
		key == 0x0034 || key == 0x0035 || key == 0x0036)
	{
		get_new_image(cmd);
		img_changes(key, cmd, cmd->img_data);
		thread_init(cmd, cmd->img_data);
		mlx_put_image_to_window(cmd->mlx, cmd->win, cmd->img, 0, 0);
	}
	return (0);
}