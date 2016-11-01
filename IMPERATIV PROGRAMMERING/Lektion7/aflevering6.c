#include <stdio.h>
#include <math.h>

double trap(double a, double b, double n);
double get_interval(double a, double b, double n);
double func_h(double x);
double zigma(double a, double b, double n);

int main(void)
{
    double n, a = -2, b = 2;

    printf("Intast n >");
    scanf("%lf", &n);

    printf("trap g for n = %.f = %.2f\n",n, trap(a,b,n));
}

double trap(double a, double b, double n)
{
    return get_interval(a,b,n)/2 * (func_h(a)+func_h(b) + 2*zigma(a,b,n));
}

double get_interval(double a, double b, double n)
{
    return (b - a) / n;
}

double func_h(double x)
{
    return sqrt(4 - pow(x, 2));
}

double zigma(double a, double b, double n)
{
    double interval = get_interval(a,b,n);
    double sum = func_h(a + interval);
    double i;

    for ( i = a + interval; i < b - interval; i+= interval)
    {
        sum += func_h(i);
    }

    return sum;
}