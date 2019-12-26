//
#include<iostream.h>
#include<conio.h>
class Complex{
	double real,img;
	public:
		Complex();
		Complex(double,double);
		void setReal(double r);
		void setImg(double i);
		void setcomp(double r,double i);
	      //	void getReal();
	      //	void getImg();
		void add_comp(Complex,Complex);
		Complex sub_comp(Complex);
		void display();
};

void main(){
	double r,i;
	Complex c;
	Complex c1;
	Complex c2(4,4);
	clrscr();

	cout<<"Enter The First Complex No:\n";
	cout<<"Enter Real Part: ";
	cin>>r;
	cout<<"\nEnter the imaginary Part: ";
	cin>>i;
	c1.setReal(r);
	c1.setImg(i);
	cout<<"\nEnter The Second Complex No:\n";
	cout<<"Enter Real Part: ";
	cin>>r;
	cout<<"\nEnter the imaginary Part: ";
	cin>>i;
	c2.setReal(r);
	c2.setImg(i);
	cout<<"\nComplex Numbers are:\n";
	c1.display();
	c2.display();
	cout<<"\n\nAddition\n";
	c.add_comp(c1,c2);
	cout<<"\nResult\n";
	c.display();
	cout<<"\n\nSubtraction\n";
	//c1.display();
	//c2.display();
	cout<<"\nResult\n";
	c=c1.sub_comp(c2);
	c.display();
	getch();

}

Complex::Complex(){
	real=img=0;
}
Complex::Complex(double r,double i){
	real=r;img=i;
}

void Complex::setcomp(double x,double y)
{
	real=x;
	img=y;
}
void Complex::setReal(double x)
{
	real=x;
}
void Complex::setImg(double y)
{
	img=y;
}



void Complex::add_comp(Complex x,Complex y)
{
	real=x.real+y.real;
	img=x.img+y.img;
}
Complex Complex::sub_comp(Complex y)
{
	Complex t;
	t.real=real-y.real;
	t.img=img-y.img;
	return t;
}
void Complex::display()
{
	/*
	if(img>=0)
		cout<<endl<<"Complex No :"<<real<<"+"<<img<<"i";
	else
		cout<<endl<<"Complex No :"<<real<<img<<"i";
	*/
		cout<<endl<<"Complex No : ("<<real<<","<<img<<")";

}

