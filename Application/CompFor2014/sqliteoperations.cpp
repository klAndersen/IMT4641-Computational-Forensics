#include "Stdafx.h"
#include "sqliteoperations.h"
#include "sharedFunctions.h"

using namespace System;
using namespace System::Collections::Generic;

using namespace ComputationalForensics;

namespace CompFor2014 {

	/*
	Default constructor
	*/
	SQLiteOperations::SQLiteOperations() {
		result = 0;
		_sqliteDB = NULL;
		_databaseName = "";
		_dbObject = gcnew DatabaseObject();
	} //constructor

	/*
	Constructor creating the connection to the database.
	Throws an object of ExceptionClass by use of
	exceptionHandling(...), if connection fails.
	--------------------------------------------------
	@see: exceptionHandling(String^, char*)
	@see: ExceptionClass
	*/
	SQLiteOperations::SQLiteOperations(String ^dbName) : SQLiteOperations() {
		try {
			_databaseName = dbName;
			std::string dbStr = "";
			SharedFunctions::MarshalString(dbName, dbStr);
			const char* database = dbStr.c_str();
			//was the connection successful?
			if(!openDatabaseConnection(database)) {
				//an error occurred
				char *errorMsg = const_cast<char *>(sqlite3_errmsg(_sqliteDB));
				String ^errorDescription = "Failed at creating database connection:\n";
				exceptionHandling(errorDescription, errorMsg);
			} //if
		} catch(ExceptionClass^) {
			throw;
		} //try/catch
	} //constructor

	/*
	Destructor.
	Closes connection to database when called.
	-----------------------------------------
	@see closeDatabaseConnection()
	*/
	SQLiteOperations::~SQLiteOperations() {
		closeDatabaseConnection();
	} //destructor

	/*
	Opens a SQLite database connection. If the connection is
	successful, the global variable 'sqliteDB' is set to the
	value of the connection and true is returned. If the
	connection fails, the function returns false.
	-------------------------------------------------
	@param dbName: const char* - Name of database to connect to
	@return: bool - Returns true if connection was successful,
	false if connection failed.
	*/
	bool SQLiteOperations::openDatabaseConnection(const char* dbName) {
		sqlite3 *db = NULL;
		if(sqlite3_open(dbName, &db) == SQLITE_OK) {
			_sqliteDB = db;
			return true;
		} //if
		return false;
	} //closeDatabaseConnection

	/*
	First retrieves a list containing the table names this database
	has, then the column names, followed by retrieving all the data
	from the database. If closeConnection is set to true, the
	connection to the database is closed after processing all
	queries.
	-------------------------------------------------
	@param dbName: String^  - name of this database (not path!)
	@param closeConnection: bool - If true, closes connection
	to database after processing executed query.
	@see: exceptionHandling(String^, char*)
	@see: ExceptionClass
	*/
	void SQLiteOperations::runDefaultQuery(String ^dbName, bool closeConnection) {
		result = 0;
		const char* tail;
		int rowCount = 0,
			columnCount = 0;
		const char *tempChar;
		std::string tempStr = "";
		std::string defaultQuery = "";
		String ^errorDescription = "";
		sqlite3_stmt *statement = NULL;
		_dbObject = gcnew DatabaseObject();
		_dbObject->setDatabaseName(dbName);
		List<String ^> ^tempList = gcnew List<String ^>();
		//loop through retrieved tables
		for each(String ^tableName in getDatabaseTables()) {
			//add the table to the list
			_dbObject->setTableName(tableName);
			SharedFunctions::MarshalString(tableName, tempStr);
			defaultQuery = "SELECT * FROM " + tempStr;
			result = sqlite3_prepare_v2(_sqliteDB, defaultQuery.c_str(), defaultQuery.length(), &statement, &tail);
			//was the query executed successfully?
			if(result == SQLITE_OK) {
				//get the number of columns and loop through them to get column names
				columnCount = sqlite3_column_count(statement);
				for(int i = 0; i < columnCount; i++) {
					tempChar = sqlite3_column_name(statement, i);
					tempList->Add(Conversion::convertConstCharToString(tempChar));
				} //for
				//add the column names to the database object
				_dbObject->setColumnNames(tempList);
				tempList = gcnew List<String ^>();
				//loop through the statement to get the query results
				while(sqlite3_step(statement) == SQLITE_ROW) {
					for(int i = 0; i < columnCount; i++) {
						tempChar = reinterpret_cast<const char *>(sqlite3_column_text(statement, i));
						tempList->Add(Conversion::convertConstCharToString(tempChar));
					} //for
					rowCount++;
				} //while
				//add the row values to the database object
				_dbObject->setRows(tempList);
				tempList = gcnew List<String ^>();
				_dbObject->setRowCount(rowCount);
				rowCount = 0;
			} else {
				//an error occurred
				char *errorMsg = const_cast<char *>(sqlite3_errmsg(_sqliteDB));
				errorDescription = "Failed at retrieving content from database:\n";
				exceptionHandling(errorDescription, errorMsg);
			} //if
			//reset and clear bindings from the statement
			resetAndClearStatement(statement);
		} //foreach
		//clean up
		sqlite3_finalize(statement);
		if(closeConnection)
			closeDatabaseConnection();
	} //runDefaultQuery

	/*
	Resets and clear the passed statement so that it can be re-used
	in the same function/loop/scope.
	-------------------------------------------------
	@param statement: sqlite3_stmt* - Statement to reset and clear
	*/
	void SQLiteOperations::resetAndClearStatement(sqlite3_stmt *statement) {
		String ^errorDescription = "";
		//was the statement reset successfully?
		if(sqlite3_reset(statement) != SQLITE_OK) {
			//an error occurred
			char *errorMsg = const_cast<char *>(sqlite3_errmsg(_sqliteDB));
			errorDescription = "Failed at resetting statement:\n";
			exceptionHandling(errorDescription, errorMsg);
		} //if
		//was the statements bindings cleared successfully?
		if(sqlite3_clear_bindings(statement) != SQLITE_OK) {
			//an error occurred
			char *errorMsg = const_cast<char *>(sqlite3_errmsg(_sqliteDB));
			errorDescription = "Failed at clearing statement bindings:\n";
			exceptionHandling(errorDescription, errorMsg);
		} //if
	} //resetAndClearStatement

	/*
	Returns a list containing all the table names in the current
	open database connection. If an error occurs, the exceptionHandling(...)
	function is called, which then throws the error by use of the ExceptionClass.
	-------------------------------------------------
	@return List<String ^>^: A list containing database tables
	@see: exceptionHandling(String^, char*)
	@see: ExceptionClass
	*/
	List<String ^> ^SQLiteOperations::getDatabaseTables() {
		result = 0;
		const char* tail;
		sqlite3_stmt *statement;
		List<String ^> ^tableList = gcnew List<String ^>();
		//query for retrieving all the tables from the database
		//had to be local due to not allowed as global since it's of native and not managed type
		const std::string tableQuery = "SELECT name FROM sqlite_master WHERE type = 'table' ORDER BY name;";
		result = sqlite3_prepare_v2(_sqliteDB, tableQuery.c_str(), tableQuery.length(), &statement, &tail);
		//was the query executed successfully?
		if(result == SQLITE_OK) {
			const char *tempChar;
			String ^tableName = "";
			//loop through the results to retrieve the table names
			while(sqlite3_step(statement) == SQLITE_ROW) {
				tempChar = reinterpret_cast<const char *>(sqlite3_column_text(statement, 0));
				tableName = Conversion::convertConstCharToString(tempChar);
				tableList->Add(tableName);
			} //while
		} else {
			//an error occurred
			char *errorMsg = const_cast<char *>(sqlite3_errmsg(_sqliteDB));
			String ^errorDescription = "Failed at retrieving tables from database:\n";
			exceptionHandling(errorDescription, errorMsg);
		} //if
		//clean up
		sqlite3_finalize(statement);
		return tableList;
	} //getDatabaseTables

	/*
	Throws a new ExceptionClass error.
	Created for simplifying the maintance of errors
	that may occur during SQLite transactions.
	-------------------------------------------------
	@param errorDescription: String^ - description of the error that occurred
	@param errorMessage: char* - the sqlite error message
	@throw: ExceptionClass
	*/
	void SQLiteOperations::exceptionHandling(String ^errorDescription, char *errorMessage) {
		String ^error = gcnew String(Conversion::convertConstCharToString(errorMessage));
		throw gcnew ExceptionClass(errorDescription + error);
	} //exceptionHandling

	/*
	Closes the connection to the SQLite database.
	*/
	void SQLiteOperations::closeDatabaseConnection() {
		sqlite3_close(_sqliteDB);
	} //closeDatabaseConnection

	/*
	Returns an object containing all the information retrieved 
	from this database.
	*/
	DatabaseObject ^SQLiteOperations::getDatabaseObject() {
		return _dbObject;
	} //getDatabaseInformation
} //namespace