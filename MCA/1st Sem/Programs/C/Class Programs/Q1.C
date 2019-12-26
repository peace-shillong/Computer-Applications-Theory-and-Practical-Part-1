//Q1
#include<stdio.h>
#include<conio.h>
#include<string.h>
//Exam01
struct emp{
	int id,age;
	char name[100],city[100];
	char salary[20];
	//double salary;
	//float and double does not work

}emp1[50];

void main(){
	int i,j,ch;
	char name[100],city[100];
	i=0;
	clrscr();
	do{
		clrscr();
		printf("\n\n\t\tMENU\n");
		printf("\n\t1.Add Records.");
		printf("\n\t2.Display Records");
		printf("\n\t3.Exit\n\t");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter Employee id: ");
				scanf("%d",&emp1[i].id);
				printf("\nEnter Employee Name: ");
				//gets(name);
				gets(name);
				scanf("%s",emp1[i].name);
				//strcpy(emp1[i].name,name);
				printf("\nEnter Employee Age: ");
				scanf("%d",&emp1[i].age);
				printf("\nEnter Employee City: ");
				//gets(city);
				//strcpy(emp1[i].city,name);
				scanf("%s",emp1[i].city);
				printf("\nEnter Employee salary: ");
				scanf("%s",emp1[i].salary);
				//scanf("%f",&emp1[i].salary);
				i++;
				break;
			case 2:
				printf("\n \tEmployee Details: ");
				printf("\n\tid\tName\tAge\tCity\tSalary\n\n");
				for(j=0;j<i;j++){
					printf("\n\t%d\t%s\t%d\t%s\t%s",emp1[j].id,emp1[j].name,emp1[j].age,emp1[j].city,emp1[j].salary);
				}
				getch();
				break;
			case 3:
				printf("\nPress any key to exit");
				break;
			default:
				printf("Re-enter your Choice.");
		}
	}while(ch!=3);
	fflush(stdin);
	getch();
}