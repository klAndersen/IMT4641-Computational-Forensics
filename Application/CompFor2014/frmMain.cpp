/**
Contains the functions used in frmMain.h
The only functions not found here are initialization functions, since
these only set text and enable/disable controls.
@author: Knut Lucas Andersen
**/

#include "stdafx.h"
#include "frmMain.h"
#include "sharedFunctions.h"
#include "sqliteoperations.h"
#include "Shlwapi.h"

#pragma comment(lib, "Shlwapi.lib")

namespace CompFor2014 {

	/*
	Sets the path to the selected parent folder,
	where the subfolders contain the databases.
	*/
	void frmMain::setFolderPath() {
		//set default path text
		this->lblPath->Text = DEFAULT_PATH_TEXT;
		System::Windows::Forms::DialogResult dialog = fbdDatabases->ShowDialog();
		//was a path chosen?
		if(dialog == System::Windows::Forms::DialogResult::OK) {
			String ^path = fbdDatabases->SelectedPath;
			this->lblPath->Text = path;
			//shows content in tooltip if the length is over the labels size
			tipLabel->SetToolTip(this->lblPath, path);
			//load the folder(s) containing the databases
			List<String ^> ^folderList = loadFolders(path);
			//was there any folder(s) found?
			if(folderList->Count > 0) {
				this->chkSelectAllFolders->Checked = false;
				this->chkLstDatabaseFolders->Items->Clear();
				setEnabledAndHiddenControls(true);
				for each(String ^folder in folderList) {
					this->chkLstDatabaseFolders->Items->Add(folder);
				} //for each
				this->chkSelectAllFolders->Checked = this->rbAllDatabases->Checked;
			} //if
		} //if
	} //setFolderPath

	/*
	Reads the name of the folders from the passed path.
	The names are then added to the list which is returned.
	-------------------------------------------------------
	@param path: String ^ - The path to parent folder with databases
	@return: List<String ^>^ - List containing the names of the folders
	containing SQLite databases
	*/
	List<String ^> ^frmMain::loadFolders(String ^path) {
		List<String ^> ^folderNames = gcnew List<String ^>();
		for each (String ^dir in Directory::GetDirectories(path)) {
			folderNames->Add(dir);
		} //foreach
		return folderNames;
	} //loadFolders

	/*
	Empty lists, clear search results from
	treeview, datagridview and labels.
	*/
	void frmMain::removePreviousSearchData() {
		pathToDatabaseList = gcnew List<String ^>();
		databaseFileList = gcnew List<List<String ^> ^>();
		additionalStringsList = gcnew List<String ^>();
		selectedSearchTypesList = gcnew List<String ^>();
		this->tvDatabases->Nodes->Clear();
		this->dgvResults->Columns->Clear();
		this->dgvResults->Rows->Clear();
		this->lblSelectedFolder->Text = "N/A";
		this->lblDatabase->Text = "N/A";
	} //removePreviousSearchData

	/*
	Starts the search for evidence presuming that the backgroundworker
	is not already running and that all pre-requisites for starting the
	search is ok.
	*/
	void frmMain::startSearch() {
		//is the backgoundworker running?
		if(!this->bwDataRetrieval->IsBusy) {
			removePreviousSearchData();
			String ^errorMsg = "";
			String ^errorTitle = "";
			String ^content = this->rTxtAdditional->Text;
			bool searchCanStart = true;
			bool specificDatabases = this->rbSpecificDatabases->Checked;
			bool specificSearchTypes = this->rbSpecificSearchType->Checked;
			if(specificDatabases || specificSearchTypes) {
				searchCanStart = isSpecifiedSelectionOK();
			} //if
			if(searchCanStart) {
				bool includeTime = this->chkIncludeTimeLine->Checked;
				bool includeAdditionalStrings = this->chkIncludeAdditionalStrings->Checked;
				//retrieve search parameters
				String ^fromDate = "";
				String ^toDate = "";
				if(includeTime) {
					fromDate = this->dtpFromDate->Value.ToShortDateString()
						+ " " + this->dtpFromTime->Value.ToShortTimeString();
					toDate = this->dtpToDate->Value.ToShortDateString()
						+ " " + this->dtpToTime->Value.ToShortTimeString();
				} //if
				if(includeAdditionalStrings && !content->Equals("")) {
					//split at newline to create seperated entries
					additionalStringsList->AddRange(content->Split('\n'));
				} //if
				searchCanStart = loadDatabasesFromFolders();
				loadFiletypesFromFiles();
				if(includeTime) {
					selectedSearchTypesList->Add(fromDate);
					selectedSearchTypesList->Add(toDate);
				} //if
				if(searchCanStart) {
					this->btnStartSearch->Enabled = false;
					this->btnBrowse->Enabled = false;
					//start the backgroundworker
					this->bwDataRetrieval->RunWorkerAsync();
				} //if
			} //if
		} //if
	} //startSearch

	/*
	Takes the number of checked items from the checkedlistboxes
	and checks if it is zero. If one of them are zero,
	the boolean value false is returned. If at least one item
	is selected, the function returns true.
	--------------------------------
	@return bool: True - At least one item is selected,
	False - No items on given specification is selected
	*/
	bool frmMain::isSpecifiedSelectionOK() {
		String ^errorMsg = "";
		String ^errorTitle = "";
		bool selectionOK = true;
		//get number of selected folders and check that at least one is selected
		int noCheckedSelections = this->chkLstDatabaseFolders->CheckedItems->Count;
		if(noCheckedSelections == 0) {
			errorMsg = "No folders are selected. \nAt least one folder must be selected before search can start.";
			errorTitle = "Folder selection";
			MessageBox::Show(errorMsg, errorTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->lstInformation->Items->Add(errorMsg);
			return false;
		} //if
		//get number of selected search types and check that at least one is selected
		noCheckedSelections = this->chkLstSelectSearchTypes->CheckedItems->Count;
		if(noCheckedSelections == 0) {
			errorMsg = "No search types are selected. \nAt least one type must be selected before search can start.";
			errorTitle = "Type selection";
			MessageBox::Show(errorMsg, errorTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->lstInformation->Items->Add(errorMsg);
			return false;
		} //if
		return selectionOK;
	} //isSpecifiedSelectionOK

	/*
	Loops through the selected database folders and checks if
	databases exits at given location. If database(s) exists at
	given location, the path (including file name/extension) is
	added to the pathToDatabaseList.
	------------------------------------------------------------
	@return: bool - Returns true if at least one folder containing
	SQLite database was found, else false.
	*/
	bool frmMain::loadDatabasesFromFolders() {
		try {
			std::wstring tempString;
			String ^mTempString = "";
			String ^dbPath = "\\data\\databases";
			pathToDatabaseList = gcnew List<String ^>();
			databaseFileList = gcnew List<List<String ^> ^>();
			List<String ^> ^tempDatabaseList = gcnew List<String ^>();
			//if all folders are selected, check them before retrieval
			if(this->rbAllDatabases->Checked) {
				selectAllInCheckedListBox(chkLstDatabaseFolders, true);
			} //if
			//loop through the selected folders and retrieve only the database files
			for each (String ^folderPath in this->chkLstDatabaseFolders->CheckedItems) {
				mTempString = folderPath + dbPath;
				//convert managed string to std::wstring and convert the std::wstring to a 
				//const char pointer (LPCTSTR) and then check if the concatenated path exists
				SharedFunctions::MarshalString(mTempString, tempString);
				LPCTSTR tempPath = const_cast<LPCTSTR>(tempString.c_str());
				if(PathIsDirectory(tempPath)) {
					pathToDatabaseList->AddRange(FileOperations::returnListOfDatabaseFiles(mTempString, tempDatabaseList));
					if(tempDatabaseList->Count > 0) {
						databaseFileList->Add(tempDatabaseList);
					} //if
					tempDatabaseList = gcnew List<String ^>();
				} //if
			} //foreach
			//was databases found in selected folders?
			if(pathToDatabaseList->Count == 0) {
				String ^title = "No databases";
				String ^errorMsg = "";
				errorMsg = "No databases found in selected folders! \nCancelling search....";
				this->lblNoMatches->Visible = true;
				this->lblNoMatches->Text = errorMsg;
				MessageBox::Show(errorMsg, title, MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->lstInformation->Items->Add(errorMsg);
				return false;
			} //if
		} catch(ExceptionClass ^ex) {
			MessageBox::Show(ex->ToString(), ex->getExceptionTitle(), MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->lstInformation->Items->Add(ex->ToString());
		} //try/catch
		return true;
	} //loadDatabasesFromFolders

	/*
	Takes the selected searchtypes and adds it to a list.
	The file containing the search types values are then opened,
	read and added to the filetypeList
	*/
	void frmMain::loadFiletypesFromFiles() {
		try {
			String ^filePath = "";
			String ^folder = "";
			selectedSearchTypesList = gcnew List<String ^>();
			List<String ^> ^tempList = gcnew List<String ^>();
			folder = SharedFunctions::SEARCH_TYPES_FOLDER;
			//if all types are selected, check them before retrieval
			if(this->rbAllSearchTypes->Checked) {
				selectAllInCheckedListBox(chkLstSelectSearchTypes, true);
			} //if
			//fill lists with selected search - and file types
			for each (String ^searchType in this->chkLstSelectSearchTypes->CheckedItems) {
				tempList->Clear();
				selectedSearchTypesList->Add(searchType);
				searchType += ".txt";
				filePath = FileOperations::returnFilePath(folder, searchType);
				tempList = FileOperations::readStringFromFile(filePath);
				selectedSearchTypesList->AddRange(tempList);
			} //foreach
		} catch(ExceptionClass ^ex) {
			MessageBox::Show(ex->ToString(), ex->getExceptionTitle(),
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		} //try/catch
	} //loadFiletypesFromFiles

	/*
	Checks if backgroundworker is running, and attemps to cancel
	the current operation by calling CancelAsync().
	*/
	void frmMain::cancelSearch() {
		if(this->bwDataRetrieval->IsBusy) {
			this->bwDataRetrieval->CancelAsync();
		} //if
	} //cancelSearch

	/*
	As long as the search has not been cancelled, this function fills
	up the treeview and datagridview with the content related to the
	executed search. As long as at least one database were found in the
	selected folders, the following will be added to the treeview:
	- The root folder
	- The subfolders containing the database(s)
	- The databases and their tables
	-------------------------------------------------------
	@param worker: BackgroundWorker^
	@param e: DoWorkEventArgs^
	*/
	void frmMain::fillUpViews(BackgroundWorker ^worker, DoWorkEventArgs ^e) {
		//has the search been cancelled?
		if(worker->CancellationPending) {
			cancelSearch();
		} else { //still active  
			List<FuzzySearch ^> ^resultList = fuzzyObj->getListOfSearchResults();
			//was databases found after filtering?
			if(resultList->Count) {
				//update progressbar
				float total = static_cast<float>(resultList->Count);
				SharedFunctions::updateProgressBar(0, total, worker);
				//set the name of the root node to the parent folder
				String ^parentFolder = this->lblPath->Text;
				root = gcnew TreeNode(parentFolder);
				for(int index = 0; index < resultList->Count; index++) {
					addNewNode(worker, resultList[index]->getPath(), root, index, total);
					SharedFunctions::updateProgressBar(index, total, worker);
				} //for
				//fill progressbar since work is completed
				SharedFunctions::updateProgressBar(static_cast<int>(total), total, worker);
			} //if
		} //if
	} //fillUpViews

	/*
	Creates a new node based on the passed values. The node is
	added as a child to the passed root, and the index is used for
	selecting the databases contained in the currently selected folder.
	-------------------------------------------------------
	@param nodeName: String^ - The name of the new node
	@param root: TreeNode^ - The parent of this node
	@param index: int - The index in the list for the current node
	*/
	void frmMain::addNewNode(BackgroundWorker ^worker, String ^nodeName, TreeNode ^root, int index, const float total) {
		TreeNode ^newNode = gcnew TreeNode(nodeName);
		fillTreeView(worker, newNode, index, total);
		root->Nodes->Add(newNode);
	} //addNewNode

	/*
	Fills the treeview with the folders databases.
	The databases are added as the children of the current folder,
	where the index is the pointer to the parent of this database.
	-------------------------------------------------------
	@param root: TreeNode^ - The parent node of the current selection
	@param index: int - The parents index in the databaseList
	*/
	void frmMain::fillTreeView(BackgroundWorker ^worker, TreeNode ^root, int index, const float total) {
		try {
			//has the search been cancelled?
			if(worker->CancellationPending) {
				cancelSearch();
			} else {
				String ^tableName = "";
				TreeNode ^tableNode;
				TreeNode ^databaseNode;
				List<DatabaseObject ^> ^dbList = gcnew List<DatabaseObject ^>();
				dbList = fuzzyObj->getListOfSearchResults()[index]->getDatabaseList();
				//loop through the databases in the current folder to create nodes
				for each(DatabaseObject ^database in dbList) {
					databaseNode = gcnew TreeNode(database->getDatabaseName());
					root->Nodes->Add(databaseNode);
					//loop through the tables and add them to the folder node
					for(int tableIndex = 0; tableIndex < database->getTableList()->Count; tableIndex++) {
						tableName = database->getTableName(tableIndex);
						tableNode = gcnew TreeNode(tableName);
						databaseNode->Nodes->Add(tableNode);
					} //for
				} //foreach
			} //if
		} catch(ExceptionClass ^ex) {
			addItemInformation("Error occured while filling treeview: " + ex->ToString());
		} // try/catch    
	} //fillTreeView

	/*
	This function handles the needs for invoke when adding content
	to the listbox from a function that is not executed on the GUI-thread.
	Example of this is when using BackgroundWorker to add information.
	-------------------------------------------------------
	@param information: String^ - The text to add to the listbox
	*/
	void frmMain::addItemInformation(String ^information) {
		//is invoke required?
		if(this->lstInformation->InvokeRequired) {
			this->lstInformation->Invoke(gcnew frmMain::invokeAddItemInformation(this,
				&frmMain::addItemInformation), information);
		} else { //no invoke needed, fill listbox
			this->lstInformation->Items->Add(information);
		} //if 
	} //addItemInformation

	/*
	Fills the datagridview with the content from the database, if any.
	The datagridview is filled based on the passed index values, where
	each value retrieves the content based on selected folder path,
	database and table.
	-------------------------------------------------------
	@param folderIndex: int - The index of the selected folder
	@param dbIndex: int - The index of the selected database
	@param tableIndex: int - The index of the selected table
	*/
	void frmMain::fillDatagridviewWithResults(int folderIndex, int dbIndex, int tableIndex) {
		//is invoke required?
		if(this->dgvResults->InvokeRequired) {
			this->dgvResults->Invoke(gcnew frmMain::invokeDatagridviewFilling(this,
				&frmMain::fillDatagridviewWithResults), folderIndex, dbIndex, tableIndex);
		} else {
			try {
				int rowCount = 0,
					columnCount = 0;
				DataGridViewTextBoxColumn ^ newColumn;


				List<String ^> ^tempList = gcnew List<String ^>();
				List<DatabaseObject ^> ^dbList = gcnew List<DatabaseObject ^>();
				dbList = fuzzyObj->getListOfSearchResults()[folderIndex]->getDatabaseList();


				//get the list containing the column names and add them to datagridview
				tempList = dbList[dbIndex]->getColumnList(tableIndex);
				for(int columnIndex = 0; columnIndex < tempList->Count; columnIndex++) {
					newColumn = gcnew DataGridViewTextBoxColumn();
					newColumn->Name = tempList[columnIndex];
					newColumn->HeaderText = newColumn->Name;
					dgvResults->Columns->Add(newColumn);
				} //for

				//get the number of rows and check that at least one row exists
				rowCount = dbList[dbIndex]->getRowCountAtIndex(tableIndex);

				if(rowCount > 0) {
					int rows = 0;
					int cells = 0;
					//get the list containing the rows
					tempList = gcnew List<String ^>();
					tempList = dbList[dbIndex]->getRows(tableIndex);
					//set the row count and get number of columns
					dgvResults->RowCount = rowCount;
					columnCount = dgvResults->ColumnCount;

					//loop through the rows
					for(int rowIndex = 0; rowIndex < tempList->Count; rowIndex++) {
						//is the current row filled up?
						if(cells >= columnCount) {
							cells = 0;
							rows++;
						} //if
						dgvResults->Rows[rows]->Cells[cells]->Value = tempList[rowIndex];
						cells++;
					} //for

					//resize columns and rows in the datagridview
					this->dgvResults->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);
					this->dgvResults->AutoResizeRows(DataGridViewAutoSizeRowsMode::AllCellsExceptHeaders);
				} //if

			} catch(IndexOutOfRangeException ^ex) {
				String ^errorMsg = ex->ToString();
				MessageBox::Show(errorMsg, "IndexOutOfRangeException", MessageBoxButtons::OK, MessageBoxIcon::Error);
				addItemInformation(errorMsg);
			} catch(ArgumentOutOfRangeException ^ex) {
				String ^errorMsg = ex->ToString();
				MessageBox::Show(errorMsg, "ArgumentOutOfRangeException", MessageBoxButtons::OK, MessageBoxIcon::Error);
				addItemInformation(errorMsg);
			} catch(ExceptionClass ^ex) {
				String ^errorMsg = "An error occured while filling datagridview: ";
				errorMsg += ex->ToString();
				MessageBox::Show(errorMsg, "Datagridview", MessageBoxButtons::OK, MessageBoxIcon::Error);
				addItemInformation(errorMsg);
			} //try/catch
		} //if
	} //fillDatagridviewWithResults

	/*
	Searches through the entries listed in the treeview and highlights
	the entries that contains the text that was searched for.
	-------------------------------------------------------
	@param searchText: String^ - The text to search after in treeview
	*/
	void frmMain::searchAndHighlightTreeviewEntries(String ^searchText) {
		String ^search = this->txtSearchTreeview->Text;
		int selectedindex = this->cmbEntryType->SelectedIndex;
		switch(selectedindex) {
			case 0:
				//search through all entries
				searchThroughAllTreeviewEntries(searchText);
				break;
			case 1:
				//search through folders
				searchThroughTreeviewFolderEntries(searchText);
				break;
			case 2:
				//search through databases
				searchThroughTreeviewDatabaseEntries(searchText);
				break;
			case 3:
				//search through tables
				searchThroughTreeviewTableEntries(searchText);
				break;
			default:
				//search through all entries
				searchThroughAllTreeviewEntries(searchText);
				break;
		} //switch
	} //setBackgroundColorTreeView

	/*
	Search through all entries listed in the treeview.
	-------------------------------------------------------
	@param searchText: String^ - The text to search after in treeview
	*/
	void frmMain::searchThroughAllTreeviewEntries(String ^searchText) {
		//there is only one rootnode, so this can be retrieved without a loop
		TreeNode ^root = this->tvDatabases->Nodes[0];
		searchText = searchText->ToLower();
		for each(TreeNode ^folder in root->Nodes) {
			//check if folder contains the searched entry
			if(folder->Text->ToLower()->Contains(searchText)) {
				folder->BackColor = System::Drawing::Color::Yellow;
			} //if
			for each(TreeNode ^db in folder->Nodes) {
				//check if database contains the searched entry
				if(db->Text->ToLower()->Contains(searchText)) {
					db->BackColor = System::Drawing::Color::Yellow;
					folder->BackColor = System::Drawing::Color::Yellow;
				} //if				
				for each(TreeNode ^table in db->Nodes) {
					//check if table contains the searched entry
					if(table->Text->ToLower()->Contains(searchText)) {
						table->BackColor = System::Drawing::Color::Yellow;
						db->BackColor = System::Drawing::Color::Yellow;
						folder->BackColor = System::Drawing::Color::Yellow;
					} //if
				} //foreach
			} //foreach
		} //foreach
	} //searchThroughAllTreeviewEntries

	/*
	Search through the folders listed in the treeview.
	-------------------------------------------------------
	@param searchText: String^ - The text to search after in treeview
	*/
	void frmMain::searchThroughTreeviewFolderEntries(String ^searchText) {
		//there is only one rootnode, so this can be retrieved without a loop
		TreeNode ^root = this->tvDatabases->Nodes[0];
		for each(TreeNode ^folder in root->Nodes) {
			if(folder->Text->Contains(searchText)) {
				folder->BackColor = System::Drawing::Color::Yellow;
			} //if
		} //foreach
	} //searchThroughTreeviewFolderEntries

	/*
	Search through the databases listed in the treeview.
	-------------------------------------------------------
	@param searchText: String^ - The text to search after in treeview
	*/
	void frmMain::searchThroughTreeviewDatabaseEntries(String ^searchText) {
		//there is only one rootnode, so this can be retrieved without a loop
		TreeNode ^root = this->tvDatabases->Nodes[0];
		for each(TreeNode ^folder in root->Nodes) {
			for each(TreeNode ^db in folder->Nodes) {
				if(db->Text->Contains(searchText)) {
					db->BackColor = System::Drawing::Color::Yellow;
					folder->BackColor = System::Drawing::Color::Yellow;
				} //if
			} //foreach
		} //foreach
	} //searchThroughTreeviewDatabaseEntries

	/*
	Search through the database tables listed in the treeview.
	-------------------------------------------------------
	@param searchText: String^ - The text to search after in treeview
	*/
	void frmMain::searchThroughTreeviewTableEntries(String ^searchText) {
		//there is only one rootnode, so this can be retrieved without a loop
		TreeNode ^root = this->tvDatabases->Nodes[0];
		for each(TreeNode ^folder in root->Nodes) {
			for each(TreeNode ^db in folder->Nodes) {
				for each(TreeNode ^table in db->Nodes) {
					if(table->Text->Contains(searchText)) {
						table->BackColor = System::Drawing::Color::Yellow;
						db->BackColor = System::Drawing::Color::Yellow;
						folder->BackColor = System::Drawing::Color::Yellow;
					} //if
				} //foreach
			} //foreach
		} //foreach
	} //searchThroughTreeviewTableEntries

	/*
	Clear the highlighted entries in the treeview.
	Entries get highlighted when searches are ran against the treeview content.
	*/
	void frmMain::clearHighlightedEntries() {
		//there is only one rootnode, so this can be retrieved without a loop
		TreeNode ^root = this->tvDatabases->Nodes[0];
		root->BackColor = System::Drawing::Color::White;
		for each(TreeNode ^folder in root->Nodes) {
			folder->BackColor = System::Drawing::Color::White;
			for each(TreeNode ^db in folder->Nodes) {
				db->BackColor = System::Drawing::Color::White;
				for each(TreeNode ^table in db->Nodes) {
					table->BackColor = System::Drawing::Color::White;
				} //foreach
			} //foreach
		} //foreach
	} //clearHighlightedEntries

	/*
	The search was completed, show the results.
	*/
	void frmMain::searchCompleted() {
		try {
			//was databases found?
			if(fuzzyObj->getListOfSearchResults()->Count > 0) {
				//clean up
				delete bwDataRetrieval;
				//switch to the tab containing the search results
				this->tabWindows->SelectedIndex = 1;
				//add the root with child nodes to the treeview
				this->tvDatabases->Nodes->Add(root);
				root->Expand();
				this->tvDatabases->SelectedNode = root;
				this->lstInformation->Items->Add("Search completed! See tab: " + this->tabSearchResult->Text) + ".";
				this->lblSelectedFolder->Text = this->tvDatabases->SelectedNode->Text;
				this->tipLabel->SetToolTip(this->lblSelectedFolder, root->Text);
				this->cmbEntryType->Enabled = true;
				this->txtSearchTreeview->Enabled = true;
				this->btnSearchTreeview->Enabled = true;
				this->btnClearTvSearch->Enabled = true;
			} else {
				String ^message = "No results matching criterias were found!";
				this->lblNoMatches->Visible = true;
				this->lblNoMatches->Text = message;
				MessageBox::Show(message, "No hits!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			} //if
		} catch(System::Exception ^ex) {
			//display error and stacktrace
			this->lstInformation->Items->Add("StackTrace:\n" + ex->StackTrace);
			MessageBox::Show(ex->Message, "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		} //try/catch
	} //searchCompleted
} //namespace