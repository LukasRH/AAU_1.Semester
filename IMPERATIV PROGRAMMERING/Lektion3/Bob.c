#include <stdio.h>
#include <math.h>

int main(void){
    double r = 5,x,y,lenght;
    
    printf("input x & y >");
    scanf("%lf %lf",&x, &y);

    lenght = sqrt((x*x)+(y*y));

    if (lenght < r)
    {
        printf("Punktet ligger inde i cirklen");
    } else if (lenght == r){
        printf("Punktet ligger på periferien");
    } else{
        printf("Punktet ligger udenfor cirkelen");
    }
    
    return 0;
}