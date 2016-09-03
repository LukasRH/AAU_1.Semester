/*
    Programmer: Lukas Rønsholt          Date: 03-09-16
    Teacher: Kurt Nørmark               Class: Imperative Programming

    Program for converting seconds to the format HH:MM:SS
*/

#include <stdio.h>
//Boolean
#include <stdbool.h>

// Define how many seconds in an min/hour
#define SEC_MINUTES 60
#define SEC_HOURS 3600
#define HOURS_DAY 24

int main(void){
    // define the variabels needed
    int seconds;
    int secondsLeft;
    int minutes;
    int hours;
    int days;
    bool day = false;

    // Promt user for seconds
    printf("Type in the time in seconds> ");
    scanf("%d",&seconds);

    // Convert the time to HH:MM:SS
    // hour
    hours = seconds / SEC_HOURS;
    secondsLeft = seconds % SEC_HOURS;
    // if more then 24 hours then add days
    if (hours >= HOURS_DAY)
    {
        days = hours / HOURS_DAY;
        hours = hours % HOURS_DAY;
        day = true;
    }
    // minutes
    minutes = secondsLeft / SEC_MINUTES;
    secondsLeft = secondsLeft % SEC_MINUTES;
    // Display the time
    if (day == true)
    {
        printf("%d seconds is equal to %d Days %d Hours %d Miuntes %d Seconds\n", seconds, days, hours, minutes, secondsLeft);
    } else
    {
        printf("%d seconds is equal to %d Hours %d Miuntes %d Seconds\n", seconds, hours, minutes, secondsLeft);
    }
    
    return 0;
}
