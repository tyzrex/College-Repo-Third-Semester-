#include <stdio.h>
#include <stdlib.h>

#include <graphics.h>

// Function Declarations
// ---------------------

void
bla_line(int x1, int y1, int x2, int y2);

void
bla_line_high(int x1, int y1, int x2, int y2);

void
bla_line_low(int x1, int y1, int x2, int y2);

// Function Implementations
// ------------------------

void
bla_line(int x1, int y1, int x2, int y2)
{
	if (abs(y2 - y1) < abs(x2 - x1)) {
		if (x1 > x2)
			bla_line_low(x2, y2, x1, y1);
		else
			bla_line_low(x1, y1, x2, y2);
	} else {
		if (y1 > y2)
			bla_line_high(x2, y2, x1, y1);
		else
			bla_line_high(x1, y1, x2, y2);
	}
}

void
bla_line_high(int x1, int y1, int x2, int y2)
{
	int dx, dy, x_inc, p, x, y;

	dx = x2 - x1;
	dy = y2 - y1;

	x_inc = 1;
	if (dx < 0) {
		x_inc = -1;
		dx    = -dx;
	}

	p = 2 * dx - dy;

	x = x1;
	y = y1;

	while (y < y2) {
		putpixel(x, y, WHITE);

		y++;
		if (p > 0) {
			x += x_inc;
			p = p + 2 * dx - 2 * dy;
		} else {
			p = p + 2 * dx;
		}
	}
}

void
bla_line_low(int x1, int y1, int x2, int y2)
{
	int dx, dy, y_inc, p, x, y;

	dx = x2 - x1;
	dy = y2 - y1;

	y_inc = 1;
	if (dy < 0) {
		y_inc = -1;
		dy    = -dy;
	}

	p = 2 * dy - dx;

	x = x1;
	y = y1;

	while (x < x2) {
		putpixel(x, y, WHITE);

		x++;
		if (p > 0) {
			y += y_inc;
			p = p + 2 * dy - 2 * dx;
		} else {
			p = p + 2 * dy;
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

	//        x1   y1   x2   y2
	bla_line(100, 100, 450, 350);
	// bla_line(450, 350, 100, 100);
	// bla_line(100, 450, 300, 100);
	// bla_line(300, 100, 100, 450);
	// bla_line(100, 100, 400, 100);
	// bla_line(400, 100, 100, 100);
	// bla_line(100, 450, 100, 250);
	// bla_line(100, 250, 100, 450);

	getchar();
	closegraph();
	return 0;
}
