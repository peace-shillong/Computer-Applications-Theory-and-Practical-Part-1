#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
// avoiding buffer overflow

void main()
{
	const int MAX=15;
	char str[MAX];


	cout << "\nEnter a string ";
	cin >> setw(MAX) >> str;
	// maximum of MAX-1 character is inserted and '\0' is added

	cout << "You entered " << str;

}