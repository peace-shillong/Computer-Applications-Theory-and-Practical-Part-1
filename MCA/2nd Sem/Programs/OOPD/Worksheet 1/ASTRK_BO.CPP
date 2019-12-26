#include<iostream.h>
#include<conio.h>

void main(){
	clrscr();
	int i,flag=0;
	for(i=0;i<9;i++){
		if(i==0 || i==8){
		     flag=0;
		}
		else{
			flag=1;
		}
		for(int j=0;j<9;j++){
			if(flag==0)
			      cout<<"*";
			else{
				if(j==0 || j==8)
					cout<<"*";
				else
					cout<<" ";
			}
			//cout<<"*";

		}
		cout<<endl;

	}
	getch();

}