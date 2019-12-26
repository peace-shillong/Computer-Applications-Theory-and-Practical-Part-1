#include<iostream.h>
#include<conio.h>
#include<string.h>
class string1
{
	private:
		char *s;
		int size;
	public:
		string1();
		string1(char *str);
		string1(const string1 &str);
		~string1();
		void concat(string1 scc);
		void copy(string1 scp);
		void display();
};
string1 :: string1()
{
	size=1;
	s=new char[size];
	s[0]='\0';
}
string1 :: string1(char *str)
{
// cout<<"constructor overloaded"<<endl;
 size=strlen(str)+1;
 str=new char[size];
 strcpy(s,str);
}
//copy constructor
string1::string1(const string1 & str)
{
	s=new char[strlen(str.s)+1];
	strcpy(s,str.s);
}
string1::~string1()
{
	delete []s;
}
void string1 :: copy(string1 scp)
{
	delete[]s;
	size=strlen(scp.s)+1;
	s=new char[size];
	strcpy(s,scp.s);
}

void  string1 :: concat(string1 scc)
{
	int l;
	l=strlen(s)+strlen(scc.s);
	char *t=new char[l+1];
	strcpy(t,s);
	strcat(t,scc.s);
	delete[]s;
	s=t;
}

void string1 :: display()
{
	cout<<s;
}

void main()
{
	string1 s1,s2("hello"),s3("world"),s4;
	clrscr();
//	s1.display();

	s4.copy(s2);
	s4.display();
      //	s4.concat(s3);
       //	s4.display();
	getch();
}