#include <iostream>

#include "app.h"

int main()
{
	try
	{
		FileDB database;
		database.setStore(App::getStorageFile());
		FileDBAdapter databaseAdapter{ database };

		App::setStorageFile("db.txt");
		App app(databaseAdapter);
		app.launch();
	}
	catch (const std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}
}