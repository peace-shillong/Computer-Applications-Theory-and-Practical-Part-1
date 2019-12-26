#include<iostream.h>
#include<conio.h>
class CQ{
	int elements[5],front,rear,flag;
	public :
		CQ();
		int deleteCQ();
		void addCQ(int );
		void display();
};
CQ::CQ(){
	flag=0;
	front=rear=-1;
}
void CQ::addCQ(int val){
	int t;
	t=(rear+1)%5;
	if((front==t) || ( t==0 && front==-1 && flag==1)){
		cout<<"C Q is FULL.";
		getch();
	}
	else{
		rear=t;
		flag=1;
		elements[rear]=val;
	 //	cout<<" e "<<elements[rear];getch();
	}
}
int CQ::deleteCQ(){
	if(rear==front){
		cout<<"CQ is Empty";
		getch();
	}
	else
	{
		front=(front +1 )%5;
		return elements[front];
	}
	return -1;

}
void CQ::display(){
	for(int i=0;i<5;i++)
		cout<<" "<<elements[i];
	getch();
}
void main(){
	CQ que;
	int ch,v;
	do{
	clrscr();
	cout<<"\n MENU ";
	cout<<"\n 1. Add \n 2. Delete \n 3. Display \n 4. Exit \n Eneter Choice \n";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"Enter VALUE to C Que";
			cin>>v;
			//cout<<" "<<v;
			getch();
			que.addCQ(v);
			break;
		case 2:
			cout<<"Deleted  ";
			cout<<que.deleteCQ();
			getch();
			break;
		case 3:
			que.display();
			break;
		default:
			break;

	}
	}while(ch!=4);
	getch();
}