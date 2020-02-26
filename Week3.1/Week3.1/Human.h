#pragma once
#include <string>

using namespace std;

class Human
{
public:
	// Conversion constructor
	//Human(const string & name);
	
	// Default Constructor ???
	// Conversion constructor (string)
	// 2-parameter Constructor
	Human(const string & name = "Mehmet", int age = 0);

	void printInfo() const;

	bool setName(const string & name);
	string getName() const;

	bool setAge(int age);
	int getAge() const;


private:
	string name;
	int age;

};

