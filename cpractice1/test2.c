//交换两个数字，不使用第三个变量

//本题使用的是两个数字亦或

#include <stdio.h>
int main (void) {
  int a , b;
  printf("please input two numbers\n");
  while(scanf("%d %d",&a,&b) == 2) {
    printf("The number you input is : a = %d , b = %d\n",a ,b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("now a = %d , b = %d\n ",a ,b);
    printf("Please input another two numbers(q to quit)\n");
  }

  return 0;
}
