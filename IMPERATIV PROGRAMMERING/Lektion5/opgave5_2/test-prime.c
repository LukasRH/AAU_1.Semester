#include <stdio.h>
#include "primes.h"

int main()
{
    int i = 0, p = 0;

    while (p <= 100)
    {

        ++i;

        if (is_prime(i) == 1)
        {
            printf("primtal %d: %d\n", p, i);
            ++p;
        }
    }

    return 0;
}