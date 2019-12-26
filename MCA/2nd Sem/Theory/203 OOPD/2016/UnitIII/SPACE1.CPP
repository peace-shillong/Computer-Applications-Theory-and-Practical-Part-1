#include<iostream.h>
#include<conio.h>

class space
{
	private:
		int a,b;
	public:
		space(): a(0),b(0) {}
		space(int,int);
		void show();
		void operator -();
};

space::space(int x,int y)
{
	a=x; b=y;
}
void space::show()
{
	cout << endl << "a = " <<a;
	cout << endl << "b = " <<b;
}

void space::operator-()
{
	a=-a;
	b=-b;
}

void main()
{
	space x(3,4);
	clrscr();
	cout << endl << "before -";
	x.show();
	-x;
	cout << endl << "after -";
	x.show();
	getch();
}
