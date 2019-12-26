#include<iostream.h>
#include<conio.h>
#include<string.h>
/*
	Template Program
*/
template<class T>
int isEqual(T var,T var2){

	if(var==var2)
		return 1;
	return 0;
}

template<class T2>
T2 add(T2 var,T2 var2){
	return var+var2;
}

class MyString{
	char *ch;
	int size;
	public:
		MyString();
		MyString(char *c);
		MyString(const MyString&);
		void setstring();
		void display();
		~MyString();
		MyString operator + (MyString r2);
		int operator == (MyString r2);
		MyString &operator =(const MyString& s2);
};

MyString::MyString(){
	size=10;
	ch=new char[size];
}
MyString::MyString(char *c){
	size=strlen(c)+1;
       //	cout<<"Size "<<size;
	ch=new char[size];
	//strcpy(ch,c);
	for(int i=0;i<size;i++)
		ch[i]=c[i];
}
MyString::MyString(const MyString &a){
	size=strlen(a.ch)+1;
	ch = new char[size];
       //	for(int i=0;i<size;i++)
      //		ch[i]=a.ch[i];
      strcpy(ch,a.ch);
}
MyString::~MyString(){
	delete[] ch;
}

MyString MyString::operator +(MyString r2){
	MyString temp;
	temp.size=this->size+r2.size+1;
	temp.ch=new char[temp.size];

	strcpy(temp.ch,this->ch);
//	for(int i=0;i<this->size;i++)
//		 temp.ch[i]=this->ch[i];
	strcat(temp.ch,r2.ch);
//	for(int j=0,k=this->size;j<r2.size;k++,j++)
//		temp.ch[k]=r2.ch[j];
       //	cout<<" COPY "<<temp.ch;
//       cout<<this->ch;

	return temp;
}

int MyString::operator == (MyString r2){
	int equality;
	equality=strcmp(this->ch,r2.ch);
	if(equality==0)
		return 1;
	return 0;
}

MyString& MyString:: operator =(const MyString& s){
	// MyString temp;
	// temp.size=strlen(s.ch)+1;

       //	 strcpy(temp.ch,s.ch);
       //	 return temp;

       if(&s!=this){
	delete[] ch;
	size=strlen(s.ch)+1;
//	strcpy(ch,s.ch);
	ch= new char[size];
	for(int i=0;i<size;i++)
		ch[i]=s.ch[i];
       }
       return *this;
}

void MyString::display(){
	cout<<"\n "<<ch<<endl;
}
void main(){
	int i=1,j=1;
	MyString str1("Hello"),str2("Hello"),str3;
	clrscr();
	str1.display();
	if(isEqual(i,j))
		cout<<endl<<i<<" and "<<j<<" are Equal";
	else
		cout<<endl<<i<<" and "<<j<<" are Not Equal";

	int res=isEqual(str1,str2);

	if(res){
		cout<<endl;str1.display();cout<<" and ";str2.display();cout<<" are Equal";}
	else{
		cout<<endl;str1.display();cout<<" and ";str2.display();cout<<" are Not Equal";
	}
	str3=add(str1,str2);
	str3.display();
	getch();
}