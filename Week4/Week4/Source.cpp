#include "Numerical.h"
#include <iostream>


using namespace std;

void printNumerical(Numerical & n);

int main()
{
	Numerical n{ 5 }, nDefault{};
	const Numerical constN{ 15 };
	int i{ 10 };
	double d{ 8.9 };

	cout << "Non-const variable: " << n.getMyType() << endl;
	cout << "Non-const variable: " << n.setMyType("Double") << endl;
	cout << "Non-const variable: " << n.getMyType() << endl;

	cout << "Const variable: " << constN.getMyType() << endl;
	//cout << "Const variable: " << constN.setMyType("Double") << endl;
	cout << "Const variable: " << constN.getMyType() << endl;

	printNumerical(nDefault);
	printNumerical(n);

	//printNumerical(i);
	//printNumerical(Numerical(i));
	//printNumerical(Numerical{ i });
	//printNumerical(static_cast<Numerical>(i));

	//printNumerical(d);
	/*printNumerical(Numerical(d));
	printNumerical(Numerical{ d });
	printNumerical(static_cast<Numerical>(d));*/

	return 0;
}

void printNumerical(Numerical & n)
{
	cout << "Type:" << n.getMyType() << endl;
	cout << "Int Val:" << n.getMyIntVal() << endl;
	cout << "Double Val:" << n.getMyDoubleVal()
		<< endl << endl;
}