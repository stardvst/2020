#include <iostream>

#include "app.h"

void Frame::setSize(int w, int h)
{
	std::cout << __FUNCTION__ << ' ' << w << ' ' << h << '\n';
}

void Frame::setVisible(bool bVisible)
{
	std::cout << __FUNCTION__ << ' ' << bVisible << '\n';
}

//////////////////////////////////////////////////////////////////////////

void FileDB::setStore(const std::string &storePath)
{
	std::cout << __FUNCTION__ << ' ' << storePath << '\n';
}

std::vector<std::string> FileDB::load(const std::string &dbName)
{
	std::cout << __FUNCTION__ << ' ' << dbName << '\n';
	return std::vector<std::string>{};
}

//////////////////////////////////////////////////////////////////////////

UI::UI(FileDBAdapter &databaseAdapter) : m_database(databaseAdapter)
{
}

void UI::showLogin()
{
	std::vector<std::string> users = m_database.load("users");
	addLoginSelector(users);
	addButtons();
	m_frame.setSize(800, 600);
	m_frame.setVisible(true);
}

void UI::addLoginSelector(const std::vector<std::string> &users)
{
	std::cout << __FUNCTION__ << ' ' << users.size() << '\n';
}

void UI::addButtons()
{
	std::cout << __FUNCTION__ << '\n';
}

//////////////////////////////////////////////////////////////////////////

App::App()
	: m_ui(m_databaseAdapter)
{
	m_database.setStore(App::getStorageFile());
}

void App::launch()
{
	std::cout << __FUNCTION__ << '\n';
	m_ui.showLogin();
}

void App::setStorageFile(const std::string &storePath)
{
	std::cout << __FUNCTION__ << ' ' << storePath << '\n';
	s_storePath = storePath;;
}

const std::string &App::getStorageFile()
{
	std::cout << __FUNCTION__ << '\n';
	return s_storePath;
}