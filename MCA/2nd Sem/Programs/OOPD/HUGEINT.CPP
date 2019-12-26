#include<iostream.h>
#include<conio.h>
#include<string.h>

class HugeInteger{
	private:
	int array[41];
	int size,i;
	public:
		HugeInteger();
		HugeInteger(char a[]);
		void input();
		void output();
		int getsize();
		HugeInteger add(HugeInteger,HugeInteger);
		HugeInteger sub(HugeInteger,HugeInteger);
		int isEqualTo(HugeInteger);
		int isNotEqualTo(HugeInteger);
		int isLessThan(HugeInteger n);
		int isLessThanOrEqualTo(HugeInteger n);
		int isGreaterThan(HugeInteger n);
		int isGreaterThanOrEqualTo(HugeInteger n);

};

HugeInteger::HugeInteger(){
	//Default
	for(i=0;i<42;i++)
		array[i]=-1;
	size=41;
}
HugeInteger::HugeInteger(char s[]){//s is Hugeinteger
	if(strlen(s)<=40){
		size=strlen(s);
	size+=2;
       //	cout<<"size "<<size;
       //	getch();
	for(i=0;i<size;i++)
		array[i+2]=s[i]-48;
	}


}
void main(){
	HugeInteger a,b,sum,diff;
	clrscr();
	cout<<"Enter First HugeInteger : ";
	a.input();

	cout<<"\nValue of a is : ";
	a.output();
	cout<<"\nEnter Second HugeInteger: ";
	b.input();
	cout<<"Value of b is : ";
	b.output();

	cout<<"\n Press ENTER key To view Operations on HugeInteger";
	getch();
	int ch;
	do{
		cout<<"\n \t MENU ";
		cout<<"\n 1. Input Two HugeIntegers.";
		cout<<"\n 2. Add the two HugeIntegers";
		cout<<"\n 3. Subtract the two HugeIntegers";
		cout<<"\n 4. Find Whether HugeIntegers are not Equal to.";
		cout<<"\n 5. Find Whether HugeIntegers are Equal to.";
		cout<<"\n 6. Find Whether HugeInteger is Lesser Than or Equal to.";
		cout<<"\n 7. Find Which HugeInteger is Lesser";
		cout<<"\n 8. Find Whether HugeInteger is Greater Than or Equal to.";
		cout<<"\n 9. Find Which HugeInteger is Greater .";
		cout<<"\n 10. EXIT.";
		cin>>ch;
		switch(ch){

			case 1:
					cout<<"Enter First HugeInteger : ";
					a.input();
					cout<<"Value of a is : ";
					a.output();
					cout<<"\nEnter Second HugeInteger: ";
					b.input();
					cout<<"Value of b is : ";
					b.output();
					break;
			case 2:
						sum=sum.add(a,b);
						cout<<"Sum of ";a.output();
						cout<<" and ";b.output();cout<<" is : ";
						sum.output();
					break;
			case 3:
					diff=diff.sub(a,b);
					cout<<"\nDifference between ";a.output();
					cout<<" and ";b.output();cout<<" is : ";
					diff.output();
					break;
			case 4:
					if(a.isNotEqualTo(b)){
						cout<<"The HugeIntegers are Not Equal";
					}
					else{
						cout<<"The HugeIntegers are Equal.";
					}
					break;
			case 5:
					if(a.isEqualTo(b)){
						cout<<"The HugeIntegers are Equal";
					}
					else{
						cout<<"The HugeIntegers are Not Equal.";
					}
					break;
			case 6:
					if(a.isLessThanOrEqualTo(b)){
						cout<<"\n The HugeInteger ";a.output();cout<<"\n is Lesser Than or Equal to ";b.output();
					}
					else{
						cout<<"\n The HugeInteger ";a.output();cout<<"\n is Not Lesser Than or Equal to ";b.output();
					}
					break;
			case 7:
					if(a.isLessThan(b)){
						cout<<"\n The HugeInteger ";a.output();cout<<"\n is Lesser Than ";b.output();
					}
					else{
						cout<<"\n The HugeInteger ";a.output();cout<<"\n is Not Lesser Than ";b.output();
					}
					break;
			case 8:
					if(a.isGreaterThanOrEqualTo(b))
					{
						cout<<"\n The HugeInteger ";
						a.output();
						cout<<"\n is Greater Than or Equal to ";
						b.output();
					}
					else{
						cout<<"\n The HugeInteger ";a.output();cout<<"\n is Not Greater Than or Equal to ";b.output();
					}
					break;
			case 9:
					if(a.isGreaterThan(b))
					{
						cout<<"\n The HugeInteger ";a.output();cout<<"\n is Greater Than ";b.output();
					}
					else{
						cout<<"\n The HugeInteger ";a.output();cout<<"\n is Not Greater Than ";b.output();
					}
					break;
			case 10:
					break;
			default:
				cout<<" Re Enter Choice.";
		}
		getch();
		clrscr();
	}while(ch!=10);

}

void HugeInteger::input(){
	char str[40];
	cout<<"Enter Size of HugeInteger (max-40)";
	cin>>size;
	if(size<1 || size>40){
		size=5;
		cout<<"Default Size is 5-digit\n";
	}
	size+=2;
	cout<<"Enter The Value: ";
	cin>>str;

	if(str[0]=='-'){
			array[0]=1;//1 -
		for(i=size-1;i>1;i--)
			array[i]=str[i-2]-48;
	}
	else{ //-1 +
		//array[2]=str[0];
		for(i=size-1;i>1;i--)
				array[i]=str[i-2]-48;
	}

	/*for(i=size;i>0;i--)

		cin>>array[i];*/
	//*a=new int[];


       // rev() No;
/*      // size++;
       int t[42];
       for(i=0;i<=size;i++)
		t[i]=-1;
       t[0]=array[0];
       for(int x=1,y=size-1;x<=size-1;x++,y--)
		t[x]=array[y];
       for(i=1;i<=size-1;i++)
	array[i]=t[i];*/
}

void HugeInteger::output(){
	//cout<<"Valur of HugeInteger is : ";
	if(array[1]==1)//carry
		cout<<array[1];
	if(array[0]==1)
		cout<<"-";
	if(array[0]==0)
		cout<<"0";
	else
	for(i=2;i<size;i++){
		if(array[i]>-1)
			cout<<array[i];

	}

       //	cout<<endl;
}
int HugeInteger::getsize(){
	return size;
}
HugeInteger HugeInteger::add(HugeInteger a, HugeInteger c){
	int carry=0;
	int k,j,s1,s2,maxsize;
	i=k=j=0;
	//Temp = HugeInteger::array[0] + c.array[0];
	//size of a -> s1 and b -> s2
	s1=a.getsize();
  //	cout<<s1;
	//getch();
	s2=c.getsize();
	HugeInteger temp;
	//temp a
	//int a[s1]=HugeInteger::array[s1];
/*	if(a.array[0]!=c.array[0]){
		a.array[0]=c.array[0]=-1;
		return temp.sub(a,c);
	} */
	if(s1>s2)
		maxsize=s1;
	else
		maxsize=s2;

//	cout<<maxsize<<endl;
	i=s1-1;j=s2-1;k=maxsize-1;
	while((i>1) && (j>1)){
	   ///	cout<<"i - j - k"<<endl;
	     //	cout<<i<<" "<<j<<" "<<k<<endl;


		if((a.array[i]+c.array[j]+carry)>=10){

			temp.array[k]=(a.array[i]+c.array[j]+carry)%10;
			carry=1;
		}
		else{

		if((a.array[i]==-1)){

				if(c.array[j]+carry>=10){
				 temp.array[k]=(c.array[j]+carry)%10;
				 carry=1;
				}
				else{
				temp.array[k]=(c.array[j]+carry)%10;
				carry=0;
				}

		}


		//	temp.array[k]=(a.array[i]+c.array[j]+carry)%10;
	       //	else{
		       //	carry=0;
		       /*	if(a.array[i]==-1){
				if(c.array[j]+carry>=10){
				 temp.array[k]=(c.array[j]+carry)%10;
				carry=1;
				}
				else{
				temp.array[k]=(c.array[j]+carry)%10;
				carry=0;
				}
			}*/
			else if(c.array[j]==-1){
			       if(a.array[i]+carry>=10){
					temp.array[k]=(a.array[i]+carry)%10;
					carry=1;
			       }
			       else{
				   temp.array[k]=(a.array[i]+carry)%10;
				   carry=0;
			       }
			    }


			else{
				temp.array[k]=(a.array[i]+c.array[j]+carry)%10;
				carry=0;

			}
	      //	cout<<"temp: "<<temp.array[k]<<endl;
		}
		i--;j--;k--;
	       //	getch();
	}
	if(i>1){
		while(i>1){
		   if((a.array[i]+carry)>=10){
			temp.array[k]=(a.array[i]+carry)%10;
			carry=1;
		    }
		   else{
		       if((a.array[i]!=-1) && (c.array[j]!=-1))
				temp.array[k]=(a.array[i]+carry)%10;
		       else{
				if(a.array[i]==-1)
				temp.array[k]=(c.array[j]+carry)%10;
			else
				temp.array[k]=(a.array[i]+carry)%10;

		       }
		      carry=0;
		   }
		i--;k--;
		}
	}
	if(j>1){
		while(j>1){
			if((c.array[j]+carry)>=10){
				temp.array[k]=(c.array[j]+carry)%10;
				carry=1;
			}
			else{
				if((a.array[i]!=-1) && (c.array[j]!=-1))
					temp.array[k]=(c.array[j]+carry)%10;
				else
				{
					if(a.array[i]==-1)
						temp.array[k]=(c.array[j]+carry)%10;
					else
						temp.array[k]=(a.array[i]+carry)%10;

				}
				carry=0;


			}

			j--;k--;
		}
	      //	cout<<" j "<<temp.array[2];
	}
	if(carry){
		temp.array[1]=1;
//		cout<<k;
	}
     //	for(i=0;i<temp.getsize();i++)
   //		cout<<i<<" -  "<<temp.array[i]<<endl;
    //	cout<<"Abouve\n";
//    cout<<a.array[2]<<"  c "<<c.array[2]<<" t "<<temp.array[2];
//    temp.output();
    getch();
	return temp;
}
HugeInteger HugeInteger::sub(HugeInteger a, HugeInteger c){
	int k,j,s1,s2,maxsize,min;

	s1=a.getsize();
	s2=c.getsize();
	if(s1>s2){
		maxsize=s1;
		min=s2;
		}
	else{
		maxsize=s2;
		min=s1;
		}

	HugeInteger temp,comp,diff;
	i=s1-1;j=s2-1;k=maxsize-1;
	cout<<"\n";
       //	comp.output();
       //	cout<<" default"<<endl;
	int carry=0;
	int h,g,f=0;
	//Finding Complement
	if(s1==s2){
		while(i>1){
			comp.array[i]=9-c.array[j];
			j--;i--;
		}
		comp.size=s1;
	}
	else if(s1>s2){

		int lim;
		if(min%2==0)
			lim=maxsize-min;
		else
			lim=maxsize-(min-1);
		while(j>=lim){
			comp.array[k]=9-c.array[j];
		       //	cout<<j<<"j"<<endl;
			k--;j--;
		}
		while(k>1){
			comp.array[k]=9;
			k--;
		}
		comp.size=s1;
	}
	else{
		while(j>1){
			comp.array[j]=9-c.array[j];
			j--;
			//cout<<j<<endl<<"j";
		}
		comp.size=s2;
	}
       //	cout<<"Complement"<<endl;
	//comp.output();
	diff=diff.add(a,comp);
	//Add
       //	cout<<"Adding"<<endl;
	//diff.output();
	if(diff.array[1]==1){ //ther is carry
		diff.array[1]=-1;

		diff.size=s1;
	       //	cout<<"Size diff"<<diff.size;getch();
		diff.array[diff.size-1]+=1;
	if(diff.array[size]>9)
			{
				diff.array[size-1]=diff.array[size-1]%10;
				carry=1;

			}
			for(i=size-1;i>=2;i--)
			{
				diff.array[i]=diff.array[i]+carry;
				if(diff.array[i]>9)
				{
					diff.array[i]=diff.array[i]%10;
					carry=1;

				}
				else
					carry=0;
			}
	    //		diff.output();
	}
	else{
		diff.array[0]=1;
		for(j=s2-1;j>=2;j--)
		{
			diff.array[j]=9-diff.array[j];

		}
		for(i=2;i<s2;i++)
		{
			if(diff.array[i]==0)
				f++;
			else
				break;
		//	cout<<f;getch();
		}
		f+=2;
		if(f==s2)
		{
			diff.array[0]=0;
		}

	}

	//cout<<"Sub done";
       //	getch();
	temp=diff;
	return temp;
}
int HugeInteger::isEqualTo(HugeInteger c)
{
	int s1=getsize();
		if(s1==c.getsize())
		{
			i=2;
			int flag=0;
			while(i<=c.getsize()-1)
			{
				if(HugeInteger::array[i]!=c.array[i])
					flag=1;
				i++;
			}
			if(flag==0)
				//cout<<"true";
				return 1;
	}
	return 0;
}
int HugeInteger::isNotEqualTo(HugeInteger c)
{
		if(getsize()==c.getsize())
		{
			int flag=0;i=2;
			while(i<=c.getsize()-1)
			{
				if(array[i]!=c.array[i]){
					flag=1;
				}
				i++;
			}
			if(flag==1){
				return 1;
			}

		}
		else
			return 1;
	       //	cout<<getsize()<<" "<<c.getsize();
		getch();

	return 0;
}

int HugeInteger::isLessThan(HugeInteger c)
{
		if(HugeInteger::getsize()<c.getsize())
			return 1;
		if(HugeInteger::getsize()==c.getsize())
		{
			int i=2;
			while(i<=HugeInteger::getsize()-1)
				if(HugeInteger::array[i]>c.array[i])
					return 0;
				else if(HugeInteger::array[i]<c.array[i])
					return 1;
				else
					i++;
		}
		return 0;
}

int HugeInteger::isLessThanOrEqualTo(HugeInteger c)
{
		if(isLessThan(c) || isEqualTo(c))
			return 1;
		else
			return 0;

}
int HugeInteger::isGreaterThan(HugeInteger c)
	{
		if(HugeInteger::getsize()>c.getsize())
			return 1;
		if(HugeInteger::getsize()==c.getsize())
		{
			int i=2;
			while(i<=HugeInteger::getsize()-1)
				if(HugeInteger::array[i]>c.array[i])
					return 1;
				else if(HugeInteger::array[i]<c.array[i])
					return 0;
				else
					i++;
		}
		return 0;
}
int HugeInteger::isGreaterThanOrEqualTo(HugeInteger c)
{
		if(isGreaterThan(c))
			return 1;
		else if(isEqualTo(c))
			return 1;
		else
			return 0;

}