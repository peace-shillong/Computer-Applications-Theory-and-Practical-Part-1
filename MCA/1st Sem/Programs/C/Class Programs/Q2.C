//Q2
#include<stdio.h>
#include<conio.h>
//Exam01
void main(){
	char s1[100]="Hello World ";
	char s2[100]="Programming";
	char s3[100],c,c2;
	FILE *f1,*f2,*fn;
	int len,count;
	count=1;

	f1=fopen("Z:\\test1.txt","w");
	f2=fopen("Z:\\test2.txt","w");
	fn=fopen("Z:\\final.txt","w+");
	clrscr();
	if(f1==NULL && f2==NULL)
		printf("Cannot open file");
	printf("Enter a sentence for test1.txt\n");
	gets(s1);
	printf("Enter a sentence for test2.txt\n");
	gets(s2);
	fputs(s1,f1);
	fputs(s2,f2);
	if(fn==NULL)
		printf("Cannot Open file");
	fclose(f1);
	fclose(f2);
	f1=fopen("Z:\\test1.txt","r");
	f2=fopen("Z:\\test2.txt","r");
	len=strlen(s1);
	printf("\nCopying from test1.txt to final.txt\n");

	fgets(s3,len+1,f1);
	fputs(s3,fn);
	printf("\nContents in test1.txt\n%s",s3);

	len=strlen(s2);
	c=0;
	printf("\nCopying from test2.txt to final.txt\n");
	//Putting space in final.txt after copying from test1.txt
	fputc(' ',fn);

	fgets(s3,len+1,f2);
	fputs(s3,fn);
	printf("\nContents in test2.txt \n%s",s3);

	fclose(fn);
	fn=fopen("Z:\\final.txt","r");
	c=0;
	while(c!=EOF){
		c=fgetc(fn);
		switch(c){
			case ' ':
				count++;
		}
	}
	printf("\n\nThe Number of words in final.txt is %d",count);
	getch();
}