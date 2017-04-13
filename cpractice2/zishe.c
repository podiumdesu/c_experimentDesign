#include<stdio.h>
#include<math.h>
int main() {
    float a,b,c,d;
    printf("请输入三角形三条边：\n");
    scanf("%f%f%f",&a,&b,&c);
    d=(a+b+c)/2;
    if(a+b>c&&a+c>b&&b+c>a)    {
        if(a==b&&a==c&&b==c) {
            printf("三角形为等边三角形\n");
            printf("面积为：%f 周长为：%f",1.732*a*a/4,3*a);    /*等边三角形面积公式：四分之根号三乘边长的平方 */
        }
        else if(a==b||a==c||b==c) {
            printf("三角形为等腰三角形\n");
            printf("面积为：%f 周长为：%f",sqrt(d*(d-a)*(d-b)*(d-c)),a+b+c);   /*套用海伦公式 下同*/
        }
        else if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a) {
            printf("三角形为直角三角形\n");
            printf("面积为：%f 周长为：%f",sqrt(d*(d-a)*(d-b)*(d-c)),a+b+c);
        }
        else {
            printf("三角形为普通三角形\n");
            printf("面积为：%f 周长为：%f",sqrt(d*(d-a)*(d-b)*(d-c)),a+b+c);
        }
    }
    else {
        printf("这三边无法构成三角形");
    }
    return 0;
}
