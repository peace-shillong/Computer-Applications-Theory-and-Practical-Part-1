#include<iostream.h>
#include<conio.h>
//To encrypt a 4-digit no for a company

int d[4];
void swap(){
	int t;
	t=d[0];
	d[0]=d[2];
	d[2]=t;

	t=d[1];
	d[1]=d[3];
	d[3]=t;
}
void main(){
	long no,no1,t,r;
	int i=3;
	clrscr();
	cout<<"Enter a 4-digit Number: ";
	cin>>no;
	t=no;

	while(t>0){
		r=t%10;
		t=t/10;
	 //	rev=rev*10+r;
		d[i]=(r+7)%10;
		//cout<<d<<endl;
		i--;
	}
      //	cout<<no<<" "<<d[0];
	swap();
	cout<<"The Encrypted No: ";
	for(i=0;i<4;i++)
		cout<<d[i];

	cout<<endl<<"Enter The Encrypted Number ";
	cin>>no1;cout<<"Reenter: ";
	cin>>no1;
	//cout<<"GOT"<<no1;
	t=no1;
	i=3;
	while(t>0){
		r=t%10;
		t=t/10;
		d[i]=r;
		//cout<<d[i];
		i--;
	}
	cout<<""<<endl;
	//swap();
	//int t;
       /*	t=d[0];
	d[0]=d[2];
	d[2]=t;
	t=d[1];
	d[1]=d[3];
	d[3]=t;
	*/
	cout<<"The 4-digit No is ";
	for(i=0;i<4;i++){
		if(d[i]>7)
			d[i]=d[i]-7;
		else
			d[i]=(d[i]+3)%10;

	       //	cout<<d[i];
	}
	swap();
	/*int tt=d[0];
	d[0]=d[2];
	d[2]=tt;
	tt=d[1];
	d[1]=d[3];
	d[3]=tt;*/
	for(i=0;i<4;i++)
		cout<<d[i];


	getch();

}