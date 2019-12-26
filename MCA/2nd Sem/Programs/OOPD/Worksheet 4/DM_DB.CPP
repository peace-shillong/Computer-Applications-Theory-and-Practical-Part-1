#include <iostream.h>
#include <conio.h>

class Distance{
	float feet,inches;
	public:
		friend class DM;
		Distance();
		Distance(int,int);
		Distance(float);
	       //	void setDistance(int);
		void setFeet(int f);
		void setInches(int i);
		float getFeet();
		float getInches();

	       //	void display();
	       //	void tometers(int,int);
	       friend void add(Distance,DM);


};
class DM{

	int m,cm;
	public:
		friend class Distance;
		DM();
		DM(int,int);
		DM(float);
		void set_m(int);
		void set_cm(int);
		int get_m();
		int get_cm();

		friend void add(Distance,DM);
};

void main()
{
	Distance d;
	DM d1;
	int f,i,m,cm;
	clrscr();
	cout<<"Enter First Distance (ft &in):\n";
	cout<<"Enter Value for Feet: ";
	cin>>f;
	cout<<"Enter Value for inches: ";
	cin>>i;
	d.setFeet(f);
	d.setInches(i);
	//d1.display();
	cout<<"\nEnter Second Distance (m & cm):\n";
	cout<<"Enter Value for Meters: ";
	cin>>m;
	cout<<"Enter Value for cm: ";
	cin>>cm;
	d1.set_m(m);
	d1.set_cm(cm);

	add(d,d1);
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
	inches=(f-i)*12;
}


////void Distance::display(){
  //	cout<<"Distance is "<<feet<<"' "<<inches<<"\"";
//}

void Distance::setFeet(int f){
	feet=f;
}

void Distance::setInches(int i){
       if(inches>12)
       while(inches>12){
	       inches=i-12;
		feet++;
       }
       else
	inches=i;

}
float Distance::getFeet(){
	return feet;
}

float Distance::getInches(){
       return inches;
}

//DM
DM::DM(){
	m=0;
	cm=0;
}
DM::DM(int f,int i){
	m=f;
	cm=i;
}
DM::DM(float f){
	int i=(int)f;
//	cout<<i<<endl;
	m = i;
	cm=(f-i)*100;
}


void DM::set_m(int f){
	m=f;
}

void DM::set_cm(int i){
       if(i>100)
       while(i>100){
	       cm=i-100;
		m++;
       }
       else
	cm=i;
}
int DM::get_m(){
	return m;
}

int DM::get_cm(){
       return cm;
}


void add(Distance d,DM dm){

	float ft_m,inch_cm;
	float new_ft,got_in,new_cm;
	new_ft=d.getFeet();
	got_in=d.getInches()/12;
	new_ft+=got_in;
	ft_m=new_ft*0.3048f;
//	inch_cm=d.getInches()*2.54f;
       //	inch_cm=(new_ft-((int)new_ft))*2.54f;
	new_cm=ft_m-(int)ft_m;
	cout<<d.getFeet()+d.getInches()/12<<" ft = "<<ft_m<<" m";
	float temp_ft=ft_m;
	ft_m=(int)ft_m;
	//cout<<"\ncm + cm "<<new_cm<<" "<<(float)dm.get_cm()/100;
	new_cm=new_cm+((float)dm.get_cm()/100);
	while(new_cm>1){
		new_cm=new_cm-(int)new_cm;
		ft_m++;
	}
	//
	new_cm*=100;
	cout<<"\nAdded Distance in m,cm\n";
	cout<<(ft_m+dm.get_m())<<" m, ";
	cout<<new_cm<<" cm\n\n";

	//m to feet cm to inches
	ft_m=dm.get_m()*3.28;
	inch_cm=dm.get_cm()*0.393;
	ft_m+=inch_cm;

	float new_m=ft_m; //got n converted to feet
	new_cm=inch_cm; //got n converted to inches
	new_m+=new_cm;
	//Add the two feet together
	temp_ft+=new_m;

       //	new_m+=got_cm;
	cout<<"\n Added Disatnce in ft,in\n";
	//cout<<((int)temp_ft+d.getFeet())<<" ft, ";
	float gott_in=d.getInches();
	gott_in=gott_in+(new_m-((int)new_m));

	//cout<<gott_in<<" in";

}