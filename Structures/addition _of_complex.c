#include <stdio.h>
typedef struct complex{
   float real;
   float imag;
} complex;
complex addition(complex num1, complex num2);
int main(){
   complex num1, num2, value;
   printf("entering real and imag parts of first complex no:\n ");
   scanf("%f %f", &num1.real, &num1.imag);
   printf("entering real and imag parts of second complex no:\n ");
   scanf("%f %f", &num2.real, &num2.imag);
   value= addition(num1, num2);
   printf("result = %.1f + %.1fi", value.real, value.imag);
   return 0;
}
complex addition(complex num1, complex num2){
   complex temp;
   temp.real = num1.real + num2.real;
   temp.imag = num1.imag + num2.imag;
   return (temp);
}
