#include<stdio.h>
#include<math.h>

#define EPS 0.00001

float f1(float x, float y1, float y2)
{
return y2;
}

float f2(float x, float y1, float y2)
{
return 3*x*y1+1;
}

float euler(float x0,float x1,float y0,float y1,float h)
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
    return y0;
}

//Routine for Heun's method

float heun(float x0,float x1,float y0,float y1,float h)
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
    printf("\n %f\t %f",x0,y0);
    return y0;
}

//Routine for Runge-Kutta method

float rk(float x0,float x1,float y0,float y1,float h)
{
    float k1,l1,k2,l2,k3,l3,k4,l4;
    printf("\n\nCalculation of y(%f) for guess %f:",x1,y1);
    printf("\n x\t\t y(x)");
    while(fabs(x1-x0)>EPS)
    {
        printf("\n %f\t %f",x0,y0);
        k1=f1(x0,y0,y1);
        l1=f2(x0,y0,y1);
        k2=f1(x0+h/2,y0+h*k1/2,y1+h*l1/2);
        l2=f2(x0+h/2,y0+h*k1/2,y1+h*l1/2);
        k3=f1(x0+h/2,y0+h*k2/2,y1+h*l2/2);
        l3=f2(x0+h/2,y0+h*k2/2,y1+h*l2/2);
        k4=f1(x0+h,y0+h*k3,y1+h*l3);
        l4=f2(x0+h,y0+h*k3,y1+h*l3);
        y0=y0+h*(k1+2*k2+2*k3+k4)/6;
        y1=y1+h*(l1+2*l2+2*l3+l4)/6;
        x0=x0+h;
    }
    printf("\n %f\t %f",x0,y0);
    return y0;
}

int main(){
    float x0,yx0,x1,yx1,guess1,guess2,guess3,yguess1,yguess2,yguess3,xp,yxp,h;
    char q;
    printf("Enter the first boundry conditions x and y(x): ");
    scanf("%f%f",&x0,&yx0);
    printf("Enter the second boundry conditions x and y(x): ");
    scanf("%f%f",&x1,&yx1);
    printf("Enter the guess1 value: ");
    scanf("%f",&guess1);
    printf("Enter the step: ");
    scanf("%f",&h);
    yguess1 = heun(x0,x1,yx0,guess1,h);
    printf("\n The calculated value of y(%f) is %f",x1,yguess1);
    if(fabs(yguess1-yx1)<EPS)
    {
        guess3 = guess1;
    }
    else{
        printf("\n Enter the second guess of y(%f):",x0);
        scanf("%f",&guess2);
        yguess2 = heun(x0,x1,yx0,guess2,h);
        printf("\n The calculated value of y(%f) is %f",x1,yguess2);
        if(fabs(yguess2-yx1)<EPS)
        {
            guess3 = guess2;
        }
        else{
            do{
                guess3 = guess2+(yx1-yguess2)*(guess2-guess1)/(yguess2-yguess1);
                yguess3 = heun(x0,x1,yx0,guess3,h);
                guess1 = guess2;
                guess2 = guess3;
                yguess1 = yguess2;
                yguess2 = yguess3;
            }while(fabs(yguess3-yx1)>EPS);
        }
        printf("\n\n The extrapolated value of y(%f) is %f",x0,yguess3);
        printf("\n\n The calculated value of y(%f) using y'(%f) is %f",x1,x0,guess3);
    }
    do{
        printf("\n\n Enter the value of x for which y(x) is to be calculated:");
        scanf("%f",&xp);
        yxp = heun(x0,xp,yx0,guess3,h);
        printf("\n The calculated value of y(%f) is %f",xp,yxp);
        printf("\n\n Do you want to continue?(y/n):");
        scanf("%s",&q);
    }while(q=='y');
    return 0;
}

