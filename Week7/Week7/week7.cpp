#include <iostream>

//#define MAP_EXAMPLE
#define CONTAINER_SIZE
//#define OUTPUT_MANIPULATION

#ifdef MAP_EXAMPLE
#include <map>
#include <string>
#endif

#ifdef CONTAINER_SIZE
#include <vector>
#include <array>
#include <stdexcept>
#endif

#ifdef OUTPUT_MANIPULATION
#include <iomanip>
#endif

using namespace std;

int main()
{
#ifdef MAP_EXAMPLE
	enum class Color {RED, BLUE, WHITE, BLACK, GREEN};
	const map<Color, string> colorToStringMap = { {Color::RED, "Red"},
		{Color::BLUE, "Blue"},
		{Color::WHITE, "White"},
		{Color::BLACK, "Black"},
		{Color::GREEN, "Green"}
	};

	const map<string, string> intToStringMap = { {"at", "bir hayvan"}, {"iki", "bir sayý"} };
	cout << intToStringMap.at("at") << endl;


	auto selectedColor{ Color::BLACK };

	cout << "Map Size: " << colorToStringMap.size() << endl;

	cout << colorToStringMap.at(selectedColor) << endl;

	switch (selectedColor)
	{
	case Color::RED:
		cout << "Red"; break;
	case Color::BLUE:
		cout << "Blue"; break;
	case Color::WHITE:
		cout << "White"; break;
	case Color::BLACK:
		cout << "Black"; break;
	case Color::GREEN:
		cout << "Green"; break;
	default:
		cout << "Unknown color";
	}
#endif

#ifdef CONTAINER_SIZE
	vector<int> v1(10);
	vector<char> v2{ 'a','b', 'c' };

	for (int i{ 0 }; i < v1.size(); ++i)
		v1[i] = i * 2;

	try {
		v1.at(10) = 1000;  // exception catched
		//v1[10] = 1000;      // no exception thrown
	}
	catch (out_of_range & e)
	{
		cout << "Exception: " << e.what() << endl;
	}

	//cout << "V1.size(): " << v1.size() << endl;
	//cout << "V2.size(): " << v2.size() << endl;

	//cout << "V1.capacity(): " << v1.capacity() << endl;
	//cout << "V2.capacity(): " << v2.capacity() << endl;

	//cout << "sizeof(V1): " << sizeof(v1) << endl;
	//cout << "sizeof(V2): " << sizeof(v2) << endl;

	//v1.resize(40);
	//cout << "V1.size(): " << v1.size() << endl;
	//cout << "V1.capacity(): " << v1.capacity() << endl;

	//for (char c = 0; c < 50; ++c)
	//{
	//	v2.push_back(c);
	//	cout << "V2.size(): " << v2.size() << endl;
	//	cout << "V2.capacity(): " << v2.capacity() << endl << endl;
	//}

	for (auto val : v1)
		cout << val << " - ";
	cout << endl;

#endif 

#ifdef OUTPUT_MANIPULATION
	// https://en.cppreference.com/w/cpp/io/manip

	std::cout.imbue(std::locale("en_US.utf8"));
	std::cout << "Left fill:\n" << std::left << std::setfill('*')
		<< std::setw(12) << -1.23 << '\n'
		<< std::setw(12) << std::hex << std::showbase << 42 << '\n'
		<< std::setw(12) << std::put_money(123, true) << "\n\n";

	std::cout << "Internal fill:\n" << std::internal
		<< std::setw(12) << -1.23 << '\n'
		<< std::setw(12) << 42 << '\n'
		<< std::setw(12) << std::put_money(123, true) << "\n\n";

	std::cout << "Right fill:\n" << std::right
		<< std::setw(12) << -1.23 << '\n'
		<< std::setw(12) << 42 << '\n'
		<< std::setw(12) << std::put_money(123, true) << '\n';

#endif
	return 0;
}

