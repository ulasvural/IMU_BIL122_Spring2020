#pragma once
#include <iostream>

using namespace std;

class MyString
{
	friend ostream& operator<<(ostream& out, const MyString& str);
	friend istream& operator>>(istream& in, MyString& str);
public:
	MyString();
	MyString(const MyString & otherString);
	MyString(MyString && otherString);
	MyString(const char * cString);

	~MyString();

	MyString& operator=(const MyString& otherString);
	MyString& operator=(MyString&& otherString);

	MyString& operator+=(const MyString& otherString);

	// bool isEmpty() const;
	// int length() const;
	// char& at(int idx);  // throws exception
	// char at(int idx) const; // throws exception

	// Stringin bos olup olmadigini kontrol eder. Bossa true doner.
	bool operator!() const;

	bool operator==(const MyString& otherString) const;
	bool operator!=(const MyString& otherString) const;
	bool operator>(const MyString& otherString) const;
	bool operator<(const MyString& otherString) const;
	bool operator>=(const MyString& otherString) const;
	bool operator<=(const MyString& otherString) const;

	MyString operator+(const MyString& otherString) const;

	char& operator[](int idx);
	char operator[](int idx) const;

private:
	char * str;
	int size;
};

