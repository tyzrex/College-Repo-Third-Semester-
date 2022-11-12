#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

void
translation(int x1, int y1, int x2, int y2, int tx, int ty)
{
	int gd = DETECT, gm = VGAMAX;
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
	int gd = DETECT, gm = VGAMAX;
	initgraph(&gd, &gm, NULL);

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
	int gd = DETECT, gm = VGAMAX;
	initgraph(&gd, &gm, NULL);

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
	int gd = DETECT, gm = VGAMAX;
	initgraph(&gd, &gm, NULL);

	int tlx = 100;                 // top-left-x
	int tly = 100;                 // top-left-y
	int trx = tlx + square_length; // top-right-x
	int trey = tly;                 // top-right-y
	int blx = tlx;                 // bottom-left-x
	int bly = tly + square_length; // bottom-left-y
	int brx = tlx + square_length; // bottom-right-x
	int bry = tly + square_length; // bottom-right-y

	line(tlx, tly, trx, trey);
	line(trx, trey, brx, bry);
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
	trx += (trey * shear_x);
	brx += (bry * shear_x);
	blx += (bly * shear_x);
	trx += (trey * shear_x);
	brx += (bry * shear_x);
	blx += (bly * shear_x);
	tlx += (tly * shear_x);

	// Shearing in y-axis
	tly += (tlx * shear_y);
	trey += (trx * shear_y);
	bry += (brx * shear_y);
	bly += (blx * shear_y);
	trey += (trx * shear_y);
	bry += (brx * shear_y);
	bly += (blx * shear_y);
	tly += (tlx * shear_y);

	line(tlx, tly, trx, trey);
	line(trx, trey, brx, bry);
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

			cout<<"Enter x1: ";
			cin>>x1;
			cout<<"Enter y1: ";
			cin>>y1;
			cout<<"Enter x2: ";
			cin>>x2;
			cout<<"Enter y2: ";
			cin>>y2;
			cout<<"Enter tx: ";
			cin>>tx;
			cout<<"Enter ty: ";
			cin>>ty;

			translation(x1, y1, x2, y2, tx, ty);
		} break;
		case 2: {
			int   x1, y1, x2, y2;
			float angle_degree;

			cout<<"Enter x1: ";
			cin>>x1;
			cout<<"Enter y1: ";
			cin>>y1;
			cout<<"Enter x2: ";
			cin>>x2;
			cout<<"Enter y2: ";
			cin>>y2;
			cout<<"Enter angle for rotation (in degree): ";
			cin>>angle_degree;

			rotation(x1, y1, x2, y2, angle_degree);
		} break;
		case 3: {
			int   x1, y1, x2, y2;
			float scale_x, scale_y;

			cout<<"Enter x1: ";
			cin>>x1;
			cout<<"Enter y1: ";
			cin>>y1;
			cout<<"Enter x2: ";
			cin>>x2;
			cout<<"Enter y2: ";
			cin>>y2;
			cout<<"Enter scale factor for x-axis: ";
			cin>>scale_x;
			cout<<"Enter scale factor for y-axis: ";
			cin>>scale_y;
			scaling(x1, y1, x2, y2, scale_x, scale_y);
		} break;
		case 4: {
			int   square_length;
			float shear_x, shear_y;

			cout<<"Enter length of square: ";
			cin>>square_length;
			cout<<"Enter shear factor for x-axis: ";
			cin>>shear_x;
			cout<<"Enter shear factor for y-axis: ";
			cin>>shear_y;
			shearing(square_length, shear_x, shear_y);
		} break;
		case 5:
			break;
		default:
			printf("Please enter a valid input!\n");
		}
	} while (input != 5);
}