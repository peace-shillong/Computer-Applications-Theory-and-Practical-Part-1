//Fread and fwrite
#include<stdio.h>
void main(){

	char r[50];
	char s[10];
	FILE *fs;
	clrscr();
	fs=fopen("Z:\\fread_test.txt","w+");
	printf("Enter");
	gets(s);
	fwrite(s,sizeof(s),1,fs);
	fseek(fs,0,SEEK_SET);
	fread(r,sizeof(r),1,fs);
	printf("%s",r);
	getch();
}