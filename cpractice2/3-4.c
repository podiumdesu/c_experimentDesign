//编写一个程序，将用户输入的任意正整数逆转，例如，输入1234，输出4321;

#include <stdio.h>
int main (void) {
  int number;
  printf("Please input a number (q = quit):");
  while (scanf("%d",&number) != 0) {
    printf("Wooow!!!!!The reverse number is :");
    while (number > 10) {
      printf("%d",number % 10);
      number /= 10;
    }
    printf("%d\n",number % 10);
    printf("Please input a number (q = quit):");
  }
  return 0;
}
