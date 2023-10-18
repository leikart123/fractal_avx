#include "fractol.h"

void    get_new_image(c_mlx_data *cmd)
{
    if (cmd->img)
                mlx_destroy_image(cmd->mlx, cmd->img);
    if (!(cmd->img = mlx_new_image(cmd->mlx, wid, hei)))
        printf("Error: cannot create image errno %d\n", errno);
    cmd->img_data->pixels_arr = (int *)mlx_get_data_addr(cmd->img, \
        &cmd->bpp, &cmd->size_line, &cmd->endian);
}