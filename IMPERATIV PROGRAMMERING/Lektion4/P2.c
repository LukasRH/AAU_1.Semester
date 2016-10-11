

#include <stdio.h>

#define MAX_PEOPLE 30000

int main(void){
    int people = 9870, count = 0;

    do{
        count++;
        people = people * 1.1;
        printf("Year %d = People %d \n",count, people);
    }
    while (people <= MAX_PEOPLE);
    printf("It took %d years \n",count);
    return 0;
}