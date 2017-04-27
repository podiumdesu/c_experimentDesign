//源程序改错
#include<stdio.h>
void sort(int b[], int n);      //未声明

int main(void) {
     int a[10] = {27, 13, 5, 32, 23, 3, 17, 43, 55, 39};
     //void sort(int [],int);  //不应该有的
     int i;
     sort(&a[0],10);   //应该传入地址
     for(i = 0; i < 10; i++)
        printf("%6d",a[i]);
     printf("\n");
     return 0;
}
void sort(int b[], int n)
{
     int i, j, t;
     for (i = 0; i < n - 1; i++)
        for ( j = 0; j < n - i - 1; j++)
           if(b[j] < b[j+1])
              t = b[j], b[j] = b[j+1], b[j+1] = t;
}
