/*
(++p)->x    100
p++,p->c    'B'
*p++->t,*p->t    'U' 'x'
*(++p)->t   'x'
*++p->t  'V'
++*p->   'V'
*/


#include <stdio.h>
int main (void) {
  char u[]="UVWXYZ";
  char v[]="xyz";
  struct T{
  	int x;
  	char c;
  	char *t;
  }a[]={{11,'A',u},{100, 'B',v}},*p=a;
  return 0;
}
