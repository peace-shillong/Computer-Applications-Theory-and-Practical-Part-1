#include<iostream.h>
#include<conio.h>

class Rational
{
	int nu;
	int de;

	public:

	Rational();
	Rational(int,int);
	Rational mul(Rational);
	void view_float();
	void view_rat();
	void red();
	void add(Rational,Rational);
	void sub(Rational,Rational);
	void div(Rational,Rational);

};

Rational::Rational()
{
	nu=1;
	de=1;
}

Rational::Rational(int n,int d)
{

	nu=n;
	de=d;

	red();
}

void main()
{
	clrscr();
	Rational r1,r2,r3;

	r1=Rational(20,40);
	r2=Rational(5,20);

	cout<<"Rational: "<<endl<<endl;
	r1.view_rat();
	r2.view_rat();

	cout<<"Float: "<<endl<<endl;
	r1.view_float();
	r2.view_float();

	cout<<"multiplying: ";
	r3=r1.mul(r2);
	r3.view_rat();

	cout<<"Addition: ";
	r3.add(r1,r2);
	r3.view_rat();

	cout<<"Substraction: ";
	r3.sub(r1,r2);
	r3.view_rat();

	cout<<"Division: ";
	r3.div(r1,r2);
	r3.view_rat();

	getch();
}

void Rational::view_rat()
{
	cout<<nu<<"/"<<de<<endl<<endl;
}

void Rational::view_float()
{
	cout<<(float)nu/de<<endl<<endl;
}


Rational Rational::mul(Rational y)
{
	Rational b;

	b.nu=nu*y.nu;
	b.de=de*y.de;
	b.red();

	return b;
}

void Rational::red()
{

	int s,i;

	if(nu<de)
		s=nu;
	else
		s=de;

	for(i=s;i>=2;i--)
	{
		if((nu%i==0)&&(de%i==0))
		{
			nu=nu/i;
			de=de/i;
		}
	}

}



void Rational::add(Rational a,Rational b)
{
	float n,hcf,lcm;
	int i;
	if(a.de==b.de)
	{
		de=a.de;
		nu=a.nu+b.nu;
	}
	else
	{
			if(a.de<b.de)
				n=a.de;
			else
				n=b.de;
			for(i=1;i<=n;i++)
			{
				if((a.de%i==0) && (b.de%i==0))
					hcf=i;
			}
			lcm=a.de*b.de/hcf;
			de=lcm;
			a.nu=(lcm/a.de)*a.nu;
			b.nu=(lcm/b.de)*b.nu;
			nu=a.nu+b.nu;
	}
	Rational::red();
}
void Rational::sub(Rational a,Rational b)
{
	float n,hcf,lcm;
	int i;
	if(a.de==b.de)
	{
		de=a.de;
		nu=a.nu-b.nu;
	}
	else
	{
			if(a.de<b.de)
				n=a.de;
			else
				n=b.de;
			for(i=1;i<=n;i++)
			{
				if((a.de%i==0) && (b.de%i==0))
					hcf=i;
			}
			lcm=a.de*b.de/hcf;
			de=lcm;
			a.nu=(lcm/a.de)*a.nu;
			b.nu=(lcm/b.de)*b.nu;
			nu=a.nu-b.nu;
	}
	Rational::red();
}

void Rational::div(Rational a,Rational b)
{
	de=a.de*b.nu;
	nu=a.nu*b.de;
	Rational::red();
}
