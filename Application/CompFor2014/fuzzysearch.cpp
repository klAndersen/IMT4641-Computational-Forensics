#include "stdafx.h"
#include "sharedFunctions.h"
#include "fuzzysearch.h"
#include "sqliteoperations.h"

using namespace System;
using namespace Collections::Generic;

namespace CompFor2014 {

	/*
	Default constructor
	*/
	FuzzySearch::FuzzySearch() {
		_path = "";
		_fuzzyResultsList = gcnew List<FuzzySearch ^>();
		_databaseList = gcnew List<DatabaseObject ^>();
	} //constructor

	/*
	Constructor that creates objects of the fuzzy logic
	search class.
	--------------------------------------------------
	@parameter path : String ^ - The directory path for this object
	@parameter databaseList : List<DatabaseObject ^> ^ - List containing
	all the database objects based on the databases found in this folder/directory
	*/
	FuzzySearch::FuzzySearch(String ^path, List<DatabaseObject ^> ^databaseList) : FuzzySearch() {
		_path = path;
		_databaseList->AddRange(databaseList);
	} //constructor

	/*
	Destructor
	*/
	FuzzySearch::~FuzzySearch() {

	} //destructor

	/*
	Loops through the retrieved databases and checks if the databases
	have any content. If the rowcount is zero or if the only table with
	content is the "android_metadata", then the entries are excluded from
	further search. After the filtering of empty databases is complete,
	the search continues by looking for entries matching the search
	parameters. If the database have no matches, it will be excluded
	from the final result.
	--------------------------------------------------
	@parameter worker: BackgroundWorker - Running backgroundworker
	@parameter e: DoWorkEventArgs - Event
	@parameter pathToDatabaseList: List<String ^> - List containing
	the path to folders with databases
	@parameter dbFileList: List<List<String ^> ^> - List containing
	the file names of the databases in the folders;
	index1: the folder index
	index2: the database index
	@parameter filterList: List<System::String ^> - List containing
	the search types used to filter out the final result
	@parameter additionalStringsList: List<System::String ^> - List containing
	additional search types used to filter out the final result
	*/
	void FuzzySearch::runFilteredSearch(BackgroundWorker ^worker, DoWorkEventArgs ^e,
		List<String ^> ^pathToDatabaseList, List<List<String ^> ^> ^dbFileList,
		List<System::String ^>  ^filterList, List<System::String ^> ^additionalStringsList) {
		int noEmptyRows = 0;
		String ^folderPath = "",
			^databasePath = "",
			^databaseName = "";
		SQLiteOperations ^sqliteObject;
		bool tableIsAndroidMetadata = false;
		DatabaseObject ^dbOject;
		List<DatabaseObject ^> ^currentDatabaseList;
		//initialize progressbar
		float total = static_cast<float>(pathToDatabaseList->Count);
		SharedFunctions::updateProgressBar(0, total, worker);
		try {
			//loop through the selected folders...
			for(int folderIndex = 0; folderIndex < pathToDatabaseList->Count; folderIndex++) {
				folderPath = pathToDatabaseList[folderIndex];
				currentDatabaseList = gcnew List<DatabaseObject ^>();
				//loop through the databases that were found...
				for(int dbIndex = 0; dbIndex < dbFileList[folderIndex]->Count; dbIndex++) {
					databaseName = dbFileList[folderIndex]->ToArray()[dbIndex];
					databasePath = FileOperations::returnFilePath(folderPath, databaseName);
					sqliteObject = gcnew SQLiteOperations(databasePath);
					sqliteObject->runDefaultQuery(databaseName, true);
					dbOject = sqliteObject->getDatabaseObject();
					//loop through the current databases tables to see if it has content...
					for(int tableIndex = 0; tableIndex < dbOject->getTableList()->Count; tableIndex++) {
						//does this table have any rows, and if it does, is this the android_metadata table?
						tableIsAndroidMetadata = dbOject->getTableName(tableIndex)->Equals(ANDROID_METADATA);
						if(dbOject->getRowCountList()[tableIndex] == 0
							|| (tableIsAndroidMetadata && dbOject->getRowCountList()[tableIndex] == 1)) {
							noEmptyRows++;
						} //if
					} //for
					//is the number of empty rows equal to the number of tables?
					if(noEmptyRows < dbOject->getTableList()->Count) {
						currentDatabaseList->Add(dbOject);
					} //if
					sqliteObject->~SQLiteOperations();
					noEmptyRows = 0;
				} //for
				//were all the databases in this folder empty?
				if(currentDatabaseList->Count > 0) {
					_fuzzyResultsList->Add(gcnew FuzzySearch(folderPath, currentDatabaseList));
				} //if
				//update progressbar
				SharedFunctions::updateProgressBar(folderIndex, total, worker);
			} //for
			//has the search been cancelled?
			if(worker->CancellationPending) {
				worker->CancelAsync();
			} else {
				//start search for entries containing the search parameters
				searchForFiletypesAndAdditionalStrings(worker, e, filterList, additionalStringsList);
			} //if
		} catch(ExceptionClass^) {
			throw;
		} finally {
			//fill progressbar since work (maybe) is completed
			SharedFunctions::updateProgressBar(static_cast<int>(total), total, worker);
		} //try/catch
	} //runFilteredSearch

	/*
	Search through the databases for content related to the filetypes, fileextensions
	and other search type data entered.
	--------------------------------------------------
	@parameter worker: BackgroundWorker - Running backgroundworker
	@parameter e: DoWorkEventArgs - Event
	@parameter filterList: List<System::String ^> - List containing
	the search types used to filter out the final result
	@parameter additionalStringsList: List<System::String ^> - List containing
	additional search types used to filter out the final result
	*/
	void FuzzySearch::searchForFiletypesAndAdditionalStrings(BackgroundWorker ^worker, DoWorkEventArgs ^e,
		List<System::String ^> ^filterList, List<System::String ^> ^additionalStringsList) {
		int roundCounter = 0;
		FuzzySearch ^fuzzyObj;
		DatabaseObject ^dbObject;
		bool foundMatch = false;
		//initialize progressbar
		float total = static_cast<float>(_fuzzyResultsList->Count);
		SharedFunctions::updateProgressBar(0, total, worker);
		//loop through the folder list to get index of the databases
		for(int pathIndex = _fuzzyResultsList->Count - 1; pathIndex > -1; pathIndex--) {
			fuzzyObj = _fuzzyResultsList[pathIndex];
			//loop through databases and check their names and their content
			for(int dbIndex = fuzzyObj->getDatabaseList()->Count -1; dbIndex > -1; dbIndex--) {
				foundMatch = false;
				dbObject = fuzzyObj->getDatabaseAtIndex(dbIndex);
				//check database name
				foundMatch = loopThroughSearchTypes(dbObject->getDatabaseName(), dbObject->getTableList(), filterList, true);
				if(!foundMatch && additionalStringsList->Count > 0) {
					foundMatch = loopThroughSearchTypes(dbObject->getDatabaseName(), dbObject->getTableList(), additionalStringsList, true);
				} //if
				if(!foundMatch) {
					//check tables
					for(int tableIndex = 0; tableIndex < dbObject->getTableList()->Count; tableIndex++) {
						foundMatch = loopThroughSearchTypes(dbObject->getTableName(tableIndex), dbObject->getTableList(), filterList, true);
						//does the columns contain the search string?
						if(!foundMatch) {
							foundMatch = loopThroughSearchTypes(dbObject->getTableName(tableIndex), dbObject->getColumnList(tableIndex), filterList, false);
						} //if
						//does the rows contain the search string?
						if(!foundMatch) {
							foundMatch = loopThroughSearchTypes(dbObject->getTableName(tableIndex), dbObject->getRows(tableIndex), filterList, false);
						} //if
						//is search for additional strings included - if so, check table name
						if(!foundMatch && additionalStringsList->Count > 0) {
							foundMatch = loopThroughSearchTypes(dbObject->getTableName(tableIndex), dbObject->getTableList(), additionalStringsList, true);
						} //if
						//is search for additional strings included - if so, check the table columns
						if(!foundMatch && additionalStringsList->Count > 0) {
							foundMatch = loopThroughSearchTypes(dbObject->getTableName(tableIndex), dbObject->getColumnList(tableIndex), additionalStringsList, false);
						} //if
						//is search for additional strings included - if so, check the table rows
						if(!foundMatch && additionalStringsList->Count > 0) {
							foundMatch = loopThroughSearchTypes(dbObject->getTableName(tableIndex), dbObject->getRows(tableIndex), additionalStringsList, false);
						} //if
					} //for
				} //if
				//if no match were found, remove database from search results
				if(!foundMatch) {
					_fuzzyResultsList[pathIndex]->getDatabaseList()->RemoveAt(dbIndex);
				} //if
			} //for
			//if all databases at given path were excluded, remove the folder also
			if(_fuzzyResultsList[pathIndex]->getDatabaseList()->Count == 0) {
				_fuzzyResultsList->RemoveAt(pathIndex);
			} //if
			//update progressbar
			roundCounter++;
			SharedFunctions::updateProgressBar(roundCounter, total, worker);
		} //for
	} //searchForFiletypesAndAdditionalStrings

	/*
	Search through the databases for content related to the filetypes, fileextensions
	and other search type data entered.
	--------------------------------------------------
	@param dbName: String ^ - Name value; e.g. database, table, column name
	@param databaseContent: List<String ^> - List containing content, e.g.
	list of tables, columns, rows, etc.
	@param filterList: List<String ^> - List containing values to search for
	@param checkDbName: bool - True; check only 'dbName'.
	False; check against content in 'databaseContent' list.
	@return: bool - True; match was found, false; no match was found
	*/
	bool FuzzySearch::loopThroughSearchTypes(String ^dbName, List<String ^> ^databaseContent,
		List<String ^> ^filterList, bool checkDbName) {
		int counter = 0,
			index = 0;
		String ^searchString = "",
			^dbContent = "";
		bool foundMatch = false;
		//should check be run against the name?
		if(checkDbName) {
			dbName = dbName->ToLower();
			while(!foundMatch && counter < filterList->Count) {
				searchString = filterList[counter]->ToLower();
				//is a match found?
				if(dbName->Contains(searchString)) {
					foundMatch = true;
				} //if
				counter++;
			} //while
		} else {
			//loop through and check the database content
			while(!foundMatch && index < databaseContent->Count) {
				dbContent = databaseContent[index]->ToLower();
				//loop through the search strings
				while(!foundMatch && counter < filterList->Count) {
					searchString = filterList[counter]->ToLower();
					//is a match found?
					if(dbContent->Contains(searchString)) {
						foundMatch = true;
					} //if
					counter++;
				} //while
				index++;
			} //while
		} //if
		return foundMatch;
	} //loopThroughSearchTypes

	/*
	:::::: NOTE! This function was not completed! :::::::::::
	Loops through content to convert timestamps into
	readable time-format. Based on entries found in
	settings file "Timestamps.txt"
	--------------------------------------------------
	@param counter: int - Counter used for error checking
	@throw: Not implemented exception!
	*/
	void FuzzySearch::convertTimeStamps(int counter) {
		throw gcnew ExceptionClass("This functio is not implemented!");
		try {
			List<String ^> ^timeStampList = FileOperations::readStringFromFile(TIMESTAMP_FILE);
		} catch(ExceptionClass^) {
			if(counter <= 0) {
				//presuming file empty error, ignore
				//since file most likely is empty, write default content and reload
				FileOperations::writeToFile(TIMESTAMP_FILE, DEFAULT_TIMESTAMPS);
				counter++;
				convertTimeStamps(counter);
			} else {
				//if counter is higher then zero, then exception is repeating
				//throw error to show exception message
				throw;
			} //if
		} //try/catch
	} //convertTimeStamps 

	/*
	Returns the directory path to this object.
	--------------------------------------------------
	@return: String^ - The directory path to this object
	*/
	String ^FuzzySearch::getPath() {
		return _path;
	} //getPath

	/*
	Returns a list containing the databases found in this
	folder/directory. Each FuzzySearch object has its
	own directory path and list with databases found at
	this location.
	--------------------------------------------------
	@return: List<String ^> - The databases found in this
	directory
	*/
	List<DatabaseObject ^> ^FuzzySearch::getDatabaseList() {
		return _databaseList;
	} //getDatabaseList

	/*
	Returns an object of the DatabaseObject class
	based on the passed index.
	--------------------------------------------------
	@return: DatabaseObject^ - Database object based on
	passed index
	*/
	DatabaseObject ^FuzzySearch::getDatabaseAtIndex(int dbIndex) {
		return _databaseList[dbIndex];
	} //getDatabaseAtIndex

	List<FuzzySearch ^> ^FuzzySearch::getListOfSearchResults() {
		return _fuzzyResultsList;
	}
} //namespace