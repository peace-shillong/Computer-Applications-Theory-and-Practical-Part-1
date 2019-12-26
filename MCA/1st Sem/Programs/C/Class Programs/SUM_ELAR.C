//Total the Elements in an array
//Author K.Dkhar
//2015
//#include<string.h>
void total_elements(int a[10][10],int,int);
void main(){
	int r,c,i,list[10][10];
	clrscr();
	printf("\n Total the ele\nEnter The Number of Rows");
	scanf("%d",&r);
	printf("Enter No of Columns:\n");
	scanf("%d",&c);
	total_elements(list,r,c);
	getch();
}
void total_elements(int list[10][10],int r,int c){
	int i,j,total=0;
	//printf("\nEnter Elements");
	for(i=0;i<r;i++){
	     for(j=0;j<c;j++){
		printf("\nEnter Element:");
		scanf("%d",&list[i][j]);
		total+=list[i][j];
	     }


	}
	printf("\t The Total of all elements is %d",total);
}