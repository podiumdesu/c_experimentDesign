/*
(4) 设某个班有N个学生，每个学生修了M门课程（用#define定义N、M）。
输入M门课程的名称，然后依次输入N个学生中每个学生所修M门课程的成绩并且都存放到相应的数组中。
试编写下列函数：
(a) 计算每个学生各门课程平均成绩；
(b) 计算全班每门课程的平均成绩；
(c) 分别统计低于全班各门课程平均成绩的人数；
(d) 分别统计全班各门课程不及格的人数和90分以上（含90分）的人数。
在调用函数中输出上面各函数的计算结果。（要求都用指针操作，不得使用下标操作。）

*/

#include <stdio.h>
#include <stdlib.h>

#define STU_NUMS 3
#define COUR_NUMS 4

typedef int(* array)[2];

float * everyCourseAver(int (*ptr)[3], int, int);
float * everyOneAver(int (*ptr)[3],int, int);
int * lowToCourseAver(const float *, int (*ptr)[3], int, int);
array analyzeHighLowScore(int (*ptr)[3], int STU_NUM, int COUR_NUM);

int main (void) {
  char course[COUR_NUMS][20];
  int score[COUR_NUMS][STU_NUMS];   //声明变量时记得看清楚宏定义
  /*申明需要的四个指针，指向四个函数的返回值*/
  float * evoa;   //everyCourseAver
  float * evca;   //everyOneAver
  int * ltca;     //lowToCourseAver
  int (*ahls)[2];  //analyzeHighLowScore
  //请为我的命名方式鼓掌！
  printf("请输入四门课程名：");
  for (int i = 0; i < COUR_NUMS; i++) {
    scanf("%s",course[i]);
  }
  for (int i = 0; i < COUR_NUMS; i++) {   //将每门课程每个学生的成绩读入数组
    printf("请输入三名同学的%s成绩",*(course+i));
    for (int j = 0; j < STU_NUMS; j++) {
      scanf("%d",(*(score+i)+j));   //读入时需要的是地址
    }
  }

  /*(1)计算每个学生各门课程的平均成绩*/
  evoa = everyOneAver(score,STU_NUMS,COUR_NUMS);
  printf("(1)每个学生各门课程平均成绩:\n");
  for (int i = 0; i < STU_NUMS; i++) {
    printf("第%d个学生：%.2f\n",(i+1),*evoa);
    evoa++;
  }
  /************************************/

  /*(2)计算全班每门课程的平均成绩*/
  evca = everyCourseAver(score,STU_NUMS,COUR_NUMS);   //得到每门课程平均成绩
  const float * target_evca = evca;    //为第三问创造条件
  printf("(2)全班每门课程的平均成绩:\n");
  for (int i = 0; i < COUR_NUMS; i++) {
    printf("课程%s：%.2f\n",*(course+i),*evca);  //输出成绩
    evca++;
  }
  /************************************/

  /*(3)分别统计低于全班各门课程平均成绩的人数*/
  ltca = lowToCourseAver(target_evca,score,STU_NUMS,COUR_NUMS);
  printf("(3)统计低于全班各门课程平均成绩的人数：\n");
  for (int i = 0; i < COUR_NUMS; i++) {
    printf("课程%s : %d\n",*(course+i),*ltca);
    ltca++;
  }
  /************************************/

  /*(4)分别统计全班各门课程不及格的人数和90分以上（含90分）的人数*/
  ahls = analyzeHighLowScore(score, STU_NUMS, COUR_NUMS);
  printf("(4)统计全班各门课程不及格的人数和大于等于90分的人数：\n");
  for (int i = 0; i < COUR_NUMS; i++) {
    printf("课程%s：不及格人数：%d，成绩优秀人数：%d\n",*(course+i), (*(*(ahls+i)+1)), (*(*(ahls+i))));
    //ahls++;    找到bug啦！！！！！！！！
  }
  /************************************/
  return 0;
}

       /*******下面是函数定义*******/

/*(1)计算每个学生各门课程的平均成绩*/
float * everyOneAver(int (*ptr)[3],int STU_NUM, int COUR_NUM) {
  float * new_ptr = malloc(sizeof(float)*STU_NUM);
  float result[3] = {0,0,0};
  float * ptrd = new_ptr;
  for (int i = 0; i < STU_NUM; i++) {
    for (int j = 0; j < COUR_NUM; j++) {
      (*(result+i)) += *(*(ptr + j) + i);    //注意是+= 不是= !!!
    }
    //printf("%f",result[i]);
    *ptrd = ((*(result+i)) / COUR_NUM);
    ptrd++;
  }
  return new_ptr;
}
/************************************/

/*(2)计算全班每门课程的平均成绩*/
float * everyCourseAver(int (*ptr)[3], int STU_NUM, int COUR_NUM) {
  float * new_ptr = malloc(sizeof(float) * COUR_NUM);
  float * ptrd = new_ptr;
  float allsum = 0;
  for (int i = 0; i < COUR_NUM; i++) {
    for (int j = 0; j < STU_NUM; j++) {
      allsum += *(*(ptr+i)+j);
      //printf(" %f ",allsum);
    }
    *ptrd = (allsum / STU_NUM);
    ptrd++;
    allsum = 0;
  }
  return new_ptr;
}
/************************************/

/*(3)分别统计低于全班各门课程平均成绩的人数*/
int * lowToCourseAver(const float * standard, int (*ptr)[3], int STU_NUM, int COUR_NUM) {
  int * ltca_num = malloc(sizeof(int)*COUR_NUM);
  int * ptr_ltca_num = ltca_num;
  int count;
  for (int i = 0; i < COUR_NUM; i++) {
    count = 0;
    for (int j = 0; j < STU_NUM; j++) {
      if ((*(*(ptr+i)+j)) < *standard) {
        count++;
      }
    }
    *ltca_num = count;
    ltca_num++;
    standard++;
  }
  return ptr_ltca_num;
}
/************************************/

/*(4)分别统计全班各门课程不及格的人数和90分以上（含90分）的人数*/
array analyzeHighLowScore(int (*ptr)[3], int STU_NUM, int COUR_NUM) {
  int (*anaResult)[2] = malloc(sizeof(int) * COUR_NUMS * 2);
  int count_ninety;
  int count_lowSixty;
  for (int i = 0; i < COUR_NUM; i++) {
    count_lowSixty = 0;
    count_ninety = 0;
    for (int j = 0; j < STU_NUM; j++) {
      if ((*(*(ptr+i)+j)) >= 90) {
        count_ninety++;
      } else if ((*(*(ptr+i)+j)) < 60){
        count_lowSixty++;
      }
    }
    *(*(anaResult+i)) = count_ninety;
    *(*(anaResult+i)+1) = count_lowSixty;
    //printf("   %d   %d ",*(*(anaResult+i)),*(*(anaResult+i)+1)); 此处计算没有问题
  }
  return anaResult;
}
/************************************/
