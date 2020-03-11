#include <iostream>

using namespace std;

auto x{ 100 };

void localVariable()
{
	auto z{ 0 };
	cout << "Local-A: " << z << endl;
	cout << "Local-B: " << ++z << endl;
}

void globalVariable()
{
	cout << "Global-A: " << x << endl;
	cout << "Global-B: " << ++x << endl;
}

void staticVariable()
{
	static auto y{ 1000 };
	cout << "Static-A: " << y << endl;
	cout << "Static-B: " << ++y << endl;
}

int main3()
{
	localVariable();
	globalVariable();
	staticVariable();

	localVariable();
	globalVariable();
	staticVariable();

	for (int i = 0; i < 10; ++i);

	for (int i = 0; i < 10; ++i);

	return 0;
}