//Students Record
//K. Dkhar
//2015
struct dob{
	int date,year;
	char month[3];
};
struct student{
	int rollno;
	char name[20];
	char add[20];
	char department[20];
	struct dob d;

};
void display(struct student s[100], int i);
void main(){
	struct student s[100];int c,i=0;
	do{
	clrscr();
	printf("\n\tStudent Recoprds System\n");
	printf("Enter Student Information\n");
	printf("Enter Student's Roll No: \n");
	scanf("%d",&s[i].rollno);
	printf("Enter Student's Name: \n");
	scanf("%s",s[i].name);
	printf("Enter Student's Address\n");
	scanf("%s",s[i].add);
	printf("Enter Student's Department\n");
	scanf("%s",s[i].department);
	printf("Enter Student's Date of Birth:\nPress any key to start input\n");
	getch();
	printf("Enter the Date: \n");
	scanf("%d",&s[i].d.date);
	printf("Enter the First Three Letters of the Month: \n");
	scanf("%s",s[i].d.month);
	printf("Enter the Year\n");
	scanf("%d",&s[i].d.year);
	clrscr();
/*	printf("\n\n\t Displaying Students Information");
	printf("\n\tStudent's Roll No: %d",s[i].rollno);
	printf("\n\tStudent's Name: %s",s[i].name);
	printf("\n\tStudent's Address: %s",s[i].add);
	printf("\n\tStudent's Department: %s",s[i].department);
	printf("\n\tStudent's Date of bitrh: %d-%s-%d",s[i].d.date,s[i].d.month,s[i].d.year);
*/	printf("\n\nDo You want to continue?\nPress 1 to Continue\nPress 0 to exit.");
	scanf("%d",&c);
	i++;
	}while(c!=0);
	display(s,i);
/*	printf("\n\n\t Displaying Students Information");
	printf("\n\nRoll No\tName \tAddress\tDepartment\tDate of Birth ");
	for(c=0;c<i;c++){
	printf("\n%d\t%s\t%s\t%s\t%d-%s-%d\n",s[c].rollno,s[c].name,s[c].add,s[c].department,s[c].d.date,s[c].d.month,s[c].d.year);
	}
	*/
	getch();

}
void display(struct student s[100],int i){
	int c,n;
	n=i;
	printf("\n\n\t Displaying Students Information");
	printf("\n\nRoll No\t\tName \t\tAddress\t\tDepartment\tDate of Birth \n--------------------------------------------------\n");
	for(c=0;c<n;c++){
	printf("\n%d\t\t%s\t\t%s\t\t%s\t\t%d-%s-%d\n",s[c].rollno,s[c].name,s[c].add,s[c].department,s[c].d.date,s[c].d.month,s[c].d.year);
	}
}