#include<stdio.h>
#define M 10
#define N 3
int main(void)
{
	int a[M],b[M];/*数组a存放圈中人的编号，数组b存放出圈人的编号*/
	int i,j,k,n;
	for(i=0;i<M;i++)/*对圈中人按顺序编号1~M*/
	   a[i]=i+1;

	for(i=M,j=0;i>1;i--){
/*i表示圈中人个数，初始为M个，剩1个人时结束循环；j表示当前报数人的位置*/
	for(k=1;k<=N;k++){
	for(;a[j]>M;j++);
	  if(j++>=(M-1)) j=0;
    }b[M-i]=j?a[j-1]:a[M-1];
	   if(j)
	   {
	   	b[M-i]=a[j-1];
	   	a[j-1]=11;
	   }
	   else
	   {
	   	for(n=1;a[M-n]>10;n++)
	   	b[M-i]=a[M-n];
	   	a[M-n]=11;
	   }
}
	for(i=0;i<M-1;i++)/*按次序输出出圈人的编号*/
	   printf("%6d",b[i]);
	for(i=0;i<M;i++)
	   if(a[i]<11)
	      printf("%6d",a[i]);/*输出圈中最后一个人的编号*/
	return 0;
}
