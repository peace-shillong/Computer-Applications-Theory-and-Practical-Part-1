#include<iostream.h>
#include<conio.h>
void main()
{
	int no,i,ch,x,r=0,res=0,s[4],t,dec,di;
	char a[4];
	clrscr();
	do
	{
		clrscr();
		cout<<"1.Encrypt."<<endl;
		cout<<"2.Decrypt."<<endl;
		cout<<"3.Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter a 4 digit number ";
				cin>>no;
				x=no;
				while(x!=0)
				{
					int d=x%10;
					r=r*10+((d+7)%10);      //r=1098
					x=x/10;
				}
				x=r;
				i=0;
				while(x!=0)
				{
								  //res=8901
					int d=x%10;
					res=res*10+d;
					x=x/10;
					s[i]=d;
					i++;
				}
				t=s[0];         //awap 1 and 3
				s[0]=s[2];      //swap 2 and 4
				s[2]=t;
				t=s[1];         //0189
				s[1]=s[3];
				s[3]=t;
				cout<<"The Encrypted message:";
				for(i=0;i<4;i++)

					cout<<s[i];
				break;
			case 2:
				cout<<"Enter a number to decrypt:";
				cin>>a;

				for(i=0;i<4;i++)
				{	s[i]=a[i];
					s[i]=s[i]-48;
				}
				t=s[0];         //awap 1 and 3
				s[0]=s[2];      //swap 2 and 4
				s[2]=t;
				t=s[1];         //0189
				s[1]=s[3];
				s[3]=t;
				cout<<endl;
				for(i=0;i<4;i++)
				{
				       s[i]=(s[i]+3) %10;
				}
				cout<<"Decrypted message:";
				for(i=0;i<4;i++)
					cout<<s[i];





		}
		getch();
	}while(ch!=3);
	getch();
}
