#include<iostream.h>
#include<conio.h>
class LIST{
	int data[20];
	static int index;

	public:
	void makenull();
	int first();
	int next();
	void insert(int);
};
int LIST::index=0;

void LIST::makenull(){
	for(int i=0;i<20;i++)
		data[i]=0;
}
void main(){
	int w;
	clrscr();
	LIST l;
	l.makenull();
	w=l.first();
	cout<<" FIRST "<<w;
	w++;
	cout<<"\nENTER DATA press 0 to exit \n";
	while(w!=0){
	cin>>w;
	if(w!=0)
	l.insert(w);
	}
	int v=l.next();
	cout<<"\nLIST CONSIST OF";
	while(v){
	       //	cout<<"\n Has "<<l.next();
	       cout<<endl<<v;
		v=l.next();
	}
       getch();
}

int LIST::first(){
	return data[0];
}


void LIST::insert(int v){

	data[index]=v;
      //	index++;
   //    cout<<"data "<<data[index];
       index++;

}
int LIST ::next(){
	int flag=0,x;
	if(index>=1){
		     flag=1;
	}
	else
		return 0;
	if(flag==1){
		index--;
		x=data[index];
	    //	cout<<"x "<<x;
	    // cout<<index<<" index\n";
		return x;
	}
	else
		return 0;
}
