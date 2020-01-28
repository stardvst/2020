#include <iostream>

#include "app.h"

int main()
{
	try
	{
		App::setStorageFile("db.txt");
		App app;
		app.launch();
	}
	catch (const std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}
}