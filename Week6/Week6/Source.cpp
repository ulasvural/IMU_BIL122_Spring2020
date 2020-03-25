// ratio example
#include <iostream>
#include <ratio>

int main()
{
	constexpr int n = 10;

	constexpr std::ratio<n, 3> one_third;
	constexpr std::ratio<2, 4> two_fourths;

	std::cout << "one_third= " << one_third.num << "/" << one_third.den << std::endl;
	std::cout << "two_fourths= " << two_fourths.num << "/" << two_fourths.den << std::endl;

	std::_Ratio_add<one_third, two_fourths> sum;

	/*

	std::cout << "div= " << div::num << "/" << div::den;
	std::cout << " (which is: " << (double(div::num) / div::den) << ")" << std::endl;

	std::cout << "1 kilogram has " << (std::kilo::num / std::kilo::den) << " grams";
	std::cout << std::endl;*/

	return 0;
}