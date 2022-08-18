#include <stdio.h>
#include <math.h>

void calculate(double a, double b, double c, int eps);


int main(void){

    double a, b, c; int eps;

    printf("ax^2 + bx + c:\n");
    printf("a: "); scanf("%lf", &a);
    printf("b: "); scanf("%lf", &b);
    printf("c: "); scanf("%lf", &c);
    printf("precision ( .number of digits ): "); scanf("%d", &eps);

    calculate(a,b,c,eps);

    return 0;
}


void calculate(double a, double b, double c, int eps){

    double D = b*b - 4.0*a*c;

    if(D<0) printf("The equation has no real solutions\n");

    else if(D==0) printf("The equation has one solution: %.*f\n", eps, -b/(2*a));

    else {

        double res1, res2;

        res1 = (-b+sqrt(D))/(2*a);
        res2 = (-b-sqrt(D))/(2*a);

        if(fabs(res1-res2) < pow(0.1,eps))
            printf("Low precision, approximate solution: %.*f\n", eps, res1);

        else
            printf("The equation has two solutions: %.*f %.*f\n", eps, res1, eps, res2);
    }

}
