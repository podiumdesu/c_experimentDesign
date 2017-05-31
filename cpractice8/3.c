/*
   从键盘输入一行英文句子，将每个单词的首字母换成大写字母，
   然后输出到一个磁盘文件“test”中保存。
   */

#include <stdio.h>
#include <ctype.h>  //提供toupper(),isalpha()
#include <stdlib.h> //提供exit()原型
#include <string.h>

int main (void) {
  FILE *fp, *out;
  out = fopen("test","w");
  //out = freopen("test","w+",stdout);
  if (out == NULL) {
    fprintf(stderr,"Sorry, can\'t open \"test\"\n");
    exit(EXIT_FAILURE);
  }
  char words[100];  //用来存储输入的每个单词

  fgets(words,100,stdin);
    for (int i = 0 ; i < strlen(words); i++) {
      if (isalpha(words[0])) {
        words[0] = toupper(words[0]);
      }
      if (!isalpha(words[i]) && isalpha(words[i+1])) {
        words[i+1] = toupper(words[i+1]);
      }
    }
    fprintf(out,"%s",words);

  printf("Done!");
  return 0;
}
