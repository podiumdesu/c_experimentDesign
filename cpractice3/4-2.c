//验证哥德巴赫猜想
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime (int x) {
  int count = 0;
  int sqrt_x = sqrt(x);
  for (int i = 2; i <= sqrt(x); i++){
    if (x % i == 0) {
      count++;
    }
  }
  if (count  == 0 ) {
    return 1;
  } else {
    return 0;
  }
}

int main (void) {
  int begin,end;
  int half_j;
  printf("Please enter the begin number(>=4) and the end number:");

  while (scanf("%d%d",&begin,&end) == 2) {
    printf("\tGOLDBACH'S CONJECTURE:\n");
    printf("\tEvery even number n>=4 is the sum of two primes\n");
    for (int j = begin; j <= end; j++) {
      if (j % 2 == 0) {
        half_j = j / 2;
        for (int k = 2; k <= half_j ;k++) {
          if (isPrime(k) && isPrime(j-k)){
            printf("\t\t%d = %d + %d\n",j,k,(j-k));
            break;
          }
        }
      }
    }
    printf("Please enter another two number(q to quit):");
  }
  return 0;
}
