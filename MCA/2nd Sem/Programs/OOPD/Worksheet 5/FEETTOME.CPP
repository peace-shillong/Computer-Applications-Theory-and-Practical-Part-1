#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class Feet
{
	double feet;
	public:
		Feet();
		Feet(double);
		void inputFeet();
		double getFeet();
		void displayFeet();
		friend class Metre;
};
Feet::Feet()
{
	feet=0.0;
}
Feet::Feet(double f)
{
	feet=f;
}
void Feet::inputFeet()
{
	cout<<"Enter feet:";
	cin>>feet;
}
double Feet::getFeet()
{
	return feet;
}
void Feet::displayFeet()
{
	cout<<"Feet="<<feet;
}
class Metre
{
	double metre;
	public:
		Metre();
		Metre(double);
		void inputMetre();
		double getMetre();
		void displayMetre();
		Metre(Feet);         //feet to meter
		operator Feet();   //metre to feet
};
Metre::Metre()
{
	metre=0.0;
}
Metre::Metre(double m)
{
	metre=m;
}

void Metre::inputMetre()
{
	cout<<"Enter metre:";
	cin>>metre;
}
double Metre::getMetre()
{
	return metre;
}
void Metre::displayMetre()
{
	cout<<"Metre="<<metre;
}
Metre::Metre(Feet f)
{
	metre=f.feet/3.28;
}
Metre::operator Feet()
{
	return(Feet(metre*3.28));
}
void main()
{
	int s;
	char ch;
	Metre m;
	Feet f;
	clrscr();
	do
	{
		cout<<"1. Feet to metre"<<endl;
		cout<<"2. Metre to feet "<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"enter choice:";
		cin>>s;
		clrscr();
		switch(s)
		{
			case 1: f.inputFeet();
				f.displayFeet();
				m=f;
				cout<<"Metre="<<m.getMetre();
				break;
			case 2: m.inputMetre();
				m.displayMetre();
				f=m;
				cout<<"feet="<<f.getFeet();
				break;
			case 3: exit(1);
			default:cout<<"Invalid choice";
		}
		cout<<endl;
		cout<<"Do you wish to continue(Y/N)?:";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	getch();
}

