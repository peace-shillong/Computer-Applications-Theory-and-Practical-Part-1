#include<stdio.h>
#include<conio.h>
void main()
{
	FILE *fp;
	char par[50];
	int vowel=0,i=0;
	clrscr();
	fp=fopen("C:\\par.txt","a+");
	if(fp==NULL)
	{
		printf("Error");
		exit(1);
	}
	printf("Enter a paragraph: ");
	gets(par);
	fprintf(fp,"%s",par);
	rewind(fp);
	fgets(par,50,fp);
       printf("para:   %s",par);

       while(i<=strlen(par))
       {
	if((par[i]=='a')||(par[i]=='e')||(par[i]=='i')||(par[i]=='o')||(par[i]=='u'))
		vowel++;

		i++;
       }
       printf("no of vowel %d",vowel);

	fclose(fp);
	getch();
}