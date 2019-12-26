#include<iostream.h>
#include<conio.h>
class Time
{
	private:
		int hour,minute,second;
	public:
		void set_time(int, int, int);
		void get_time();
		void set_hour(int);
		void set_min(int);
		void display();
};
void Time::set_time(int h, int m, int s)
{
	hour=h;
	minute=m;
	second=s;
}
void Time::get_time()
{
	cout<<"\tEnter Hour : ";
	cin>>hour;
	cout<<"\tEnter Minute : ";
	cin>>minute;
	cout<<"\tEnter Second : ";
	cin>>second;
}
/*
void Time::set_hour(int hr)
{
	hour=hr;
}
void Time::set_minute(int min)
{
	minute=min;
}
void Time::set_second(int sec)
{
	second=sec;
}*/
void Time::display()
{
	cout<<endl<<"\t"<<hour<<":"<<minute<<":"<<second;
}
void main()
{
	Time t1,t2;
	clrscr();
	t1.set_time(11,59,59);
/*	t1.set_hour(7);
	t1.set_minute(45);
	t1.set_second(15);  */

	t2.get_time();
	cout<<endl<<"\tThe Time T1 (Provided by the Argument) :- ";
	t1.display();
	cout<<endl<<"\tThe Time T2 (Input by the User) :- ";
	t2.display();
	getch();
}