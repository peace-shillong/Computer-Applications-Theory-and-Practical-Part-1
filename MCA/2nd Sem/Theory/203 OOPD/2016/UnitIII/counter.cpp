#include<iostream>
#include<conio.h>


using namespace std;

class Counter{
private:
	int count;
public:
	Counter();
	Counter(int c);
	Counter(Counter &c);
	void display() { cout << "count  is " << count << endl;}
	Counter operator ++();     //prefix
	Counter operator ++(int);  //postfix

};

Counter::Counter()
{
	count=0;

}

Counter::Counter(int c)
{
	count=c;
}
Counter::Counter(Counter &c)
{
	count=c.count;
}

Counter Counter::operator ++()
{
	return Counter(++count);
}

Counter Counter::operator ++(int)
{
	
	return Counter(count++);
}



int main()
{
	
	Counter c1,c2,c3,c4;
	c1.display();
	c3=c1++;
	c4=++c2;
	c3.display();
	c4.display();
	c1.display();
	c2.display();
	return 1;
	
}





