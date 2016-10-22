#include "Stdafx.h"
#include "databaseobject.h"

using namespace System;
using namespace Collections::Generic;

namespace ComputationalForensics {

	/*
	Default constructor
	*/
	DatabaseObject::DatabaseObject() {
		_databaseName = "";
		_tableList = gcnew List<String ^>();
		_columnList = gcnew List<List<String ^> ^>();
		_rowCountList = gcnew List<int>();
		_rowContentList = gcnew List<List<String ^> ^>();
	} //constructor

	/*
	Destructor
	*/
	DatabaseObject::~DatabaseObject() {

	} //destructor

	/*
	Returns a list containing the row count for all the 
	tables in this database, where the index is the index 
	of the selected table.
	--------------------------------------------------
	@return: List<int> - List with row counts 
	*/
	List<int> ^DatabaseObject::getRowCountList() {
		return _rowCountList;
	} //getRowCountList

	/*
	Returns the name of this database
	--------------------------------------------------
	@return: String ^ - Name of this database
	*/
	String ^DatabaseObject::getDatabaseName() {
		return _databaseName;
	} //getDatabaseName

	/*
	Returns the list of tables in this database
	--------------------------------------------------
	@return: List<String ^> - List of tables
	*/
	List<String ^> ^DatabaseObject::getTableList() {
		return _tableList;
	} //getTableList

	/*
	Returns the row count for the given table.
	--------------------------------------------------
	@parameter tableIndex: int - Index of selected table
	@return: int - the rowcount at the given table index
	*/
	int DatabaseObject::getRowCountAtIndex(int tableIndex) {
		return _rowCountList[tableIndex];
	} //getRowCountAtIndex

	/*
	Returns the table name of the given table based 
	on passed index.
	--------------------------------------------------
	@parameter tableIndex: int - Index of selected table
	@return: String ^ - The name of table at this index
	*/
	String ^DatabaseObject::getTableName(int tableIndex) {
		return _tableList[tableIndex];
	} //getTableName

	/*
	Returns the columns belonging to the table, based on the 
	passed index.
	--------------------------------------------------
	@parameter tableIndex: int - Index of selected table
	@return: List<String ^> - List of columns for given table.
	*/
	List<String ^> ^DatabaseObject::getColumnList(int tableIndex) {
		return _columnList[tableIndex];
	} //getColumnList

	/*
	Returns the rows belonging to the table, based on the 
	passed index.
	--------------------------------------------------
	@parameter tableIndex: int - Index of selected table
	@return: List<String ^> - List of rows for given table. 
	*/
	List<String ^> ^DatabaseObject::getRows(int tableIndex) {
		return _rowContentList[tableIndex];
	} //getRows

	/*
	Returns the column name for the given table, based on 
	passed table and column index
	--------------------------------------------------
	@parameter tableIndex: int - Index of selected table
	@parameter columnIndex: int - Index of selected column
	@return: String^ - The name of this column in the table
	*/
	String ^DatabaseObject::getColumnName(int tableIndex, int columnIndex) {
		return _columnList[tableIndex]->ToArray()[columnIndex];
	} //getColumnName

	/*
	Returns the content found in the cell at the passed position 
	of the given column and row number.
	--------------------------------------------------
	@parameter columnIndex: int -  Index of selected column
	@parameter rowIndex: int -  Index of selected row
	@return: String^ - The cell content at given column and row
	*/
	String ^DatabaseObject::getCellContent(int columnIndex, int rowIndex) {
		return _rowContentList[columnIndex]->ToArray()[rowIndex];
	} //getCellContent

	/*
	Set the name of this database.
	--------------------------------------------------
	@parameter dbName: String^ - DatabaseObject name
	*/
	void DatabaseObject::setDatabaseName(String ^dbName) {
		this->_databaseName = dbName;
	} //setDatabaseName

	/*
	Set the name of this database.
	--------------------------------------------------
	@parameter rowCount: int - Row count for current table
	*/
	void DatabaseObject::setRowCount(int rowCount) {
		this->_rowCountList->Add(rowCount);
	} //setRowCount

	/*
	Set the tables belonging to this database.
	--------------------------------------------------
	@parameter tableName: String ^ - List of tables
	*/
	void DatabaseObject::setTableName(String ^tableName) {
		this->_tableList->Add(tableName);
	} //setTables

	/*
	Set the columns belonging to this databases tables.
	--------------------------------------------------
	@parameter columnList: List<String ^> - List of columns
	*/
	void DatabaseObject::setColumnNames(List<String ^> ^columnList) {
		this->_columnList->Add(columnList);
	} //setColumns

	/*
	Set the rows belonging to this databases tables.
	--------------------------------------------------
	@parameter rowContentList: List<String ^> - List containing 
	the rows found in the given table
	*/
	void DatabaseObject::setRows(List<String ^> ^rowContentList) {
		this->_rowContentList->Add(rowContentList);
	} //setRows
} //namespace 