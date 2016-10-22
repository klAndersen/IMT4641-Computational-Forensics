#pragma once
#include "stdafx.h"

using namespace System::ComponentModel;
using namespace System::Collections::Generic;

using namespace ComputationalForensics;

namespace CompFor2014 {

#ifndef FUZZYSEARCH_H

#define FUZZYSEARCH_H
	/*
	Class using Fuzzy Logic to filter out search results 
	based on the selected parameters and search types.
	@author: Knut Lucas Andersen
	*/
	public ref class FuzzySearch sealed {
	public:
		//default constructor
		FuzzySearch();
		//constructor initializing a fuzzy logic search object
		FuzzySearch(System::String ^path, List<DatabaseObject ^> ^databaseList);
		//destructor
		~FuzzySearch();
		//returns the path of this object
		System::String ^getPath();
		//
		List<FuzzySearch ^> ^getListOfSearchResults();
		//returns a list of databases contained in the path of this object
		List<DatabaseObject ^> ^getDatabaseList();
		//returns the database located at given index
		DatabaseObject ^getDatabaseAtIndex(int dbIndex);
		//runs a filtered search through all the passed folders and their databases
		void runFilteredSearch(BackgroundWorker ^worker, DoWorkEventArgs ^e, 
			List<System::String ^> ^pathToFolderList, List<List<System::String ^> ^> ^databaseFileList,
			List<System::String ^> ^filterList, List<System::String ^> ^additionalStringsList);
		//parameter used for excluding databases with content only in this named table
		static System::String ^ANDROID_METADATA = "android_metadata";
	private:
		//the path belonging to this object
		System::String ^_path;
		//converts timestamps into readable time
		void convertTimeStamps(int counter);
		//list of databases belonging to this object
		List<DatabaseObject ^> ^_databaseList;
		//list containing the results after search completed
		List<FuzzySearch ^> ^_fuzzyResultsList;
		//search databases for specified search types and additional data
		void searchForFiletypesAndAdditionalStrings(BackgroundWorker ^worker, DoWorkEventArgs ^e, 
			List<System::String ^>  ^filterList, List<System::String ^> ^additionalStringsList);
		//loop through the search types
		bool loopThroughSearchTypes(System::String ^dbName, List<System::String ^> ^databaseContent, 
			List<System::String ^> ^filterList, bool checkDbName);
		//parameter used to search for timestamps
		static System::String ^DEFAULT_TIMESTAMPS = "utc\ntimestamps";
		//parameter used to search for timestamps
		static System::String ^TIMESTAMP_FILE = SharedFunctions::SEARCH_TYPES_FOLDER + "Timestamps.txt";
	}; //FuzzySearch
#endif 

} //namespace