#pragma once
#include <iostream>
using namespace std;
class String
{
	friend ostream& operator<<(std::ostream&, const String&);
	//friend istream& operator>>(std::istream&, String&);
public:

	String();

	String(const String&);
	String(const size_t, const char gelen = '\0');
	String(const char*);
	String(const char);

	const String& operator=(const char*);
	const String& operator=(const char);
	const String& operator=(const  String&);

	const String& operator+=(const String&);
	const String& operator+=(const char*);
	const String& operator+=(const char);

	const String operator+(const String&);
	const String operator+(const char*);
	const String operator+(const char);

	char operator[](int) const;
	char& operator[](int);

	//bool operator==(const String&) const;
	//bool operator!=(const String&) const;
	//bool operator>(const String&) const;
	//bool operator<(const String&) const;
	//bool operator>=(const String&) const;
	//bool operator<=(const String&) const;

	int getSize() const;
	
	void del();
	void helpfonk(const char*);


private:
	char* str;
	size_t size;
};
