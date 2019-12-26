class Employee{
	protected:
		char f_name[80];
		char l_name[80];
		int ssn;
	public:
		Employee();
		Employee(char *f,char *l,int id);
		void setData(char *f,char *l,int id);
		void display();		
		~Employee();
};

class SalariedEmployee: public Employee
{	
	private:
		float weekly_salary;
	public:
		SalariedEmployee():Employee();
		SalariedEmployee(char *f,char *l,int id,float sal):Employee(f,l,id);
		void setData(char *f,char *l,int id,float sal);
		void display();				
		
};
class HourlyEmployee: public Employee
{
	private:
		int wage, noOfHours,overtimePay;
	public:
		HourlyEmployee():Employee();
		HourlyEmployee(char *f,char *l,int id,int w,int n,int op):Employee(f,l,id);
		void setData(char *f,char *l,int id,int w,int n,int op);
		void display();		

};

class CommissionEmployee: public Employee
{
	private:
		float cRate,gSales;
	public:
		CommissionEmployee():Employee();
		CommissionEmployee(char *f,char *l,int id,float c,float g):Employee(f,l,id);
		void setData(char *f,char *l,int id,float c,float g);
		void display();		

};

void main(){
	SalariedEmployee s1;
	HourlyEmployee h1;
	CommissionEmployee c1;
	
	
}

Employee::Employee(){
	f_name=new char[100];
	l_name=new char[100];
	strcpy(f_name,"A");
	strcpy(l_name,"B");
	ssn=0;
}
Employee::Employee(char *f,char *l,int id){
	f_name=new char[100];
	l_name=new char[100];
	strcpy(f_name,f);
	strcpy(l_name,l);
	ssn=id;
}
Employee::~Employee(){
	delete []f_name;
	delete []l_name;
}
