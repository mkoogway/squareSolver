#include <stdio.h>
#include <math.h>

void calculate (double a, double b, double c, double *res);
void calcIN (double * a, double * b, double * c, int * eps);
void calcOUT (double * res, int eps);
void inputError (void);

int main(void){

    double a = NAN, b = NAN, c = NAN;
    int eps = 0;
    double res[2] = {NAN, NAN};

    calcIN(&a, &b, &c, &eps);
    calculate(a,b,c, res);
    calcOUT(res, eps);

    return 0;
}

void calcIN (double * a, double * b, double * c, int * eps){


    printf("This program solves square/linear equations:\n"
           "Format of the equation: ax^2 + bx + c = 0\n"
           "(In case of linear input 0 b c)\n"
           "Input: a b c\n");

    while (scanf("%lf%lf%lf", a, b, c) != 3){
        inputError();
    }

    printf("Input precision in \n"
           "number of digits after dot: ");

    while (!scanf("%d", eps)){
        inputError();
    }
}

void calculate (double a, double b, double c, double *res){

    if (a == 0){
        res[0] = -c / b;
        return;
    }

    double D = b*b - 4*a*c;

    if (D == 0)
        res[0] = -b / (2*a);
    else if (D > 0){
        res[0] = ( -b + sqrt(D) ) / (2*a);
        res[1] = ( -b - sqrt(D) ) / (2*a);
    }

}

void calcOUT (double * res, int eps){

    if (isnan(res[0]))
        printf("\nThe equation has no real solutions\n");
    else if (isnan(res[1]))
        printf("\nThe equation has one solution: %.*f\n", eps, res[0]);
    else if (fabs(res[0]-res[1]) < pow(0.1, eps))
        printf("\nDecrease precision, approximate solution: %.*f\n", eps, res[0]);
    else
        printf("\nThe equation has two solutions: %.*f %.*f\n", eps, res[0], eps, res[1]);
}

void inputError(void){
    char ch = 0;
    while((ch = getchar()) != '\n')
            continue;
    printf("Input should be decimal. For example: 3\n");
}
