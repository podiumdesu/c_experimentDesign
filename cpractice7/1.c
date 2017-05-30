/*
(++p)->x    100
p++,p->c    'B'
*p++->t,*p->t    'U' 'x'
*(++p)->t   'x'
*++p->t  'V'
++*p->   'V'
*/


#include<stdio.h>
char u[]="UVWXYZ";
char v[]="xyz";
struct T{
	int x;
	char c;
	char *t;
}a[]={{11,'A',u},{100,'B',v}},*p=a;
int main()
{
	p=a;
	printf("(++p)->x = %d\n",(++p)->x);
    p=a;
	printf("p++,p->c = %c\n",(p++,p->c));
	p=a;
	printf("*p++->t,*p->t = %c\n",(*p++->t,*p->t));
	p=a;
	printf("*(++p)->t = %c\n",*(++p)->t);
	p=a;
	printf("++*p->t = %c\n",++*p->t);
	p=a;
	printf("*++p->t = %c",*++p->t);
	return 0;
}
