#include <iostream.h>
#include <conio.h>

class Distance{
	float feet,inches;
	public:
		Distance();
		Distance(int,int);
		Distance(float);
	       //	void setDistance(int);
		void setFeet(int f);
		void setInches(int i);
		float getFeet();
		float getInches();

		void display();
	       //	void tometers(int,int);
};

void main()
{
	Distance d;
	Distance d1(4);
       //	clrscr();
	d1.display();
	getch();

}

Distance::Distance(){
	feet=0;
	inches=0;
}
Distance::Distance(int f,int i){
	feet=f;
	inches=i;
}
Distance::Distance(float f){
	int i=(int)f;
//	cout<<i<<endl;
	feet = i;
	inches=f-i;
}


void Distance::display(){
	cout<<"Distance is "<<feet<<"' "<<inches<<"\"";
}

void Distance::setFeet(int f){
	feet=f;
}

void Distance::setInches(int i){
       inches=i;
}
float Distance::getFeet(){
	return feet;
}

float Distance::getInches(){
       return inches;
}