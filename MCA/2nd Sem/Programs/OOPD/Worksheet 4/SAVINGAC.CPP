#include<iostream.h>
#include<conio.h>
class SavingsAccount{
	float savBal;

	static float air;
	public:

		SavingsAccount();
		SavingsAccount(float);
		void setBal(float);

		float getBal();
		static float mod_air(float);

		void cal_mi();

};
float SavingsAccount::air=4.0f;
void main()
{
	SavingsAccount saver1,saver2(3000.0f);
	saver1.setBal(2000.0);

	clrscr();
	cout<<"Balance of saver1 account is:\n"<<saver1.getBal()<<endl;
	cout<<"Balance of saver2 account is:\n "<<saver2.getBal();
	saver1.cal_mi();
	saver2.cal_mi();

	cout<<"\n\nBalance of saver1 account is:\n"<<saver1.getBal()<<endl;
	cout<<"Balance of saver2 account is:\n "<<saver2.getBal();
	cout<<endl<<"New Interest Rate "<<SavingsAccount::mod_air(5.0f);

	saver1.cal_mi();
	saver2.cal_mi();
	cout<<"\nBalance of saver1 account is:\n"<<saver1.getBal()<<endl;
	cout<<"Balance of saver2 account is:\n "<<saver2.getBal();

	getch();

}


SavingsAccount::SavingsAccount(){
	savBal=0.0;
}
SavingsAccount::SavingsAccount(float s){
	savBal=s;
}
void SavingsAccount::setBal(float l){
	savBal=l;
}
float SavingsAccount::getBal(){
     return savBal;
}
void SavingsAccount::cal_mi(){

	savBal=savBal+((savBal*air)/12);
}

 float SavingsAccount::mod_air(float n){
//	cout<<n;
	air=n;
	return air;
}
