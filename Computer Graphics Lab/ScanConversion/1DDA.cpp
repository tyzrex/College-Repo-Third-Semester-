#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;


int main(){
	int gd=DETECT, gm;
	initgraph (&gd, &gm,NULL);
	float x0,y0,x1,y1,x,y,dx,dy;
	cout<<"Enter value of x0 and y0: ";
	cin>>x0>>y0;
	cout<<"Enter value of x1 and y1: ";
	cin>>x1>>y1;
	dx=x1-x0;
	dy=y1-y0;
	x=x0;
	y=y0;
	float m = dy/dx;
    putpixel (x,y,WHITE);
	while(x!=x1 && y!=y1){
		if(m<1){
			x=x+1;
			y=y+m;
		}
		else if(m>1){
			x=x+(1/m);
			y=y+1;
		}
		else{
			x=x+1;
			y=y+m;
		}
		putpixel (x,y,WHITE);
		delay(100);
	}
	getch();
	closegraph();
	return 0;
}