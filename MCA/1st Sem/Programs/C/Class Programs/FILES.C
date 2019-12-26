//FILE
#include<conio.h>
#include<stdio.h>
void main(){

	//clrscr();
	FILE *fp;
	char c[100];
	char s[100];
	int count=0,len,i;
	clrscr();
	fp=fopen("Z:\\File.txt","w+");
	if(fp==NULL){
		printf("File !Exist");
	}
	gets(s);
	printf("\ns= %s",s);
	fputs(s,fp);
	len=strlen(s);
	//fprintf(fp,"%s",s);
	rewind(fp);
       //	while(!feof(fp)){
		fgets(c,len+1,fp);
		//fscanf(fp,"%s",c);
		len=strlen(c);
		//c=fgetc(fp);
		printf("\na= %s\n %d ",c,len);
		for(i=0;i<len;i++){
		switch(tolower(c[i])){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			count++;
			printf (" \n in File%c ",c[i]);
			break;
		case ' ':
			printf(" \n Space ");
		}
	}
       //	}
	printf("There are %d vowels",count);
	getch();
}