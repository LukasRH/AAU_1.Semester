#include <stdio.h> 

int quotient(int dividend, int divisor, int resQ);
int modulus(int dividend, int divisor);

int main(void){
  int dividend, divisor, resQ = 0;
  
  printf("Input dividend and divisor: ");
  scanf("%d %d", &dividend, &divisor);
  
  printf("Quotient: %d\n", quotient(dividend, divisor, resQ));
  printf("Modulus: %d\n", modulus(dividend, divisor));
  return 0;
}

int quotient(int dividend, int divisor, int resQ){
   if (dividend > 0)
   {
       ++resQ;
       return quotient(dividend - divisor, divisor, resQ);
   } else if (dividend == 0)
   {
       return resQ;
   } else
   {
       return resQ - 1;
   }
}

int modulus(int dividend, int divisor){
  int res = dividend;
  if (dividend - divisor >= 0)
  {
    res -= divisor;
    return modulus(res, divisor);
  } 
  else 
    return res;
}





