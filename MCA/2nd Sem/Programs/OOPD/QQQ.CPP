#include<iostream.h>
#include<conio.h>
//PROGRAM TO CONVERT TEMPERATURE
class Centi{
	private:
		float temp;
	public:
		Centi();
		Centi(float);
//		Centi operator<<(Centi&);
		friend ostream& operator<<(ostream&,Centi&);
		friend class Fahren;
		Centi(Fahren);
};

class Fahren{
	private:
		float ftemp;
	public:
		Fahren();
		Fahren(float);
		float getT();
		friend class Centi;
		friend ostream& operator<<(ostream&,Fahren&)
		Fahren(Centi);
};
void main(){
	Centi C;
	Fahren F;
	float t;
	int ch;
	do{
	clrscr();
	cout<<"\n Program on Temperature.(Centigrade and Fahrenheit)";
	cout<<"\n MENU \n 1. Enter The Temperature in Fahrenheit";
	cout<<"\n 2. Enter Temperature in Centigrade.";
	cout<<"\n 3. Display The Entered Temperature.";
	cout<<"\n 4. Convert Temperature from Fahrenheit to Centigrade.";
	cout<<"\n 5. Convert Temperature from Centigrade to Fahrenheit";
	cout<<"\n 6. Exit";
	cout<<"\n Enter Your Choice.";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"\n Enter Temperature in Fahrenheit:\n";
			cin>>t;
			F=t;
			break;
		case 2:
			cout<<"\n Enter Temperature in Centigrade:\n";
			cin>>t;
			C=t;
			break;
		case 3:
			cout<<"\n Entered Temperature in Fahrenheit is ";
			cout<<endl<<F;
			cout<<"\n Entered Temperature in Centigrade is ";
			cout<<endl<<C;
			break;
		case 4:
			cout<<"\n Temperature in Fahrenheit is ";
			cout<<F;
			C=F;
			cout<<"\n Temperature in Centigrade is ";
			cout<<C;
			break;
		case 5:
			cout<<"\n Temperature in Centigrade is";
			cout<<C;
			F=C;
			cout<<"\n Temperature in Fahrenheit is";
			cout<<F;
			break;
		case 6:
			cout<<"Program will Exit.";
			break;
		default:
			cout<<"\nInput Error";
			break;
	}
	getch();
	}while(ch!=6);
	//cout<<C;
	getch();
}

Centi::Centi(){
	temp=0.0f;
}
Centi::Centi(float f){
	temp=f;
}
Centi::Centi(Fahren f){
	//cout<<"F Temp "<<f.ftemp;
	float te=(float)5/(float)9;
	this->temp=(f.ftemp-32)*te;
	//cout<<" C t "<<this->temp;
}
Fahren::Fahren(){
	ftemp=0.0f;
}
Fahren::Fahren(float f){
	ftemp=f;
}
Fahren::Fahren(Centi c){

	ftemp=c.temp*((float)9/(float)5)+32;
       //	cout<<"C in F "<<ftemp;

}
/*operator<<(ostream& o,Centi& C){
	Centi C2;
	C2.temp=C.temp;
	 o<<"\n C opt "<<C2.temp;
	 getch();
	 return 0;
} */
ostream& operator<< (ostream &o, Centi& C){
    o<<"\n ";
    o<<C.temp<<" C";
    return o;
}
ostream& operator<<(ostream& a,Fahren& F){
	 a<<" \n "<<F.ftemp<<" F";
	 return a;
}


float Fahren::getT(){
	return ftemp;
}