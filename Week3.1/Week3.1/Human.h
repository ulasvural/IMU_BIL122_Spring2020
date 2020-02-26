#pragma once
#include <string>

using namespace std;

class Human
{
public:


	void printInfo() const;

	bool setName(const string & name);
	string getName() const;

	bool setAge(int age);
	int getAge() const;


private:
	string name;
	int age;

};

