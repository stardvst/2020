#include <iostream>
#include <optional>
#include <vector>
#include <any>

int main()
{
	// generated more code
	std::vector<int> vec(3, 3);
	std::optional<std::vector<int>> o1(std::move(vec));

	// another option
	std::optional<std::vector<int>> o2(std::vector<int>(3, 3));

	// another option, call vector ctor in-place; better than move
	std::optional<std::vector<int>> o3(std::in_place, 3, 3);
	std::optional<std::vector<int>> o4(std::in_place, { 1, 2, 3 });

	std::any a(std::in_place_type_t<std::vector<int>>{}, 3, 3);
}
