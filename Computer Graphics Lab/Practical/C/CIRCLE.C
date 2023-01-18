#include <stdio.h>

#include <graphics.h>

void
mid_point_circle(int h, int k, int radius)
{
	int x, y, p;

	x = 0;
	y = radius;

	p = 1 - radius;
	while (x < y) {
		putpixel( x + h,  y + k, WHITE);
		putpixel(-x + h,  y + k, WHITE);
		putpixel( x + h, -y + k, WHITE);
		putpixel(-x + h, -y + k, WHITE);
		putpixel( y + h,  x + k, WHITE);
		putpixel(-y + h,  x + k, WHITE);
		putpixel( y + h, -x + k, WHITE);
		putpixel(-y + h, -x + k, WHITE);

		x++;
		if (p < 0) {
			p = p + (2 * x) + 1;
		} else {
			p = p + (2 * x) - (2 * y) + 1;
			y--;
		}
	}
}

int
main(void)
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:/TC/BGI");

	// Rendering
	// ---------

	//                x    y    r
	mid_point_circle(100, 100, 50);

	getchar();
	closegraph();
	return 0;
}
