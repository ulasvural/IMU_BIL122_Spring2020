#include <iostream>
#include <string>

using namespace std;

class A
{
public:
	A(const string& a = ""):a{a}
	{
		cout << "A-Const:" << a << endl;
	}

	~A()
	{
		cout << "A-Dest:" << a << endl;
	}
private:
	string a;
};

class B
{
public:
	B(const string& b = "b") :b{ b }, a{b}
	{
		cout << "B-Const:" << b << endl;
		//a = A("x");		
	}

	~B()
	{
		cout << "B-Dest:" << b << endl;
	}
private:
	A a;
	string b;
};

class C : public B {
public:
	C(const string& c = "c") :c{ c }, a1{ c }, B{ c }
	{
		cout << "C-Const:" << c << endl;
		//a1 = A("x");
	}

	~C()
	{
		cout << "C-Dest:" << c << endl;
	}
private:
	A a1;
	string c;
};

int main()
{
	C c1{ "1" };
	//B b2{ "2" };

	return 0;
}