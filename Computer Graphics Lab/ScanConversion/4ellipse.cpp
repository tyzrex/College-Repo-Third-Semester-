#include<graphics.h>
#include<iostream>
using namespace std;
void drawEllipse(float x, float y, float xc, float yc)
 {
    putpixel(xc+x,yc+y,WHITE);
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc-x,yc-y,WHITE);
        delay(100);
 }
void midPointEllipse(float xc,float yc,float a,float b)
{
    float x=0, y=b;
    float p=b*b-a*a*b+a*a/4;
    while(2.0*b*b*x <= 2.0*a*a*y)
    {
        if(p < 0)
        {
            x++;
            p = p+2*b*b*x+b*b;
        }
        else
        {
            x++;
            y--;
            p = p+2*b*b*x-2*a*a*y+b*b;
        }
        drawEllipse(x,y,xc,yc);
    }
 
 
    p=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
    while(y > 0)
    {
        if(p <= 0)
        {
            x++;
            y--;
            p = p+2*b*b*x-2*a*a*y+a*a;
        }
        else
        {
            y--;
            p = p-2*a*a*y+a*a;
        }
        drawEllipse(x,y,xc,yc);
    }
}

int main()
{
    int rx,ry,xc,yc;
	cout<<"Enter minor radius (rx,ry): ";
	cin>>rx>>ry;
	cout<<"Enter radius (xc,yc): ";
	cin>>xc>>yc;
	
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    cout<<"Enter the x and y coordinates";
    midPointEllipse(rx,ry,xc,yc);
    getch();
    closegraph();
}