#include <stdio.h>
#include <math.h>
#define MAX 100
int main()
{
  int i, n;
  float x[MAX], y[MAX],u[MAX];
  float sumx = 0.0, sumu = 0.0, sumxy = 0.0, sumxx = 0.0,sumxu=0.0, xmean, ymean, umean , denom, a, b;
  printf("\n Input the number of data points: ");
  scanf("%d", &n);
  printf("\n Input x and y values(one set on each line:)");
  for (i = 1; i <= n; i++)
  {
    scanf("%f%f", &x[i], &y[i]);
  }
  for (i = 1; i <= n; i++)
  {
    u[i]=log(y[i]);
  }
  for (i = 1; i <= n; i++)
  {
    sumx = sumx + x[i];
    sumu = sumu + y[i];
    sumxy = sumxy + x[i] * y[i];
    sumxu = sumxx + x[i] * u[i];
  }
  xmean = sumx / n;
  umean = sumu / n;
  denom = n * sumxx - sumx * sumx;
  b = (n * sumxu - sumx * sumu) / denom;
  a = exp(umean-b*xmean);
  printf("\n The line that is fir to the given data is y = %f + %fx", a, b);
  return 0;
}
