#include<iostream>

using namespace std;

class SmartIntPtr {
public:
	SmartIntPtr(int * ptr) :data(ptr) {}
	SmartIntPtr(const SmartIntPtr &) = delete; // unique_ptr gibi
	SmartIntPtr & operator=(const SmartIntPtr &) = delete;
	~SmartIntPtr()
	{
		if (data)
			delete data;
	}

	//dereferencing operator
	int& operator*() { return *data; }
	int operator*() const { return *data; }

private:
	int * data;
	// int counter; // shared_ptr icin
};

int main()
{
	SmartIntPtr sPtr{ new int{19} };
	const SmartIntPtr csPtr{ new int{29} };

	if (*sPtr == 0)
		return 0;

	cout << "data:" << *sPtr << endl;
	(*sPtr)++;
	cout << "data:" << *sPtr << endl;

	cout << "data:" << *csPtr << endl;
	//(*csPtr)++; //hatali cunku csPtr const ama degeri degistirilebilecek bir operator cagriliyor
	cout << "data:" << *csPtr << endl;

	return 0;
}


#ifdef __STL_SMART_POINTERS__
#include<iostream>
#include<memory>

using namespace std;

void testUniquePtr(const unique_ptr<int>& prm)
{
	cout << "Func Ptr:" << *prm << endl;
}

int main()
{
	auto rawPtr = new int{ 5 };

	auto xPtr = unique_ptr<int>{ rawPtr };
	unique_ptr<int> xPtr1 = unique_ptr<int>{ new int{ 120 } };

	std::cout << *rawPtr << " " << *xPtr << " " << *xPtr1 << endl;
	*rawPtr = 10;
	std::cout << *rawPtr << " " << *xPtr << " " << *xPtr1 << endl;
	*xPtr = 20;
	std::cout << *rawPtr << " " << *xPtr << " " << *xPtr1 << endl;
	*xPtr1 = 30;
	std::cout << *rawPtr << " " << *xPtr << " " << *xPtr1 << endl;
	testUniquePtr(xPtr);

	auto rawPtr1 = new int{ 99 };
	auto xSPtr = shared_ptr<int>{ rawPtr1 };
	auto xSPtr1 = xSPtr;

	std::cout << "Shared:" << *rawPtr1 << " " << *xSPtr << " " << *xSPtr1 << endl;
	*xSPtr = 10;
	std::cout << "Shared:" << *rawPtr1 << " " << *xSPtr << " " << *xSPtr1 << endl;
	*xSPtr = 10;
	std::cout << "Shared:" << *rawPtr1 << " " << *xSPtr << " " << *xSPtr1 << endl;

	return 0;
}
#endif

//#define __RAW_POINTER_PROBLEMS__

#ifdef __RAW_POINTER_PROBLEMS__
// raw pointer kullaniminin problemleri 
#include <iostream>

using namespace std;

int main()
{
	int *a = new int{ 0 };
	if (!a)
		return -1;

	int *b = new int{ 0 };
	if (!b)
		return -1;

	cout << "a: ";
	cin >> *a;

	cout << "b: ";
	cin >> *b;

	if (!(*b))  
	{
		cout << "a: " << *a << "\tb: " << *b << endl;
		cout << "Sýfýra bölme tanýmsýzdýr.";
		delete a; // unutmasi kolay!!!
		delete b;
		
		return 0;
	}

	cout << "a: " << *a << "\tb: " << *b << endl;
	cout << "a/b: " << *a / *b << endl;

	delete a;
	delete b;

	return 0;
}
#endif