#include<iostream.h>
#include<conio.h>
//Program to Find the Mathematical constant e
//e = 1+1/1!+....
int fact(int no){
	  int fact=1;
      for(int j=1;j<=no;j++){
	   fact*=j;
      }
      //cout<<"fact "<<fact<<endl;
      return fact;
}
void main(){
	clrscr();
	int i,n;
	float e=1.0f;
	cout<<"Enter The value/limit ";
	cin>>n;

	for(i=1;i<=n;i++){
	     e+=(float)i/fact(i);
	}
		cout<<"e :"<<e<<endl;

	getch();

}