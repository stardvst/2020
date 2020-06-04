#include <iostream>
#include <vector>

struct S
{
	int id;
	int data;
};

S &getValue(std::vector<S> &vec, const int id)
{
	const auto value = std::find_if(begin(vec), end(vec),
		[id](const auto &s)
	{
		return s.id == id;
	});

	if (value == vec.end()) [[unlikely]]
	{
		vec.emplace_back(S{ id, 0 });
		return vec.back();
	}
	else [[likely]]
		return *value;
}

int main(const int argc, const char *argv[])
{
	if (argc > 5) [[unlikely]]
		std::cout << 29 << '\n';
	else [[likely]]
		std::cout << 42 << '\n';
}
