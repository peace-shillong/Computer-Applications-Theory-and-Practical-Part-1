//Total the Elements in a row of a 2d array
//Author K.Dkhar
//2015
//#include<string.h>
void total_elements_row(int a[10][10],int,int);
void main(){
	int r,c,i,list[10][10];
	clrscr();
	printf("\n Total the elements of array in a row\nEnter The Number of Rows\n");
	scanf("%d",&r);
	printf("Enter No of Columns:\n");
	scanf("%d",&c);
	total_elements_row(list,r,c);
	getch();
}
void total_elements_row(int list[10][10],int r,int c){
	int i,j,total[10];
	//printf("\nEnter Elements");
	for(i=0;i<r;i++){
		total[i]=0;
	     for(j=0;j<c;j++){
		printf("\nEnter Element:");
		scanf("%d",&list[i][j]);
		total[i]+=list[i][j];
	     }


	}
	printf("\t The Total of all elements in a row \n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
		printf("\t %d",list[i][j]);
		}
		printf("\t=\t%d \n",total[i]);
	}
}