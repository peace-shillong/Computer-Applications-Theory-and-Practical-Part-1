//Display Addition and Subtraction of Array
//Author K.Dkhar
//2015
//#include<string.h>
void add_arr(int a[10][10],int b[10][10],int,int);
void disp(int a[10][10],int,int);
void input(int a[10][10],int,int);
void sub_arr(int a[10][10],int b[10][10],int,int);
void main(){
	int r,c,i,list[10][10],list2[10][10];
	clrscr();
	printf("\n2D Array Program\nEnter The Number of Rows\n");
	scanf("%d",&r);
	printf("Enter No of Columns:\n");
	scanf("%d",&c);
	input(list,r,c);
	input(list2,r,c);
	add_arr(list,list2,r,c);
	sub_arr(list,list2,r,c);
	getch();
}
void input(int list[10][10],int r,int c){
	int i,j;
	printf("\nInput Into Array");
	for(i=0;i<r;i++){
	     for(j=0;j<c;j++){
		printf("\nEnter Element:");
		scanf("%d",&list[i][j]);
	     }
	}
}
void add_arr(int list[10][10],int list2[10][10],int r,int c){
	int i,j,sum[10][10];
	printf("\nAdding the Arrays\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			sum[i][j]=0;
		}
	}
	for(i=0;i<r;i++){
	     for(j=0;j<c;j++){
		sum[i][j]=list[i][j]+list2[i][j];
	     }
	}
	disp(sum,r,c);
}
void sub_arr(int list[10][10],int list2[10][10],int r,int c){
	int i,j,diff[10][10];
	printf("\nSubtracting the Arrays\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			diff[i][j]=0;
		}
	}
	for(i=0;i<r;i++){
	     for(j=0;j<c;j++){
		diff[i][j]=list[i][j]-list2[i][j];
	     }
	}
	disp(diff,r,c);
}
void disp(int list[10][10],int r,int c){
	int i,j;
	printf("\nDisplaying Array\n");
	for(i=0;i<r;i++){
	     for(j=0;j<c;j++){
		printf("\t %d ",list[i][j]);

	     }
	     printf("\n");
	}
}