//将输入的十进制，八进制，十六进制转换成二进制

/*#include<stdio.h>
#include<stdlib.h>

int main (void) {
  int n;
  int number;
  char string[32];

  printf("请输入你的进制值（８or10or16\n");
  scanf("%d",&n);

  if(n == 10) {
    printf("请输入一个十进制整数\n");
    scanf("%d",&number);
    itoa(number,string,2);
    printf("%s\n",string);
  }
  else if (n == 8) {
    printf("请输入一个八进制整数\n");
    scanf("%o",&number);
    itoa(number,string,2);
    printf("%s\n",string);
  }
  else if (n == 16) {
    printf("请输入一个十六进制整数\n");
    scanf("%x",&number);
    itoa(number,string,2);
    printf("%s\n",string);
  }
  return 0;
}
*/
#include <stdio.h>
int main (void) {
  int x;
  int i;
  printf("Please input a number\n");
  scanf("%d",&x);
  char display[15];
  for(i = 0; i < 16 ;i++){
    display[i] = (x % 2 == 0) ? '0' : '1';
    x >>= 1;
  }
  for (i = 15; i >= 8; i--) {
    putchar(display[i]);
  }
  printf(" ");
  for (i = 7; i >= 0; i--) {
    putchar(display[i]);
  }
  return 0;
}
