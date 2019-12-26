#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<iomanip.h>

//using namespace std;
// avoiding buffer overflow

void main()
{
	const int MAX=5;
	char str[MAX];
	char s2[MAX];

	clrscr();
	cout << "\nEnter a string ";
	cin.get(str,MAX);
//	cin >> setw(MAX) >> str;
	// maximum of MAX-1 character is inserted and '\0' is added

	cout << "You entered " << str;
	cin.ignore(MAX,'\n');
	cout << "\nEnter a string ";
	cin.get(s2,MAX);
  //	cin >> setw(MAX) >> s2;

	cout << "You entered " << s2;


}