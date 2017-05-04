/*
已知一个长整型变量占4个字节，其中每个字节又分成高4位和低4位。
试编写一个程序,从该长整型变量的高字节开始，
依次取出每个字节的高4位和低4位并以十六进制数字字符的形式进行显示。
*/

#include <stdio.h>


int main (void) {
  int new[4][2];
  char result[4][2];
  long int number;
  printf("请输入一个长整型十六进制数");
  scanf("%lx",&number);
  long int mask = 0;

  for (int i = 0; i < 4; i++) {
    mask |= (1 << i);
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      new[i][j] = number & mask;
      number >>= 4;
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      if (new[i][j] < 10) {
        result[i][j] = new[i][j] + '0';
      } else {
        result[i][j] = new[i][j]-10+'a';
      }
    }
  }
  for (int i = 3; i >= 0; i--) {
    printf("第%d个字节：  高     低\n",4-i);
    printf("       ");
    for (int j = 1; j >= 0; j--) {
      printf("      %c",result[i][j]);
    }
    printf("\n");
  }
  return 0;
}
