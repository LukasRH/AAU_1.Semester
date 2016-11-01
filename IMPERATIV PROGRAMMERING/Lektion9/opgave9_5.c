#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(double*)a - *(double*)b );
}

int main(void){
  double* n = (double*)malloc(100*sizeof(double));
  int i, times = 100;
  
  if (n == NULL){
    printf("Cannot allocate memory. Bye \n");
    exit(EXIT_FAILURE);
  }
  
  srand(time(NULL));
  
  /* random values assign to array */
  for (i = 0; i < times; ++i) {
  n[i] = rand() % 100; // PRINTER MELLEM 1-99
  }
  
  /* print løkke */
  
  
  printf("Before sorting the list is: \n");
  for (i = 0; i < times; ++i) {
    printf("%3.2f ", n[i]);
  }
  
  qsort(n, times, sizeof(double), cmpfunc);
  
  printf("\nAfter sorting the list is: \n");
  for (i = 0; i < times; ++i) {
    printf("%3.2f ", n[i]);
  }
  
  free(n);
  return(0);
}
