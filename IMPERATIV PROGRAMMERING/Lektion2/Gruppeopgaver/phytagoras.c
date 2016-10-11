/*
PROGRAM:    Phytagoras - Triangle calculator
DATE:       4. September
BY:         Rasmus Egholm Nielsen
*/

#include <stdio.h>

int main(void)
{
    double m, n;
            
    /* Looking for m and n */
    printf("\nWrite the length of the 2 sides: \n");
    scanf("%lf %lf", &m, &n);
    
    /* Calculate side1, side2 and hypetenuse, based on input and formulas */
    double side1 = (m * m) - (n * n),
           side2 = 2 * (m * n);
    printf("Side1 = %4.2f \n", side1);
    printf("Side2 = %4.2f \n", side2);
    double hypetenuse = m * m + n * n;
    printf("Hypetenuse = %4.2f \n", hypetenuse);

    return 0;
}