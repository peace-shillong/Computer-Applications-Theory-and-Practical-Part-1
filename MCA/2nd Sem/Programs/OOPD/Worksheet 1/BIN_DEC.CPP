#include<iostream.h>
#include<conio.h>
#include<math.h>
//To convert given binary no t oequivalent decimal nomber
void main(){
	long no,t;
	int dec=0,i=0,p=0,r;
	clrscr();
	cout<<"Enter a Bunary Number: "<<endl;
	cin>>no;
	t=no;
	while(t>0){
		r=t%10;
		t=t/10;
		//rev=rev*10+r;
		p=pow(2,i);
		cout<<p;
		cout<<r;
		dec=dec+(p*r);
		cout<<"dec"<<dec<<endl;
		i+=1;
	}
//	cout<<no<<" "<<rev;

	cout<<endl<<no<<"Decimal :"<<dec;
	getch();

}