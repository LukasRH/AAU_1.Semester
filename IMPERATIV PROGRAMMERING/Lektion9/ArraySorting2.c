 /*
    Programmer: Lukas Rønsholt          Date: 01-11-16
    Teacher: Kurt Nørmark               Class: Imperative Programming

    Description:
    Function that will merge the contents of two sorted (ascending order) arrays of type double values, storing the result in an array output
*/

#include <stdio.h>
#include <stdlib.h>


void merge_sorted(double first_array[], double second_array[], double res_array[], double size_first, double size_second);
void print(double res_array[], double count);

int main(void)
{
    /* initialize varaibles, and get memory for output array */
    double first_array[] = {-10.5,-1.8,3.5,6.3,7.2}, second_array[] = {-1.8,3.1,6.3};
    double max_size = sizeof(first_array) + sizeof(second_array);
    double *res_array = (double *)malloc(max_size);

    int size_first = sizeof(first_array)/sizeof(double);
    int size_second = sizeof(second_array)/sizeof(double);

    merge_sorted(first_array, second_array, res_array, size_first, size_second);

    free(res_array);
}

void merge_sorted(double first_array[], double second_array[], double res_array[], double size_first, double size_second)
{
    int i=0, j=0, k=0;
    /* Sorting when both arrays are not exhausted */
    while (i < size_first && j < size_second)
    {
        if (first_array[i] < second_array[j])
        {
            res_array[k++] = first_array[i++];
        }
        else if (first_array[i] == second_array[j])
        {
            res_array[k++] = first_array[i++];
            ++j;
        }
        else
        {
            res_array[k++] = second_array[j++];
        }
    }
    /* 1 array is exhausted */
    while (i < size_first)
        res_array[k++] = first_array[i++];
    while (j < size_second)
        res_array[k++] = second_array[j++];
    
    print(res_array, k);
}

void print(double res_array[], double count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%3.2f ", res_array[i]);
    }
    printf("\n");
}