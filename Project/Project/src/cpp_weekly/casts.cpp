#include <cstring>

// reinterpret_cast == (almost always) UB

struct S
{
	int i;
	int j;
};

void update(char *blob, int newValue)
{
	/*
		---------------------------------
		|	|	|	|	|	|	|	|	|
		---------------------------------
		| treat as int	| treat as int	|

		BUT: there's no int that lives in 1st/2nd segment,
		neither struct S, it's 4 (+4) bytes!
		=> we're asking to access object whose lifetimes han't begun
		which is UB!

		You can't create any object anywhere in memory.
		If the CPU needs the ints to be aligned,
		an arbitrary char pointer can't have that guarantee.
		If you start with an S object on the stack,
		you know the pointer you get is aligned.
	*/
	reinterpret_cast<S *>(blob)[2].j = newValue;
}

void updateNotUB(char *blob, int newValue)
{
	S obj[3];
	memcpy(obj, blob, sizeof(obj));
	obj[2].j = newValue;
	memcpy(blob, obj, sizeof(obj));
}

int main()
{
}
