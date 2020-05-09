#include <iostream>
#include <functional>

/*
	callables:
	1. lambda
	2. free functions
	3. member function pointers
	4. member objects <---
*/

struct S
{
	int i{10};

	int get() const
	{
		return i;
	}
};

int main()
{
	S s;
	//return s.i; // cannot do if i is not inited
	std::cout << s.i << '\n';

	int (S:: * mem_fn_ptr)() const = &S::get;
	std::cout << (s.*mem_fn_ptr)() << '\n';

	S *sPtr = &s;
	std::cout << (sPtr->*mem_fn_ptr)() << '\n';

	// member objects, not particular i, but i in general
	int(S:: * mem_obj_ptr) = &S::i;
	std::cout << s.*mem_obj_ptr << '\n';
	std::cout << std::invoke(mem_obj_ptr, s) << '\n';

	S s2;
	s2.i = 5;
	std::cout << s2.*mem_obj_ptr << '\n';
}
