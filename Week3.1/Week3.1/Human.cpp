#include "Human.h"
#include <iostream>

using namespace std;

//Human::Human(const string & name):age{0}
//{
//	setName(name);
//}

Human::Human(const string & name, int age)
{
	setName(name);
	setAge(age);
}

void Human::printInfo() const
{
	cout << "Name: " << this->name << endl;
	cout << "Age: " << this->age << endl;
}

bool Human::setName(const string & name)
{
	if (name.length() < 2 || name.length() > 40)
		return false;

	this->name = name;
	return true;
}

string Human::getName() const
{
	return this->name;
}

bool Human::setAge(int age)
{
	if (age < 0 || age > 120)
		return false;

	this->age = age;
	return true;
}

int Human::getAge() const
{
	return this->age;
}
