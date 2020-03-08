#include <iostream>
#include <exception>

void f1()
{
}

void f2()
{
}

void g1()
{
	try
	{
		f1();
	}
	catch (const std::runtime_error &)
	{
		std::clog << "runtime_error\n";
	}
	catch (const std::exception &)
	{
		std::clog << "exception\n";
	}
	catch (...)
	{
		std::clog << "unknown\n";
	}
}

void g2()
{
	try
	{
		f2();
	}
	catch (const std::runtime_error &)
	{
		std::clog << "runtime_error\n";
	}
	catch (const std::exception &)
	{
		std::clog << "exception\n";
	}
	catch (...)
	{
		std::clog << "unknown\n";
	}
}

// all exception handling is in one place, less (generated?) code!
void lippincott()
{
	try
	{
		// re-throw last unhandled exception
		throw;
	}
	catch (const std::runtime_error &)
	{
		std::clog << "runtime_error\n";
	}
	catch (const std::exception &)
	{
		std::clog << "exception\n";
	}
	catch (...)
	{
		std::clog << "unknown\n";
	}
}

void g1_lippincott()
{
	try
	{
		f1();
	}
	catch (...)
	{
		lippincott();
	}
}

void g2_lippincott()
{
	try
	{
		f2();
	}
	catch (...)
	{
		lippincott();
	}
}

int main()
{
	g1();
	g2();

	g1_lippincott();
	g2_lippincott();
}
