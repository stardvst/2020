#include <iostream>

/*

struct Base1
{
	virtual void f() = 0;

	// constructor does not initialize these fields : data
	// member variable 'data' has public visibility
	int data;
};

struct Derived1 : Base1
{
	// 'Derived::f' hides overloaded virtual function
	virtual void f(int i)
	{
	}
};

*/

// fixed
struct Base2
{
	virtual void f() = 0;

	// class 'Base2' defines a default destructor but does not
	// define a copy constructor, a copy assignment operator,
	// a move constructor or a move assignment operator
	virtual ~Base2() = default;

	Base2()
	{
		std::cout << data << '\n';
	}

	Base2(const Base2 &) = default;
	Base2 &operator=(const Base2 &) = default;
	Base2(Base2 &&) = default;
	Base2 &operator=(Base2 &&) = default;

private:
	//  private field 'data' is not used
	int data{};
};

struct Derived2 : Base2
{
	void f() override
	{
	}
};

int main()
{
/*
	Base2 *b = new Derived2;
	b->f();

	// Potential leak of memory pointed to by 'b'

	// delete called on 'Base2' that is abstract but has non-virtual destructor
	// deleting a pointer through a type that is not marked
	// 'gsl::owner<>'; consider using a smart pointer instead
	delete b;
*/

	std::unique_ptr<Base2> b = std::make_unique<Derived2>();
	b->f();
}
