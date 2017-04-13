//打印杨辉三角形
#include<stdio.h>

#define N 10                /*给定行数 */

int main()

{

    int i,j,k;

      int b,c;

      for(i=0;i<N;i++)

      {
        
      for(j=N;j>i;j--)

      printf("  ");           /*输出前置空格*/

      for(j=0;j<=i;j++)

      {

      b=c=1;

      if(j>=1)

      {

      for(k=i-j+1;k<=i;k++)   /*公式使用*/

      b=b*k;

      for(k=1;k<=j;k++)       /*公式使用*/

      c=c*k;

      }

      printf("%4d",b/c);

      }

      printf("\n");           /*换行*/

      }

      return 0;

}
