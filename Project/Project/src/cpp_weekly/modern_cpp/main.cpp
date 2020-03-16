// inclusion of deprecated C++ header 'stdio.h'; consider using 'cstdio' instead
#include <stdio.h>

#include <iostream>

// do not use namespace using - directives; use using - declarations instead
using namespace std;

int main()
{
	puts("Hello World");

	cout << "Hello World" << endl;
	return 0;
}
