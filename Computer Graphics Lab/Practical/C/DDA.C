#include <stdio.h>
#include <stdlib.h>

#include <graphics.h>

void
dda_line(int x1, int y1, int x2, int y2)
{
	int dx, dy, steps, i;
	float x_inc, y_inc, x, y;

	dx = x2 - x1;
	dy = y2 - y1;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	x_inc = (float)dx / (float)steps;
	y_inc = (float)dy / (float)steps;

	x = (float)x1;
	y = (float)y1;
	putpixel((int)x, (int)y, WHITE);

	for (i = 0; i < steps; i++) {
		x += x_inc;
		y += y_inc;
		putpixel((int)x, (int)y, WHITE);
	}
}


int
main(void)
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:/TC/BGI");

	// Rendering
	// ---------

	//        x1   y1   x2   y2
	dda_line(100, 100, 450, 350);
	// dda_line(450, 350, 100, 100);
	// dda_line(100, 450, 300, 100);
	// dda_line(300, 100, 100, 450);
	// dda_line(100, 100, 400, 100);
	// dda_line(400, 100, 100, 100);
	// dda_line(100, 450, 100, 250);
	// dda_line(100, 250, 100, 450);

	getchar();
	closegraph();

	return 0;
}
