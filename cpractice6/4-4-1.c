/*
(4) 设某个班有N个学生，每个学生修了M门课程（用#define定义N、M）。
输入M门课程的名称，然后依次输入N个学生中每个学生所修M门课程的成绩并且都存放到相应的数组中。
试编写下列函数：
(a) 计算每个学生各门课程平均成绩；
*/

#include <stdio.h>
#include <stdlib.h>
#define STU_NUM 4
#define COU_NUM 3

int main (void) {
  char course[COU_NUM][20];
  //int score[STU_NUM][COU_NUM];    //i个学生，每个学生j个成绩
  //int **ptr = score;
  char *ptr_course[20];//定义一个指针数组
  //数组首地址代表的是一个指针
  int (*ptr_score)[COU_NUM];   //定义一个指针数组 二维的
  printf("4 students and 3 courses\n");
  printf("Please input the courses:");
  for (int i = 0; i < COU_NUM; i++) {
    *(ptr_course+i) = malloc(sizeof(char)*20);
    scanf("%s",*(ptr_course+i));
    printf("Now please input students' score:");
    for (int j = 0; j < STU_NUM; i++) {
      *(*(ptr_score+i)+j) = malloc(sizeof(int)*STU_NUM);
      scanf("%d",*(ptr_score+i)+j);
    }
  }
  return 0;
}
