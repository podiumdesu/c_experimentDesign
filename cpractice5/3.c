#include<stdio.h>
void strncatddd(char [],char [],int);
int main(void)
{
      int length;
      char a[50]="The adopted symbol is ",b[27]="abcdefghijklmnopqrstuvwxyz";
      printf("[a] = %s ; [b] = %s\n",a,b);
      printf("Please input how long you want to copy:");
       while (scanf("%d",&length) == 1) {
         char a[50]="\tThe adopted symbol is ";
         strncatddd(a, b, length);
         printf("%s\n",a);
         printf("Input another number:(q to quit)");

       }

return 0;
}

void strncatddd(char s[],char t[], int n)
{
      int i = 0, j;
    while(s[i++]) ;
    i--;   ////////////////////////

    for(j = 0; j < n && t[j];) {
      s[i++] = t[j++];
    }
    s[i] = '\0';  //注意数组下标和i之间差1
}
