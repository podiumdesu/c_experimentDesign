//程序设计3-1/if
//假设工资税金按照以下方法计算
//x ＜ 1000元，不收取税金；
//1000 ≤ x ＜ 2000，收取5%的税金；
//2000 ≤ x ＜ 3000，收取10%的税金；
//3000 ≤ x ＜ 4000，收取15%的税金；
//4000 ≤ x ＜ 5000，收取20%的税金；
//x＞5000，收取25%的税金。

#include<stdio.h>
int main (void) {
  int salary;
  double tax;
  printf("Please input your salary!!(q to quit):\n");
  while(scanf("%d",&salary) != 0) {
    if (salary < 1000) {
      printf("You don't need to pay tax\n");
    }
    else if (salary >= 1000 && salary < 2000) {
      tax = (salary) * 0.05;
      printf("tax:%.2f\n",tax);
    }
    else if (salary >= 2000 && salary < 3000) {
      tax = (salary) * 0.1;
      printf("tax:%.2f\n",tax);
    }
    else if (salary >= 3000 && salary < 4000) {
      tax = (salary) * 0.15;
      printf("tax:%.2f\n",tax);
    }
    else if (salary >= 4000 && salary < 5000) {
      tax = (salary) * 0.2;
      printf("tax:%.2f\n",tax);
    }
    else {
      tax = (salary) * 0.25;
      printf("tax:%.2f\n",tax);
    }
    printf("Please input your salary(q to quit):\n");
  }
  return 0;
}
