#include <stdio.h>

double area(const double radius)
{
	return 3.14159 * radius * radius;
}

// no overloading in c
// 'area': redefinition; different basic types
//float area(const float radius)
//{
//	return 3.14159 * radius * radius;
//}

// so we have to name them differently, as in the standard
float areaf(const float radius)
{
	return 3.14159 * radius * radius;
}

long double areal(const double radius)
{
	return 3.14159 * radius * radius;
}

// c11, gcc
#define AREA(x) _Generic((x), long double: areal,	\
	default: area,	\
	float: areaf)(x)

int main()
{
	printf("%f, %f\n", AREA(5), AREA((float)5));
}
