#include <stdio.h>
#include <math.h>
#include <graphics.h>

// Every rendering function is followed by a `scanf()` and inside every
// rendering function we have `getchar()`.
#define FLUSH_SCANF_NEWLINE getchar();

void
translation(int x1, int y1, int x2, int y2, int tx, int ty)
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	line(x1, y1, x2, y2);
	outtextxy(x2 + 2, y2 + 2, "Original line");

	int x3 = x1 + tx;
	int y3 = y1 + ty;
	int x4 = x2 + tx;
	int y4 = y2 + ty;

	line(x3, y3, x4, y4);
	outtextxy(x4 + 2, y4 + 2, "Line after translation");

	getchar();
	closegraph();
}

void
rotation(int x1, int y1, int x2, int y2, float angle_degree)
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:/TC/BGI");

	line(x1, y1, x2, y2);
	outtextxy(x2 + 2, y2 + 2, "Original line");

	float angle_radian = angle_degree * (3.14 / 180);

	int x3 = (x1 * cos(angle_radian)) - (y1 * sin(angle_radian));
	int y3 = (x1 * sin(angle_radian)) + (y1 * cos(angle_radian));
	int x4 = (x2 * cos(angle_radian)) - (y2 * sin(angle_radian));
	int y4 = (x2 * sin(angle_radian)) + (y2 * cos(angle_radian));

	line(x3, y3, x4, y4);
	outtextxy(x4 + 2, y4 + 2, "Line after rotation");

	getchar();
	closegraph();
}

void
scaling(int x1, int y1, int x2, int y2, float scale_x, float scale_y)
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:/TC/BGI");

	line(x1, y1, x2, y2);
	outtextxy(x2 + 2, y2 + 2, "Original line");

	int x3 = x1 * scale_x;
	int y3 = y1 * scale_y;
	int x4 = x2 * scale_x;
	int y4 = y2 * scale_y;

	line(x3, y3, x4, y4);
	outtextxy(x4 + 2, y4 + 2, "Line after scaling");

	getchar();
	closegraph();
}

void
shearing(int square_length, float shear_x, float shear_y)
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:/TC/BGI");

	int tlx = 50;                  // top-left-x
	int tly = 50;                  // top-left-y
	int trx = tlx + square_length; // top-right-x
	int try = tly;                 // top-right-y
	int blx = tlx;                 // bottom-left-x
	int bly = tly + square_length; // bottom-left-y
	int brx = tlx + square_length; // bottom-right-x
	int bry = tly + square_length; // bottom-right-y

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
	// Menu
	// ----

	printf("Enter a choice:\n");
	printf("1. Translation\n");
	printf("2. Rotation\n");
	printf("3. Scaling\n");
	printf("4. Shearing\n");
	printf("5. Exit\n");

	int input;
	do {
		printf("\n> ");
		scanf("%d", &input);

		switch (input) {
		case 1: {
			int x1, y1, x2, y2;
			int tx, ty;

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
			int   x1, y1, x2, y2;
			float angle_degree;

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
			int   x1, y1, x2, y2;
			float scale_x, scale_y;

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
			int   square_length;
			float shear_x, shear_y;

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
