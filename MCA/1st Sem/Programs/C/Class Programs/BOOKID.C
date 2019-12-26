#include<stdio.h>
#include<conio.h>
struct book
{
   int id ;
   char name[20],author[20],publisher[20];
   int quantity,edition;

};
void main()
{
	struct book s[50];
	int i,n,id;
	FILE *fp;
	fp=fopen("Z:\\Books.Txt","w+");
	clrscr();
	printf("Book Information System\nEnter the number of entries  you want :\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	 printf("Enter the ID number :\n");
	 scanf("%d",&s[i].id);
	 printf("Enter the name of the Book:\n");
	 scanf("%s",s[i].name);
	 printf("Enter the Author : \n");
	 scanf("%s",s[i].author);
	 printf("Enter the publisher of book :\n");
	 scanf("%s",s[i].publisher);
	 printf("Enter the quantity of book:\n");
	 scanf("%d",&s[i].quantity);
	 printf("Enter the edition of book :\n");
	 scanf("%d",&s[i].edition);

	 fwrite(s,sizeof(s),1,fp);
	 }
	 fseek(fp,0,SEEK_SET);
	 do
		{
		 printf("\nSearching for a book:\n Enter book id : else enter 0 to exit");
		 scanf("%d",&id);
	  //	printf("\n\nName\t ID\t Author \t Quantity\t Edition \t Publisher \n");
		fread(&s,sizeof(s),1,fp);
		//printf("%d %d",s[0].id,s[1].id);
		 for(i=0;i<n;i++)
			{
			if(id==0)
			break;
			if(s[i].id==id)
			printf("%s\t%d\t%s\t\%d\t\t\%d\t\t%s\n",s[i].name,s[i].id,s[i].author,s[i].quantity,s[i].edition,s[i].publisher);
			}
		//rewind(fp);
		}
	 while(id!=0);
	 getch();
 }


