#include <iostream>

// possible implementation
template<class T, class U = T>
T exchange(T &obj, U &&new_value)
{
	T old_value = std::move(obj);
	obj = std::forward<U>(new_value);
	return old_value;
}

int main()
{
	int last = 0, newValue = 1234;
	for (auto i = 0; i < 1000; ++i)
	{
		/*last = i;
		i = current;*/

		last = std::exchange(i, newValue);
		std::cout << last << ' ' << i;
	}
}