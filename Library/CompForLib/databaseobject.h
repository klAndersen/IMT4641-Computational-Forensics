#pragma once
#include "Stdafx.h"

using namespace System::Collections::Generic;

namespace ComputationalForensics {

#ifndef DATABASE_H

#define DATABASE_H
	/*
	Class creating objects of databases for easier access, description 
	and presentation when shown as result in the user interface.
	@author: Knut Lucas Andersen
	*/
	public ref class DatabaseObject sealed {
	public:
		//default constructor
		DatabaseObject();
		//destructor
		~DatabaseObject();
		//returns the list containing the row counts for the tables
		List<int> ^getRowCountList();
		//returns the name of this database
		System::String ^getDatabaseName();
		//returns the list of tables in this database
		List<System::String ^> ^getTableList();
		//returns the rowcount for the given table
		int getRowCountAtIndex(int tableIndex);
		//returns the name of the given table
		System::String ^getTableName(int tableIndex);
		//returns the rows for the given table
		List<System::String ^> ^getRows(int tableIndex);
		//returns the columns for the given table
		List<System::String ^> ^getColumnList(int tableIndex);
		//returns the cell content found at given colum and row no.
		System::String ^getCellContent(int columnIndex, int rowIndex);
		//returns the column name of the given table at the given column no.
		System::String ^getColumnName(int tableIndex, int columnIndex);
		//set the name of this database	
		void setDatabaseName(System::String ^dbName);
		//set rowcount for database tables
		void setRowCount(int rowCount);
		//add tables to this database
		void setTableName(System::String ^tableName);
		//add columns to this database
		void setColumnNames(List<System::String ^> ^columnList);
		//add rows to this database
		void setRows(List<System::String ^> ^rowContentList);
	private:
		//the rowcount for the tables in this database
		List<int> ^_rowCountList;
		//the name of this database
		System::String ^_databaseName;
		//list of tables in this database
		List<System::String ^> ^_tableList;
		//list of columns in this database
		//index1: table index
		//index2: column index
		List<List<System::String ^> ^> ^_columnList;
		//list containing the row cells in this database
		//index1: table index
		//index2: row index
		List<List<System::String ^> ^> ^_rowContentList;
	};
#endif
} //namespace
