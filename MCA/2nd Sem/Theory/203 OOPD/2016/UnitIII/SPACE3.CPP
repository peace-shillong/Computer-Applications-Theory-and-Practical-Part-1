#include<iostream.h>
#include<conio.h>
//use of unary - with friend function
class space
{
	private:
		int a,b;
	public:
		space(): a(0),b(0) {}
		space(int,int);
		void show();
		friend space operator -(space&);
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

space operator-(space &s)
{
	return space(-s.a,-s.b);

}

void main()
{
	space x(3,4);
	clrscr();
	cout << endl << "before -";
	x.show();
	space y=-x;
	cout << endl << "after - and assigning to y";
	y.show();
	getch();
}
