#include<stdio.h>
#include<math.h>

#define EPS 0.00001

float f1(float x, float y1, float y2)
{
return -4*y1+2*y2;
}

float f2(float x, float y1, float y2)
{
return 2*y1-4*y2;
}

void euler(float x0,float x1,float y0,float y1,float h)
{
    float m1,m2;
    printf("\n\nCalculation of y(%f) for guess %f:",x1,y1);
    printf("\n x\t\t y(x)");
    while(fabs(x1-x0)>EPS)
    {
        printf("\n %f\t %f",x0,y0);
        m1=h*f1(x0,y0,y1);
        m2=h*f2(x0,y0,y1);
        y0=y0+m1;
        y1=y1+m2;
        x0=x0+h;
    }
    printf("\n %f\t %f",x0,y0);
}

//Routine for Heun's method

void heun(float x0,float x1,float y0,float y1,float h)
{
    float m1,m2,m3,m4;
    printf("\n\nCalculation of y(%f) for guess %f:",x1,y1);
    printf("\n x\t\t y(x)");
    while(fabs(x1-x0)>EPS)
    {
        printf("\n %f\t %f",x0,y0);
        m1=h*f1(x0,y0,y1);
        m2=h*f2(x0,y0,y1);
        m3=h*f1(x0+h,y0+m1,y1+m2);
        m4=h*f2(x0+h,y0+m1,y1+m2);
        y0=y0+(m1+m3)/2;
        y1=y1+(m2+m4)/2;
        x0=x0+h;
    }
    printf("\n %f\t %f\t %f",x0,y0,y1);
    return;
}

float rk(float x0,float x1,float y0,float y1,float h)
{
    float k1,l1,k2,l2,k3,l3,k4,l4;
    printf("\n\nCalculation of y(%f) for guess %f:",x1,y1);
    printf("\n x\t\t y(x)");
    while(fabs(x1-x0)>EPS)
    {
        printf("\n %f\t %f",x0,y0);
        k1=h*f1(x0,y0,y1);
        l1=h*f2(x0,y0,y1);
        k2=h*f1(x0+h/2,y0+k1/2,y1+l1/2);
        l2=h*f2(x0+h/2,y0+k1/2,y1+l1/2);
        k3=h*f1(x0+h/2,y0+k2/2,y1+l2/2);
        l3=h*f2(x0+h/2,y0+k2/2,y1+l2/2);
        k4=h*f1(x0+h,y0+k3,y1+l3);
        l4=h*f2(x0+h,y0+k3,y1+l3);
        y0=y0+(k1+2*k2+2*k3+k4)/6;
        y1=y1+(l1+2*l2+2*l3+l4)/6;
        x0=x0+h;
    }
    printf("\n %f\t %f",x0,y0);
    return y0;
}

int main(){
    float x0,x1,y0,y1,h;
    char ch;
    printf("Enter the initial values of x and y(x):");
    scanf("%f%f",&x0,&y0);
   printf("Enter the value  of y_2(x):");
    scanf("%f",&y1);
    printf("Enter the step size:");
    scanf("%f",&h);

    do{
        printf("\n\n Enter the value of x for which y(x) is to be calculated:");
        scanf("%f",&x1);
        heun(x0,x1,y0,y1,h);
        printf("\n\n Do you want to continue? (y/n)");
        scanf("%c",&ch);
    }while(ch=='y');
    return 0;
}
