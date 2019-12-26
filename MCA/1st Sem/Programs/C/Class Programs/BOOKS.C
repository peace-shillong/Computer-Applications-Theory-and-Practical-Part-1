#include<stdio.h>
#include<conio.h>

struct books
{
	char name[20];
	char author[20];
	int quantity;
};

void main()
{
	struct books b;
	FILE *fp,*t;
	int choice,flag=0,size;
	char name[20];
	clrscr();
	size=sizeof(b);
	fp=fopen("C:\\books.txt","a+");
	do{
	clrscr();
	printf("\t\t1.Add Books\n\t\t2.Show Books\n\t\t3.Modify");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			{
				fseek(fp,0,SEEK_END);
				printf("Enter book Name: ");
				scanf("%s",b.name);
				printf("Enter book Author: ");
				gets(b.author);
				printf("Enter book Quantity: ");
				scanf("%d",&b.quantity);

				fwrite(&b,size,1,
				fp);


			}
			break;

		case 2:
			{
				rewind(fp);
				printf("Enter name of the book you want to search: ");
				scanf("%s",name);
				while((fread(&b,size,1,fp))==1)
				{
				       if(strcmp(b.name,name)==0)
					{
						printf("Book Name: %s\nBook Author: %s\nBook Quantities: %d\n",b.name,b.author,b.quantity);
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					printf("No records of the Books");
				}
				flag=0;
			}
			break;

		case 3:
			{
				rewind(fp);
				printf("Enter name of the book you want to modify: ");
				scanf("%s",name);
				t=fopen("C:\\temp.txt","w+");
				while((fread(&b,size,1,fp))==1)
				{

					if((strcmp(name,b.name))!=0)
					{
					  fwrite(&b,size,1,t);
					}

					if((strcmp(name,b.name))==0)
					{
						printf("Enter New Book name: ");
						scanf("%s",b.name);
						printf("Enter New Author name: ");
						scanf("%s",b.author);
						printf("Enter new Quantity: ");
						scanf("%d",&b.quantity);


					      //	fseek(fp,-size,SEEK_CUR);
						fwrite(&b,size,1,t);
						flag=1;

					}
				}
				if(flag==0)
				{
					printf("No records of the Books");
				}
				else
				{
					fclose(fp);
					fp=fopen("C:\\books.txt","w");
					rewind(t);
					while((fread(&b,size,1,t))==1)
					{
						fwrite(&b,size,1,fp);
					}
					fclose(fp);
					fp=fopen("C:\\books.txt","a+");
				}
				flag=0;
			}
			break;

		default:
			printf("Error");
	}
	getch();
	}while(choice!=4);
	fclose(fp);
	getch();


}