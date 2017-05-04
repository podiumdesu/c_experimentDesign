//源程序改错
#include<stdio.h>
int main(void)
{
     float *p;
     //scanf("%f",p);
     float a;
     scanf("%f",&a);
     p = &a;
     printf("%f\n",*p);
     return 0;
}
