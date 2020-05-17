#include "Header.h"

A::A()
{
	cout << "Const-A\n";
}

A::~A()
{
	cout << "Dest-A\n";
}

void A::nonVirt() const
{
	cout << "Non-Virt-A\n";
}

void A::virt() const
{
	cout << "Virt-A\n";
}

void A::virtNonCost()
{
	cout << "Virt-A NonConst\n";
}

B::B()
{
	cout << "Const-B\n";
}

B::~B()
{
	cout << "Dest-B\n";
}

void B::nonVirt() const
{
	cout << "Non-Virt-B\n";
}

void B::virt() const
{
	cout << "Virt-B\n";
}

C::C()
{
	cout << "Const-C\n";
}

C::~C()
{
	cout << "Dest-C\n";
}
void C::nonVirt() const
{
	cout << "Non-Virt-C\n";
}

void C::virt() const
{
	cout << "Virt-C\n";
}

void C::cSpecial() const
{
	cout << "C-Special-Non-Virtual\n";
}

void C::cSpecialVirt() const
{
	cout << "C-Special-Virtual\n";
}

D::D()
{
	cout << "Const-D\n";
}

D::~D()
{
	cout << "Dest-D\n";
}