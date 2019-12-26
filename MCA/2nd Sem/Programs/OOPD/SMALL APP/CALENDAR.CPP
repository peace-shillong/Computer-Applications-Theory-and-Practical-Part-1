//CALENDAR PROGRAM
#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class Date{
	int date,month;
	public:
	Date();
	void setDate(int);
	void setMonth(int);
	int getDate();
	int getMonth();
};
class Calendar : public Date{
	public:
		Calendar();
		Calendar(int,int);
		void displayDay();
		void displayMonth();
		int num_days_month();
};
void main()
{

 int ch=0;
 Calendar c,c1(2,2);
 while(ch!=3){
 clrscr();

 cout<<"\n\t 2016 CALENDAR PROGRAM";
 cout<<"\n\n\t MENU\n";
 cout<<"1. Display Month.";
 cout<<"\n2. Display Day.";
 cout<<"\n3. Exit.";
 cout<<"\n Enter Your Choice: ";
 cin>>ch;
 switch(ch){
	case 1:
		c.displayMonth();
		break;
	case 2:
		c.displayDay();
		//c1.displayDay();
		break;
	case 3:
		cout<<"Exiting Program... Press any key";
		break;
	default:
		cout<<"You Entered and invalid Input\n";
		getch();
	}
 }
   getch();
}

Date::Date(){
	date=month=1;
}
Calendar::Calendar(){
	setDate(1);
	setMonth(1);
}
Calendar::Calendar(int d,int m){
	if((d>0 && d<31) && (m>0 && m<12)){
	setMonth(m);
	setDate(d);
	}
	else
	setMonth(1);
	setDate(1);
}
void Date::setDate(int day){
	if(month==2){
	   if(day<30 && day>0)
		date=day;
	   else{
		date=1;
		cout<<"Date is : "<<date<<"/"<<month<<"/2016\n";
	   }
	}
	else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
		if(day<32)
			date=day;
		else{
			date=1;
			cout<<"Date is : "<<date<<"/"<<month<<"/2016\n";
		}
	}
	else{
		if(day<31)
			date=day;
		else{
			date=1;
			cout<<"Date is : "<<date<<"/"<<month<<"/2016\n";
		}
	}
}
void Date::setMonth(int mon){
	if(mon>=1 && mon<=12)
		month=mon;
	else{
		month=1;
		cout<<"Invalid month. Month set to Jan\n";
	}
}
int Date::getMonth(){
	return month;
}
int Date::getDate(){
	return date;
}
void Calendar::displayDay(){
	 int d,m,day,i,num_days=0;
	 char ch;
	 cout<<"\nDisplaying the day.\n";
	 cout<<"Do You Want to Set the Date: Y/N \n";
	 cin>>ch;
	 if(ch=='Y' || ch=='y'){
	 cout<<"Enter Day";
	 cin>>d;
	 cout<<"Enter Month: ";
	 cin>>m;
	 setMonth(m); //requires Month to be set First
	 setDate(d); // Then set the date
	 }
	   for(i=1;i<getMonth();i++){
		if(i==2)
		     num_days+=29;
		else if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
			num_days+=31;
		else
			num_days+=30;
	   }
	   num_days=num_days+(getDate()-1);
	   cout<<endl<<getDate()<<"/"<<getMonth()<<"/2016 is a ";
	   day=num_days%7;
	   if(day==0)
		  cout<<"FRIDAY";
	   else if(day==1)
		  cout<<"SATURDAY";
	   else if(day==2)
		  cout<<"SUNDAY";
	   else if(day==3)
		  cout<<"MONDAY";
	   else if(day==4)
		  cout<<"TUESDAY";
	   else if(day==5)
		  cout<<"WEDNESDAY";
	   else if(day==6)
		  cout<<"THURSDAY";
	getch();
}
int Calendar::num_days_month(){
	int month=getMonth();
	if(month==2)
		return 29;
	else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
		return 31;
	}
	else
		return 30;
}
void Calendar::displayMonth(){
	int m,d=1,firstday,max_days,i,num_days=0;
	cout<<"Enter Month: ";
	cin>>m;
	setMonth(m);
	setDate(d);
	max_days=num_days_month();
	//Know Firstday is
	 for(i=1;i<getMonth();i++){
		if(i==2)
		     num_days+=29;
		else if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
			num_days+=31;
		else
			num_days+=30;
	   }
	   num_days=num_days+(getDate()-1);
	   //cout<<endl<<getDate()<<"/"<<getMonth()<<"/2016 is a ";
	   firstday=num_days%7;
	switch(getMonth()){
		case 1:
			cout<<"\n\t JANUARY \n";
			break;
		case 2:
			cout<<"\n \t FEBRUARY\n";
			break;
		case 3:
			cout<<"\n\tMARCH\n";
			break;
		case 4:
			cout<<"\n\tAPRIL\n";
			break;
		case 5:
			cout<<"\n\t MAY \n";
			break;
		case 6:
			cout<<"\n \t JUNE\n";
			break;
		case 7:
			cout<<"\n\tJULY\n";
			break;
		case 8:
			cout<<"\n\tAUGUST\n";
			break;
		case 9:
			cout<<"\n\t SEPTEMBER \n";
			break;
		case 10:
			cout<<"\n \t OCTOBER\n";
			break;
		case 11:
			cout<<"\n\t NOVEMBER\n";
			break;
		case 12:
			cout<<"\n\t DECEMBER\n";
			break;
	}
	cout<<"\tSUN \t MON \t TUE \t WED \t THU \t FRI\t SAT \n";
	switch(firstday){
		case 0: //Friday
			cout<<"\t \t \t \t \t \t "<<d;
			break;
		case 1: //Saturday
			cout<<"\t \t \t \t \t \t \t "<<d;
			break;
		case 2: // Sunday
			cout<<"\t "<<d;
			break;
		case 3: //MOnday
			cout<<"\t \t "<<d;
			break;
		case 4: //TUesday
			cout<<"\t \t \t "<<d;
			break;
		case 5: //Wed
			cout<<"\t \t \t \t "<<d;
			break;
		case 6:    //Thurs
			cout<<"\t \t \t \t \t "<<d;
			break;
	}
	d++;
	if(firstday!=1)
	for(;d<=max_days;d++){
		    cout<<"\t "<<d;
		    firstday++;
		    if(firstday==1)
			cout<<endl;
		    else if(firstday==7)
			firstday=firstday%7;
		}
	else
	for(;d<=max_days;d++){
		    if(firstday==1)
			cout<<endl;
		    else if(firstday==7)
			firstday=firstday%7;

		    cout<<"\t "<<d;
		    firstday++;
		}
	getch();
}
