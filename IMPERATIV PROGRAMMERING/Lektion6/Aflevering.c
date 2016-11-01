
/*
    Programmer: Lukas Rønsholt          Date: 10-10-16
    Teacher: Kurt Nørmark               Class: Imperative Programming

    ATM simulator:
    changes an amount of USD to the least possible combination of the bills 100, 50, 20, 10.
*/
#include <stdio.h>

void change(int amount, int *ten, int *twenty, int *fifty, int *hundred);

int main(void){
    // initialize the variable needed in main
    int amount;
    int ten, twenty, fifty, hundred;

    //prompt the user for input
    printf("Amount to change ?\n");
    printf("Amount in USD: ");
    scanf("%d", &amount);

    // check if input is dividable by 10
    if (amount % 10 == 0)
    {
        // call the change function to get the input in bill combination
        change(amount, &ten, &twenty, &fifty, &hundred);
        printf("\n%d USD is changeable to:\n\n%d hundred bills\n%d fifty bills\n%d twenty bills\n%d ten bills\n", amount, hundred, fifty, twenty, ten);
    } else {
        // print out that the input is not dividable by 10
        printf("Please enter an amount which is dividable by 10\n");
    }
}
// function to change amount to the smallest combination of bills
void change(int amount, int *ten, int *twenty, int *fifty, int *hundred){
    // initialize a rest variable
    int rest_amount;

    // conversion and output 
    *hundred = amount / 100;
    rest_amount = amount % 100;

    *fifty = rest_amount / 50;
    rest_amount %= 50;

    *twenty = rest_amount / 20;
    rest_amount %= 20;

    *ten = rest_amount / 10;
}