#include<iostream.h>
#include<conio.h>
void main()
{
	int i,j;
	char n='*';
	clrscr();
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if((i==0) || (i==8) || j==0 || j==8)
				cout<<n;
		       //	if (((i>0) || (i<9)) && ((j==0) ||(j==8)))
			 //	cout<<n;

			else
				cout<<" ";
		}
		cout<<endl;

	}
	cout<<endl<<endl;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{

			cout<<" ";
		 }
			for(int k=0;k<i;k++)
				cout<<n;
		       //	else
			//	cout<<" ";

		cout<<endl;
	 }
	getch();
}