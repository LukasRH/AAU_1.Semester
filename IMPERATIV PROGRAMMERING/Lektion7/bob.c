#include <stdio.h>

enum grade_simple {not_passed, passed};

enum grade_13 {nul_nul = 0, nul_tre = 3, fem = 5, seks,
               syv, otte, ni, ti, elleve, tretten = 13};

enum grade_simple convert_grade_13_to_simple_grade (enum grade_13 g){
  enum grade_simple result; 

  if (g <= fem)
    result = not_passed;
  else 
    result = passed;
  
  return result;
}

void prnt_grade_simple(enum grade_simple g){
  switch (g) {
    case not_passed: printf("Not passed");
      break;
    case passed: printf("Passed");
      break;
  }
}  
    
int main(void){
  
  int grade_number; 
 
  printf("Enter '13 skala' grade: ");
  scanf(" %d", &grade_number);

  prnt_grade_simple(
         convert_grade_13_to_simple_grade(grade_number));
  printf("\n");

  return 0;
}    