#include<iostream>


using std::cout;
using std::cin;
using std::endl;

#include<exception>
using std::exception;

#include<new>
using std::bad_alloc;




int main()
{
	
	double *ptr[500];
	
	try{
		
		for(int i=0;i<500;i++)
		{
			ptr[i]=new double[50000000];
			cout <<endl<< "allocated 50000000 doubles in ptr[" <<i<<"]";
		}
	}
	catch(bad_alloc& e)
	{
			cout <<"Exception occurred "  <<e.what()<<endl;
	}
	cout << "program continues after catching in main " <<endl;
	return 0;
}
