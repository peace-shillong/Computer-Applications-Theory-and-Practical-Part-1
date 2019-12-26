//files1
#include<stdio.h>
#include<conio.h>
void main(){
	FILE *fs;
	char c='c';
	clrscr();
	//Writing to File
	fs=fopen("Z:\\C\\Files1.txt","a+");
	if(fs==NULL)
	{
		printf("File does not Exist\n");
	}
	fputc(c,fs);
	fclose(fs);
	//Reading The File
	fopen("Z:\\C\\Files1.txt","r");
	while(!feof(fs)){
	printf("%c",fgetc(fs));
	}
	fclose(fs);
	getch();
}
