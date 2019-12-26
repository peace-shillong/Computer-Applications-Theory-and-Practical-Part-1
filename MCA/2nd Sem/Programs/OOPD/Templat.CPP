#include<iostream.h>
#include<conio.h>
/*
	Template Program
*/
template<class T>
void sort(T array[],int size){
	int i,j;
	T temp;

	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(array[i]>array[j]){
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
}
template <class T2>
void printArray(T2 array[100],int size){
	for(int i=0;i<size;i++)
		cout<<" "<<array[i];
	cout<<endl;
}
class Rectangle
{	private:
		int len;
		int brd;

	public:
		Rectangle();
		Rectangle(int l,int b);
		int area();
		int getLength();//
		void setData();
		void setDimen(int l,int b);
		friend ostream& operator<<(ostream& , Rectangle&); //overload operator <<
		friend Rectangle operator + (Rectangle r1,Rectangle r2);
		friend int operator > (Rectangle r1,Rectangle r2);
};
Rectangle::Rectangle(){
	 //initialize
	 len=1;
	 brd=1;
}
Rectangle::Rectangle(int l,int b){
	//initialize & assign data member with parameters
	len=l;
	brd=b;
}
//memeber function
int Rectangle::area(){
	return len*brd;
}

void Rectangle::setDimen(int l,int b){
	//assignment
	len=l;
	brd=b;
}
void Rectangle::setData(){
	int l,b;
	cout<<"Enter Length";
	cin>>l;
	cout<<"Enter breadth ";
	cin>>b;
	setDimen(l,b); // member

}
void main(){

	Rectangle r1(4,4),r3(3,4),r4;//call para constr
//	int i=0;
//	int l,b;
	clrscr();
	int a[2]={2,1};
	float f[2]={200.4f,54.4f};
	Rectangle r[2];

	r[0].setData();
	r[1].setData();

	//operator << calls ists overloaded fn below
	//cout<<r1;
	//operator +
       //	r4=r1+r3;
       //	cout<<r4;
	//cout<<"\n Length "<<r1.getLength();
	//cout<<"Area is "<<r1.area();

	sort(r,2);
	printArray(r,2);
	sort(a,2);
	printArray(a,2);
	sort(f,2);
	printArray(f,2);
	getch();
}

ostream& operator<<(ostream& o,Rectangle& r){
	o<<"Length is "<<r.len<<endl;
	o<<"Breadth is "<<r.brd<<endl;
	return o;
}
Rectangle operator +(Rectangle r1,Rectangle r2){
	Rectangle temp;
	temp.len=r1.len+r2.len;
	temp.brd=r1.brd+r2.brd;
	return temp;
}
int Rectangle::getLength(){
	return len;
}

int operator >(Rectangle r1,Rectangle r2){
	if(r1.area()>r2.area())
		return 1;
	return 0;
}

