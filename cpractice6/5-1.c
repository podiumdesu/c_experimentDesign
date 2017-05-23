/*(1) 设有N位整数和M位小数（N=20，M=10）的数据a,b。编程计算a+b并输出结果。*/

/*（1）设有N位整数和M位小数（N=20，M=10）的两个数据a,b。编程计算a+b并输出结果。如：
12345678912345678912.1234567891+98765432109876543210.0123456789
*/

#include <stdio.h>
#define SIZE 32
int main (void) {
	char a[SIZE] = "12345678912345678912.1234567891";
	char b[SIZE] = "98765432109876543210.0123456789";
	int len = 31;
	char new_a[SIZE];
	char new_b[SIZE];
	char result[] = "0";
	for (int i = len - 1; i >= 0; i--) {
		*(new_a + len - 1 -i) = *(a+i);     //将数组a中的字符倒序存入新的数组中
		*(new_b + len - 1 -i) = *(b+i);
	}
	int j = 0;
	*result = 0;

	for (int i = 0; i < 31; i++) {
		if ( ((*(new_a+i) - '0') + (*(new_b+i) - '0' + *(result+j)) < 10) && (*(new_a+i)) != '.' ) { //相加是否大于10需要进位
			*(result+j) += (*(new_a+i) - '0') + (*(new_b+i));    //如果不是，直接相加输出字符
			*(result+j+1) = 0;
		} else if ((((*(new_a+i) - '0') + (*(new_b+i) - '0'+ *(result+j))) >= 10) && (*(new_a+i+1) != '.')) { //相加大于10但是不在小数点附近
			*(result+j) += (*(new_a+i) - '0') + (*(new_b+i)) - 10;
			*(result+j+1) = 1;
		} else if ((((*(new_a+i) - '0') + (*(new_b+i) - '0'+ *(result+j))) >= 10) && (*(new_a+i+1) == '.')) { //相加大于10而且在小数点附近
			*(result+j) += (*(new_a+i) - '0') + (*(new_b+i)) - 10;
			*(result+j+1) = 0;
			*(result+j+2) = 1;
		} else if (*(new_a+i) == '.') {
			*(result+j) = '.';
			if(*(result+j+1) != 1) {
				*(result+j+1) = 0;
			}
		} else {
			continue;
		}
		j++;
	}

  if(*(result+j) == 1) {
    *(result+j) = 1+'0';
    printf("a =  %s\n",a);
    printf("b =  %s\n",b);
    printf("a+b=");
    for (int i = 31; i >= 0; i--) {
      printf("%c", *(result+i));
    }
  } else {
    printf("a = %s\n",a);
    printf("b = %s\n",b);
    printf("a+b=");
    for (int i = 30; i >= 0; i--) {
      printf("%c", *(result+i));
    }
  }
	return 0;
}
