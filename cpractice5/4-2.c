//编写一个程序，输入一个整数，将它在内存中二进制表示的每一位转换成对应的数字字符中
//存放到一个字符数组中，然后输出该整数的二进制表示

/*#include <stdio.h>
void binary2 (int * p, int n);
int main (void) {
  int binary[100];
  int number;
  printf("Please input a number:");
  while (scanf("%d",&number) == 1) {
    printf("ddd\n");
    binary2(binary,number);
    printf("dddds\n");

    for (int i = 0; ; i++) {
      printf("ddddd\n");

      printf("%d",binary[i]);
    }
  }
  return 0;
}

void binary2(int * p, int n) {
  while (n / 2 >= 0) {
    *p++ = (n % 2 == 0) ? 0 : 1;
  }
}
*/

#include <stdio.h>
int main (void) {
  int binary[100];
  int number;
  int i;
  printf("Please input a number:");
  while(scanf("%d",&number) ==1){
    i = 0;
    while (number > 0) {
      binary[i] = (number % 2 == 0) ? 0 : 1;
      i++;
      number /= 2;
    }
    printf("该数的二进制表示为：");
    for (int j = i-1 ; j >= 0; j--) {
      printf("%d",binary[j]);
    }
    printf("\n");
    printf("\n");
    printf("Please input a number:");
  }
  return 0;
}
