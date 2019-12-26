//Program to store marks of student
struct Student{
	char name[20];
	int marks[3];
	float avg;
};
void main(){

	struct Student s[10];
	int n,i,j;
	char sname[20];
	float t;
	clrscr();
	printf("Enter No of Students (Max 10\n)");
	scanf("%d",&n);
	if(n>10)
		n=10;
	for(i=0;i<n;i++){
		s[i].avg=0;
		printf("Enter Students Name: ");
		scanf("%s",sname);
		strcpy(s[i].name,sname);
		for(j=0;j<3;j++){
			printf("Enter Marks %d: ",j+1);
			scanf("%d",&s[i].marks[j]);
			s[i].avg+=s[i].marks[j];
		}

		s[i].avg=s[i].avg/3;
	}
	for(i=0;i<n;i++)
		printf("%s \t%f \n",s[i].name,s[i].avg);

		printf("\n");
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
		if(s[i].avg<s[j].avg)
		{
			strcpy(sname,s[i].name);
			strcpy(s[i].name,s[j].name);
			strcpy(s[j].name,sname);
			t=s[i].avg;
			s[i].avg=s[j].avg;
			s[j].avg=t;
		}
		}
		//printf("%s \t%f \n",s[i].name,s[i].avg);

	}

	printf("TOP 5\n\n");
	for(i=0;i<5;i++)
	printf("%s \t%f \n",s[i].name,s[i].avg);


	getch();
}