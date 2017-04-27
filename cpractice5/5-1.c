//编写函数strnins(s,t,n)，其功能是将字符数组t中的字符串插入到字符数组s中
//字符串的第n个字符后面，编写Main测试strnins的正确性



#include <stdio.h>
#include <string.h>
#define SIZE 150

void strnins (char s[], char t[], int n);
int main (void) {
    char s[SIZE];
    char t[50];
    int n;
    printf("You can input the array s:");
    scanf("%s",s);
    printf("\nnow please input the array t:");
    scanf("%s",t);
    printf("where to put t? ");
    scanf("%d",&n);
    strnins(s,t,n);
    printf("%s",s);
    return 0;
}




void strnins (char s[], char t[], int n) {
    char copy[100];
    int length = strlen(s);
    int length_n = strlen(t);
    for (int i = n, j = 0; i < length; i++, j++) {
        copy[j] = s[i];
    }
    copy[length - n] = '\0';

    for (int i = n , j = 0; j < length_n; j++,i++) {
        s[i] = t[j];
    }
//  s[length_n + n] = '\0';
    //printf("%s",s);
    for (int i = n+length_n , j = 0 ; i < length + length_n; i++,j++) {
        s[i] = copy[j];
    }
    //s[length + length_n -1] = '\0';

}
