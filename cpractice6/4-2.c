/*
(2) 利用大小为n的指针数组指向用gets函数输入的n行，每行不超过80个字符。
试编写一个函数，它将每一行中连续的多个空格字符压缩为一个空格字符。
在调用函数中输出压缩空格后的各行，空行不予输出。
*/

#include <stdio.h>
#include <stdlib.h>
#define ROW 2
int main (void) {
  char * ptr[ROW];   //指针数组
  // 这是一个二维的数组， *ptr保存的是第一行的地址，**ptr是第一行第一个字，不是地址了
  // 可以通过*ptr获得第一行的首字母的地址，然后使用%s进行打印
  //    通过**ptr可以获得该行的第一个字母，使用%c进行打印
  // *ptr++ 获得下一行首字母的地址
  // *(*(ptr)+i) 获得 %c
  char array[ROW][80];

  printf("You can input something,");
  printf("and you can input 4 rows: \n");
  for (int i = 0; i < ROW; i++) {
    *(ptr+i) = malloc(sizeof(char)*81);
    gets(*(ptr+i));
  }
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < 80; j++) {
      if (*(*(ptr+i)+j) == ' ') {
        
      }
    }
  }
  //printf("*ptr = %s %p\n",*(ptr), *(ptr));
  //printf("**ptr = %c %c\n",**ptr, *(*(ptr)+1));
  for (int i = 0; i < ROW; i++) {
    puts(*(ptr+i));
  }
  return 0;
}
