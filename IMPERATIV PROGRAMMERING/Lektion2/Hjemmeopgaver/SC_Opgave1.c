/*
    Self check opgave 1 side 88 i Problem solving and program design in C.

    - Lukas Rønsholt
    - 03-09-16
*/

#include <stdio.h>

int main(void) {

    int m;
    int n;

    printf("Enter two integers> ");
    scanf("%d%d", &m, &n);

    m = m + 5;
    n = 3 * n;

    printf("m = %d\nn = %d\n", m, n);

    return 0;
}