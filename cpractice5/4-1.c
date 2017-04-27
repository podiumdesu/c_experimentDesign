//编写一个程序，从键盘读取数据，对一个3x4的矩阵进行赋值，求其转置矩阵
#include <stdio.h>
#define ROW 3
#define COLUMN 4
int main (void) {
  int array[ROW][COLUMN];

  printf("please input the numbers");
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COLUMN; j++) {
      scanf("%d",&array[i][j]);
    }
  }
  printf("\n原矩阵为：\n");
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COLUMN; j++) {
      printf("%d ",array[i][j]);
    }
    printf("\n");
  }
  printf("转置矩阵为：\n");
  for (int j = 0; j < COLUMN; j++) {
    for (int i = 0; i < ROW; i++) {
      printf("%d ",array[i][j]);
    }
    printf("\n");
  }
}
