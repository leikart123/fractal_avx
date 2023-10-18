#include "fractol.h"

void	print_usage()
{
	ft_putstr("usage: ./fractol [fractal_name]\n");
	ft_putstr("names: \njulia\nmandelbrot\nburning_ship\nmandel_cos\nmandel_sin\nflowerbrot\n");
	ft_putstr("use keys [1 2 3 4 5 6] to chage fractals\n");
	ft_putstr("[q w e r] for colors\n");
	ft_putstr("[+ -] for iterations number\n");
	ft_putstr("left mouse button for zoomimg in mousepoint\n");
	ft_putstr("mouse scroll for zumming in center\n");
}

int		args_parse(int argc, char **argv, c_mlx_data *cmd)
{
	cmd->img_data->fractal_num = -1;
	if (argc != 2)
	{
		print_usage();
		return (-1);
	}
	if (argc == 2)
	{
		if (ft_strequ(argv[1], "julia\0"))
			cmd->img_data->fractal_num = 1;
		if (ft_strequ(argv[1], "mandelbrot\0"))
			cmd->img_data->fractal_num = 2;
		if (ft_strequ(argv[1], "burning_ship\0"))
			cmd->img_data->fractal_num = 3;
		if (ft_strequ(argv[1], "mandel_cos\0"))
			cmd->img_data->fractal_num = 4;
		if (ft_strequ(argv[1], "mandel_sin\0"))
			cmd->img_data->fractal_num = 5;
		if (ft_strequ(argv[1], "flowerbrot\0"))
			cmd->img_data->fractal_num = 6;
		if (cmd->img_data->fractal_num < 0)
			ft_putstr("wrong fractal name\n");
	}
	return (cmd->img_data->fractal_num < 0 ? -1 : 1);
}
