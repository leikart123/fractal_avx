#include "fractol.h"

int second_palett(double maxIter, int i)
{
    double t = (double)i / (double)maxIter;
    int r;
	int g;
	int b;
	int color;


	t = (double)i / (double)maxIter;
	r = (int)(128 * (1 + sin(0.1 + t * 4.0)));
	g = (int)(128 * (1 + sin(0.2 + t * 4.0)));
	b = (int)(128 * (1 + sin(0.3 + t * 4.0)));
	g <<= 8;
	r <<= 16;
	color = (r | g | b);

    return color;
}

int first_palett(double maxIter, int i)
{
    double t = (double)i / (double)maxIter;
    int intensity = (int)(t * 255);
    
    int color = (intensity << 16) | (intensity << 8) | intensity;
    return color;
}

int		third_palett(double maxIter, double i)
{
    double golden_angle = 137.50776405003785464634873962837027762068838904975090;
    double hue = fmod(golden_angle * i, 360.0);
    
    // Convert HSV color to RGB
    int r, g, b;
    int c = 255;
    int x = (1 - fabs(fmod(hue / 60.0, 2) - 1)) * 255;
    
    if (hue >= 0 && hue < 60) {
        r = c;
        g = x;
        b = 0;
    } else if (hue >= 60 && hue < 120) {
        r = x;
        g = c;
        b = 0;
    } else if (hue >= 120 && hue < 180) {
        r = 0;
        g = c;
        b = x;
    } else if (hue >= 180 && hue < 240) {
        r = 0;
        g = x;
        b = c;
    } else if (hue >= 240 && hue < 300) {
        r = x;
        g = 0;
        b = c;
    } else {
        r = c;
        g = 0;
        b = x;
    }
    
    r <<= 16;
    g <<= 8;

    int color = (r | g | b);

    return color;

}

int		fourth_palett(double maxIter, int i)
{
    int color;
    int r = (i * 15) % 255;
    int g = (i * 6) % 255;
    int b = (i * 9) % 255;
    g <<= 8;
	r <<= 16;
	color = (r | g | b);

    return color;
}

int		get_color(double maxIter, double i, int palett_type)
{
	if (palett_type == 1)
		return (first_palett(maxIter, i));
	if (palett_type == 2)
		return (second_palett(maxIter, i));
	if (palett_type == 3)
		return (third_palett(maxIter, i));
	if (palett_type == 4)
		return (fourth_palett(maxIter, i));
}