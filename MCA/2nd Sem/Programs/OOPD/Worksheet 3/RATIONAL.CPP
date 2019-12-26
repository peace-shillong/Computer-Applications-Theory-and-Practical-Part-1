#include<iostream.h>
#include<conio.h>
class Rational
{
	int num,deno;
	public:
		Rational();
		Rational(float,float);
		void addition(Rational,Rational);
		Rational sub(Rational,Rational);
		void mul(Rational,Rational);
		void div(Rational,Rational);
		void print_fraction();
		void print_float();
		void reduce();
};
Rational::Rational()
{
	num=1;
	deno=2;
}
Rational::Rational(float a,float b)
{
	num=a;
	deno=b;
}
int hcf=1;
void main()
{
	clrscr();
	Rational r1(4,4),r2(16,5),r3;
	r3.addition(r1,r2);
	r3.reduce();
	r3.print_fraction();
	r3.print_float();
	r3.sub(r1,r2);
	//r3=sub(r1,r2);
	r3.reduce();
	r3.print_fraction();
	r3.print_float();
	r3.mul(r1,r2);
	r3.reduce();
	r3.print_fraction();
	r3.print_float();
	r3.div(r1,r2);
	r3.reduce();
	r3.print_fraction();
	r3.print_float();
	getch();
}
void Rational::addition(Rational a,Rational b)
{
	float n,lcm;
	int i;
	if(a.deno==b.deno)
	{
		deno=a.deno;
		num=a.num+b.num;
	}
	else
	{
			if(a.deno<b.deno)
				n=a.deno;
			else
				n=b.deno;
			for(i=1;i<=n;i++)
			{
				if((a.deno%i==0) && (b.deno%i==0))
					hcf=i;
			}
			lcm=a.deno*b.deno/hcf;
			deno=lcm;
			a.num=(lcm/a.deno)*a.num;
			b.num=(lcm/b.deno)*b.num;
			num=a.num+b.num;
	}
	cout<<"\nADDITION"<<endl;
}
Rational Rational::sub(Rational a,Rational b)
{
	Rational temp;
	float n,lcm;
	int i;
	if(a.deno==b.deno)
	{
		temp.deno=a.deno;
		temp.num=a.num-b.num;
	}
	else
	{
			if(a.deno<b.deno)
				n=a.deno;
			else
				n=b.deno;
			for(i=1;i<=n;i++)
			{
				if((a.deno%i==0) && (b.deno%i==0))
					hcf=i;
		     //			cout<<"hcf"<<hcf;
			}
			lcm=a.deno*b.deno/hcf;
			temp.deno=lcm;
			cout<<"LCM"<<lcm<<" "<<hcf;
			a.num=(lcm/a.deno)*a.num;
			b.num=(lcm/b.deno)*b.num;
			temp.num=a.num-b.num;
	}
		cout<<"\nSUBTRACTION"<<endl;
		return temp;
}
void Rational::mul(Rational a,Rational b)
{
	deno=a.deno*b.deno;
	num=a.num*b.num;
	cout<<"\nMULTIPLICATION"<<endl;

}
void Rational::div(Rational a,Rational b)
{
	deno=a.deno*b.num;
	num=a.num*b.deno;
	cout<<"\nDivision"<<endl;
}
void Rational::reduce()
{
	float a;
	if(num==deno)
	{
		deno=1;
		num=1;
	}
       /*	else if(num<deno && deno%num==0 )
	{
		a=num;
		num=num/a;
		deno=deno/a;
	}
	else if(num>deno  && num%deno==0 )
	{
		a=deno;
		num=num/a;
		deno=deno/a;
	}
	else
	{
		num=num/hcf;
		cout<<"HCF"<<hcf<<endl;
		deno=deno/hcf;
	}*/
	int min,i;

	if(num<deno)
		min=num;
	else
		min=deno;

	for(i=min;i>=2;i--)
	{
		if((num%i==0)&&(deno%i==0))
		{
			num=num/i;
			deno=deno/i;
		}
	}


}
void Rational::print_fraction()
{
	cout<<"Fraction Format"<<endl;
	cout<<num<<"/"<<deno<<endl;
}
void Rational::print_float()
{
	float f;
	cout<<"Floating Format"<<endl;
	f=(float)num/deno;
	cout<<f;
}
