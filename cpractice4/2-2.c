#include <stdio.h>
#define MAX(a,b,c) (a>b)?((a>c)?a:c):((b>c)?b:c)

double sum(float x, float y);
int main(void)
  {
   int a, b, c;
   int t;
   float d, e;
   printf("Enter three integers:");
   scanf("%d%d%d",&a,&b,&c);
   printf("\nthe maximum of them is %d\n",MAX(a,b,c));
   printf("Enter two floating point numbers:");
   scanf("%f%f",&d,&e);
   printf("\nthe sum of them is %f\n",sum(d,e));
   return 0;
 }

double sum(float x, float y)
 {
   return x+y;
 }
