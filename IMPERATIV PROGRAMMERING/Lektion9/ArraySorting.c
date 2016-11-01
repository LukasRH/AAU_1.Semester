/*  
 *  
 *  
 *  */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int first_array[] = {1, 3, 5, 7, 9}, second_array[] = {2, 4, 6, 8, 10};
    int max_size = sizeof(first_array) + sizeof(second_array);
    int *res_array = (int *)malloc(max_size);
    int length = (sizeof(first_array) >= sizeof(second_array)) ? sizeof(first_array) / sizeof(int) : sizeof(second_array) / sizeof(int);

    for (int i = 0; i < length; i++)
    {
        int min = (first_array[i] < second_array[i])? first_array[i] : second_array[i];
        int max = (first_array[i] > second_array[i])? first_array[i] : second_array[i];

        if (res_array[i] > min)
        {
            res_array[i+1] = res_array[i];
            res_array[i] = min;
            
            if (res_array[i+1] > max)
            {
                res_array[i+2] = res_array[i+1];
                res_array[i+1] = max;
            } else if (res_array[i+1] < max)
            {
                res_array[i+2] = max;
            }


        } /*else if (res_array[i] < min)
        {
            res_array[i+1] = min;
            //res_array[i+2] = max;
        } else
        {
            res_array[i] = min;
            //res_array[i+1] = max;
        }*/
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", res_array[i]);
    }
    

    free(res_array);
}