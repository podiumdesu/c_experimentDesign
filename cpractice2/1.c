//源程序改错题
//计算s = n!

#include <stdio.h>

int  main(void)

{

int i,n,s=1;

  printf("Please enter n:");

//  scanf("%d", n);
  scanf("%d",&n);
//  for(i=1,i<=n,i++)
  for (i = 1; i <= n; i++) {
    s=s*i;

  }

  printf("%d! = %d",n,s);

  return 0;

}
