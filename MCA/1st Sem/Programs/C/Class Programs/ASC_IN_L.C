//Arrange in ascending order of all nos in list
//Author K.Dkhar
//2015
void ascend(int a[],int);
void main(){
	int nos[100],n,i;
	clrscr();
	printf("\n Arrange in Ascending order in a list\n Enter the Size\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter No:\n");
		scanf("%d",&nos[i]);
	}
	ascend(nos,n);
	getch();
}
void ascend(int a[],int n){

	int i,j;
	for(i=0;i<n-1;i++){
	for(j=i+1;j<n;j++){
	     if(a[i]>a[j]){
		a[j]+=a[i];
		a[i]=a[j]-a[i];
		a[j]-=a[i];
		}
	     }
	}
	for(i=0;i<n;i++)
	printf("\t %d",a[i]);
}