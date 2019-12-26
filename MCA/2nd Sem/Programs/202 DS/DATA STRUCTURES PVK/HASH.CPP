#include<iostream.h>
#include<conio.h>
#define EMPTY 0
#define PRESENT 1

int hash(int,int);
int a[100],t[100];

int insertLinear (int m, int k) {
	int i=0,j;
	j=hash(k,m);
       //	cout<<" j "<<j ;
	do
	{
		if(t[j]==EMPTY)
		{
			a[j]=k;
			t[j]=PRESENT; //EMPTY=0,PRESENT=1
			return j;
			//return a;
		}
		i++;
		j=(j+i)%m; //to ensure the index are within m.
	}while(i<m);
	return -1; //no space found where insertion can be made
}
int searchLinear (int m, int k)
{
	int i=0,j,temp=k;
	j=hash(k,m);
       //	cout<<"j "<<j;
	do
	{
		if(a[j]==temp)
			return j; //returns position where found
		i++;
		j=(j+i)%m; //to ensure the index are within m. 
	}while(i<m);
	return -1; //not found
}

void main(){

	//int array[10],h_table[10]={0,0,0,0,0,0,0,0,0,0};
	int i=0,val,pos,n;
	for(;i<100;i++)
		t[i]=0;
	i=0;
	clrscr();
	cout<<"\n Enter the Size of the array: ";
	cin>>n;
	cout<<" \n INSERT AND SEARCH AN ARRAY USING HASHING";
	cout<<"\n Enter Values into Array";
	while(i<n){
		cout<<"\n\n Enter Value : ";
		cin>>val;
		pos=insertLinear(n,val);
		cout<<"\n"<<val<<" Inserted at pos: "<<pos<<endl;
		i++;
	}
	cout<<"\n Searching the Array";
	cout<<"Enter Value to search";
	cin>>val;
	int res = searchLinear(n,val);
	//cout<<"\n Array: "<<array[3];
	cout<<"\n HASH TABLE FOR Array";
	for(i=0;i<n;i++)
		cout<<endl<<i<<" - "<<a[i];
	cout<<"\n";
	if(res!=-1)
		cout<<" Found at position "<<res;
	else
		cout<<"NOT FOUND";
	getch();
}

int hash(int k,int n){

	return (k%n);
}