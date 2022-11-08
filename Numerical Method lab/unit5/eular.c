// eulers method

#include <stdio.h>
#include <math.h>

float f(float x, float y)
{
    return (y - x * x + 1);
}

int main(){
    int i, n;
    float x,y,xp,h,dy;
    printf("\nInput initial values of x and y: ");
    scanf("%f%f", &x, &y);
    printf("\nInput x at which y is required: ");
    scanf("%f", &xp);
    printf("\nInput the number of steps: ");
    scanf("%f", &h);
    n = (int)((xp - x) / h + 0.5);
    for (i = 1; i <= n; i++)
    {
        dy = h * f(x, y);
        y = y + dy;
        x = x + h;
        printf("\n%d\t%f\t%f", i, x, y);
    }
    printf("\nValue of y at x = %f is %f ", x, y);
    return 0;
}