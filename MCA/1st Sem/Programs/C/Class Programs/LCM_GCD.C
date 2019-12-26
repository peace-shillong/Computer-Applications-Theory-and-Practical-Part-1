//Program to Find LCM and GCD
//2015
//author K.Dkhar
//lcm=(n1*n2)/hcf

void main(){

	int n,n1,t,t1,i,b,hcf,lcm;
	clrscr();
	printf("Enter Two Numbers:");
	scanf("%d %d",&n,&n1);
	t=n;t1=n1;
	if(n>n1)
		b=n;
	else
		b=n1;
	hcf=1;
	for(i=2;i<b;i++){

		if((n%i==0) && (n1%i==0)){
			hcf=i;
			n=n/i;
			n1=n1/i;
		}
	}
	printf("GCD: %d",hcf);
	//LCM
	lcm=hcf*n*n1;
	//lcm=(t*t1)/hcf;
	printf("\nLCM: %d",lcm);
	getch();
}