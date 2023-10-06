#include <iostream>
#include <vector>

template <typename R, typename ... Ts>
auto matches(const R& range, Ts ... ts)
{
	return (std::count(std::begin(range), std::end(range), ts) + ...);
}

int main()
{
	std::vector<int> v {1, 2, 3, 4, 5};

	std::cout << matches(v,         2,   5)        << std::endl;
	std::cout << matches(v,         100, 200)      << std::endl;
	std::cout << matches("abcdefg", 'a', 'd', 'f') << std::endl;
}