#pragma once
//path to SQLite3 library
#include <../SQLite3/sqlite3.h>

#pragma comment (lib, "sqlite3.lib")

using namespace System::Collections::Generic;

using namespace ComputationalForensics;

namespace CompFor2014 {

#ifndef SQLITEOPERATIONS_H

#define SQLITEOPERATIONS_H

	/*
	Class handling the connections to the SQLite databases.
	Some of the functionality this class handles are (not all are public):
	- Open connection to SQLite
	- Retrieve tables
	- Retrieve all the database content
	- Close connection to SQLite
	-----------------------------------------
	@Author: Knut Lucas Andersen
	*/
	public ref class SQLiteOperations sealed {
	public:
		//default constructor
		SQLiteOperations();
		//constructor creating connection to SQLite DB
		SQLiteOperations(System::String ^dbName);
		//destructor
		~SQLiteOperations();
		//closes connection to database
		void closeDatabaseConnection();
		//runs a query selecting everything from the database
		void runDefaultQuery(System::String ^dbName, bool closeConnection);
		//returns an object containing database information
		DatabaseObject ^getDatabaseObject();
	private:
		//create a database object that contains the information retrieved
		DatabaseObject ^_dbObject;
		//variabel for the result when attempting connections and queries
		int result;
		//object containing the connection to the database
		sqlite3 *_sqliteDB;
		//name of current database connection
		System::String ^_databaseName;
		//function opening the database connection
		bool openDatabaseConnection(const char* dbName);
		//fill a list with all the tables from the database
		List<System::String ^> ^getDatabaseTables();
		//reset statement and clear bindings so that it can be re-used
		void resetAndClearStatement(sqlite3_stmt *statement);
		//error/exception handling function
		void exceptionHandling(System::String ^errorDescription, char *errorMessage);
	}; //SQLiteOperations

#endif
} //namespace