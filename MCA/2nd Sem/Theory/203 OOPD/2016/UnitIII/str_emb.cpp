#include<iostream>
#include<string>


using namespace std;
// reading embedded blanks
//or reading multiword string

void main()
{
	const int MAX=20;
	char str[MAX];

	
	cout << "\nEnter a string ";
	//cin.get(str,MAX);   // multiword till newline is encountered
	// maximum of MAX-1 character is inserted and '\0' is added
	cin.get(str,MAX,'$');
	cout << "You entered " << str << endl;
	
}