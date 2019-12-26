#include<iostream.h>
#include<conio.h>

void main(){
	clrscr();
	int i,space;
	space=9;
	for(i=0;i<9;i++){
		for(int j=1;j<=space;j++)
				cout<<" ";
		for(j=2;j<2*i;j++)
		if(j==2)
				cout<<"*";


		cout<<endl;space--;

	}

	space=1;
	for(i=0;i<9;i++){
		for(int j=1;j<=space;j++)
				cout<<" ";
		for(j=2;j<2*i;j++)
		//if(j==i+3)
				cout<<"*";


		cout<<endl;space--;

	}
		cout<<endl;


	getch();

}