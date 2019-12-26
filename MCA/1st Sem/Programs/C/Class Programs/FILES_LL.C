//Program using Low Level IO
#include<fcntl.h>
#include<types.h>
#include<stat.h>
#include<stdio.h>
void main(){

	int inhandle,outhandle,bytes;
	char source[128],target[128];
	char buffer[512],b[512]="";
	clrscr();
	printf("\nEnter the Source(Path and filename)\n");
	gets(source);
	outhandle=open(source,O_CREAT|O_TEXT|O_RDWR,S_IWRITE|S_IREAD);
	if(outhandle==-1)
	{
		printf("\nSource file not created");
		getch();
		exit(0);
	}
	printf("\nEnter Content to Source file.");
	gets(b);
	write(outhandle,b,512);
	fflush(stdin);
	close(outhandle);
	printf("\nEnter the Target(Path and filename)\n");
	gets(target);
	outhandle=open(source,O_TEXT|O_RDWR);
	inhandle=open(target,O_APPEND|O_TEXT|O_RDWR);
	while(1){
		bytes=read(outhandle,buffer,512);

		if(bytes>0){
			write(inhandle,buffer,bytes);
		}
		else{
			printf("Copy Success.");
			break;
		}
	}

	getch();
}