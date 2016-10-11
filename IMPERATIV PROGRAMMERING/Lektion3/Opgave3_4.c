
#include <stdio.h>
#include<stdlib.h>

// Define how many seconds in an min/hour and hours a day
#define SEC_MINUTES 60
#define SEC_HOURS 3600
#define SEC_DAY 86400

int main(void){
    // Define variabels
    int sec,
        secLeft,
        min,
        hour,
        days;
    char plural,
         spacer,
         spacer2;

    // Promt for user input
    printf("Type in amount of seconds: ");
    scanf("%d",&sec);
    
    // Conversion
    // Days
    days = sec / SEC_DAY;
    secLeft = sec % SEC_DAY;
    // Hours 
    hour = secLeft / SEC_HOURS;
    secLeft %= SEC_HOURS;
    // Minutes
    min = secLeft / SEC_MINUTES;
    secLeft %= SEC_MINUTES;

    //Print output
    printf("\n%d seconds is equal to ",sec);
    if (days >= 1)
    {
        spacer = (hour >= 1 || min >= 1 || secLeft >= 1)? ',':' ';
        plural = (days > 1)? 's':spacer;
        spacer2 = (plural == 's')? spacer:' ';
        printf("%d Day%c%c ",days, plural,spacer2);
    }
    if (hour >= 1)
    {
        spacer = (min >= 1 || secLeft >= 1)? ',':' ';
        plural = (hour > 1)? 's':spacer;
        spacer2 = (plural == 's')? spacer:' ';
        printf("%d Hour%c%c ",hour, plural,spacer2);
    } 
    if (min >= 1)
    {
        spacer = (secLeft >= 1)? ',':' ';
        plural = (min > 1)? 's':spacer;
        spacer2 = (plural == 's')? spacer:' ';
        printf("%d Minute%c%c ",min, plural, spacer2);
    }
    if (secLeft >= 1)
    {
        plural = (secLeft > 1)? 's':'.';
        printf("%d Second%c",secLeft, plural);
    }
    printf("\n\nPress Enter to exit");
    getchar();
    getchar();
    return 0;
}