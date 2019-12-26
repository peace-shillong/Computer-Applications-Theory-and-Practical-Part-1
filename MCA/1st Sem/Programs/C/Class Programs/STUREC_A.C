//Program to store marks of student using array
/*struct Student{
	char name[20];
	int marks[3];
	float avg;
};*/
void main(){

       //	struct Student s[10];
	int n,i,j;
	int marks[10][3];
	float avg[10];
	char sname[10][20],temp[20];
	float t;
	clrscr();
	printf("Enter No of Students (Max 10\n)");
	scanf("%d",&n);
	if(n>10)
		n=10;
	for(i=0;i<n;i++){
		//s[i].avg=0;
		avg[i]=0;
		printf("Enter Students Name: ");
		scanf("%s",sname[i]);
		//strcpy(s[i].name,sname);
		for(j=0;j<3;j++){
			printf("Enter Marks %d: ",j+1);
			scanf("%d",&marks[i][j]);//&s[i].marks[j]);
			avg[i]+=marks[i][j];
			//s[i].avg+=s[i].marks[j];
		}

		 avg[i]=avg[i]/3;
		//s[i].avg=s[i].avg/3;
	}
	for(i=0;i<n;i++)
		printf("%s \t%f \n",sname[i],avg[i]);//s[i].name,s[i].avg);

		printf("\n");
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
		if(avg[i]<avg[j])//s[i].avg<s[j].avg)
		{
			strcpy(temp,sname[i]);
			strcpy(sname[i],sname[j]);
			strcpy(sname[j],temp);
			t=avg[i];
			avg[i]=avg[j];
			avg[j]=t;
		}
		}
		//printf("%s \t%f \n",s[i].name,s[i].avg);

	}

	printf("TOP 5\n\n");
	for(i=0;i<5;i++)
	if(i<n)
	printf("%s \t%f \n",sname[i],avg[i]);


	getch();
}