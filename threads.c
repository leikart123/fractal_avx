#include "fractol.h"

void    clear(c_image_data *img_buf)
{
	ft_memdel((void **)&img_buf->pixels_arr);
	free(img_buf);
}

void    thread_init(c_mlx_data *cmd, c_image_data *img_d)
{
	clock_t start_time = clock();
	pthread_t tid[thread_num];
	threadArgs args[thread_num];
	int i;
	int j;

	i = 1;
	j = 0;
	set_minimum(img_d);
	while(i <= thread_num)
	{   
		args[i - 1].img_d = img_d;
		args[i - 1].tid = i;
		pthread_create(&tid[i - 1], NULL, (void *)(*drawfractal), (void *)&args[i - 1]);
		i++;
	}
	i = 1;
	while(i <= thread_num)
	{
		pthread_join(tid[i - 1],NULL);
		i++;
	}
	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("Time to calculate one frame: %.2f seconds\n", elapsed_time);
	printf("number of iterations: %d\n", img_d->maxIter);
	printf("zoom: %f\n", img_d->zoom);
}
