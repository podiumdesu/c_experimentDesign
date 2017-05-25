

#include<stdio.h>
#include <stdlib.h>
struct s_list{
int data;                         /* 数据域 */
struct s_list *next;              /* 指针域 */
} ;
void create_list (struct s_list **headp,int *p);

int main(void)
{
	struct s_list *head=NULL,*p;
	int s[]={1,2,3,4,5,6,7,8,0};     /* 0为结束标记 */
	create_list(&head,s);             /* 创建新链表 */     /*传入的必须是链表，而不是仅仅复制，不然不修改值*/
	p=head;                       /* 遍历指针p指向链头 */
	while(p){
		printf("%d\t",p->data);      /* 输出数据域的值 */
		p=p->next;               /* 遍历指针p指向下一结点 */
	}
	printf("\n");
  return 0;
}


void create_list(struct s_list **headp, int *p) {
  struct s_list * loc_head = NULL, *tail,*nextnode;
  if(p[0]==0) /* 相当于*p==0 */
    ;
  else {
    loc_head = (struct s_list *)malloc(sizeof(struct s_list));  //给首节点分配内存
    loc_head->data = *p++;   //将数据存入首节点
    tail = loc_head;  //定位最开始的那个节点在哪里
    while(*p) {
      nextnode = (struct s_list *)malloc(sizeof(struct s_list));  //分配下一块内存
      nextnode->next = loc_head;   //下一块内存指向刚刚的节点
      loc_head = nextnode;   //
      loc_head->data = *p++;
    }
    tail->next=NULL;            /* 对指针域赋NULL值 */
  }
  *headp=loc_head;          /* 使头指针headp指向新创建的链表 */
}
