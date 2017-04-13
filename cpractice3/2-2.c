#include <stdio.h>
unsigned long long factorial (int n) ;
int main (void) {
  int number;
  double result;
  while(scanf("%d",&number) == 1) {
    result = 0.0;
    for (int i = 1 ; i <= number; i++) {
      result = result + (1.0 / factorial(i));
    }
    printf("k = %d , sum = %.9lf\n",number,result);
  }
  return 0;
}

unsigned long long factorial (int n) {
  unsigned long long ans;
  ans = 1;
  for (int i = 1; i <= n; i++) {
    ans *= i;
  }
  return ans;
}
