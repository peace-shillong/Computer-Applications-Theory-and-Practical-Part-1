#include<iostream.h>
#include<conio.h>
//use of unary -
class space
{
	private:
		int a,b;
	public:
		space(): a(0),b(0) {}
		space(int,int);
		void show();
		space operator -();
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

space space::operator-()
{
	return space(-a,-b);

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
	x.show();
	getch();
}
