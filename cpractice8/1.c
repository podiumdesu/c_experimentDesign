#include <stdio.h>
int  main(void)
{
	short a=0x253f,b=0x7b7d;
	char ch;
	FILE *fp1,*fp2;
	fp1=fopen("abc1.bin","wb+");
  fp2=fopen("abc2.txt","w+");
	fwrite(&a,sizeof(short),1,fp1);
	fwrite(&b,sizeof(short),1,fp1);     //
	fprintf(fp2,"%hx %hx",a,b);   //写入fp2文件

    rewind(fp1); rewind(fp2);  //回到文件开始处
	while((ch = fgetc(fp1)) != EOF)
		putchar(ch);
	putchar('\n');

	while((ch = fgetc(fp2)) != EOF)
		putchar(ch);
	putchar('\n');

	fclose(fp1);
	fclose(fp2);
   return 0;
}



/*
2: 输出应该是  ?}
*/

/*
3：输出的是十进制   9535 31613
*/
