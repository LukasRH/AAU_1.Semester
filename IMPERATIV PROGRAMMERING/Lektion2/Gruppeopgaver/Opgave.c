#include <stdio.h>

int main(void) {

  double a, b, c, d;

  printf("noget: ");
  scanf("%lf %lf %lf %lf",&a,&b,&c,&d);

  printf("tid: %f",(a*b - c*d)/2);
  return 0;
}