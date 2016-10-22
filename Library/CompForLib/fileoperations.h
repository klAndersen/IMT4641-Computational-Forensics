#pragma once
#include "Stdafx.h"

namespace ComputationalForensics {

#ifndef FILEOPERATIONS_H

#define FILEOPERATIONS_H	
	/*
	Class reading and writing content to and from file.
	It also creates a new file if the file don't exist, 
	and checks if file has content when reading.
	-----------------------------------------
	@Author: Knut Lucas Andersen
	*/
	public ref class FileOperations sealed {
	public:
		//read string content from file
		static List<String ^>^ readStringFromFile(String ^fileName);
		//create a folder if it doesn't exist
		static void createNewFolderIfNotExists(String ^folderName);
		//write content to file
		static void writeToFile(String ^path, String ^fileContent);
		//delete files in folder
		static void deleteAllFilesInFolder(String ^path);
		//return a file path based on folder and filename
		static String ^FileOperations::returnFilePath(String ^folder, String ^fileName);
		//return a list containing the path to the SQLite database, including filename/extension
		static List<String ^> ^returnListOfDatabaseFiles(String ^path, List<String ^> ^%databaseList);
	private:
		//constructor
		FileOperations();
		//destructor for cleanup
		~FileOperations();
		//check if the file is able to be opened and that it isn't empty
		static bool isFileReadableAndNotEmpty(String ^fileName);
		//create the file if it doesn't exist
		static void createFileIfFileNotExists(const std::string filename);
		//count number of lines in textfile to check if file is empty
		static int numLinesInTextfile(std::ifstream &openFile);
		//remove newline if that's the last element in the List
		static void removeLastEntryIfNewline(List<String^> ^fileContent);
	};
#endif
} //namespace