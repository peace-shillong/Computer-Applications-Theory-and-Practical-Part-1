//DYNAMIC ARRAY TO HOLD RECORD OF STUDENTS AND DISPLAY BASED ON MERIT
//Author K.Dkhar
//2015

void input( char a[100][20],int marks[100][3],float avg[100],float top[5],int);
void main(){
	int no;
	float avg[100],top[5]={0,0,0,0,0};
	int marks[100][3];
	char list[100][20];
	clrscr();
	printf("\n Program for Students Record\nEnter The Number of Students\n");
	scanf("%d",&no);
	input(list,marks,avg,top,no);
//	comp(list,no);
	getch();
}
void input(char list[100][20],int marks[100][3],float avg[100],float top[5],int no){
	int i,j,t;
	printf("\nInput Into Record");
	for(i=0;i<no;i++){
		printf("\nEnter Students Name: ");
		scanf("%s",(list+i));

	     }
	//Getiing Input and finding avg
	for(i=0;i<no;i++){
	avg[i]=0;
	for(j=0;j<3;j++){
	//	printf("%s",(list+j));
		marks[i][j]=0;
		printf("Enter Marks subject %d : ",j);
		scanf("%d",marks[i][j]);
		avg[i]+=marks[i][j];
	}
	avg[i]=avg[i]/3;
       }
       for(i=0,j=0;i<no-1;i++){
//       printf("\t Avg %f");
		if(avg[i]>avg[i+1]){
		       //	top[j]=i+1;
		       //	j++;
		}
		else{
			t=avg[i+1];
			avg[i]=avg[i+1];
			avg[i+1]=t;

		       //	top[j]=i;
		       //	j++;
		}
       }
       for(i=0;i<5;i++){

		printf("Position of Top is %f\n",top[i]);
       }
}