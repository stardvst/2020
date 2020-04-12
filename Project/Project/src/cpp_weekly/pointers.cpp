#include <iostream>

int main()
{
	int i = 5;
	int j = 10;

	// refs
	int &iRef = i;
	std::cout << i << ' ' << iRef << '\n';

	iRef = 11;
	std::cout << i << ' ' << iRef << '\n';

	// pointers
	int *iPtr = &i;
	std::cout << i << ' ' << *iPtr << '\n';

	iPtr = &j;
	std::cout << j << ' ' << *iPtr << '\n';

	// refs to pointers
	//int &*refToPtr = iPtr; // pointer to ref is not allowed
	int *&refToPtr = iPtr; // okay
	std::cout << "ref to ptr: " << *refToPtr << ", j: " << j << '\n';

	// assign address of i to this which is a ref that points to
	// iPtr which contains the address of j, so now iPtr contains
	// the address of i
	refToPtr = &i;
	std::cout << "ref to ptr: " << *refToPtr << ", i: " << i << '\n';

	// the const-ness
	//int *&ptrRef1 const = iPtr; // declaration requires an initializer

	int *&const ptrRef2 = iPtr; // okay

	int *const &ptrRef3 = iPtr; // const ptr to ref? or ptr to const value
	//ptrRef3 = &j; // it's const, cannot re-assign
	*ptrRef3 = 123; // okay
	// => it's the pointer that's const, not the value

	// a reference of type "const int *&" (not const-qualified)
	// cannot be initialized with a value of type "int *"
	//int const *&ptrRef4 = iPtr;

	const int *constPtr = &i;
	int const *&ptrRef5 = constPtr;

	// what part of it is const?
	//*ptrRef5 = 123; // the thing pointer to is const
	ptrRef5 = &j; // okay

	// very-very const
	// from cdecl.org:
	// declare ptrRef6 as reference to const pointer to const int
	const const int const * const &ptrRef6 = constPtr;
}
