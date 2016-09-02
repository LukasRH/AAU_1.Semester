/*
    Name: Programeringsstil
    Program til at udregne gennemsnittet af 3 tal.
    Svagheder: Programmet tager ikke højde for om hvilken type der bliver indtastet, og der kan komme forkerte outputs
               Variablerne har ikke sammenhængende navne og kan forkomme forvirende.
*/

#include <stdio.h>

int main(void) {
    float first_number,
          xxx, 
          sidsteTal;

    printf("Give me three: ");
    scanf("%f %f %f", &first_number, &xxx, &sidsteTal);
    printf("The result: %f\n", (first_number + xxx + sidsteTal) / 3.0);
    
    return 0;
}