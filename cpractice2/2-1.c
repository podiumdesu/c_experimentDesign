//源程序修改替换题
//修改第一题，分别使用while和do-while语句替换for语句

#include <stdio.h>
int main (void) {

  int n,s=1;

    printf("Please enter n(use while):");

  //  scanf("%d", n);
    scanf("%d",&n);
  //  for(i=1,i<=n,i++)
    int i = 1;
    //使用while语句
    while (i <= n) {
      s = s*i;
      i++;
    }
    printf("%d! = %d\n",n,s);

//    for (i = 1; i <= n; i++) {
//      s=s*i;
//    }

    //使用do while语句
    printf("please input another number(use do-while)");
    scanf("%d",&n);
    s = 1;
    i = 0;
    do{
      s = s*(i+1);
      i++;
    }while(i<n);
    printf("%d! = %d\n",n,s);

    return 0;

}
