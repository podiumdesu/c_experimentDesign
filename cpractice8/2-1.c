//用输入输出重定向freopen改写main函数
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    char ch;
    FILE *fp;
    if (argc != 2) {
      printf("Arguments error!\n");
      exit(EXIT_FAILURE);
    }
    if ((fp = freopen(argv[1],"r",stdin)) == NULL) {    //重定向
      printf("Can't open %s file!\n",argv[1]);
      exit(EXIT_FAILURE);
    }
    while ((ch = fgetc(fp)) != EOF) {
      putchar(ch);
    }
    fclose(fp);
    return 0;
}
