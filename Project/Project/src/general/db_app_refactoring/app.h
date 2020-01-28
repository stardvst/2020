#pragma once

#include <vector>

struct Frame
{
	void setSize(int w, int h);
	void setVisible(bool bVisible);
};

struct FileDB
{
	void setStore(const std::string &storePath);
	std::vector<std::string> load(const std::string &dbName);
};

class UI
{
public:
	UI();

	void showLogin();

private:
	void addLoginSelector(const std::vector<std::string> &users);
	void addButtons();

	Frame m_frame;
	FileDB m_database;
};

class App
{
public:
	void launch();

	static void setStorageFile(const std::string &storePath);
	static const std::string &getStorageFile();

private:
	UI m_ui;
	static inline std::string s_storePath;
};