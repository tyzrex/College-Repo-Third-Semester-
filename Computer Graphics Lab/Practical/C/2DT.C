#include <stdio.h>
#include <math.h>

#include <graphics.h>

// Every rendering function is followed by a `scanf()` and inside every
// rendering function we have `getchar()`.
#define FLUSH_SCANF_NEWLINE getchar();

void
translation(int x1, int y1, int x2, int y2, int tx, int ty)
{
	int gd, gm, x3, y3, x4, y4;

	gd = DETECT;
	initgraph(&gd, &gm, "C:/TC/BGI");

	line(x1, y1, x2, y2);
	outtextxy(x2 + 2, y2 + 2, "Original line");

	x3 = x1 + tx;
	y3 = y1 + ty;
	x4 = x2 + tx;
	y4 = y2 + ty;

	line(x3, y3, x4, y4);
	outtextxy(x4 + 2, y4 + 2, "Line after translation");

	getchar();
	closegraph();
}

void
rotation(int x1, int y1, int x2, int y2, float angle_degree)
{
	int gd, gm, x3, y3, x4, y4;
	float angle_radian;

	gd = DETECT;
	initgraph(&gd, &gm, "C:/TC/BGI");

	line(x1, y1, x2, y2);
	outtextxy(x2 + 2, y2 + 2, "Original line");

	angle_radian = angle_degree * (3.14 / 180);

	x3 = (x1 * cos(angle_radian)) - (y1 * sin(angle_radian));
	y3 = (x1 * sin(angle_radian)) + (y1 * cos(angle_radian));
	x4 = (x2 * cos(angle_radian)) - (y2 * sin(angle_radian));
	y4 = (x2 * sin(angle_radian)) + (y2 * cos(angle_radian));

	line(x3, y3, x4, y4);
	outtextxy(x4 + 2, y4 + 2, "Line after rotation");

	getchar();
	closegraph();
}

void
scaling(int x1, int y1, int x2, int y2, float scale_x, float scale_y)
{
	int gd, gm, x3, y3, x4, y4;

	gd = DETECT;
	initgraph(&gd, &gm, "C:/TC/BGI");

	line(x1, y1, x2, y2);
	outtextxy(x2 + 2, y2 + 2, "Original line");

	x3 = x1 * scale_x;
	y3 = y1 * scale_y;
	x4 = x2 * scale_x;
	y4 = y2 * scale_y;

	line(x3, y3, x4, y4);
	outtextxy(x4 + 2, y4 + 2, "Line after scaling");

	getchar();
	closegraph();
}

void
shearing(int square_length, float shear_x, float shear_y)
{
	int gd, gm, tlx, tly, trx, try, blx, bly, brx, bry;

	gd = DETECT;
	initgraph(&gd, &gm, "C:/TC/BGI");

	tlx = 50;                  // top-left-x
	tly = 50;                  // top-left-y
	trx = tlx + square_length; // top-right-x
	try = tly;                 // top-right-y
	blx = tlx;                 // bottom-left-x
	bly = tly + square_length; // bottom-left-y
	brx = tlx + square_length; // bottom-right-x
	bry = tly + square_length; // bottom-right-y

	line(tlx, tly, trx, try);
	line(trx, try, brx, bry);
	line(brx, bry, blx, bly);
	line(blx, bly, tlx, tly);
	outtextxy(blx, bly + 5, "Original square");

	// Moving the square in x-axis by 300 pixels
	tlx += 300;
	trx += 300;
	blx += 300;
	brx += 300;

	// Shearing in x-axis
	tlx += (tly * shear_x);
	trx += (try * shear_x);
	brx += (bry * shear_x);
	blx += (bly * shear_x);
	trx += (try * shear_x);
	brx += (bry * shear_x);
	blx += (bly * shear_x);
	tlx += (tly * shear_x);

	// Shearing in y-axis
	tly += (tlx * shear_y);
	try += (trx * shear_y);
	bry += (brx * shear_y);
	bly += (blx * shear_y);
	try += (trx * shear_y);
	bry += (brx * shear_y);
	bly += (blx * shear_y);
	tly += (tlx * shear_y);

	line(tlx, tly, trx, try);
	line(trx, try, brx, bry);
	line(brx, bry, blx, bly);
	line(blx, bly, tlx, tly);
	outtextxy(blx, bry + 5, "Square after shearing");

	getchar();
	closegraph();
}

int
main(void)
{
	int input, x1, y1, x2, y2, tx, ty, square_length;
	float angle_degree, scale_x, scale_y, shear_x, shear_y;

	// Menu
	// ----

	printf("Enter a choice:\n");
	printf("1. Translation\n");
	printf("2. Rotation\n");
	printf("3. Scaling\n");
	printf("4. Shearing\n");
	printf("5. Exit\n");

	do {
		printf("\n> ");
		scanf("%d", &input);

		switch (input) {
		case 1: {
			printf("Enter x1: ");
			scanf("%d", &x1);
			printf("Enter y1: ");
			scanf("%d", &y1);
			printf("Enter x2: ");
			scanf("%d", &x2);
			printf("Enter y2: ");
			scanf("%d", &y2);

			printf("Enter tx: ");
			scanf("%d", &tx);
			printf("Enter ty: ");
			scanf("%d", &ty);

			FLUSH_SCANF_NEWLINE

			translation(x1, y1, x2, y2, tx, ty);
		} break;
		case 2: {
			printf("Enter x1: ");
			scanf("%d", &x1);
			printf("Enter y1: ");
			scanf("%d", &y1);
			printf("Enter x2: ");
			scanf("%d", &x2);
			printf("Enter y2: ");
			scanf("%d", &y2);

			printf("Enter angle for rotation (in degree): ");
			scanf("%f", &angle_degree);

			FLUSH_SCANF_NEWLINE

			rotation(x1, y1, x2, y2, angle_degree);
		} break;
		case 3: {
			printf("Enter x1: ");
			scanf("%d", &x1);
			printf("Enter y1: ");
			scanf("%d", &y1);
			printf("Enter x2: ");
			scanf("%d", &x2);
			printf("Enter y2: ");
			scanf("%d", &y2);

			printf("Enter scaling factor in x: ");
			scanf("%f", &scale_x);
			printf("Enter scaling factor in y: ");
			scanf("%f", &scale_y);

			FLUSH_SCANF_NEWLINE

			scaling(x1, y1, x2, y2, scale_x, scale_y);
		} break;
		case 4: {
			printf("Enter square length: ");
			scanf("%d", &square_length);

			printf("Enter shearing factor in x: ");
			scanf("%f", &shear_x);
			printf("Enter shearing factor in y: ");
			scanf("%f", &shear_y);

			FLUSH_SCANF_NEWLINE

			shearing(square_length, shear_x, shear_y);
		} break;
		case 5:
			break;
		default:
			printf("Please enter a valid input!\n");
		}
	} while (input != 5);

	return 0;
}
