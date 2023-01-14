#include <stdio.h>
#include "graphics.h"

void shearing_rectangle(int length, int breadth, float shear_x, float shear_y) {
	outtextxy(50, 20, "Original rectangle");
	rectangle(50, 50, 50 + length, 50 + breadth);

	int tlx = 50;
	int tly = 50;
	int trx = tlx + length;
	int try = tly;
	int blx = tlx;
	int bly = tly + breadth;
	int brx = tlx + length;
	int bry = tly + breadth;

	tlx += (tly * shear_x);
	trx += (try * shear_x);
	brx += (bry * shear_x);
	blx += (bly * shear_x);
	trx += (try * shear_x);
	brx += (bry * shear_x);
	blx += (bly * shear_x);
	tlx += (tly * shear_x);

	tly += (tlx * shear_y);
	try += (trx * shear_y);
	bry += (brx * shear_y);
	bly += (blx * shear_y);
	try += (trx * shear_y);
	bry += (brx * shear_y);
	bly += (blx * shear_y);
	tly += (tlx * shear_y);

	outtextxy(trx + 15, try - 15, "Rectangle after shearing");
	line(tlx, tly, trx, try);
	line(trx, try, brx, bry);
	line(brx, bry, blx, bly);
	line(blx, bly, tlx, tly);
}

int main(void) {
	int   length, breadth;
	float shear_x, shear_y;

	printf("Enter the length of the rectangle: ");
	scanf("%d", &length);
	printf("Enter the breadth of the rectangle: ");
	scanf("%d", &breadth);

	printf("Enter the shearing in x-axis: ");
	scanf("%f", &shear_x);
	printf("Enter the shearing in y-axis: ");
	scanf("%f", &shear_y);

	getchar();

	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	shearing_rectangle(length, breadth, shear_x, shear_y);

	getchar();
	closegraph();

	return 0;
}
