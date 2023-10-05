//Making a decision using constexpr-if

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using vec_str = std::vector<std::string>;	//For convenience

//Adding a value of type U to a value of type T
template <typename T>
class addable
{
	T val;
public:
	addable(T v) : val{ v } {}

	template <typename U>
	T add(U x) const {
		if constexpr (std::is_same_v<T, std::vector<U>>) {
			auto copy(val);
			for (auto& n : copy) {
				n += x;
			}
			return copy;
		}
		else {
			return val + x;
		}
	}
};

//overload the vector output operator
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	for (auto data : v) os << data << " ";
	return os;
}

int main()
{
	std::cout << std::left << std::setw(42) << "addable<int>{1}.add(2): "                    << addable<int>{1}.add(2) << std::endl;
	std::cout << std::left << std::setw(42) << "addable<float>{1.0}.add(2): "                << addable<float>{1.0}.add(2)                                         << std::endl;
	std::cout << std::left << std::setw(42) << "addable<std::string>{\"aa\"}.add(\"bb\"): "  << addable<std::string>{"aa"}.add("bb")                               << std::endl;
	std::cout << std::left << std::setw(42) << "addable<std::vector<int>>.add(10): "         << addable<std::vector<int>>{std::vector<int> {1, 2, 3}}.add(10)      << std::endl;
	std::cout << std::left << std::setw(42) << "addable<vec_str>{}.add(string{ \"z\" }): "   << addable<vec_str>{vec_str{ "a", "b", "c" }}.add(std::string{ "z" }) << std::endl;
}