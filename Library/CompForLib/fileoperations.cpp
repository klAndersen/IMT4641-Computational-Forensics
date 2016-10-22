#include "Stdafx.h"
#include "fileoperations.h"
#include <fstream>

using namespace std;
using namespace System::IO;

namespace ComputationalForensics {

	/*
	Default constructor
	*/
	FileOperations::FileOperations() {

	} //constructor

	/*
	Destructor
	*/
	FileOperations::~FileOperations() {

	} //destructor

	/*
	Reads all the content from the file and adds each line into a list.
	----------------------------------------------------
	@param fileName: string - name of file to be read from
	@throw: ExceptionClass - throws error if f
	@return List<String>: Pointer to content of the file
	*/
	List<String^> ^ FileOperations::readStringFromFile(String^ fileName) {
		List<String^> ^ fileContent = gcnew List<String ^>();
		try {
			if(isFileReadableAndNotEmpty(fileName)) {
				string content = "",
					fName = "";
				ifstream openFile;
				Conversion::MarshalString(fileName, fName);
				//no need to check for file error, since if we get here we know the file 
				//was successfully opened and probably has content		
				openFile.open(fName.c_str());
				//read content from file
				while(!openFile.eof()) {
					getline(openFile, content, '\n');
					fileContent->Add(gcnew String(content.c_str()));
				} //while
				openFile.close();
				removeLastEntryIfNewline(fileContent);
			} //if
		} catch(ExceptionClass^) {
			throw;
		} //try/catch
		return fileContent;
	} //readStringFromFile

	/*
	Check if the last element in the list is a newline/not a valid number
	(based on the constant Conversion::INPUT_NOT_A_NUMBER).
	----------------------------------------------------
	@param fileContent: List<String ^> - list filled with content from file
	*/
	void FileOperations::removeLastEntryIfNewline(List<String ^> ^fileContent) {
		//were there any data in the file?
		if(fileContent->Count > 0) {
			//get size of list
			unsigned int listSize = fileContent->Count - 1;
			int lastValue = Conversion::convertStringToInteger(fileContent[listSize]);
			//check if the last element is -9999 (failed conversion due to e.g. newline)
			if(lastValue == Conversion::INPUT_NOT_A_NUMBER) {
				//last element is a failed conversion, remove it
				fileContent->RemoveAt(listSize);
			} //if
		} //if
	} //removeLastEntryIfNewline

	/*
	Check if the file can be opened and if the file is empty.
	If file cannot be opened or if the file is empty, an ExceptionClass error
	is thrown.
	----------------------------------------------------
	@param fileName: String^ - name of file to be read from
	@throw: ExceptionClass - throws error if file cannot be opened or is empty
	@return: bool - returns true if file is accessible and not empty
	*/
	bool FileOperations::isFileReadableAndNotEmpty(String^ fileName) {
		string fName = "";
		ifstream openFile;
		Conversion::MarshalString(fileName, fName);
		//create file if file doesnt exist
		createFileIfFileNotExists(fName);
		openFile.open(fName.c_str());
		//was the file opened?
		if(openFile.fail()) {
			throw gcnew ExceptionClass("Couldn't open file: " + fileName + "!", "File error");
		} else { //file was opened
			int counter = numLinesInTextfile(openFile);
			//close the file
			openFile.close();
			//does the file have any content?
			if(counter == 0) {
				throw gcnew ExceptionClass("File \"" + fileName + "\" is empty.", "File error");
			} //if
		} //if
		return true;
	} //isFileReadableAndNotEmpty

	/*
	Writes the passed file content to a file based on the
	passed path. The path must include the file that content
	should be written to. Use FileOperations::returnFilePath(...)
	to create path if needed.
	--------------------------------------------------
	@param path: String ^ - path to the file that content should be written to
	(needs to include the filename and file extension)
	@param fileContent: String ^ - the content to write to file
	*/
	void FileOperations::writeToFile(String ^path, String ^fileContent) {
		File::WriteAllText(path, fileContent);
	} //writeToFile

	/*
	Returns the path to a file based on the passed folder
	and filename. The folder is the path to the parent folder
	of the file, and the file name is the name of the file,
	including the file extension.
	--------------------------------------------------
	@param folder: String ^ - path to files parent folder
	@param fileName: String ^ - file name including file extension,
	e.g. "textfile.txt"
	*/
	String ^FileOperations::returnFilePath(String ^folder, String ^fileName) {
		String ^path = "";
		path = folder + "\\" + fileName;
		return path;
	} //returnFilePath

	/*
	Create file if file doesn't exist.
	To avoid deletion of existing data, ios:app is used.
	--------------------------------------------------
	@param fileName: std::string - name of file to be created
	*/
	void FileOperations::createFileIfFileNotExists(const string fileName) {
		ofstream createFile(fileName, ios::app);
		createFile.close();
	} //createFileIfNotExists

	/*
	Create a folder/directory. The folder is created by
	using Directory::CreateDirectory(folderName).
	--------------------------------------------------
	@param folderName: String ^ - name of folder to be created
	@throw: ExceptionClass^
	*/
	void FileOperations::createNewFolderIfNotExists(String ^folderName) {
		try {
			Directory::CreateDirectory(folderName);
		} catch(ExceptionClass ^) {
			throw;
		} //try/catch
	} //createNewFolderIfNotExists

	/*
	Deletes all the files in the given path.
	--------------------------------------------------
	@param path: String ^ - path to directory with files to delete
	*/
	void FileOperations::deleteAllFilesInFolder(String ^path) {
		for each(String ^file in Directory::GetFiles(path)) {
			File::Delete(file);
		} //foreach
	} //deleteAllFilesInFolder

	/*
	Checks if the passed path contains SQLite databases by looking at the
	file extension. If the file is a database file, it gets added to the list.
	After all files in current path are checked, the list is returned.
	--------------------------------------------------
	@param path: String ^ - path to directory that may contain SQLite databases
	@param databaseList: List<String ^>^ - referenced list that gets filled with
	the database filenames (used for extracting information from given database)
	@return: List<String ^>^ - List with paths to SQLite database files
	@throw: ExceptionClass^
	*/
	List<String ^> ^FileOperations::returnListOfDatabaseFiles(String ^path, List<String ^>  ^%databaseList) {
		FileInfo ^fi;
		int length = 0,
			charCount = 3;
		String ^extension = ".db";
		List<String ^> ^fileList = gcnew List<String ^>();
		try {
			//loop through the files in the directory
			for each(String ^file in Directory::GetFiles(path)) {
				length = file->Length - charCount;
				//is this a SQLite database file?
				if(file->Substring(length, charCount)->Equals(extension)) {
					fi = gcnew FileInfo(file);
					databaseList->Add(fi->Name);
					//does this directory exist in the list?
					if(!fileList->Contains(path))
						fileList->Add(path);
				} //if
			} //foreach
		} catch(ExceptionClass^) {
			throw;
		} //try/catch
		return fileList;
	} //returnListOfDatabaseFiles

	/*
	Loops through the content of the file and counts up the number of lines.
	The only task of this function is to check if file has content.
	------------------------------------------------------------------------------
	@param openFile: reference to object of ifstream; object used to open file in question
	@return: integer (number of lines in file, if empty, 0 is returned)
	*/
	int FileOperations::numLinesInTextfile(ifstream &openFile) {
		string fileContent = "";
		//initialize a counter that counts the number of lines in the textfile
		//starts at -1 so that the loop is run at least one time and that the counter 
		//properly counts number of lines to check if file is empty
		int counter = -1;
		//loop through the file to see if it has content
		while(!openFile.eof()) {
			//read line by line, seperated by newline
			getline(openFile, fileContent, '\n');
			//increase counter for each line
			counter++;
		} //while
		return counter;
	} //numLinesInTextfile
} //namespace