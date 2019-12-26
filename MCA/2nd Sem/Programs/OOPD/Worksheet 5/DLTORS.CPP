#define euro_val 0.82
#define dol_val 46.49
#include<iostream.h>
#include<conio.h>
class Euro;
class Dollar;
class Rupee
{
	double rs;
	public:
		Rupee(double);
		void getRupee();
		double getValue();
		Rupee();
		Rupee(Dollar  d); //Dollar to Rupees
		Rupee(Euro e);    //Euro to Rupees
		operator Dollar(); //Rupees to Dollar
		operator Euro();  //Rupees to Euro

};
class Dollar
{
	double dol;
	public:
		Dollar();
		Dollar(double);
	       //	operator Rupee();
		void getDollar();
		double getValue();
};
class Euro{
	double euro;
	public:
		Euro();
		Euro(double);
		Euro(Rupee);
		operator Dollar();
		//operator Rupee();
		Euro(Dollar);
		void getEuro();
		double getValue();
};
void main()
{
	clrscr();
	Dollar d1(4);
	cout<<"Dolar Value:\n";
	d1.getDollar();
	cout<<endl;
	Rupee r1;
	r1=d1;
	cout<<"In Rupees \n";
	r1.getRupee();
	cout<<endl;
	Euro e(4);
	e=d1;
	cout<<"In Euro \n";
	r1.getRupee();
	Euro e1(4);
	cout<<"\nEuro Value:\n";
	e1.getEuro();
	cout<<endl;
	d1=e1;
	cout<<"In Dollars:\n";
	d1.getDollar();
	r1=d1;
	cout<<"In Rupees: \n";
	r1.getRupee();
	cout<<endl;

	getch();
}
Euro::Euro(double e){
	euro=e;
}
Euro::Euro(){
	euro=0;
}
void Euro::getEuro(){
	cout<<"Currency Value is : E "<<euro;
}
double Euro::getValue(){
	return euro;
}
Euro::operator Dollar(){
	double er=euro*euro_val;
	return (Dollar(er));
}
/*Euro::operator Rupee(){
	double rs=(euro*euro_val)*dol_val;
	return (Rupee(rs));
}*/
Euro::Euro(Rupee r){
	euro = (r.getValue()*dol_val)*(euro_val);
}
Euro::Euro(Dollar d)
{
	euro = d.getValue()*(euro_val);
}
Dollar::Dollar(){
	dol=0;
}
Dollar::Dollar(double d){
	dol=d;
}
void Dollar::getDollar(){
	cout<<"Currency Value is : $ "<<dol;
}
double Dollar::getValue(){
	return dol;
}
/*
Dollar::operator Rupee(){
	double rs= dol * dol_val;
	return (Rupee(rs) );
}*/
Rupee::Rupee(){
	rs=0;
}
Rupee::Rupee(double r){
	rs=r;
}
void Rupee::getRupee(){
	cout<<"Currency Value is : Rs "<<rs;
}
double Rupee::getValue(){
	return rs;
}
Rupee::Rupee(Dollar d)
{
	rs = d.getValue()*(dol_val);
}
Rupee::Rupee(Euro e)
{
	rs = e.getValue()*(56.6951);
}
Rupee::operator Euro()
{
	Euro e;
       //	t = rupees*(0.0176);
	return e;
}
Rupees::operator Dollar()
{
	Dollar d;
	d.dollar = rupees*(0.0215);
	return d;
}
