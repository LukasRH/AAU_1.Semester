/*
    Name: Programeringsstil
    Program til at udregne gennemsnittet af 3 tal.
    Svagheder: Programmet tager ikke højde for om hvilken type der bliver indtastet, og der kan komme forkerte outputs.
*/

#include <stdio.h>

int main(void) {
    float firstNumber,
          secondNumber, 
          thirdNumber;

    printf("Find the average of 3 numbers.\nType in three numbers: ");
    scanf("%f %f %f", &firstNumber, &secondNumber, &thirdNumber);
    printf("The result: %f\n", (firstNumber + secondNumber + thirdNumber) / 3.0);
    
    return 0;
}