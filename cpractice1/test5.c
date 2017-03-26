//（3）IP地址通常是4个用句点分隔的小整数（即点分十进制），
//如32.55.1.102。这些地址在机器中用无符号长整形表示。
//编写一个程序，以机器存储的形式读入一个互联网IP地址，对其译码，
//然后用常见的句点分隔的4部分的形式输出。

//例如，整形676879571二进制表示就是：00101000 01011000 01011100 11010011，
//按照8位一组可表示为：40 88 92 211，由于CPU处理数据的差异，它的顺序是颠倒的，所有最终格式为211.92.88.40。

#include<stdio.h>
int main (void){
  unsigned int number;
  unsigned int a , b , c ,d ;
  printf("Please input an unsigned int number to get its ip address\n");
  while (scanf("%ld",&number) == 1) {
    a = number>>24;
    b = number<<8 >>24;
    c = number<<16 >>24;
    d = number<<24 >>24;
    printf("The ip address is %d.%d.%d.%d\n",d,c,b,a);
    printf("Please input another unsigned int number (q to quit)\n");
//    scanf("%ld",&number);
  }
  printf("Bye!!Have a nice day!\n");
  return 0;
}
