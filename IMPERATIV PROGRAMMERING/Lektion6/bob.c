#include <stdio.h>
#include <math.h>

void converter( double dollars, double *kroner, double *euros, double *rubler, double *yen);

int main(void){
  double dollars, euros, kroner, rubler, yen;
  
  printf("Enter the wished amount of dollars you wish to convert: ");
  scanf("%lf", &dollars); 
  
  converter(dollars, &kroner, &euros, &rubler, &yen);
  
  printf("That equals %.2f euro(s), %.2f krone(r), %.2f ruble(r) and %.2f yen(s)\n", euros, kroner, rubler, yen);
  
	for (dollars = 0; dollars <= 100; dollars++)
  {
      converter(dollars, &kroner, &euros, &rubler, &yen);
    	printf("| USD %.2f | DDK %.2f | EUR %.2f | RUB %.2f | YEN %.2f |", dollars, kroner, euros, rubler, yen);
  }
  
}

void converter( double dollars, double *kroner, double *euros, double *rubler, double *yen){
    *kroner = dollars * 6.66;
    *euros = dollars * 0.89;
    *rubler = dollars * 66.43;
    *yen = dollars * 119.9;

  }