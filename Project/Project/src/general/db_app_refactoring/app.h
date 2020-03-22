#pragma once

#include <vector>

#define REPLACE_FILEDB_WITH_DATABASE_INTERFACE 1
#define CHANGE_DATABASE_TO_REFERENCE 1
#define CHANGE_PARAMETER_TO_ADAPTER 1

#if REPLACE_FILEDB_WITH_DATABASE_INTERFACE
struct Database
{
	virtual std::vector<std::string> load(const std::string &dbName) = 0;
};
#endif

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

#if CHANGE_PARAMETER_TO_ADAPTER
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
#endif

class UI
{
public:
#if !CHANGE_DATABASE_TO_REFERENCE
	UI(FileDB &database);
#else
	UI(FileDBAdapter &database_adapter);
#endif

	void showLogin();

private:
	void addLoginSelector(const std::vector<std::string> &users);
	void addButtons();

	Frame m_frame;
#if !REPLACE_FILEDB_WITH_DATABASE_INTERFACE
	#if !CHANGE_DATABASE_TO_REFERENCE
		FileDB m_database;
	#else
	#endif
#else
	Database &m_database;
#endif
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
#if CHANGE_PARAMETER_TO_ADAPTER
	FileDBAdapter m_databaseAdapter{ m_database };
#endif
	UI m_ui;
	static inline std::string s_storePath;
};