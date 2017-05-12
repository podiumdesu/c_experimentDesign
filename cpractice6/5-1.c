/*(1) 设有N位整数和M位小数（N=20，M=10）的数据a,b。编程计算a+b并输出结果。*/

#include <stdio.h>
#include <string.h>
#define N 20
#define M 10
#define SIZE 32

int main (void) {
//  char a[SIZE] = "14625367835167873521.1356727836";   //此时size长度应该为31
    //char b[SIZE] = "97267278252562772828.4226143429";
    char a[SIZE] = "73211515234116121121.1217525411";
    char b[SIZE] = "12212341161413143161.1112314529";

    int len = 31;
    //printf("%d",len);
    char new_a[SIZE];
    char new_b[SIZE];
    char result[] = "0";
    for (int i = len - 1; i >= 0; i--) {
        new_a[len-1-i] = a[i];
        new_b[len-1-i] = b[i];
    }
    int j = 0;
    result[0] = 0;

    for (int i = 0; i < 31; i++) {
        if ( ((*(new_a+i) - '0') + (*(new_b+i) - '0') < 10) && (*(new_a+i)) != '.' ) { //相加是否大于10需要进位
            result[j] += (*(new_a+i) - '0') + (*(new_b+i));    //如果不是，直接相加输出字符
            result[j+1] = 0;
        } else if (((*(new_a+i) - '0') + (*(new_b+i) - '0') > 10) && (*(new_a+i+1) != '.')) { //相加大于10但是不在小数点附近
            result[j] += (*(new_a+i) - '0') + (*(new_b+i)) - 10;
            result[j+1] = 1;
        } else if (((*(new_a+i) - '0') + (*(new_b+i) - '0') > 10) && (*(new_a+i+1) == '.')) { //相加大于10而且在小数点附近
            result[j] += (*(new_a+i) - '0') + (*(new_b+i)) - 10;
            result[j+1] = 0;
            result[j+2] = 1;
        } else if (*(new_a+i) == '.') {
            result[j] = '.';
            result[j+1] = 0;
        } else {
            continue;
        }
        j++;
    }
    //printf("%s",result);
//    printf("%c   ",result[j+1]);
    printf("a = %s\n",a);
    printf("b = %s\n",b);
    printf("a+b=");
    if (result[j] == '1') {
        for (int i = 30; i >= 0; i--) {
            printf("%c",result[i]);
        }
    } else {
        for (int i = 30; i >= 0; i-- ) {
            printf("%c",result[i]);
        }
    }
    return 0;
}
