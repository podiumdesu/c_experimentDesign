//（1）编写一个程序，输入字符ｃ，如果ｃ是大写字母，则将ｃ转换成对应的小写，否则ｃ的值不变，最后输出ｃ。


#include<stdio.h>
int main (void) {
   char character;

   printf("Please input a character to get its lowercase:\n");

   while(scanf("%c", &character) == 1) {
     if((character < 65) || (character > 122) || ((character >= 91) && (character <= 96))) {
        printf("Please input a character!!!\n");
     }
  //   else if (character >= 91 & character<=96){
  //      printf("Please input a character!!!\n");
  //   }
     else if (character >= 97 && character <= 122) {
        printf("This character %c has already been a lowercase letter!\n",character);
     }
     else {
        printf("This character is a uppercase one, and its lowercase letter is ");
        printf("%c\n",character + 32);
     }
     printf("\n");
     printf("Please input another character to get its lowercase(ctrl+c to quit)\n");
//     scanf("%c", &character);
     getchar();
   }
   printf("Bye!!Have a nice day!");
   return 0;
}
