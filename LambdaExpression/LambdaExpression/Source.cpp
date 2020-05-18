
#define __STR_COMPARISON_LAMBDA__

#ifdef __STR_COMPARISON_1__

#include <iostream>
#include <string>

using namespace std;

template<class T>
bool compare(const T & item1, const T & item2)
{
	if (item1 > item2)
		return true;

	return false;
}

template<class T>
void swapItems(T & item1, T & item2)
{
	T temp = item1;
	item1 = item2;
	item2 = temp;
}

template<class T>
void print(const T* items, int size)
{
	if (size < 1)
	{
		cout << "Empty array" << endl;
		return;
	}
		
	for (auto i{ 0 }; i < size - 1; ++i)
		cout << items[i] << ", ";
	cout << items[size - 1] << endl;
}

template<class T>
void sort(T* items, int size)
{
	for (auto i{ 0 }; i < size; ++i)
		for (auto j{ i+1 }; j < size; ++j)
			if (!compare(items[i], items[j]))
				swapItems(items[i], items[j]);
}

int main()
{
	int dizi1[] = { 34, 23, 5, 2, 67, 5, 24, 99, 0 };

	print(dizi1, sizeof(dizi1) / sizeof(int));
	sort(dizi1, sizeof(dizi1) / sizeof(int)); // buyukten kucuge
	print(dizi1, sizeof(dizi1) / sizeof(int));
	sort(dizi1, sizeof(dizi1) / sizeof(int)); // kucukten buyuge
	print(dizi1, sizeof(dizi1) / sizeof(int));

	char dizi2[] = { 'a', 'Z', 'c', 'G', 'n', 'f', 'y', 'A', 'u', 'm', 'T', };

	print(dizi2, sizeof(dizi2) / sizeof(char));
	sort(dizi2, sizeof(dizi2) / sizeof(char));
	print(dizi2, sizeof(dizi2) / sizeof(char));

	return 0;
}

#elif defined __STR_COMPARISON_2__
#include <iostream>
#include <string>

using namespace std;

template<class T>
bool isGreater(const T & item1, const T & item2)
{
	if (item1 > item2)
		return true;

	return false;
}

template<class T>
bool isSmaller(const T & item1, const T & item2)
{
	if (item1 < item2)
		return true;

	return false;
}

template<class T>
void swapItems(T & item1, T & item2)
{
	T temp = item1;
	item1 = item2;
	item2 = temp;
}

template<class T>
void print(const T* items, int size)
{
	if (size < 1)
	{
		cout << "Empty array" << endl;
		return;
	}

	for (auto i{ 0 }; i < size - 1; ++i)
		cout << items[i] << ", ";
	cout << items[size - 1] << endl;
}

template<class T>
void sort(T* items, int size, bool(*compare)(const T&, const T&))
{
	for (auto i{ 0 }; i < size; ++i)
		for (auto j{ i + 1 }; j < size; ++j)
			if (!compare(items[i], items[j]))
				swapItems(items[i], items[j]);
}

int main()
{
	int dizi1[] = { 34, 23, 5, 2, 67, 5, 24, 99, 0 };

	print(dizi1, sizeof(dizi1) / sizeof(int));
	sort(dizi1, sizeof(dizi1) / sizeof(int), isGreater);
	print(dizi1, sizeof(dizi1) / sizeof(int));
	sort(dizi1, sizeof(dizi1) / sizeof(int), isSmaller);
	print(dizi1, sizeof(dizi1) / sizeof(int));
	cout << endl;

	char dizi2[] = { 'a', 'Z', 'c', 'G', 'n', 'f', 'y', 'A', 'u', 'm', 'T', };

	print(dizi2, sizeof(dizi2) / sizeof(char));
	sort(dizi2, sizeof(dizi2) / sizeof(char), isGreater);
	print(dizi2, sizeof(dizi2) / sizeof(char));
	sort(dizi2, sizeof(dizi2) / sizeof(char), isSmaller);
	print(dizi2, sizeof(dizi2) / sizeof(char));
	cout << endl;
	return 0;
}

#elif defined __STR_COMPARISON_3__
#include <iostream>
#include <string>

using namespace std;

template<class T>
bool isGreater(const T & item1, const T & item2)
{
	if (item1 > item2)
		return true;

	return false;
}

template<class T>
bool isSmaller(const T & item1, const T & item2)
{
	if (item1 < item2)
		return true;

	return false;
}

bool isSmallerLex(const char & item1, const char & item2)
{
	char temp1 = toupper(item1);
	char temp2 = toupper(item2);

	if (temp1 < temp2)
		return true;

	return false;
}

template<class T>
void swapItems(T & item1, T & item2)
{
	T temp = item1;
	item1 = item2;
	item2 = temp;
}

template<class T>
void print(T* items, int size)
{
	if (size < 1)
	{
		cout << "Empty array" << endl;
		return;
	}

	for (auto i{ 0 }; i < size - 1; ++i)
		cout << items[i] << ", ";
	cout << items[size - 1] << endl;
}

template<class T>
void sort(T* items, int size, bool(*compare)(const T&, const T&))
{
	for (auto i{ 0 }; i < size; ++i)
		for (auto j{ i + 1 }; j < size; ++j)
			if (!compare(items[i], items[j]))
				swapItems(items[i], items[j]);
}

int main()
{
	int dizi1[] = { 34, 23, 5, 2, 67, 5, 24, 99, 0 };

	print(dizi1, sizeof(dizi1) / sizeof(int));
	sort(dizi1, sizeof(dizi1) / sizeof(int), isGreater);
	print(dizi1, sizeof(dizi1) / sizeof(int));
	sort(dizi1, sizeof(dizi1) / sizeof(int), isSmaller);
	print(dizi1, sizeof(dizi1) / sizeof(int));
	//sort(dizi1, sizeof(dizi1) / sizeof(int), isSmallerLex); // Hata!!!
	cout << endl;

	char dizi2[] = { 'a', 'Z', 'c', 'G', 'n', 'f', 'y', 'A', 'u', 'm', 'T', };

	print(dizi2, sizeof(dizi2) / sizeof(char));
	sort(dizi2, sizeof(dizi2) / sizeof(char), isGreater);
	print(dizi2, sizeof(dizi2) / sizeof(char));
	sort(dizi2, sizeof(dizi2) / sizeof(char), isSmaller);
	print(dizi2, sizeof(dizi2) / sizeof(char));
	sort(dizi2, sizeof(dizi2) / sizeof(char), isSmallerLex);
	print(dizi2, sizeof(dizi2) / sizeof(char));
	cout << endl;
	return 0;
}
#elif defined __LAMBDA_1__
// Lambda Expressions


// Ref: https://www.drdobbs.com/cpp/lambdas-in-c11/240168241
// Ref: https://www.softwaretestinghelp.com/lambdas-in-cpp/

#include <iostream>

using namespace std;

int main()
{
	// [CAPTURE CLAUSE](parameter_list) mutable exception -> return_type {BODY} 
	auto lambda = []() { cout << "Code within a lambda expression" << endl; };
	lambda();

	[](){ cout << "Lambda expression without any label 1" << endl; };
	[](){ cout << "Lambda expression without any label 2" << endl; } ();

	return 0;
}
#elif defined __LAMBDA_2__
#include <iostream>

using namespace std;

int main()
{
	auto sum = [](int x, int y) { return x + y; };
	cout << sum(5, 2) << endl;
	cout << sum(10, 5) << endl;

	return 0;
}
#elif defined __LAMBDA_3__

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> numbers{ 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
	auto greater_than_5_count = 
		count_if(numbers.begin(), numbers.end(), [](int x) { return (x > 7); });
	cout << "The number of elements greater than 5 is: "
		<< greater_than_5_count << "." << endl;
}

#elif defined __LAMBDA_4__

#include <iostream>
#include <string>

using namespace std;

int main()
{
	auto sum = [](int a, int b) {
		return a + b;
	};

	cout << "Sum of two integers:" << sum(5, 6) << endl;

	return 0;
}
#elif defined __GENERALIZED_LAMBDA_1__

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int numberOfMultOp{ 0 };
	int numberOfSumOp{ 0 };

	auto mult = [numberOfSumOp, &numberOfMultOp](const int & a, const int & b) -> int {
		numberOfMultOp++;
		cout << "#*:" << numberOfSumOp << " " << numberOfMultOp << endl;
		return a + b;
	};

	// generalized lambda
	auto sum = [&numberOfSumOp, numberOfMultOp](const auto & a, const auto & b) -> auto {
		numberOfSumOp++;
		cout << "#+:" << numberOfSumOp << " " << numberOfMultOp << endl;
		return a + b;
	};

	cout << "Sum(5,6) = " << sum(5, 6) << endl; // sum of two integers
	cout << "Mul(5,6) = " << mult(5, 6) << endl; // mul of two integers

	cout << "Sum(2.0,6.5) = " << sum(2.0, 6.5) << endl; // sum of two float numbers

	// sum of two strings
	cout << "Sum((string(\"SoftwareTesting\"), string(\"help.com\")) = "
		<< sum(string("SoftwareTesting"), string("help.com")) << endl; 

		return 0;
}
#elif defined __STR_COMPARISON_LAMBDA__

#include <iostream>
#include <string>

using namespace std;

template<class T>
bool isGreater(const T & item1, const T & item2)
{
	if (item1 > item2)
		return true;

	return false;
}

template<class T>
bool isSmaller(const T & item1, const T & item2)
{
	if (item1 < item2)
		return true;

	return false;
}

bool isSmallerLex(const char & item1, const char & item2)
{
	char temp1 = toupper(item1);
	char temp2 = toupper(item2);

	if (temp1 < temp2)
		return true;

	return false;
}

template<class T>
void swapItems(T & item1, T & item2)
{
	T temp = item1;
	item1 = item2;
	item2 = temp;
}

template<class T>
void print(const T* items, int size)
{
	if (size < 1)
	{
		cout << "Empty array" << endl;
		return;
	}

	for (auto i{ 0 }; i < size - 1; ++i)
		cout << items[i] << ", ";
	cout << items[size - 1] << endl;
}

template<class T, class F>
void sort(T* items, int size, F compare)
{
	for (auto i{ 0 }; i < size; ++i)
		for (auto j{ i + 1 }; j < size; ++j)
			if (!compare(items[i], items[j]))
				swapItems(items[i], items[j]);
}

int main()
{
	int dizi1[] = { 34, 23, 5, 2, 67, 5, 24, 99, 0 };

	print(dizi1, sizeof(dizi1) / sizeof(int));
	sort(dizi1, sizeof(dizi1) / sizeof(int), isGreater<int>);
	print(dizi1, sizeof(dizi1) / sizeof(int));
	sort(dizi1, sizeof(dizi1) / sizeof(int), isSmaller<int>);
	print(dizi1, sizeof(dizi1) / sizeof(int));
	// sort(dizi1, sizeof(dizi1) / sizeof(int), isSmallerLex); // Hata!!!
	cout << endl;

	char dizi2[] = { 'a', 'Z', 'c', 'G', 'n', 'f', 'y', 'A', 'u', 'm', 'T', };

	print(dizi2, sizeof(dizi2) / sizeof(char));
	sort(dizi2, sizeof(dizi2) / sizeof(char), isGreater<char>);
	print(dizi2, sizeof(dizi2) / sizeof(char));
	sort(dizi2, sizeof(dizi2) / sizeof(char), isSmaller<char>);
	print(dizi2, sizeof(dizi2) / sizeof(char));
	sort(dizi2, sizeof(dizi2) / sizeof(char), isSmallerLex);
	print(dizi2, sizeof(dizi2) / sizeof(char));
	sort(dizi2, sizeof(dizi2) / sizeof(char), isSmallerLex);
	print(dizi2, sizeof(dizi2) / sizeof(char));

	sort(dizi2, sizeof(dizi2) / sizeof(char), [](const char & i1, const char & i2)->bool
		{
			if (i1 > i2) return true;
			return false;
		});
	print(dizi2, sizeof(dizi2) / sizeof(char));
	cout << endl;
	return 0;
}


#elif defined __FUNCTORS_1__
// Ref: https://www.bogotobogo.com/cplusplus/functors.php
#include <iostream>
using namespace std;

class Line {
	double a;	// slope
	double b;	// y-intercept

public:
	Line(double slope = 1, double yintercept = 1) :
		a(slope), b(yintercept) {}
	double operator()(double x) {
		return a * x + b;
	}
};

int main() {
	Line fa;			// y = 1*x + 1
	Line fb(5.0, 10.0);		// y = 5*x + 10

	double y1 = fa(20.0);		// y1 = 20 + 1
	double y2 = fb(3.0);		// y2 = 5*3 + 10

	cout << "y1 = " << y1 << " y2 = " << y2 << endl;
	return 0;
}

#elif defined __FUNCTORS_2__
// Ref: https://www.bogotobogo.com/cplusplus/functors.php

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Print {
public:
	void operator()(int elem) const {
		cout << elem << " ";
	}
};

int main() {
	vector<int> vect;
	for (int i = 1; i < 10; ++i) {
		vect.push_back(i);
	}

	Print print_it;
	for_each(vect.begin(), vect.end(), print_it);
	cout << endl;
	return 0;
}

#endif