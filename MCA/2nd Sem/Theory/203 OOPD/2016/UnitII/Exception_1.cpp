#include<iostream>


using std::cout;
using std::cin;
using std::endl;

#include<exception>

using std::exception;

class DivideByZeroException:public exception
{
	public:
		DivideByZeroException():exception("attempted  to divide by zero") {}
};

double quotient(int num,int deno) throw(DivideByZeroException)
{
		if(deno==0)
			throw DivideByZeroException();
		return ((double)num/deno);
}


int main()
{
	int num1;
	int num2;
	double result;

	cout << "Enter two integers : ";
	cin >> num1 >>num2;

	try{
		result=quotient(num1,num2);
		cout << endl<< "the quotient is " << result << endl;
	}
	catch(DivideByZeroException& e)
	{
			cout <<"Exception occurred " << e.what() <<endl;
	}
	return 0;
}
