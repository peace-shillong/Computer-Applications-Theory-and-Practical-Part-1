//Biggest of all nos in list
//Author K.Dkhar
//2015
void biggest(int a[],int);
void main(){
	int nos[100],n,i;
	clrscr();
	printf("\n Find Biggest Number in a list\n Enter the Size\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter No:\n");
		scanf("%d",&nos[i]);
	}
	biggest(nos,n);
	getch();
}
void biggest(int a[],int n){

	int i,big=a[0];
	for(i=0;i<n;i++){
	     if(a[i]>big)
		big=a[i];
	}
	printf("\nThe Biggest no is : %d",big);
}