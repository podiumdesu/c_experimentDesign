/*(1) 对上述程序设计题中第（2）题的程序，增加按照平均成绩进行升序排序的函数，
试写出用交换结点数据域的方法升序排序的函数，排序可用选择法或冒泡法。
(2) 对选做题第（1）题，进一步写出用交换结点指针域的方法升序排序的函数。
*/

//将代码进行重构
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define c_num 4
typedef struct stu_info {   //定义学生信息结构
  char id_no[15];
  char name[20];
  float score[4];
  float avg;
  float sum;
  struct stu_info * next;
}STU_INFO,*pINFO;

/*************创建链表************/
void create_list(pINFO *headp,int stu_num) {
  pINFO current,head;
  head = (pINFO)malloc(sizeof(STU_INFO));
  head->next = NULL;
  current = head;
  while (stu_num--){
    current->next = (pINFO)malloc(sizeof(STU_INFO));
    current = current->next;
    //获取数据
    scanf("%s",current->id_no);
    scanf("%s",current->name);
    for (int i = 0; i < c_num; i++) {
      scanf("%f",&current->score[i]);
    }
    current->next = NULL;
  }
  *headp = head;     //修改头指针指向
}

/***********输出成绩*****************/
void show_list(pINFO head) {
  pINFO current;
  current = head->next;

  printf("%-15s%-20s%-10s%-10s%-10s%-10s\n","Id","Name","English","Maths","Physics","C");  //按格式输出
  while(current) {
    printf("%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n",current->id_no,current->name,current->score[0],current->score[1],current->score[2],current->score[3]);
    current = current->next;
  }
}

/*********修改成绩******************/
void change_score(pINFO *headp) {
  printf("\n");
  int change_num;
  printf("How many changes do you want to make? \n");
  scanf("%d",&change_num);
  char c_name[change_num][10];
  char new_id[change_num][15];
  float new_score[change_num];
  int c_id[change_num];

  int p = change_num;
  int c = 0;
  printf("Plese input the id and new scores: \n");
  while (p--) {   //获取修改信息
    scanf("%s",new_id[c]);
    scanf("%s",c_name[c]);
    scanf("%f",&new_score[c]);
    c++;
  }
  for (int i = 0; i < c; i++) {    //获取修改课程的课程序号
    if(c_name[i][0] == 'E' || c_name[i][0] == 'e') {
      c_id[i] = 0;
    } else if(c_name[i][0] == 'M' || c_name[i][0] == 'm') {
      c_id[i] = 1;
    } else if(c_name[i][0] == 'P' || c_name[i][0] == 'p') {
      c_id[i] = 2;
    } else {
      c_id[i] = 3;
    }
  }
  pINFO current;
  current = (*headp)->next;
  while (current) {
    for (int i = 0; i < change_num; i++) {
      if (strcmp(new_id[i],current->id_no) == 0) {     //判断是否是寻找的那个需要修改的id
        current->score[c_id[i]] = new_score[i];
      }
    }
    current = current->next;
  }
}
/*************显示平均分***********/
void show_avg(pINFO *head, int s_num) {
  float avg[s_num];
  float sum[s_num];
  pINFO current;
  current = (*head)->next;
  while(current) {
    current->sum = 0;
    for (int i = 0; i < c_num; i++) {
      current->sum += current->score[i];
    }
    current->avg = current->sum / c_num;    //计算平均值
    current = current->next;
  }
  current = (*head)->next;
  printf("Avg&Sum:\n");   //输出成绩
  printf("%-15s%-20s%-10s%-10s%-10s%-10s%-10s%-10s\n","Id","Name","English","Maths","Physics","C","Avg","Sum");
  while (current) {
    printf("%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n",current->id_no,current->name,current->score[0],current->score[1],current->score[2],current->score[3],current->avg,current->sum);
    current = current->next;
  }
}


int main (void) {
  int stu_num;
  pINFO head, current;   //定义头指针和中间指针
  printf("How many students?  \n");     //获取学生个数
  scanf("%d",&stu_num);
  printf("Please input the information: \n");
  create_list(&head,stu_num    //创建链表
  printf("\nHere are the info of the students\n");
  show_list(head);    //显示链表，不改动链表数据
  change_score(&head);     //修改表中信息
  printf("\nChange:\n");
  show_list(head);    //显示修改后的链表
  printf("\n");
  show_avg(&head,stu_num);    //给结构体中的avg和sum赋值，并显示平均分
  return 0;
}
