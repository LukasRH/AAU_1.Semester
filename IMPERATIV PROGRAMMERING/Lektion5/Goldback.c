#include <stdio.h>
#include "primes.h"

int goldbach(int x);

int main(void){
    int x, y = 2000000;

    for ( x = 8; x <= y; x + 2)
    {
        goldbach(x);
    }
    return 0;
}

int goldbach(int x){
    int a,b;

    while (a < x)
    {
        while (b < a)
        {
            if (is_prime(a) && is_prime(b))
            {
                if (a + b == x)
                {
                    printf("Yup");
                } 
            }
            ++a;
            ++b;
        }
    }
}