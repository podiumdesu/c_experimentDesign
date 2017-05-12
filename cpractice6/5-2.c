/*(2) 编写一个使用复杂声明“char *(*p[2])(const char *,const char *);”的程序。
提示：p中元素可为strstr等函数名。
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *before(const char *s,const char *t)
{
	char *temp=(char *)malloc(strlen(s)+strlen(t)+1);  /*定义一个存放最终结果的
字符数组*/
	strcpy(temp,s);                            /*调用strcpy和strcat函数*/
	strcat(temp,t);
	return temp;
}
char *behind(const char *s,const char *t)
{
	char *temp=(char *)malloc(strlen(s)+strlen(t)+1);
	strcpy(temp,t);
	strcat(temp,s);
	return temp;
}
int main()
{
	int n;
	char * (*p[2])(const char* ,const char* );  //函数指针数组
  
	char * t;
	printf("请输入第1个字符串：\n");
	char * s = malloc(sizeof(char)*20);               /*动态创建一个含有20个元素的数组*/
	gets(s);
	printf("请输入第2个字符串：\n");
	t=(char*)malloc(20);
	gets(t);
	printf("请输入0或1（0代表选择字符串2复制到1后面，1代表选择字符串1复制到2后面)：\n");
	scanf("%d",&n);
	p[0]=before;
	p[1]=behind;
	if(n==0||n==1)
	{
	    printf("结果为：%s",p[n](s,t));
	}
	else
	printf("输入错误！");
	return 0;
}
