//通过函数指针和菜单选择来调用字符串拷贝函数或者字符串链接函数


#include<stdio.h>
#include <string.h>
char* (*p)(char *,const char *);
int main(void)
{
    char a[80],b[80],c[160],*result=c;
	  int choice,i;
	  do{
		  printf("\t\t1 copy string.\n");
		  printf("\t\t2 connect string.\n");
		  printf("\t\t3 exit.\n");
		  printf("\t\tinput a number (1-3) please!\n");
		  scanf("%d",&choice);
	  //}while(choice<1 || choice>5);
    } while (choice < 1 || choice > 4);
	  switch(choice){
	  case 1:
		  //p=strcpy;
      p = &strcpy;
		  break;
	  case 2:
		  //p=strcat;
      p = &strcat;
		  break;
	  case 3:
		  goto down;
}
	  getchar();
	  printf("input the first string please!\n");
	  i=0;
	  fgets(a,80,stdin);
    a[strlen(a)-1]='\0';
printf("input the second string please!\n");
	  i=0;
	  fgets(b,80,stdin);
    b[strlen(b)-1]='\0';
	  result= (*p)(a,b);
	  printf("the result is %s\n",result);
down:
	  return 0;
}
