//宏定义控制电文输出
#include <stdio.h>
#include <ctype.h>
#define CHANGE choice

int main (void) {
  int rows;
  int choice;

  char c;
  int input_num;

  printf("Please input the rows:");
  scanf("%d",&rows);


  while (rows --) {
    printf("Please input the way(0 or 1):");
    scanf("%d",&choice);
//    printf("%c%d\n",c,input_num);
    c = getchar();
    c = getchar();
    if (CHANGE) { //改变大小写
      while (c != '\n') {
        if (c <= 'z' && c >= 'a') {
          c = toupper(c);
        } else if (c <= 'Z' && c >= 'A') {
          c = tolower(c);
        } else {
        }
        putchar(c);
        c = getchar();
      }
      printf("\n");
    } else {  //原文输出
      while (c != '\n') {
        putchar(c);
        c = getchar();
      }
      printf("\n");
    }
  }
  return 0;
}
