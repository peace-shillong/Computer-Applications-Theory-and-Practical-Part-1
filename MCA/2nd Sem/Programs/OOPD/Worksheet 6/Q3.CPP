#include<iostream.h>
#include<conio.h>

class CommunityMember{
	protected:
		char *name;
		int id;
		float memberFee;
	public:
		CommunityMember();
		CommunityMember(char *c,int id,float fee);
		void setDataTo(char *c,int id,float fee);
		virtual void display(){};
};

class Employee: public CommunityMember{
	private:
		float salary;
	public:
		Employee();
		Employee(char *n,int id,float fee,float sal);
		void setDataTo(char *c,int id,float fee,float sal);
		void display();
		float accessor();
};

class Faculty:public Employee{
	private:
		char *subject;
		int publications;
	public:
		Faculty():Employee(){};
		Faculty(char *n,int id,float fee,float sal,char *sub,int pub):Employee(n,id,fee,sal){
			subject=sub;
			publications=pub;
		};
		void setDataTo(char *c,int id,float fee,float sal,char *sub,int pub);
		void display();
		int accessPub();
		char* accessSub();
};

void main(){

	CommunityMember *CM[3];
	Employee *e=new Employee("Alex",1,100.0f,1000.0f);
	Faculty *f=new Faculty("Bankit",2,100.0f,2000.0f,"Comp",1);
	CM[0]=e;
	CM[1]=f;
	clrscr();
	for(int i=0;i<2;i++){
		if(i==0)
		{
			cout<<"\nEmployee CLASS\n";
			cout<<"\n ID \tNAME \tFEE \tSALRY\n";
		}
		else{
			cout<<"\n\nFaculty Class\n";
			cout<<"\nID \tNAME \t FEE \tSALARY \tSUBJECT \tPUBLICATIONS \n";
		}
		CM[i]->display();
	}

	/*
		char *n;
		cout<<"Enter Employee Details: "<<endl<<"Enter Name ";
		cin>>n;

		e->setDataTo("Bunki",1,100.0f,2000.0f);
		f->();
	*/
	getch();
}

CommunityMember::CommunityMember(){
	id=0;
	name="ABC";
	memberFee=100.0f;
}

CommunityMember::CommunityMember(char *c,int id,float fee){
	this->id=id;
	name=c;
	memberFee=fee;
}

void CommunityMember::setDataTo(char *c,int idp,float fee){
	id=idp;
	name=c;
	memberFee=fee;
}

Employee::Employee():CommunityMember(){
	salary=0.0f;
}
Employee::Employee(char *c,int idp,float fee,float sal):CommunityMember(c,idp,fee){
			salary=sal;
};
void Employee::setDataTo(char *c,int idp,float fee,float sal){
	//id=idp;
       //	name=c;
       //	memberFee=fee;
	CommunityMember::setDataTo(c,idp,fee);
	salary=sal;
}
void Employee::display(){
	cout<<id<<"\t "<<name<<"\t "<<memberFee<<"\t "<<salary;
}
float Employee::accessor(){
	return salary;
}
void Faculty::setDataTo(char *c,int idp,float fee,float sal,char *sub,int pub ){
//	id=idp;
  //	name=c;
    //	memberFee=fee;
	Employee::setDataTo(c,idp,fee,sal);
	subject=sub;
	publications=pub;
}
void Faculty::display(){
	//cout<<id<<" \t"<<name<<"\t "<<memberFee<<"\t "<<subject<<"\t "<<publications<<endl;
	Employee::display();
	cout<<"\t"<<subject<<" \t\t"<<publications;
}
int Faculty::accessPub(){
	return publications;
}
char* Faculty::accessSub(){
	return subject;
}