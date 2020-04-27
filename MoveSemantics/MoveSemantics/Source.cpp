#include <iostream>

template<class T>
class Auto_ptr4
{
	T* m_ptr;
public:
	Auto_ptr4(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr4()
	{
		delete m_ptr;
	}

	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr4(const Auto_ptr4& a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Move constructor
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4(Auto_ptr4&& a)
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr; // we'll talk more about this line below
	}

	// Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr4& operator=(const Auto_ptr4& a)
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Copy the resource
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	// Move assignment
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4& operator=(Auto_ptr4&& a)
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // we'll talk more about this line below

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr4<Resource> generateResource()
{
	Auto_ptr4<Resource> res(new Resource);
	return res; // this return value will invoke the move constructor
}

int main()
{
	Auto_ptr4<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the move assignment

	return 0;
}
//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public: 
//	A() :x{ 0 }, c{ sc++ } 
//	{ 
//		cout << "Default Constructor-" << c << " : x = " << x << endl; 
//	}
//
//	A(int i) :x{ i }, c{ sc++ } 
//	{ 
//		cout << "Conversion Constructor-" << c << " : x = " << x << endl; 
//	}
//
//	A(const A& a) :x{ a.x }, c{ sc++ } 
//	{ 
//		cout << "Copy Constructor-" << c << " : x = " << x << " copied from " << a.c << endl; 
//	}
//
//	A(const A&& a) :x{ a.x }, c{ sc++ } 
//	{ 
//		cout << "Move Constructor-" << c << " : x = " << x << " moved from " << a.c << endl; 
//	}
//
//	~A() 
//	{ 
//		cout << "Destructor-" << c << " : x = " << x << endl; 
//	}
//
//	A& operator=(const A& a) {
//		x = a.x;
//		cout << "Copy Assignment Op-" << c << " : x = " << x << " copied from " << a.c << endl;;
//		return *this;
//	}
//
//	A& operator=(const int i) {
//		x = i;
//		cout << "Copy Assignment Op-" << c << " : x = " << x << " copied from int variable" << endl;;
//		return *this;
//	}
//
//	A& operator=(const A&& a) {
//		x = a.x;
//		cout << "Move Assignment Op-" << c << " : x = " << x << " moved from " << a.c << endl;;
//		return *this;
//	}
//private:
//	int x;
//	static char sc;
//	char c;
//};
//
//char A::sc = 'a';
//
//A functionA(A a)
//{
//	cout << "Func-A Begins" << endl;
//	A t = a;
//	cout << "Func-A Ends" << endl;
//
//	return t;
//}
//
//A functionB(const A& a)
//{
//	cout << "Func-B Begins" << endl;
//	A t = a;
//	cout << "Func-B Ends" << endl;
//	return t;
//}
//
//A functionC(const A&& a)
//{
//	cout << "Func-C Begins" << endl;
//	A t = a;
//	cout << "Func-C Ends" << endl;
//	return t;
//}
//
//int main()
//{
//	cout << "******" << endl;
//	A a;
//	cout << "******" << endl;
//	A b(20);
//	cout << "******" << endl;
//	A c(b);
//
//	cout << "******" << endl;
//	A d = a;
//	cout << "******" << endl;
//	
//	A e = 10;
//	cout << "******" << endl;
//	e = d;
//	cout << "******" << endl;
//	e = 50;
//	cout << "******" << endl;
//	e = move(d);
//	cout << "******" << endl;
//	A f(move(a)); //move -> A&&
//	cout << "******" << endl;
//	
//	functionA(e);
//	cout << "******" << endl; 
//	e = functionA(e);
//	cout << "******" << endl;
//	functionB(e);
//	cout << "******" << endl;
//	e = functionB(e);
//	cout << "******" << endl;
//	functionC(move(e));
//	cout << "******" << endl;
//	e = functionC(move(e));
//	cout << "******" << endl;
//	return 0;
//}