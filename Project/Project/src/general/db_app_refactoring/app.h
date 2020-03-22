#pragma once

#include <vector>

struct Database
{
	virtual std::vector<std::string> load(const std::string &dbName) = 0;
};

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

struct FileDBAdapter : Database
{
	FileDBAdapter(FileDB &db)
		: file_db(db)
	{
	}

	std::vector<std::string> load(const std::string &dbName) override
	{
		std::cout << __FUNCTION__ << '\n';
		return file_db.load(dbName);
	}

	FileDB &file_db;
};

class UI
{
public:
	UI(FileDBAdapter &database_adapter);

	void showLogin();

private:
	void addLoginSelector(const std::vector<std::string> &users);
	void addButtons();

	Frame m_frame;
	Database &m_database;
};

class App
{
public:
	App();
	void launch();

	static void setStorageFile(const std::string &storePath);
	static const std::string &getStorageFile();

private:
	FileDB m_database;
	FileDBAdapter m_databaseAdapter{ m_database };
	UI m_ui;
	static inline std::string s_storePath;
};