#include<iostream.h>
#include<conio.h>
//Distance
struct Distance{
	int feet,inches;
};
Distance isLonger(const Distance &l1,const Distance &l2);

void main()
{
	Distance d1,d2,d3;
	clrscr();
	cout<<endl<<"Program to Find longer distance"<<endl;
	cout<<"Enter First Distance ";
	cout<<endl<<"Enter the Feet ";
	cin>>d1.feet;
	cout<<"Enter inches";
	cin>>d1.inches;
	if(d1.inches>=12){
		d1.inches-=12;
		d1.feet++;
	}
	cout<<"Enter Second Distance ";
	cout<<endl<<"Enter the Feet ";
	cin>>d2.feet;
	cout<<"Enter inches";
	cin>>d2.inches;
	if(d2.inches>=12){
		d2.inches-=12;
		d2.feet++;
	}
	//cout<<endl<<"Distances D1: "<<d1.feet<<"' "<<d1.inches<<endl;
	d3=isLonger(d1,d2);
	cout<<endl<<"Longer Distances : "<<d3.feet<<"' "<<d3.inches<<endl;

	//cout<<"Numbers : "<<x<<" "<<y<<endl;
	getch();
}

Distance isLonger(const Distance &l1,const Distance &l2){
	if(l1.feet>l2.feet){
	       //	l1.feet++;
		return l1;
	}
	else if(l1.feet<l2.feet){
		return l2;
	}
	else
		if(l1.inches>l2.inches)
			return l1;
		else
			return l2;

}