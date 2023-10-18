#include "fractol.h"

int thread_num;
int wid;
int hei;

void    clean_cmd(c_mlx_data *cmd)
{
    ft_memdel((void **)&cmd->img_data);
    ft_memdel((void **)&cmd->img);
    ft_memdel((void **)&cmd);
}

void get_thread_number(void)
{
    FILE *fp = fopen("/proc/cpuinfo", "r");
    int logicalProcessorCount = 0;

    if (fp != NULL) {
        char line[256];

        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, "processor")) {
                logicalProcessorCount++;
            }
        }

        fclose(fp);
        printf("Number of logical processors: %d\n", logicalProcessorCount);
        thread_num = logicalProcessorCount;
    } else {
        printf("Error opening /proc/cpuinfo\n");
        thread_num = DEFAULT_THREAD_NUM;
    }
}

int     main(int argc, char **argv)
{
    c_mlx_data	*cmd;

    if (!(cmd = (c_mlx_data *)malloc(sizeof(c_mlx_data))))
        return (0);
    get_thread_number();
    wid = thread_num * 100;
    hei = thread_num * 100;
    init_mlx(cmd);
    if(args_parse(argc, argv, cmd) < 0)
    {
        clean_cmd(cmd);
        exit(0);
    }
    img_data_init(cmd->img_data, cmd);
    thread_init(cmd, cmd->img_data);
    key_mouse_control(cmd);
    mlx_put_image_to_window(cmd->mlx, cmd->win, cmd->img, 0, 0);
    mlx_loop(cmd->mlx);
    return (0);
}