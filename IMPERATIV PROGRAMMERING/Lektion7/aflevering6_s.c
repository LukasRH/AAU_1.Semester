#include <stdio.h>
#include <math.h>

/*
g(x) = x² * sin(x)

a = 0

b = 3.14159
*/
double sineFunc(double x);


/*
h(x) = sqrt(4 - x²)

a = -2

b = 2
*/
double sqrtFunc(double x);

double getIntervals(double a, double b, double n);

double getAreaUnder(double (*func)(double), double a, double b, double n);
/*

*/

int main(void) {

    printf("Calculate area under function:\n");
    printf("function 1: h(x) = sqrt(4 - x²), a = -2, b = 2\n");
    printf("The area under the function is: %.2f\n", getAreaUnder(sqrtFunc, -2, 2, 128));

    return 0;
}

double sineFunc(double x) {
    return x * x * sin(x);
}

double sqrtFunc(double x) {
    return sqrt(4 - x * x);
}

double getIntervals(double a, double b, double n) {
    return (b - a) / n;
}

double getAreaUnder(double (*func)(double), double a, double b, double n) {
    double interval = getIntervals(a, b, n);
    double i = interval;
    double fxi = (*func)(a + i);

    for (i = a + interval; i < b - interval; i+= interval) {
        fxi += (*func)(i);
    }
    return interval / 2 * ((*func)(a) + (*func)(b) + 2 * fxi);
}