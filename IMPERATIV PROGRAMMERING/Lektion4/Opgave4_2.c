
#include <stdio.h>
#define K 3
int main(void){
    int n,m,small,large;

    printf("Giv mig 2 nummre din sæk! ");
    scanf("%d%d",&n,&m);

    small = n <= m ? n : m;
    large = n <= m ? m : n;

    printf("large = %d \nsmall = %d\n",large,small);

    for ( small; small <= large; small++)
    {
        if (small % K == 0)
        {
            printf("%d \n",small);
        }
    }

    return 0;
}