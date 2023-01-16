#include <stdio.h>
#include <math.h>

float interpolate(float xp, float *x, float *f, int n)
{
    float lf, sum = 0;
    for (int i = 0; i < n; i++)
    {
        lf = 1.0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                lf = lf * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        sum = sum + lf * f[i];
    }
    return sum;
}

int main()
{
    int size;
    char q;
    printf("Enter the number of data points: ");
    scanf("%d", &size);
    float x[size], f[size], xp, fp;
    printf("Enter the data points: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%f%f", &x[i], &f[i]);
    }
    do
    {
        printf("Input x at which interpolation is required: ");
        scanf("%f", &xp);
        fp = interpolate(xp, x, f, size);
        printf("Interpolated function value at x = %.5f is %.5f.\n", xp, fp);
        printf("Do you want to input another value? (y/n): ");
        scanf("%c", &q);
    } while (q == 'y');
    return 0;
}