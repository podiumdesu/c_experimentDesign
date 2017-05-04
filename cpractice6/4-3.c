/*
(3) 编写一个程序,输入n个整数，排序后输出。
排序的原则由命令行可选参数-d决定，有参数-d时按递减顺序排序，否则按递增顺序排序。
要求将排序算法定义成函数，利用指向函数的指针使该函数实现递增或递减排序。
*/



/*定义函数指针
#include <stdio.h>
//返回两个数中较大的一个
int max(int a, int b){
    return a>b ? a : b;
}
int main(){
    int x, y, maxval;
    //定义函数指针
    int (*pmax)(int, int) = max;  //也可以写作int (*pmax)(int a, int b)
    printf("Input two numbers:");
    scanf("%d %d", &x, &y);
    maxval = (*pmax)(x, y);
    printf("Max value: %d\n", maxval);
    return 0;
}
*/

#include <stdio.h>
#include <string.h>
void bubble_sort(int *s,int n);
int main (int argc, char **argv) {
  int rows;
  printf("How many integers?");
  scanf("%d",&rows);
  int arr[rows];
  int count;
  printf("Please input some integers:");
  for (int i = 0; i < rows; i++) {
    scanf("%d",&arr[i]);  //获取数字数组
  }
  void (*pbub_sort)(int *,int ) = bubble_sort;   //定义函数指针
  pbub_sort(arr,rows);  //使用函数指针
  int * ptr = arr;  //将排序好后的arr数组的首地址赋给ptr指针
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i],"-d") == 0) {
      count++;
    }
  }
  if (count == 0) {
    printf("You will get a low to high array\n");
    getchar();
    getchar();
    for (int i = 0; i < rows; i++) {
      printf("%d ",*ptr);  //输出指针ptr对应的值
      ptr++;  //递增指针
    }
  } else {
    printf("You will get a high to low array\n");
    getchar();
    getchar();
    ptr = ptr+rows-1;
    //printf("%d",*ptr);
    for (int i = 0; i < rows; i++) {
      printf("%d ",*ptr);  //输出指针ptr对应的值
      ptr--;  //递减指针
    }
  }
  return 0;
}

void bubble_sort(int *s,int n) {
  int *ptr = s;
  int temp;
  for (int i = 0; i < n; i++) {   //使用冒泡排序对数组中的值进行排序
    for (int j = 0; j < n - 1 - i; j++) {
      if (*(ptr+j) > *(ptr+j+1)) {
        temp = *(ptr+j);
        *(ptr+j) = *(ptr+j+1);
        *(ptr+j+1) = temp;
      }
    }
  }
}
