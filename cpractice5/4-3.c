//输入n个学生姓名和c语言成绩，将成绩按照从高到低排序，姓名做相应调整，输出排序后的结果
//然后输入一个c语言课程成绩，用二分查找进行搜索，如果查找到有该成绩，就输出该成绩同学的姓名和c语言课程成绩，否则输出"no found"

#include <stdio.h>
#include <string.h>
void swap (int * p1 , int * p2);

int main (void) {
 // printf("zlc zz\n");
  int SIZE;
  int score[100];
  int target;

//  while(scanf("%d",&SIZE) != EOF) {
    printf("How many students?: ");
  scanf("%d",&SIZE);
    char name[SIZE][30];   //定义名字的数组
    printf("请输入学生姓名和成绩:");
    for (int k = 0; k < SIZE; k++){
      scanf("%s %d",&name[k],&score[k]);  //为名字和成绩赋值
    }

    for (int i = 0; i < SIZE ; i++) {  //使用冒泡排序进行排序，从高到低。
      for (int j = 1; j < SIZE - i; j++) {
        if (score[j-1] < score[j]){
          swap(&score[j-1],&score[j]);
          char paste[30];
          strcpy(paste,name[j-1]);   //交换成绩的同时交换姓名
          strcpy(name[j-1],name[j]);
          strcpy(name[j],paste);
        }
      }
    }
    printf("\n");
    printf("这是从高到低的学生成绩\n");
    for (int m = 0 ; m < SIZE; m++) {
      printf("%s %d\n",name[m],score[m]);
    }
    printf("\n");
//  }
int max, min ,mid;
  printf("Please input the score you want to find");
  while (scanf("%d",&target) == 1){
    min = SIZE-1;
    max = 0;
    mid = (min + max) / 2;
    while (target != score[mid]) {
      if (target > score[mid]) {
        min = mid - 1;
        if (min < max) {
          printf("no found\n");
          break;
        }
        mid = (min + max) / 2;
      } else {
        max = mid + 1;
        if (max > min) {
          printf("no found\n");
          break;
        }
        mid = (min + max) / 2;
      }
    }
    if (target == score[mid]) {
      printf("This is what you want: %s %d\n",name[mid],score[mid]);
    }
  }



  for (int k = 0; k < SIZE; k++) { //输出成绩数组
    printf("%d ",score[k]);
  }
return 0;
}

void swap (int * p1, int * p2) {
  int temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}
