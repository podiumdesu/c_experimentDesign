//计算圆的面积，以及圆的整数部分

#include<stdio.h>
#include<assert.h>
#define R


int integer_fraction(float x);
int main(void)
{
    float  r, s;
    int s_integer=0;
        printf ("input a number: ");
        scanf("%f",&r);
        #ifdef  R
           s=3.14159*r*r;
           printf("area of round is: %f\n",s);
           s_integer= integer_fraction(s);
            assert((s-s_integer)<=1.0);  //假设程序错误，即终止程序
            printf("the integer fraction of area is %d\n", s_integer);
        #endif
        return 0;
}

int integer_fraction(float x)
{
      int i=x;
      return i;
}
