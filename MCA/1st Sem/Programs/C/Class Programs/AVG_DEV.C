//Average and Deviation of nos
//Author K.Dkhar
//2015
void avg_dev(int a[],int);
void main(){
	int nos[100],n,i;
	clrscr();
	printf("\n Find Average and Deviation \n Enter the Limit\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter No:\n");
		scanf("%d",&nos[i]);
	}
	avg_dev(nos,n);
	getch();
}
void avg_dev(int a[],int n){
	float avg,dev;
	int i,sum=0;
	for(i=0;i<n;i++){
	     sum+=a[i];
	}
	avg=(float)sum/n;
	printf("\nThe Average is : %f",avg);
	for(i=0;i<n;i++){
		dev=a[i]-avg;
		printf("\n Deviation of %d from %f is %f",a[i],avg,dev);
	}
}