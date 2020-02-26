#include "Human.h"

int main()
{
	const Human mehmet;
	mehmet.getName();
	mehmet.printInfo();

	Human ahmet("Ahmet");
	ahmet.printInfo();

	Human zeynep("Zeynep", 29);
	zeynep.printInfo();

	return 0;
}