#include "../../includes/rt.h"

void	pixel_put(t_image *img, int x, int y, rgba c)
{
	char	*pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(int *)pixel = colortoi(c);
}