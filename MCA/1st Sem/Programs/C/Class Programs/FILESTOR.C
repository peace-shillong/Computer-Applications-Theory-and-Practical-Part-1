#include<stdio.h>
#include<conio.h>

void main()
{
	FILE *fp;
	struct students
	{
		char name[20];
		int age;
	};
	struct students s[20];
	int no,i;
	clrscr();
	fp=fopen("C:\\melvin.txt","a+");
	if(fp==NULL)
	{
		printf("No file");
		exit(1);
	}
	printf("Enter no of students: ");
	scanf("%d",&no);

	for(i=0;i<no;i++)
	{
		printf("Enter name: ");
		scanf("%s",s[i].name);
		printf("Enter age: ");
		scanf("%d",&s[i].age);

		fprintf(fp,"%s %d\n",s[i].name,s[i].age);
		fflush(stdin);
	}

	rewind(fp);
	i=0;
	while(fscanf(fp,"%s%d",s[i].name,s[i].age)!=EOF)
	{
		printf("Name %s\tAge: %d",s[i].name,s[i].age);
		i++;
	}
	fclose(fp);
	getch();
}