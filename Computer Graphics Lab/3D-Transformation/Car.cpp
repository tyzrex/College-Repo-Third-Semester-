#include <stdio.h>
#include <graphics.h>

int main(void) {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	for (int i = 0; i <= 600; i = i + 10) {
		cleardevice();

		line(0 + i, 420, 210 + i, 420);
		line(50 + i, 420, 75 + i, 390);
		line(75 + i, 390, 150 + i, 390);
		line(150 + i, 390, 175 + i, 420);
		line(0 + i, 420, 0 + i, 450);
		line(210 + i, 420, 210 + i, 450);
		line(0 + i, 450, 210 + i, 450);

		fillellipse(65 + i, 450, 15, 15);
		fillellipse(145 + i, 450, 15, 15);

		delay(100);
	}

	getchar();
	closegraph();

	return 0;
}
