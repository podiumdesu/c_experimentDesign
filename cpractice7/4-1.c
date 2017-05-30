//用单向链表建立一张班级成绩单，包括学号、姓名、英语、高等数学、物理、c语言成绩
/*功能：
1.输入每个学生的各项信息
2.输出每个学生的各项信息
3.修改指定学生的指定数据项的内容
4.统计每个同学的平均成绩（保留2位小数）
5.输出各位同学的学号、姓名、四门课程的总成绩和平均成绩。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu_info {
  char id_no[10];
  char name[20];
  int score[4];
  struct stu_info *next;
}STU_INFO,*pINFO;     //定义结构和结构指针

int main (void) {
  int stu_num;
  printf("How many students?  ");
  scanf("%d",&stu_num);    //获取学生人数
  int s_num = stu_num;
  printf("Please input the infomation of every student\n");
  pINFO head, current;     //定义头指针和中间指针
  head = (pINFO)malloc(sizeof(STU_INFO));    //为头指针分配空间
  head->next = NULL;    //将头指针的指针域设置为 空
  current = head;  //将中间指针指向头指针
  while (s_num--) {     //获取输入的学生信息
    current->next = (pINFO)malloc(sizeof(STU_INFO));    //为下一个链表项申请内存
    current = current->next;   //将中间指针指向下一个链表项
    scanf("%s",current->id_no);    //将数据存入链表项的内容域
    scanf("%s",current->name);
    for (int i = 0; i < 4; i++) {
      scanf("%d",&current->score[i]);
    }
    current->next = NULL;     //中间指针的指针域设置为 空
  }

  /**********输出每个学生的各项成绩**********/
  current = head->next;    //重置中间指针的指向
  printf("Here is the information of every student:\n");
  printf("%-20s%-10s%-10s%-10s%-10s%-10s\n","id","name","english","maths","physics","C");
  while(current) {   //指针域存在
    printf("%-20s%-10s%-10d%-10d%-10d%-10d\n",current->id_no,current->name,current->score[0],current->score[1],current->score[2],current->score[3]);
    current = current->next;
  }
  /**********************************/
  /*********修改指定学生的指定数据项的成绩*********/

  printf("which info do you want to change? Please input the name\n");
  char change_name[10];
  scanf("%s",change_name);    //获取要修改的id
  printf("Which score do you want to change? Please input the course and the new score\n");
  char change_course[10];
  int change_score;
  scanf("%s",change_course);  //获取需要修改的课程名字
  scanf("%d",&change_score);  //获取需要修改的成绩

  int id;
  if (change_course[0] == 'e') {
    id = 0;
  } else if (change_course[0] == 'm') {
    id = 1;
  } else if (change_course[0] == 'p') {
    id = 2;
  } else {
    id = 3;
  }
  current = head->next;
  while(current) {
    if (strcmp(current->name,change_name) == 0) {
      current->score[id] = change_score;
    } else {
    }
    current = current->next;
  }

  current = head->next;
  printf("Here is the information of every student:\n");
  printf("%-20s%-10s%-10s%-10s%-10s%-10s\n","id","name","english","maths","physics","C");
  while(current) {
    printf("%-20s%-10s%-10d%-10d%-10d%-10d\n",current->id_no,current->name,current->score[0],current->score[1],current->score[2],current->score[3]);
    current = current->next;
  }
  /**********************************/
  /**********统计每个学生的平均成绩（两位小数）*********/
  printf("*************************\n");
  printf("Now here is every one\'s average score\n");
  printf("%-20s%-10s%-10s\n","id","name","average");
  current = head->next;
  double scores[stu_num];
  double scores_all[stu_num];
  int count = 0;
  while(current) {
      scores_all[count] = 0;
      for (int j = 0; j < 4; j++) {
        scores_all[count] += current->score[j];
      }
      scores[count] = scores_all[count] / 4;
      printf("%-20s%-10s%-10.2lf\n",current->id_no,current->name,scores[count++]);
    current = current->next;
  }
  /**********************************/
  current = head->next;
  printf("*************************\n");
  printf("Now here is the id, name, allscore and average\n");
  printf("%-20s%-10s%-10s%-10s\n","id","name","score","average");
  count = 0;
  while(current) {
    printf("%-20s%-10s%-10.2lf%-10.2lf\n",current->id_no,current->name,scores_all[count],scores[count]);
    count++;
    current = current->next;
  }


  return 0;
}
