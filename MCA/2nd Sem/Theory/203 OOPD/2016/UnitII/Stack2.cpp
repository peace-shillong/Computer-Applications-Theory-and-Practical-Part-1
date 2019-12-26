#include<iostream>

using namespace std;

template <class T>
class Stack2
{
	int top;
	T *a;
	int size;

public:
	Stack2(int s);
	T pop();
	void push(T var);
	~Stack2()
	{
		delete[] a;
	}
};

template <class T>
Stack2<T>::Stack2(int s)
{
	a=new T[s];
	size=s;
	top=-1;
}

template <class T>
T Stack2<T>::pop()
{
	return a[top--];
}

template <class T>
void Stack2<T>::push(T var)
{
	a[++top]=var;
}


int main()
{
	Stack2<int> st(3);
	Stack2<float> st1(2);

	st.push(2);
	st.push(3);
	st.push(4);

	cout << st.pop() << endl;

	st1.push(2.5);
	st1.push(5.5);

	cout << st1.pop() << endl;

	return 0;
}

