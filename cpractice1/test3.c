//（1）编写一个程序，输入字符ｃ，如果ｃ是大写字母，则将ｃ转换成对应的小写，否则ｃ的值不变，最后输出ｃ。
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void quit(int signal) {
    if (signal == SIGINT) {
        printf("\nBye!!Have a nice day!\n");
        exit(0);
    }
    return;
}

int main(void) {
    char character;
    printf("Please input a character to get its lowercase:\n");
    signal(SIGINT, quit);  //使用回调函数
    while (character = getchar()) {
        if (character >= 65 && character <= 90) {
          printf("You input an uppercase letter, and its lowercase one is %c\n", character + 32);
        } else {
          printf("You just input %c\n", character);
        }
        printf("Please input another one. (ctrl+c to quit)\n");
        getchar();
    }
    return 0;
}
