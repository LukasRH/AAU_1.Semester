/*  Wri te a program segment that computes 1  +  2  +  3  +  ...  +  (n  -  1)  +  n , where n  is a data value. 
    Follow the loop body with an if  statement that compares this value to (n  *  (n  +  1))  /  2  
    and displays a message that indicates whether the values are the same or different. 
    What message do you think will be displayed? */

#include <stdio.h>

int main(void){
    int count, n, sum = 0, sum2;

    printf("input number: ");
    scanf("%d",&n);

    for ( count = 0; count <= n; count++)
    {
        sum += count;
    }

    sum2 = (n*(n+1))/2;

    if (sum == sum2)
    {
        printf("Same Value \n");
    } else
    {
        printf("Not Same Value \n");
    }
    return 0;
}