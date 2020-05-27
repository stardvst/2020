void black_box();
void f(int);

// if you pass by reference, the compiler will have to reread the object
// from memory, whenever it can't prove that the object wasn't modified

void by_ref(int const &n)
{
	f(n);
	black_box();
	f(n);
	black_box();
}

void by_value(int n)
{
	f(n);
	black_box();
	f(n);
	black_box();
}

int main()
{
}
