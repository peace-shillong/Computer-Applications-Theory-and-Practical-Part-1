//Display Elements of Diagonal
//Author K.Dkhar
//2015
//#include<string.h>
void disp_diag(int a[10][10],int,int);
void main(){
	int r,c,i,list[10][10];
	clrscr();
	printf("\nTo Display the Elements in th eDiagonal\nEnter The Number of Rows\n");
	scanf("%d",&r);
	printf("Enter No of Columns:\n");
	scanf("%d",&c);
	disp_diag(list,r,c);
	getch();
}
void disp_diag(int list[10][10],int r,int c){
	int i,j;
	//printf("\nEnter Elements");
	for(i=0;i<r;i++){
	     for(j=0;j<c;j++){
		printf("\nEnter Element:");
		scanf("%d",&list[i][j]);
	     }
	}
	printf("\t The diagonal elements in the matrix \n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(i==j)
				printf("\t %d",list[i][j]);
			else
				printf("\t");
		}
		printf("\n");
	}
}