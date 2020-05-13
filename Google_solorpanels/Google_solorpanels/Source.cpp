#include <iostream>
#include <math.h>

using namespace std;

int area(long long int totalArea)
{
	if (totalArea < 1)
		return 0;
	
	long long int minSq = (long long int)sqrt(totalArea);

	cout << minSq << " ";
	return area(totalArea - minSq * minSq);
}

int main()
{
	cout << "15324" << endl;
	area(15324);
	cout << endl << endl << "12" << endl;
	area(1);
	cout << endl << endl << "-12" << endl;
	area(-12);
	cout << endl << endl << "64" << endl;
	area(1000000);
	cout << endl << endl << "65" << endl;
	area(65);

	return 0;
}