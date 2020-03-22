#include <iostream>

#include "app.h"

int main()
{
	try
	{
		FileDB database;
		database.setStore(App::getStorageFile());

		App::setStorageFile("db.txt");
		App app(database);
		app.launch();
	}
	catch (const std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}
}