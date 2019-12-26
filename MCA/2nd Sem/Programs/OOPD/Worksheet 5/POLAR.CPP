#include<iostream.h>
#include<conio.h>
#include<math.h>
class Polar;
class Rectangular{
	private:
		double x,y;
	public:
		Rectangular();
		Rectangular(double x1,double y1);
		double getX();
		double getY();
		Rectangular operator+(Rectangular);
		operator Polar();//from Rectangular to Polar
		void display();
};
Rectangular::Rectangular(){
	x = 0;
	y = 0;
}
Rectangular:: Rectangular(double x1, double y1){
	x = x1;
	y = y1;
}
double Rectangular::getX(){
	return x;
}
double Rectangular::getY(){
	return y;
}
class Polar{
	private:
		double radius;
		double angle;
	public:
		Polar();
		Polar(double r,double t);
		void setvalue();
		Polar operator+(Polar);
		double getradius();
		double getangle();
		operator Rectangular();//Polar to Rectangular
		void display();
}
Polar::Polar(){
	radius = 0;
	angle = 0;
}
Polar::Polar(double r,double t){
	radius = r;
	angle = t;
}
void Polar:: setvalue(){
	cout<<"\n\n\tPlease enter the radius:: ";
	cin>>radius;
	cout<<"\n\n\tPlease enter the angle:: ";
	cin>>angle;
}
double Polar:: getradius(){
	return(radius);
}
double Polar:: getangle(){
	return(angle);
}
void Rectangular::display(){
	cout<<"\n\n\tx = "<<x<<" y = "<<y<<endl<<endl;
}
void Polar:: display(){
	cout<<"\n\n\tradius = "<<radius<<" angle = "<<angle<<endl<<endl;
}
Polar Polar:: operator+(Polar p){
	Rectangular r1,r2,r3;
	r1 = *this;
	r1.display();
	r2 = p;
	r2.display();
	return Polar(r1+r2);
}
Rectangular Rectangular:: operator+(Rectangular r1){
	double x1,y1;
	x1 = x+r1.x;
	y1 = y+r1.y;
	return Rectangular(x1,y1);
}
Rectangular:: operator Polar(){//Rectangular to Polar
	double i,j,r,t;
	i = this->x;
	j= this->y;
	r = sqrt(i*i+j*j);
	if(i!=0)
		t = tan(j/i);
	return Polar(r,t);
}
Polar::operator Rectangular(){//Polar to Rectangular
	double i,j,r,t;
	r = this->radius;
	t = this->angle;
	i = r*cos(t);
	j = r*sin(t);
	return Rectangular(i,j);
}
void main(){
	clrscr();
	Polar p1,p2,p3;
	cout<<"\n\n\tPlese enter the 1st Polar co-ordinate: ";
	p1.setvalue();
	cout<<"\n\n\tPlease enter the 2nd Polar co-ordinate: ";
	p2.setvalue();
	cout<<"\n\n\tTwo Polar co-ordinates to be added are: ";
	p1.display();
	p2.display();
	p3 = p1+p2;
	p3.display();
	getch();
}