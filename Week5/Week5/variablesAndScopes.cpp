#include <iostream>

using namespace std;

auto var{ 8 };

int main2()
{
	cout << "A: " << var << endl;

	auto var{ 10 };

	cout << "B: " << var << endl;
	cout << "C: " << ::var << endl;

	{
		auto var{ 20 };
		cout << "D: " << var << endl;
		cout << "E: " << ::var << endl;
	}

	{
		// Compile Error
		/*auto var{ var };
		int var{ var };
		int var = var; */

		int var{ 100 };
		cout << "F: " << var << endl;
	}

	cout << "G: " << var << endl;

	return 0;
}