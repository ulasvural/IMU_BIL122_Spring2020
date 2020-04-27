#include "MyString.h"

ostream & operator<<(ostream & out, const MyString & str)
{
	for (int i{ 0 }; i < str.size; ++i)
		out << str.str[i];

	return out;
}

istream & operator>>(istream & in, MyString & str)
{
	int s{ 0 };
	in >> s;

	if (s > 0)
	{
		str.size = s;
		str.str = new char[s];

		if (!str.str)
			throw(-1);

		for (int i = 0; i < s; ++i)
			cin.get(str.str[i]);
	}
	
	return in;
}

MyString::MyString():size{0}, str{nullptr}
{

}

MyString::MyString(const MyString & otherString):size{ otherString.size}
{
	cout << "Copy constructor" << endl;
	str = new char[size];
	
	if (str == nullptr)
		throw(-1);

	for (auto i = 0; i < size; ++i)
		str[i] = otherString.str[i];
}

MyString::MyString(MyString && otherString):
	size{ otherString.size }, str{otherString.str}
{
	cout << "Move constructor" << endl;
	otherString.size = 0;
	otherString.str = nullptr;
}

MyString::MyString(const char * cString)
{
	size = strlen(cString);

	str = new char[size];

	if (str == nullptr)
		throw(-1);

	for (auto i = 0; i < size; ++i)
		str[i] = cString[i];
}

MyString::~MyString()
{
	if (str != nullptr)
		delete[] str;

	str = nullptr;
}

MyString & MyString::operator=(const MyString & otherString)
{
	cout << "Copy Assignment" << endl;
	// self assignment
	if (this != &otherString)
	{
		if (str)
			delete[] str;

		size = otherString.size;

		str = new char[size];

		if (str == nullptr)
			throw(-1);

		for (auto i = 0; i < size; ++i)
			str[i] = otherString.str[i];
	}

	return *this;
}

MyString & MyString::operator=(MyString && otherString)
{
	cout << "Move Assignment" << endl;

	if (this == &otherString)
		return *this;

	if (str)
		delete[] str;

	size = otherString.size;
	str = otherString.str;

	otherString.size = 0;
	otherString.str = nullptr;

	return *this;
}

MyString & MyString::operator+=(const MyString & otherString)
{
	// self assignment
	int tempSize = size + otherString.size;
	char * tempStr = new char[tempSize];

	if (tempStr == nullptr)
		throw(-1);

	for (auto i = 0; i < size; ++i)
		tempStr[i] = str[i];

	for (auto i = 0; i < otherString.size; ++i)
		tempStr[size + i] = otherString.str[i];

	if (str)
		delete[] str;

	size = tempSize;
	str = tempStr;

	return *this;
}

bool MyString::operator!() const
{
	return (size == 0);
}

bool MyString::operator==(const MyString & otherString) const
{
	if ( size != otherString.size)
		return false;

	for (int i = 0; i < size; ++i)
		if (str[i] != otherString.str[i])
			return false;

	return true;
}

bool MyString::operator!=(const MyString & otherString) const
{
	return !(*this == otherString);
}

bool MyString::operator>(const MyString & otherString) const
{
	int minSize = (size < otherString.size) ? size : otherString.size;

	for (int i = 0; i < minSize; ++i)
		if (otherString.str[i] > str[i])
			return false;

	if (size > otherString.size)
		return true;

	return false;
}

bool MyString::operator<(const MyString & otherString) const
{
	return !(*this >= otherString);
}

bool MyString::operator>=(const MyString & otherString) const
{
	return (*this > otherString || *this == otherString);
}

bool MyString::operator<=(const MyString & otherString) const
{
	return !(*this > otherString);
}

MyString MyString::operator+(const MyString & otherString) const
{
	MyString temp(*this);

	temp += otherString;

	return temp;
}

char & MyString::operator[](int idx)
{
	return str[idx];
}

char MyString::operator[](int idx) const
{
	return str[idx];
}
