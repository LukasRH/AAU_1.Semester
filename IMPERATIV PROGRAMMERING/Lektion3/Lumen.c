#include <stdio.h>

int main(void){
    int watt, Lumen;

    printf("Type in Watts >");
    scanf("%d",&watt);

    switch (watt)
    {
        case 15:
            Lumen = 125;
            break;
        case 25:
            Lumen = 215;
            break;
        case 40:
            Lumen = 500;
            break;
        case 60:
            Lumen = 880;
            break;
        case 75:
            Lumen = 1000;
            break;
        case 100:
            Lumen = 1675;
            break;
        default:
            printf("Go fuck yourself.\n");
            break;
    }
    if (Lumen >= 125 && Lumen <= 1675)
    {
        printf("Lumen: %d\n",Lumen);
    }
    return 0;
}