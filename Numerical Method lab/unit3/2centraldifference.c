#include <stdio.h>
#include <math.h>

float f(float x)
{
    return exp(x)*sqrt((sin(x)+log(x)));
}

int main()
{
    float a, h, fd1, fd2;
    char q;
    do
    {
        printf("Enter the point at which derivative are required: ");
        scanf("%f", &a);
        printf("\n Enter the value of h: ");
        scanf("%f", &h);
        fd1 = (f(a + h) - f(a - h)) / (2 * h);
        fd2 = (f(a + h) - 2 * f(a) + f(a - h)) / (h * h);
        printf("The first and second derivatives at x=%f are %f and %f respectively.\n",a,fd1,fd2);
        printf("\n Do you want to input another value? (y/n): ");
        scanf("%c", &q);
    } while (q == 'y');
    return 0;
}