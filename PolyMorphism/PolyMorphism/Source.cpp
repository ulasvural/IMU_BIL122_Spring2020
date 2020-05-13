#include <iostream>
#include <vector>

#include "Header.h"


using namespace std;

int main()
{
	cout << "CONSTRUCTORS" << endl;

	vector<A *> basePtrs = { new A(), new B(), new C, new D };

	cout << "NON-VIRTUAL FUNCTIONS" << endl;
	for (const A * p : basePtrs)
		p->nonVirt();

	cout << "VIRTUAL FUNCTIONS" << endl;
	for (const A * p : basePtrs)
		p->virt();


	cout << "SPECIAL FUNCTION" << endl;
	for (A * p : basePtrs)
	{
		C * cPtr = dynamic_cast<C*>(p);

		if (cPtr != nullptr)
		{
			cPtr->cSpecial();
			cPtr->cSpecialVirt();
		}
		else cout << "C Nesnesi degil" << endl;
	}


	cout << "DESTRUCTORS" << endl;
	for (const A * p : basePtrs)
		delete p;

	return 0;
}