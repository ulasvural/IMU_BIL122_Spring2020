#include <iostream>     
#include <iomanip>      
#include <string>

#include "MyVector.h"
#include "MyQueue.h"
#include "MyStack.h"

using namespace std;

void title(const string & strArg, char fillchar = '*', int screenWidth = 60)
{
	string str = "  " + strArg + "  ";

	cout.width(screenWidth); cout.fill(fillchar); cout << fillchar << endl;

	cout.width(screenWidth / 2); 
	cout.fill(fillchar); 
	cout << str.substr(0, str.length() / 2);

	cout.width(screenWidth / 2);
	cout.fill(fillchar); 
	cout << left << str.substr(str.length() / 2, str.length() / 2) << endl;

	cout.width(screenWidth); cout.fill(fillchar); cout << fillchar << endl;

	cout << right << endl;
}


int main()
{
	title("TEST VECTOR CONSTRUCTORS");

	MyVector<int> v1( 10, 5 );
	MyVector<char> v2( 10, 'a' );
	//MyVector<int> v1{10, 5};  // mantik hatasina neden olabilir!!!
	//MyVector<char> v2{10, 'a'};
	MyVector<int> v3{1, 2, 3, 4, 5, 6, 7, 56, 54, 34, 38, 768};

	MyVector<int> v4;

	v4 += v3;
	v4 += v3;

	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;
	cout << "v3: " << v3 << endl;
	cout << "v4: " << v4 << endl;
	
	title("TEST QUEUE CONSTRUCTORS");

	MyQueue<int> q1;
	MyQueue<int> q2{ 1, 2, 3, 4, 5, 6, 7, 56, 54, 34, 768 };
	MyQueue<int> q3 = v4;
	MyQueue<int> q4{ v4 };

	cout << "q1: " << q1 << endl;
	cout << "q2: " << q2 << endl;
	cout << "q3: " << q3 << endl;
	cout << "q4: " << q4 << endl;

	title("TEST QUEUE POP");

	while (q3.getSize()>0)
		cout << "q3 pop: " << q3.pop() << " --> q3: " << q3 << endl;


	title("TEST QUEUE PUSH");

	while (q3.getSize() < 10)
	{
		q3.push(q3.getSize() * 5);
		cout << "q3: " << q3 << endl;
	}

	title("TEST QUEUE POP");

	while (q3.getSize() > 0)
		cout << "q3 pop: " << q3.pop() << " --> q3: " << q3 << endl;


	title("TEST STACK CONSTRUCTORS");

	MyStack<int> s1;
	MyStack<int> s2{ 1, 2, 3, 4, 5, 6, 7, 56, 54, 34, 768 };
	MyStack<int> s3 = v4;
	MyStack<int> s4{ v4 };

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;

	title("TEST STACK POP");

	while (s3.getSize() > 0)
		cout << "s3 pop: " << s3.pop() << " --> s3: " << s3 << endl;


	title("TEST STACK PUSH");

	while (s3.getSize() < 10)
	{
		s3.push(s3.getSize() * 5);
		cout << "s3: " << s3 << endl;
	}

	title("TEST STACK POP");

	while (s3.getSize() > 0)
		cout << "s3 pop: " << s3.pop() << " --> s3: " << s3 << endl;

	return 0;
}