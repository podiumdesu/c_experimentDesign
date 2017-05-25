#include <stdio.h>

typedef struct bits {
  unsigned int bit0 : 1;
  unsigned int bit1 : 1;
  unsigned int bit2 : 1;
  unsigned int bit3 : 1;
  unsigned int bit4 : 1;
  unsigned int bit5 : 1;
  unsigned int bit6 : 1;
  unsigned int bit7 : 1;
}BITS;

union number {
  unsigned short all;   //联合上下都是八位，选择一种存储
  BITS bits;
};
//定义一堆函数
void fun0(union number number) {
  printf("the function 0 is called!\n");
}
void fun1(union number number) {
  printf("the function 1 is called!\n");
}
void fun2(union number number) {
  printf("the function 2 is called!\n");
}
void fun3(union number number) {
  printf("the function 3 is called!\n");
}
void fun4(union number number) {
  printf("the function 4 is called!\n");
}
void fun5(union number number) {
  printf("the function 5 is called!\n");
}
void fun6(union number number) {
  printf("the function 6 is called!\n");
}
void fun7(union number number) {
  printf("the function 7 is called!\n");
}



int main (void) {
  //定义函数指针数组
  BITS bits;
  union number number;
  void (*p_fun[8])(union number) = {fun0,fun1,fun2,fun3,fun4,fun5,fun6,fun7};
  printf("Please input an unsigned number");
  while (scanf("%hd",&number.all)) {
    getchar();
    printf("%hd:\n",number.all);
    if(number.bits.bit0) {
      fun0(number);
    }
    if(number.bits.bit1) {
      fun1(number);
    }
    if(number.bits.bit2) {
      fun2(number);
    }
    if(number.bits.bit3) {
      fun3(number);
    }
    if(number.bits.bit4) {
      fun4(number);
    }
    if(number.bits.bit5) {
      fun5(number);
    }
    if(number.bits.bit6) {
      fun6(number);
    }
    if(number.bits.bit7) {
      fun7(number);
    }
    printf("\n");
    printf("Please input another number: ");
  }
  return 0;
}
