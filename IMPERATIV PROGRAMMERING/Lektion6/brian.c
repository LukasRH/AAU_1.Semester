#include <stdio.h>
#include <math.h>

void do_next_op(double *a, double b, char op, int *running);
void scan_data(double *b, char *op);

int main(void){
  	int running = 1;
    double a, b;
  	char op;
  
  while (running == 1) {
  	scan_data(&b, &op);
    do_next_op(&a, b, op, &running);
    printf("The result is now: %.00f \n", a);
  }
}	

void do_next_op(double *a, double b, char op, int *running){
  switch (op)
    {
    case '+':
    	*a = *a + b;
        break;
    case '-':
        *a = *a - b; 
    	break;
    case '*':
    	*a = *a * b; 
    	break; 
    case '/':
    	*a = *a / b;
    	break;
    case '^':
    	*a = pow(*a, b);
        break;
    case 'q': 
    	*running = 0;
    	break;
    default:
        break;
    }

}

void scan_data(double *b, char *op){
    printf("Enter operator and operand: ");
  	scanf(" %c %lf", &*op, &*b);
}