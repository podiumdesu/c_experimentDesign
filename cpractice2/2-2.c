//源程序修改替换题

//修改第一题，要求输入改为整数s，输出改为满足“n!>=s的最小整数n”
//例如输入40310，输出8


#include <stdio.h>
int multiply_func(int num) {
  int s = 1;
  for (int i = 1; i <= num ; i++) {
    s *= i;
  }
  return s;
}

int main (void) {

  int input_num;
  printf("Please input a number(q = quit): ");
  while (scanf("%d",&input_num) != 0) {
    for (int i = 0 ; i <= 100 ; i++) {
      if (multiply_func(i) >= input_num) {
        printf("The biggest number is %d\n",i);
        printf("Please input a number(q = quit): ");
        break;
      }
    }
  }
  return 0;
}
