#include <stdio.h>

#include <graphics.h>

// Bit masks of edges

#define LEFT_EDGE   0x1 // 0001
#define RIGHT_EDGE  0x2 // 0010
#define BOTTOM_EDGE 0x4 // 0100
#define TOP_EDGE    0x8 // 1000

// Macros to check the meaning of outcodes -- Whether completely inside or
// outside (at least one edge) relative to the clip window.

#define INSIDE(a)    (!a)
#define REJECT(a, b) (a & b)
#define ACCEPT(a, b) (!(a | b))

// Constants and macros about the world and viewport

#define WORLD_WIDTH  640
#define WORLD_HEIGHT 480

#define VIEW_WIDTH  320
#define VIEW_HEIGHT 240

#define VIEW_MIN_X (WORLD_WIDTH - VIEW_WIDTH) / 2
#define VIEW_MIN_Y (WORLD_HEIGHT - VIEW_HEIGHT) / 2
#define VIEW_MAX_X WORLD_WIDTH - VIEW_MIN_X
#define VIEW_MAX_Y WORLD_HEIGHT - VIEW_MIN_Y

// Helper macros

#define SWAP_VAR(a, b) (a ^= b, b = a ^ b, a ^= b)

// Function Declarations
// ---------------------

// Get the outcode for the given x-y coordinate relative to the viewport
// coordinates.
unsigned char
outcode_get(int x, int y);

// Clips the line and draws it (the clipped line) as well as the original line.
// Calls `draw_line()` internally.
void
draw_line_clipped(int x1, int y1, int x2, int y2);

// Draw the line with two circles on the starting and ending points.
// To be called by `draw_line_clipped()`.
void
draw_line(int x1, int y1, int x2, int y2);

// Draw rectangle representing the viewport.
void
init_viewport(void);

// Function Implementations
// ------------------------

unsigned char
outcode_get(int x, int y)
{
	unsigned char outcode = 0x00;

	if (x < VIEW_MIN_X)
		outcode |= LEFT_EDGE;
	if (x > VIEW_MAX_X)
		outcode |= RIGHT_EDGE;
	if (y < VIEW_MIN_Y)
		outcode |= BOTTOM_EDGE;
	if (y > VIEW_MAX_Y)
		outcode |= TOP_EDGE;

	return outcode;
}

void
draw_line_clipped(int x1, int y1, int x2, int y2)
{
	unsigned char outcode1, outcode2;
	int           done = 0;
	int           draw = 0;
	while (!done) {
		outcode1 = outcode_get(x1, y1);
		outcode2 = outcode_get(x2, y2);

		if (ACCEPT(outcode1, outcode2)) { // completely inside
			draw = 1;
			done = 1;
			continue;
		}

		if (REJECT(outcode1, outcode2)) { // completely outside
			done = 1;
			continue;
		}

		// If the code gets here, it means the line is partially outside

		if (INSIDE(outcode1)) {
			SWAP_VAR(x1, x2);
			SWAP_VAR(y1, y2);
			SWAP_VAR(outcode1, outcode2);
		}

		// Use slope (m) to find line-clip edge intersections

		float m;
		if (x2 != x1)
			m = (float)(y2 - y1) / (x2 - x1);

		if (outcode1 & LEFT_EDGE) {
			y1 += ((float)VIEW_MIN_X - x1) * m;
			x1 = VIEW_MIN_X;
			continue;
		}

		if (outcode1 & RIGHT_EDGE) {
			y1 += (VIEW_MAX_X - x1) * m;
			x1 = VIEW_MAX_X;
			continue;
		}

		if (outcode1 & BOTTOM_EDGE) {
			// Need to update x1 for non-vertical lines only
			if (x2 != x1)
				x1 += (VIEW_MIN_Y - y1) / m;
			y1 = VIEW_MIN_Y;
			continue;
		}

		if (outcode1 & TOP_EDGE) {
			if (x2 != x1)
				x1 += (VIEW_MAX_Y - y1) / m;
			y1 = VIEW_MAX_Y;
		}
	}

	if (draw)
		draw_line(x1, y1, x2, y2); // processed points
}

void
draw_line(int x1, int y1, int x2, int y2)
{
	fillellipse(x1, y1, 3, 3);
	line(x1, y1, x2, y2);
	fillellipse(x2, y2, 3, 3);
}

void
init_viewport(void)
{
	line(VIEW_MIN_X, 0, VIEW_MIN_X, WORLD_HEIGHT);
	line(VIEW_MAX_X, 0, VIEW_MAX_X, WORLD_HEIGHT);
	line(0, VIEW_MIN_Y, WORLD_WIDTH, VIEW_MIN_Y);
	line(0, VIEW_MAX_Y, WORLD_WIDTH, VIEW_MAX_Y);
}

int
main(void)
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:/TC/BGI");

	// Show original lines
	outtextxy(10, 10, "Original Lines");
	init_viewport();
	draw_line(200, 200, 350, 300);  // Fully inside
	draw_line(400, 300, 550, 300);  // Partially inside
	draw_line(100, 250, 550, 430);  // Partially inside but both endpoints are outside

	getchar();
	cleardevice();

	// Show clipped lines
	outtextxy(10, 10, "Clipped Lines");
	init_viewport();
	draw_line_clipped(200, 200, 350, 300);  // Fully inside
	draw_line_clipped(400, 300, 550, 300);  // Partially inside
	draw_line_clipped(100, 250, 550, 430);  // Partially inside but both endpoints are outside

	getchar();
	closegraph();

	return 0;
}