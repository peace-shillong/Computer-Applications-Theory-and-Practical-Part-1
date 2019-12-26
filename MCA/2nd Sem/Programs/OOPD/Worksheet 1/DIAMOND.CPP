#include<iostream.h>
#include<conio.h>
void main(){
	clrscr();
	int z=1;
	int i,j,k;
	for(i=0;i<=5;i++){
		for(j=5;j>i;j--)
			cout<<" ";
		cout<<"*";
		if(i>0){
			for(k=1;k<=z;k++)
				cout<<" ";
			z+=2;
			cout<<"*";
		}
		cout<<endl;
	}
	z-=4;
	for(i=0;i<=4;i++){
		for(j=0;j<=i;j++)
			cout<<" ";
		cout<<"*";
		for(k=1;k<=z;k++)
			cout<<" ";
		z-=2;
		if(i!=4)
			cout<<"*";
		cout<<endl;
	}
	getch();
}