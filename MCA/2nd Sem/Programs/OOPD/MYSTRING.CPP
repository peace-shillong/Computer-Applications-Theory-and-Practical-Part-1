#include<iostream.h>
#include<conio.h>
class MyString{
	char *ch;
	int size;
	public:
		MyString();
		MyString(int );
		void setsize(int s);
		void setstring();
		void display();
		void copy(MyString);
		MyString copy2(MyString);
		~MyString();
};

MyString::MyString(){
	size=1;
	ch=new char[size];
}
MyString::MyString(int s){
	size=s;
	ch=new char[size];
}
MyString::~MyString(){
	delete []ch;
}

void main(){
	MyString s1(5),s2,s3;
	clrscr();
       /*	int s;
	clrscr();
	cout<<"Enter your String Length: ";
	cin>>s;
	if(s<0 && s>32500){
		s=10;
		cout<<"String Default Size is 10";
	}
	s1.setsize(s);*/
	s1.setstring();
	s1.display();
	cout<<"\n Copying the Above String to Another String";
	s2.copy(s1);
	//s2=s2.copy2(s1);
	//cout<<"\n Second String is ";
	s2.display();

      //	s3=s3.copy2(s1);
      //	s3.display();
	getch();
}

void MyString::setsize(int s){
	size=s;
}
void MyString::setstring(){
	//ch=new char[size];
	int i;
	cout<<"Enter String : ";
	for(i=0;i<size;i++){
		cin>>ch[i];
	}
}
void MyString::display(){
	cout<<"\nString is ";
	for(int i=0;i<size;i++)
		cout<<ch[i];
//		cout<<endl<<"WOW"<<*ch;
}

void MyString::copy(MyString s){
       //One Way of Copying
       MyString::setsize(s.size);
	for(int i=0;i<s.size;i++)
	{
	   MyString::ch[i]=s.ch[i];
	  // cout<<"\n"<<MyString::ch[i];
	  // cout<<" GOT :"<<s.ch[i];
	}
//	cout<<"\n";

}
MyString MyString::copy2(MyString s){
	//Another Way of Copying by object
	//requires us to return Object
	//But Destructor must be removed

	MyString temp;
//	cout<<endl<<temp.ch[0]<<"End\n";
	temp.setsize(s.size);
	for(int i=0;i<temp.size;i++)
		temp.ch[i]=s.ch[i];
	return temp;
}