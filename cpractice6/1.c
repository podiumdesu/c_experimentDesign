//源程序改错
#include<stdio.h>
int main(void)
{
     float *p;   //此时只是定义了一个指针变量，但是不知道他指向什么地方的。
     //是一个悬挂指针
     //scanf("%f",p);
     float a;
     scanf("%f",&a);
     p = &a;
     printf("%f\n",*p);
     return 0;
}
