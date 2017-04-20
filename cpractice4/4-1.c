//计算三角形面积
//宏定义求三角形面积
#include <stdio.h>
#include <math.h>

#define COMPUTE_S(a,b,c) ((a+b+c)/2.0)
#define AREA(s,a,b,c) (sqrt((s*(s-a)*(s-b)*(s-c))))

int isTriangle (float a, float b, float c);
int main (void) {
  float a,b,c;
  float s;
  double area;
  printf("Please input three numbers:");
  while (scanf("%f%f%f",&a,&b,&c) != EOF) {
    if (isTriangle (a,b,c)&&isTriangle (b,c,a)&&isTriangle (a,c,b)){
      s = COMPUTE_S(a,b,c);
      area = AREA(s,a,b,c);
      printf("The area of this triangle is %.2f\n",area);
    } else {
      printf("这三边无法构成三角形\n");
    }

    printf("Please input three numbers:");
  }
  return 0;
}

int isTriangle (float a, float b, float c) {
  if (a+b > c) {
    return 1;
  } else {
    return 0;
  }
}
