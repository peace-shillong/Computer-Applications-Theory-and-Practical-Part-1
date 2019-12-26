//Multiply two Matrix
void main(){
	int a[10][10],b[10][10],m[10][10],i,j,k,c1,c2,r1,r2;
	clrscr();
	printf("Enter rows and Columns.");
	scanf("%d %d",&r1,&c1);
	printf("Enter rows and Columns.");
	scanf("%d %d",&r2,&c2);
	if(r2==c1){
		 for(i=0;i<r1;i++){
			for(j=0;j<c1;j++){
				scanf("%d",&a[i][j]);
			}
		 }
		 for(i=0;i<r2;i++){
			for(j=0;j<c2;j++){
				scanf("%d",&b[i][j]);
			}
		 }
		 for(i=0;i<r1;i++){
			for(j=0;j<c2;j++){
				m[i][j]=0;
			}
		 }
		for(i=0;i<r1;i++){
			for(j=0;j<c2;j++){
				for(k=0;k<c2;k++){
					m[i][j]+=a[i][k]*b[k][j];
				}

			}
		 }
		for(i=0;i<r1;i++){
			for(j=0;j<c2;j++){
				printf("\t%d",m[i][j]);
			}
			printf("\n");
		}
	}

	getch();
}
