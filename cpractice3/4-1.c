//编程让用户输入两个整数
#include <stdio.h>
int maxDividedNum (int n, int k);
int main (void) {
  int num_1,num_2;
  while (scanf("%d%d",&num_1,&num_2) == 2) {
    if (num_1 < num_2) {
      num_1 = num_1 ^ num_2;
      num_2 = num_1 ^ num_2;
      num_1 = num_1 ^ num_2;
    }
    printf("%d和%d的最大公约数为: %d\n",num_1,num_2,maxDividedNum(num_1,num_2));
  }
  return 0;
}

int maxDividedNum (int n, int k) {
  int rem;
  rem = n % k;
  if (!rem) {
    return k;
  }
  maxDividedNum(k,rem);
}
