#include<iostream>
#include<exception>
using namespace std;


class Inches{
private:
	int in;
public:
	Inches() {in=0;}
	Inches(int i)
	{
		in=i;
	}
	~Inches()
	{
		cout << "Inches desctructor called" << endl;
		
	}
};

class Integer{
private:
	int in;
public:
	Integer() {in=0;}
	Integer(int i)
	{
		in=i;
	}
	~Integer()
	{
		cout << "Integer desctructor called" << endl;
		throw exception();
		cout << "Integer desctructor completed" << endl;
		
	}
};

class Feet{
private :
	int ft;
	Inches in;
public:
	Feet(int f,int i):in(i)
	{
		cout <<"throwing exception from Feet" << endl;
		throw exception();
	}
	~Feet()
	{
		cout << " Feet destructor called " << endl;
	}
};


int main()
{
	try{
		Inches i1;
		Inches i[2];
		Feet ft(12,2);
	}
	catch(exception )
	{
		cout << "caught Constructor exception" << endl;
	}

	try{
		
		Integer *it=new Integer();
		delete it;
	}
	catch(exception )
	{
		cout << "caught Destructor exception" << endl;
	}

	return 0;
}

		