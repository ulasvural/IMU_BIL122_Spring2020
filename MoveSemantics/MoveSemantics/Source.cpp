#include <iostream>

using namespace std;

class A
{
public: 
	A() :x{ 0 }, c{ sc++ } 
	{ 
		cout << "Default Constructor-" << c << " : x = " << x << endl; 
	}

	A(int i) :x{ i }, c{ sc++ } 
	{ 
		cout << "Conversion Constructor-" << c << " : x = " << x << endl; 
	}

	A(const A& a) :x{ a.x }, c{ sc++ } 
	{ 
		cout << "Copy Constructor-" << c << " : x = " << x << " copied from " << a.c << endl; 
	}

	A(const A&& a) :x{ a.x }, c{ sc++ } 
	{ 
		cout << "Move Constructor-" << c << " : x = " << x << " moved from " << a.c << endl; 
	}

	~A() 
	{ 
		cout << "Destructor-" << c << " : x = " << x << endl; 
	}

	A& operator=(const A& a) {
		x = a.x;
		cout << "Copy Assignment Op-" << c << " : x = " << x << " copied from " << a.c << endl;;
		return *this;
	}

	A& operator=(const int i) {
		x = i;
		cout << "Copy Assignment Op-" << c << " : x = " << x << " copied from int variable" << endl;;
		return *this;
	}

	A& operator=(const A&& a) {
		x = a.x;
		cout << "Move Assignment Op-" << c << " : x = " << x << " moved from " << a.c << endl;;
		return *this;
	}
private:
	int x;
	static char sc;
	char c;
};

char A::sc = 'a';

A functionA(A a)
{
	cout << "Func-A Begins" << endl;
	A t = a;
	cout << "Func-A Ends" << endl;

	return t;
}

A functionB(const A& a)
{
	cout << "Func-B Begins" << endl;
	A t = a;
	cout << "Func-B Ends" << endl;
	return t;
}

A functionC(const A&& a)
{
	cout << "Func-C Begins" << endl;
	A t = a;
	cout << "Func-C Ends" << endl;
	return t;
}

int main()
{
	cout << "******" << endl;
	A a;
	cout << "******" << endl;
	A b(20);
	cout << "******" << endl;
	A c(b);

	cout << "******" << endl;
	A d = a;
	cout << "******" << endl;
	
	A e = 10;
	cout << "******" << endl;
	e = d;
	cout << "******" << endl;
	e = 50;
	cout << "******" << endl;
	e = move(d);
	cout << "******" << endl;
	A f(move(a)); //move -> A&&
	cout << "******" << endl;
	
	functionA(e);
	cout << "******" << endl; 
	e = functionA(e);
	cout << "******" << endl;
	functionB(e);
	cout << "******" << endl;
	e = functionB(e);
	cout << "******" << endl;
	functionC(move(e));
	cout << "******" << endl;
	e = functionC(move(e));
	cout << "******" << endl;
	return 0;
}