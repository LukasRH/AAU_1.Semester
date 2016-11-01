#include <stdio.h>
#include <stdlib.h>
#define MAX 6
#define SENTINEL 0

int enter_numbers(int tab[], int capacity);
void print_table(int tab[], int n);
void insert_number_in_table(int a_number, int tab[], int place, int capacity);

int main(void) {
  int n;
  int *tab = (int*)malloc(MAX * sizeof(int));

  if (tab == NULL){
    printf("Out of memory...");
    exit(EXIT_FAILURE);
  }

  n = enter_numbers(tab, MAX);
  print_table(tab, n);

  free(tab);

  return 0;
}

int enter_numbers(int tab[], int capacity){
  int a_number, done = 0, count = 0;

  while(!done && count < capacity){  
    /* Prompt for input number */
    printf("Enter a number: "); 
    scanf(" %d", &a_number);
  
    done = a_number == SENTINEL;

    if(!done){
      insert_number_in_table(a_number, tab, count, capacity);
      ++count;
    }
  }
  return count;
}

void insert_number_in_table(int a_number, int tab[], int place, int capacity){
  int i = 0, j = 0;
  /* Progress i as long as small numbers */
  while(tab[i] < a_number) ++i;

  /*for(j = place-1; j > i; --j){
    tab[j+1] = tab[j];
  }*/
  tab[i+1] = tab[i];
 
  tab[i] = a_number;
}

void print_table(int tab[], int number_of_elements_in_table){
  int i;
  for(i = 0; i < number_of_elements_in_table; ++i){
    printf("%3d", tab[i]);
  }
}