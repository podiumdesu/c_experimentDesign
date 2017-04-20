//计算平方差和交换两数

#include<stdio.h>

#define SUM(a,b) (a+b)

#define DIF(a,b) (a-b)

#define SWAP(a,b)  a=a^b,b=a^b,a=a^b

int main(void)

{
      int a;
      int b, t;

      printf("Input two integers a,b:");
      scanf("%d%d",&a,&b);

      printf("SUM=%d\nThe difference between square of a and square of b is:%d",SUM(a,b), SUM(a,b)*DIF(a,b));

      SWAP(a,b);

      printf("\nNow a=%d,b=%d\n",a,b);

      return 0;

}
