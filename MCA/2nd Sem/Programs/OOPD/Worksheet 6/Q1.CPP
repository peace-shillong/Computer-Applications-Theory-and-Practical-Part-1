class Employee{
	protected:
		char f_name[80];
		char l_name[80];
		int ssn;
	public:
		Employee();
		Employee(char *f,char *l,int id);
		
};

class SalariedEmployee: public Employee
{	
	private:
		int weekly_salary;
	public:
		SalariedEmployee():Employee();
		SalariedEmployee(char *f,char *l,int id):Employee(f,l,id);
		
}