//编写一个程序，将输入的一行字符复制到输出
//复制过程中将一个以上的空格字符用一个空格代替
#include <stdio.h>
int main (void) {
  char c;
  printf("You can input something~(ctrl+c to quit)\n");
  while(c = getchar()) {
    if (c != ' ') {
      putchar(c);
    } else {
      putchar(c);
      c = getchar();
      while (c == ' ') {
        c = getchar();
      }
      putchar(c);
    }
  }
  return 0;
}
