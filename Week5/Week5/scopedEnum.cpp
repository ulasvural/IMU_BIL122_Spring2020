#include <iostream>

using namespace std;

// c/c++03 type enum without scope
typedef enum {
	MON, TUE, WED, THU,
	FRI, SAT, SUN
} C_Days;

//typedef enum {
//	MON, TUE, WED, THU,	FRI
//} C_WeekDays;

// C++ scoped enum class -> Global scope
enum class Days {
	MON, TUE, WED, THU,
	FRI, SAT, SUN
};

int main1()
{
	// C++ scoped enum class -> Local scope
	enum class WeekDays {
		MON, TUE, WED, THU,
		FRI
	};

	WeekDays firstDay{ WeekDays::MON };
	WeekDays today{ WeekDays::WED };
	WeekDays tomorrow;

	C_Days cToday = MON;

	tomorrow = today = firstDay;

	if (today == WeekDays::MON)
	{
		tomorrow = WeekDays::TUE;
		cout << "First day of the week!!!\n";
	}
	else
		cout << "!First day of the week!!!\n";

	return 0;
}