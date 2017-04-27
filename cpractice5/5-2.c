//八皇后
//在8*8的方格国际棋盘上放置8个皇后，任意两个皇后不能放在同一行，同一列，或同一斜线，并输出所有可能的方法

#include<stdio.h>
#define Queens 8 /*皇后数量*/

int A[Queens*3];
int B[Queens*3];
int C[Queens*3];
int k[Queens+1][Queens+1];
int inc;
int *a=&A[Queens];
int *b=&B[Queens];
int *c=&C[Queens];

void lay(int i)
{
    int j=0,t,u;
    while(++j<=Queens)
        if(a[j]+b[j-i]+c[j+i]==0)
         {
            k[i][j]=a[j]=b[j-i]=c[j+i]=1;
            if(i<Queens)lay(i+1);
            else
            {
                ++inc;
                printf("(%d)\n",inc);
                for(u=Queens+1; --u; printf("\n"))
                    for(t=Queens+1; --t;)k[t][u]?printf("1 "):printf("+ ");
                printf("\n\n");
            }
            a[j]=b[j-i]=c[j+i]=k[i][j]=0;
        }
}
int main(void)
{
    lay(1);
    printf("%d皇后共计%d个解",Queens,inc);
    getchar();
    return 0;
}
