//（2）编写一个程序，输入无符号短整数x，ｍ，ｎ
//（0 ≤ｍ≤ 15, 1 ≤ ｎ≤ 16-ｍ），
//取出x从第ｍ位开始向左的ｎ位（ｍ从右至左编号为0～15），
//并使其向左端（第15位）靠齐。


#include<stdio.h>
int main(){
	unsigned short x,m,n,a,b;
  printf("请输入x（16进制），m，n\n");
	printf("Please notice that 0<=m<=15 and 1<=n<=(16-m)!!\n");
	while (scanf("%hx %hd %hd",&x,&m,&n) == 3) {

			if(m >= 0 && m <= 16 && n >= 1 && n <= 16-m) {
		  	a = x>>m;
			  b = a<<(16-n);
		  	printf("The result is %hx\n",b);
		  }
		  else {
				printf("Please input correct numbers\n");
			}
			printf("Please input another number and the m n that you want to take(q to quit)\n");
//			scanf("%hd %hd %hd",&x,&m,&n);
	}
	printf("Bye!!Have a nice day!\n");

	return 0;
}
