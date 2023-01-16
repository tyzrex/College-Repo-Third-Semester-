#include<stdio.h>
#include<math.h>

float f(float x)
{
    return exp(-x*x);
}

void trapezoidal(float a, float b, int n)
{
    float h = (b-a)/n;
    float x[n+1], y[n+1];
    for (int i = 0; i <= n; i++)
    {
        x[i] = a + i*h;
        y[i] = f(x[i]);
    }
    float sum = y[0] + y[n];
    for (int i = 1; i < n; i++)
    {
        sum = sum + 2*y[i];
    }
    sum = sum * h/2;
    printf("The value of the integral is %.5f.\n", sum);
}

int main()
{
    float a, b;
    int n;
    printf("Enter the lower limit of integration: ");
    scanf("%f", &a);
    printf("Enter the upper limit of integration: ");
    scanf("%f", &b);
    printf("Enter the number of subintervals: ");
    scanf("%d", &n);
    trapezoidal(a, b, n);
    return 0;
}