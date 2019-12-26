//Display Matrix of 1's and 0's with its Complement
//Author K.Dkhar
//2015
//#include<string.h>
void comp(int a[10][10],int,int);
void disp(int a[10][10],int,int);
void input(int a[10][10],int,int);
void main(){
	int r,c,i,list[10][10],list2[10][10];
	clrscr();
	printf("\n2D Array Program\nEnter The Number of Rows\n");
	scanf("%d",&r);
	printf("Enter No of Columns:\n");
	scanf("%d",&c);
	input(list,r,c);
	comp(list,r,c);
	input(list2,r,c);
	comp(list2,r,c);
	getch();
}
void input(int list[10][10],int r,int c){
	int i,j,t;
	printf("\nInput Into Matrix");
	for(i=0;i<r;i++){
	     for(j=0;j<c;j++){
		printf("\nEnter 0 or 1:");
		scanf("%d",&t);
		if(t==0)
			list[i][j]=t;
		else
		list[i][j]=1;
	     }
	}
}
void comp(int list[10][10],int r,int c){
	int i,j;
	printf("\nDisplaying Complement of the Matrix\n");
	for(i=0;i<r;i++){
	     for(j=0;j<c;j++){
		if(list[i][j]==0)
			printf("\t 1 ");
		else
			printf("\t 0 ");
	     }
	     printf("\n");
	}
}