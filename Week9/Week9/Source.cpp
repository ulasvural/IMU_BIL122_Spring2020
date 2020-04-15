#include <iostream>
#include "MyVector.h"

using namespace std;

int main()
{
	cout << "###########################" << endl;

	MyVector<int> v1;
	MyVector<int> v2(8);
	MyVector<int> v3(6, 4);
	MyVector<char> v4(8, '$');
	MyVector<char> v5(4, '+');

	cout << "V1\n" << v1 << endl;
	cout << "V2\n" << v2 << endl;
	cout << "V3\n" << v3 << endl;
	cout << "V4\n" << v4 << endl;
	cout << "V5\n" << v5 << endl;

	cout << "###########################" << endl;

	MyVector<int> v6(v3);
	v1 = v2 = v6;

	cout << "V1\n" << v1 << endl;
	cout << "V2\n" << v2 << endl;
	cout << "V3\n" << v3 << endl;
	cout << "V4\n" << v4 << endl;
	cout << "V5\n" << v5 << endl;
	cout << "V6\n" << v6 << endl;

	cout << "###########################" << endl;

	v1.at(2) = 9;
	v2.at(3) = 6;
	v3.at(0) = 1;
	v4.at(0) = '>';
	v5.at(2) = '1';

	cout << "V1\n" << v1 << endl;
	cout << "V2\n" << v2 << endl;
	cout << "V3\n" << v3 << endl;
	cout << "V4\n" << v4 << endl;
	cout << "V5\n" << v5 << endl;
	cout << "V6\n" << v6 << endl;

	cout << "###########################" << endl;

	v1 += v2;
	v2 += v3;

	v4 += v5;

	cout << "V1\n" << v1 << endl;
	cout << "V2\n" << v2 << endl;
	cout << "V3\n" << v3 << endl;
	cout << "V4\n" << v4 << endl;
	cout << "V5\n" << v5 << endl;
	cout << "V6\n" << v6 << endl;


	cout << "###########################" << endl;

	return 0;
}