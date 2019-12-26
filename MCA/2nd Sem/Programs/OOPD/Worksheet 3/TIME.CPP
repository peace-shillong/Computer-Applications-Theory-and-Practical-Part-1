#include<iostream.h>
#include<conio.h>
class Time{
	int hour,min,sec;
	public:
		Time();
		Time(int,int,int);
		void setTime(int,int,int);
		void setHour(int);
		void setMinute(int);
		void setSeconds(int);
		void printStandard();
		void printUniversal();

};
void main(){
	Time t;
	int ch,n,h,m,s;
	clrscr();
	//t.setTime(10,10,9);
	cout<<"Current Time"<<endl;
	t.printUniversal();
	t.printStandard();
	getch();
	do{
		clrscr();
		cout<<"\tMenu.\n1.Display Time.\n2.Set Time.\n3.Exit";
		cout<<"\nEnter Choice";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"1.Standard Time\n2.Universal Time.";
				cin>>n;
				if(n==2){
					t.printUniversal();
					getch();
					}
				else{
					t.printStandard();
					getch();
					}
				break;
			case 2:
				cout<<"1.Set Time.\n2.Set Hour \n3.Set Minute\n4.Set Second.";
				cin>>n;
				if(n==2){
					cout<<"Enter Hour:";
					cin>>h;
					t.setHour(h);
					cout<<"Hour has been set";
					}
				else if(n==3){
					cout<<"Enter Minute:";
					cin>>m;
					t.setMinute(m);
					cout<<"Minute has been set";
					}
				else if(n==4){
					cout<<"Enter Seconds:";
					cin>>s;
					t.setSeconds(s);
					cout<<"Seconds has been set";
					}
				else{
					cout<<"Enter Hour:";
					cin>>h;
					cout<<"Enter Minutes:";
					cin>>m;
					cout<<"Enter Seconds:";
					cin>>s;
					t.setTime(h,m,s);
					}

		}


	}while(ch!=3);
	getch();
}

//
Time::Time(){

	hour=min=sec=0;
}

//
void Time::setTime(int h,int m,int s){
	if(h>=0 && h<=23)
		hour=h;
	if(h>=24)
		hour=0;
	if(m>=0 && m<=59)
		min=m;
	else if(m>=60){
		min=m%60;
		int mm=m/60;
		hour=hour+mm;
	}
	if(s<60 && s>=0)
		sec=s;
	else if(s>=60){
		sec=s%60;
		int ss=s/60;
		min+=ss;
	}
	else
		sec=0;

}
void Time::setHour(int h){
	if(h>=0 && h<=23)
		hour=h;
	else
		hour=0;
}
void Time::setMinute(int m){
	if(m>=0 && m<=59)
		min=m;
	else if(m>=60){
		min=m%60;
		int mm=m/60;
		hour=hour+mm;
	}
}
void Time::setSeconds(int s){
	if(s<60 && s>=0)
		sec=s;
	else if(s>=60){
		sec=s%60;
		int ss=s/60;
		min+=ss;
	}
}

void Time::printUniversal(){
	cout<<"Time: "<<hour<<":"<<min<<":"<<sec<<endl;
}


void Time::printStandard(){
	if(hour>=0 && hour<12)
		cout<<"Time: "<<hour<<":"<<min<<":"<<sec<<" AM"<<endl;
	else
		cout<<"Time: "<<(hour-12)<<":"<<min<<":"<<sec<<" PM"<<endl;
}