#include <concepts>
#include <vector>
#include <array>
#include <cassert>

auto allocatedSize(const auto &container)
{
	if constexpr (requires { container.capacity(); })
		return container.capacity();
	else
		return container.size();
}

int main()
{
	std::vector<int> vec;
	assert(allocatedSize(vec) == 0);

	vec.push_back(1);
	assert(allocatedSize(vec) == 1);

	vec.push_back(2);
	assert(allocatedSize(vec) == 2);

	vec.push_back(3);
	assert(allocatedSize(vec) == 4);

	std::array<int, 10> arr;
	assert(allocatedSize(arr) == 10);
}
