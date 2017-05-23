/*
(2) 利用大小为n的指针数组指向用gets函数输入的n行，每行不超过80个字符。
试编写一个函数，它将每一行中连续的多个空格字符压缩为一个空格字符。
在调用函数中输出压缩空格后的各行，空行不予输出。
*/



#include <stdio.h>
#include <string.h>
int main (void) {
	int rows;
	int count;
	scanf("%d\n",&rows);
	//getchar();
	char string[rows][80];
	char result[rows][80];
	count = rows;
	for (int i = 0; i < count; i++) {
		gets(*(string+i));
	}
  for (int i = 0; i < count; i++) {
		int k = 0;
		int len = strlen(*(string+i));
		for (int j = 0 ; j < len; j++) {
			if (*(*(string+i)+j) != ' ') {
				(*(*(result+i)+k)) = *(*(string+i)+j);
				k++;
			} else {
				if ( *(*(string+i)+j+1) == ' '){
					continue;
				} else {
					(*(*(result+i)+k)) = *(*(string+i)+j);
				  k++;
				}
			}
		}
		(*(*(result+i)+k)) = '\0';
	}

	//输出压缩完成后的各行
	for (int i = 0; i < count; i++) {
		puts(*(result+i));
	}
	return 0;
}
