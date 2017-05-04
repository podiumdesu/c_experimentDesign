/*
 * 请按下面的要求对所给源程序进行操作，并回答问题和排除错误。
(1) 单步执行源程序。进入strcpy时,watch窗口中s为何值？返回main时, watch窗口中s为何值？
(2) 排除源程序中的错误，使程序输出结果为： there is a boat on the lake.
 */

//1) ""

#include<stdio.h>
char *strcpy(char *,char *);
int main(void)
{
    char a[20],b[60]="there is a boat on the lake.";
    printf("%s\n",strcpy(a,b));
    return 0;

}
char *strcpy(char *s,char *t)
{
    char *new = s;
    while(*s++=*t++)
    ;
    return new;
}
