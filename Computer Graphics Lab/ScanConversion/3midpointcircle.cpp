#include<iostream>
#include<graphics.h>

using namespace std;
 

void symmetry(int x, int y, int h, int k){
	putpixel(x+h,y+k,WHITE);
	putpixel(-x+h,y+k,WHITE);
	putpixel(x+h,-y+k,WHITE);
	putpixel(-x+h,-y+k,WHITE);
	putpixel(y+h,x+k,WHITE);
	putpixel(-y+h,x+k,WHITE);
	putpixel(y+h,-x+k,WHITE);
	putpixel(-y+h,-x+k,WHITE);

}

void midPointCircle(int h,int k, int radius){
  int x = 0;
  int y = radius;
  int p = 1 - radius;
  while(x<y){
    symmetry(x,y,h,k);
            x++;
    
    if(p<0){
      p=p+(2*x)+1;
    }
    else{
      p = p + (2*x)-(2*y)+1;
      y--;
    }
    symmetry(x,y,h,k);
     delay(50);
  }
 
} 

int main(){
  int radius,x,y;
  cout<<"Enter the radius of circle: ";
  cin>>radius;
  cout<<"Enter the x and y centre coordinates of the circle: ";
  cin>>x>>y;
  int gmode, gdriver=DETECT;
  initgraph(&gdriver,&gmode, NULL);
  midPointCircle(x,y,radius);
  getch();
  closegraph();
  return 0;
}