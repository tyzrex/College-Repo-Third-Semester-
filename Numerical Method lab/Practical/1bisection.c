#include <stdio.h>
#include <math.h>
#define E 0.0001

float f(float x)
{
    return x * x * x - 3 * x + 1;
}

int main()
{
    float a, b, c;
    printf("Enter the values of a and b: ");
    scanf("%f%f", &a, &b);
    if (f(a) * f(b) > 0)
    {
        printf("No root in interval!");
    }
    else
    {
        do
        {
            c = (a + b) / 2;
            if (f(c) == 0)
            {
                printf("The root is: %f", c);
                break;
            }
            if (f(a) * f(c) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
        } while (fabs((b - a) / b) > E);
        printf("The root is: %f", c);
    }
    return 0;
}