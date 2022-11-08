#include<stdio.h>
#include<math.h>

float f(float x, float y)
{
		return (y-x*y+1);
}

int main(){
	int i,n;
	float x,y,xp,h,m1,m2;
	printf("\nInput initial values of x and y: ");
	scanf("%f%f",&x,&y);
	printf("\nInput x at which y is required: ");
	scanf("%f",&xp);
	printf("\nInput the number of steps: ");
	scanf("%f",&h);
	n=(int)((xp-x)/h+0.5);
	for(i=1;i<=n;i++){
		m1=f(x,y);
		m2=f(x+h,y+h*m1);
		y=y+(h/2)*(m1+m2);
		x=x+h;
		printf("\n%d\t%f\t%f",i,x,y);
	}
	printf("\nValue of y at x = %f is %f ",x,y);
	return 0;
}

