#include<iostream.h>
#include<conio.h>

void main(){
	clrscr();
	int r,c,space,star=5;
	space=star-1;
	for(r=1;r<star-1;r++){
		//cout<<" ";
		//if(i%2==0){
			for(c=1;c<=space;c++){
				cout<<" ";
			}

			for(c=2;c<=2*r;c++)
				cout<<"*";

			cout<<endl;
			space--;
		}
		 for(r=1;r<=6;r++)
			cout<<"    *"<<endl;
		 //cout<<"*"<<endl;


		//cout<<endl;


	getch();

}