#include "fractol.h"

void    julia_calc(c_image_data *img_d, int x, int y, int max_y, int *pixels_arr)
{
	__m256d z_re = _mm256_set1_pd(x / img_d->zoom + img_d->min.re);
    __m256d z_im = _mm256_set1_pd(y / img_d->zoom + img_d->min.im);
    const __m256d k_im = _mm256_set1_pd(0.11301);
    const __m256d k_re = _mm256_set1_pd(-0.74543);
    const __m256d two = _mm256_set1_pd(2.0);
    int i;
    for (i = 0; i < img_d->maxIter; i += 4) {
        __m256d z2_re = _mm256_mul_pd(z_re, z_re);
        __m256d z2_im = _mm256_mul_pd(z_im, z_im);
        __m256d comparison_result = _mm256_add_pd(z2_im, z2_re);
        comparison_result = _mm256_cmp_pd(comparison_result, _mm256_set1_pd(4.0), _CMP_GT_OQ);
        int mask = _mm256_movemask_pd(comparison_result);
        if (mask)
            break;
        z_im = _mm256_mul_pd(z_re, z_im);
        z_im = _mm256_fmadd_pd(z_im, two, k_im);
        z_re = _mm256_add_pd(_mm256_sub_pd(z2_re, z2_im), k_re);
    }
    pixels_arr[(img_d->thread_size - 1 - (max_y - y)) * hei + x] = get_color(img_d->maxIter, i, img_d->palett_type);
}

void    mandel_calc(c_image_data *img_d, int x, int y, int max_y, int *pixels_arr)
{
	int		i;
	__m256d z_re;
	__m256d z_im;
	__m256d c_re;
	__m256d c_im;
	__m256d z2_re;
	__m256d z2_im;

	double cre;
	double cim;
	int		color;
	
	z_re = _mm256_setzero_pd();
	z_im = _mm256_setzero_pd();
	z2_re = _mm256_setzero_pd();
	z2_im = _mm256_setzero_pd();
	cre = x / img_d->zoom + img_d->min.re;
	cim = y / img_d->zoom + img_d->min.im;
	c_re = _mm256_setr_pd(cre,cre,cre,cre);
	c_im = _mm256_setr_pd(cim,cim,cim,cim);
	i = 0;
	while (i < img_d->maxIter)
	{
		z2_re = _mm256_mul_pd(z_re, z_re);
		z2_im = _mm256_mul_pd(z_im, z_im);
		__m256d comparison_result = _mm256_add_pd(z2_im, z2_re);
		comparison_result = _mm256_cmp_pd(comparison_result, _mm256_set1_pd(4.0), _CMP_GT_OQ);
		int mask = _mm256_movemask_pd(comparison_result);
		if (mask)
			break ;
		z_im = _mm256_mul_pd(z_re, z_im);
		__m256d two = _mm256_set1_pd(2.0);
		z_im = _mm256_mul_pd(z_im, two);
		z_im = _mm256_add_pd(z_im, c_im);
		z_re = _mm256_sub_pd(z2_re, z2_im);
		z_re = _mm256_add_pd(z_re, c_re);
		i += 4;
	}
	pixels_arr[(img_d->thread_size - 1 - (max_y - y)) * hei + x] = \
	get_color(img_d->maxIter, i, img_d->palett_type);
}
