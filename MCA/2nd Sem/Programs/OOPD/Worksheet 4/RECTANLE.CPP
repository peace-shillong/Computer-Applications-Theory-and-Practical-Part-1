#include<iostream.h>
#include<conio.h>
class Rectangle{
	float length,width;
	public:
		Rectangle();
		Rectangle(float l,float b);
		void setLength(float l);
		void setBreadth(float b);
		float getLength();
		float getBreadth();
		float perimeter();
		float area();
		const void display();

};
void main()
{
	Rectangle r1,r2(2.0f,4.0f);
	const Rectangle r3(4,5);
	r1.setLength(10.5);
	r1.setBreadth(3.5);
	clrscr();

	cout<<"Length and Breadth is:\n"<<r1.getLength()<<endl;
	cout<<r1.getBreadth();
	cout<<"\nReactangle 2\nArea of rectangle is "<<r2.area();
	cout<<"\nPerimeter is :"<<r2.perimeter();
	cout<<"\n\nLength and breadth of const object";
	r3.display();
       //	r3=r1; error
       //	r3.setLength(6);
	cout<<"\nArea :"<<r3.area();
	getch();

}

Rectangle::Rectangle(){
	length=width=1.0;
}
Rectangle::Rectangle(float l,float b){
	if(l>=0.0 && l<=20.0)
		length=l;
	else
		length=1.0f;
	if(b>=0.0 && b<=20.0)
		width=b;
	else
		width=1.0f;
}
void Rectangle::setLength(float l){
     if(l>=0.0 && l<=20.0)
	length=l;
     else
	length=1.0f;
}
void Rectangle::setBreadth(float b){
     if(b>=0.0 && b<=20.0)
	width=b;
     else
	width=1.0f;
}

float Rectangle::getLength(){
     return length;
}
float Rectangle::getBreadth(){
	return width;
}
float Rectangle::perimeter(){
	return 2*(length+width);
}

float Rectangle::area(){
	return length*width;
}
const void Rectangle::display(){
	cout<<"\nThe length is "<<length;
	cout<<endl<<"The width is"<<width;
}