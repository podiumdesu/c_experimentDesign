//使用牛顿迭代法求方程的一个近似根
#include <stdio.h>

double function (double x) {
  double result;
  result = 3*(x*x*x) - 4*(x*x) - 5*x + 13;
  return result;
}
double functionddd (double x) {
  double result;
  result = 9*(x*x) - 8*x -5;
  return result;
}

double abss (double x) {
  if(x >= 0){
    return x;
  } else {
    return -x;
  }
}
int main (void) {
  double num_1,num_2;
  printf("Please input the \'a\':");
  scanf("%lf",&num_1);
  num_2 = num_1 - function(num_1) / functionddd(num_1);
  while (abss(num_2 - num_1) > 10e-6) {
    num_1 = num_2;
    num_2 = num_2 - function(num_2) / functionddd(num_2);
  }
  printf("%f",num_2);
  return 0;
}
