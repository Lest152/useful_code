#include <iostream>
#include <vector>

//Returns the number of all elements in the range
template <typename R, typename ... Ts>
auto matches(const R& range, Ts ... ts)
{
	return (std::count(std::begin(range), std::end(range), ts) + ...);
}

//Checking whether all parameters fall within the specified range
template <typename T, typename ... Ts>
bool within(T min, T max, Ts ...ts)
{
	return ((min <= ts && ts <= max) && ...);
}

int main()
{
	{
		std::cout << "Testing matches():" << std::endl;

		std::vector<int> v{ 1, 2, 3, 4, 5 };

		std::cout << matches(v, 2, 5) << std::endl;
		std::cout << matches(v, 100, 200) << std::endl;
		std::cout << matches("abcdefg", 'a', 'd', 'f') << std::endl;
	}

	{
		std::cout << "\n\n====================\n";
		std::cout << "Testing within():" << std::endl;

		std::cout << within(10,  20,    1,   15,  30)  << std::endl;
		std::cout << within(10,  20,    11,  12,  13)  << std::endl;
		std::cout << within(5.0, 5.5,   5.1, 5.2, 5.3) << std::endl;
	}
}
