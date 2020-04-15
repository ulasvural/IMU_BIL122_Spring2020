#include <iostream>
#include "MyVector.h"

using namespace std;

int main()
{
	MyVector<int> v1;
	MyVector<int> v2(8);
	MyVector<int> v3(6, 4);
	MyVector<char> v5(8, '$');

	//cout << "V1\n" << v1 << endl;
	//cout << "V2\n" << v2 << endl;
	//cout << "V3\n" << v3 << endl;

	MyVector<int> v4(v3);
	v1 = v2 = v4;

	/*cout << "###########################" << endl;
	cout << "V1\n" << v1 << endl;
	cout << "V2\n" << v2 << endl;
	cout << "V3\n" << v3 << endl;
	cout << "V4\n" << v4 << endl;
*/
	v1.at(2) = 9;
	v2.at(3) = 6;
	v3.at(0) = 1;

	//cout << "###########################" << endl;
	//cout << "V1\n" << v1 << endl;
	//cout << "V2\n" << v2 << endl;
	//cout << "V3\n" << v3 << endl;
	//cout << "V4\n" << v4 << endl;

	return 0;
}