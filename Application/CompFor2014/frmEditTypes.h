#pragma once
#include "sharedFunctions.h"

namespace CompFor2014 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	using namespace ComputationalForensics;

	/// <summary>
	/// Summary for frmEditTypes
	/// </summary>
	public ref class frmEditTypes : public System::Windows::Forms::Form {

	public:
		frmEditTypes(System::Windows::Forms::Form ^parent) {
			parentForm = parent;
			InitializeComponent();
		} //constructor

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmEditTypes() {
			if(components) {
				delete components;
			} //if
		} //destructor

#pragma region COMPONENT_CREATION

	private: System::Windows::Forms::Form ^parentForm;
	private: System::Windows::Forms::ComboBox^  cmbSelection;
	protected:

	private: System::Windows::Forms::Label^  lblSelection;
	private: System::Windows::Forms::Button^  btnSave;

	private: System::Windows::Forms::RichTextBox^  rTxtEditContent;

	private: System::Windows::Forms::Label^  lblEditContent;
	private: System::Windows::Forms::Button^  btnClose;
	private: System::Windows::Forms::Label^  lblEditTypes;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma endregion Creation of components used in the WinForm

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			this->cmbSelection = (gcnew System::Windows::Forms::ComboBox());
			this->lblSelection = (gcnew System::Windows::Forms::Label());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->rTxtEditContent = (gcnew System::Windows::Forms::RichTextBox());
			this->lblEditContent = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->lblEditTypes = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// cmbSelection
			// 
			this->cmbSelection->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbSelection->FormattingEnabled = true;
			this->cmbSelection->Location = System::Drawing::Point(143, 56);
			this->cmbSelection->Name = L"cmbSelection";
			this->cmbSelection->Size = System::Drawing::Size(177, 21);
			this->cmbSelection->TabIndex = 0;
			this->cmbSelection->SelectedIndexChanged += gcnew System::EventHandler(this, &frmEditTypes::cmbSelection_SelectedIndexChanged);
			// 
			// lblSelection
			// 
			this->lblSelection->AutoSize = true;
			this->lblSelection->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSelection->Location = System::Drawing::Point(12, 57);
			this->lblSelection->Name = L"lblSelection";
			this->lblSelection->Size = System::Drawing::Size(125, 16);
			this->lblSelection->TabIndex = 5;
			this->lblSelection->Text = L"select_what_to_edit";
			// 
			// btnSave
			// 
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSave->Location = System::Drawing::Point(12, 318);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(308, 31);
			this->btnSave->TabIndex = 2;
			this->btnSave->Text = L"save_changes";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmEditTypes::btnSave_Click);
			// 
			// rTxtEditContent
			// 
			this->rTxtEditContent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rTxtEditContent->Location = System::Drawing::Point(12, 110);
			this->rTxtEditContent->Name = L"rTxtEditContent";
			this->rTxtEditContent->Size = System::Drawing::Size(308, 202);
			this->rTxtEditContent->TabIndex = 1;
			this->rTxtEditContent->Text = L"";
			// 
			// lblEditContent
			// 
			this->lblEditContent->AutoSize = true;
			this->lblEditContent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEditContent->Location = System::Drawing::Point(12, 91);
			this->lblEditContent->Name = L"lblEditContent";
			this->lblEditContent->Size = System::Drawing::Size(80, 16);
			this->lblEditContent->TabIndex = 6;
			this->lblEditContent->Text = L"edit_content";
			// 
			// btnClose
			// 
			this->btnClose->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClose->Location = System::Drawing::Point(12, 355);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(308, 31);
			this->btnClose->TabIndex = 3;
			this->btnClose->Text = L"close_form";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &frmEditTypes::btnClose_Click);
			// 
			// lblEditTypes
			// 
			this->lblEditTypes->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblEditTypes->AutoSize = true;
			this->lblEditTypes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEditTypes->Location = System::Drawing::Point(40, 9);
			this->lblEditTypes->Name = L"lblEditTypes";
			this->lblEditTypes->Size = System::Drawing::Size(245, 24);
			this->lblEditTypes->TabIndex = 4;
			this->lblEditTypes->Text = L"edit_files_and_search_types";
			// 
			// frmEditTypes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(332, 398);
			this->Controls->Add(this->lblEditTypes);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->lblEditContent);
			this->Controls->Add(this->cmbSelection);
			this->Controls->Add(this->lblSelection);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->rTxtEditContent);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"frmEditTypes";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"frmEditTypes";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &frmEditTypes::frmEditTypes_FormClosed);
			this->Load += gcnew System::EventHandler(this, &frmEditTypes::frmMediaType_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion		

	private:
		String ^ADD_NEW_SEARCH_TYPES = "Add new search types";
		bool updatedValues = false;

	private: System::Void frmMediaType_Load(System::Object^  sender, System::EventArgs^  e) {
		setDefaultText();
		readTypesFromFile(0);
	} //frmMediaType_Load

	private: void setDefaultText() {
		this->Text = "Edit types";
		//labels
		this->lblEditTypes->Text = "Edit search and file types";
		this->lblSelection->Text = "Select what to edit:";
		this->lblEditContent->Text = "Add or remove content (seperate by newline)";
		//buttons
		this->btnSave->Text = "Save changes";
		this->btnClose->Text = "Close window";
	} //setDefaultText

	private: void readTypesFromFile(int index) {
		bool readSuccessfully = false;
		this->cmbSelection->Items->Clear();
		this->cmbSelection->Items->Add(ADD_NEW_SEARCH_TYPES);
		try {
			//create the folder if it doesn't exist
			FileOperations::createNewFolderIfNotExists(SharedFunctions::SEARCH_TYPES_FOLDER);
			String ^filePath = FileOperations::returnFilePath(SharedFunctions::SEARCH_TYPES_FOLDER,
				SharedFunctions::SEARCH_TYPES_FILE);
			List<String ^> ^searchTypesList = FileOperations::readStringFromFile(filePath);
			//does the file contain any search types?
			if(searchTypesList->Count > 0) {
				readSuccessfully = true;
				//retrieve the search types
				for each(String ^type in searchTypesList) {
					this->cmbSelection->Items->Add(type);
				} //foreach
			} //if
		} catch(ExceptionClass ^ex) {
			MessageBox::Show("An error occurred while attempting to read from files.\n" + ex->Message,
				"Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		} //try/catch
		//was content read from the file?
		if(!readSuccessfully) {
			//no file content, give hint on how to add types
			String ^helpText = "File is empty! Seperate new entries w/ newline:";
			this->lblEditContent->Text = helpText;
			this->rTxtEditContent->Focus();
		} //if
		//set the selected index
		this->cmbSelection->SelectedIndex = index;
	} //readTypesFromFile

	private: System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e) {
		//is the textbox empty and are no entries selected in the combobox?
		if(this->rTxtEditContent->Text == "" && this->cmbSelection->Text == ADD_NEW_SEARCH_TYPES) {
			//give warning that this will delete all existing entries
			String ^warning = "The field is empty. \nThis will delete all entries! \nContinue?";
			System::Windows::Forms::DialogResult dialog = MessageBox::Show(warning, "Warning!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
			if(dialog == System::Windows::Forms::DialogResult::Yes) {
				FileOperations::deleteAllFilesInFolder(SharedFunctions::SEARCH_TYPES_FOLDER);
			} else {
				this->rTxtEditContent->Focus();
			} //if
		} else {
			//write entries to file, check if conent is to be written to 
			//main file or the specified file type
			String ^path = "";
			String ^entries = this->rTxtEditContent->Text;
			if(this->cmbSelection->Text == ADD_NEW_SEARCH_TYPES) {
				path = FileOperations::returnFilePath(SharedFunctions::SEARCH_TYPES_FOLDER, SharedFunctions::SEARCH_TYPES_FILE);
			} else {
				String ^fileName = this->cmbSelection->Text + ".txt";
				path = FileOperations::returnFilePath(SharedFunctions::SEARCH_TYPES_FOLDER, fileName);
			} //if
			int length = entries->Length;
			String ^lastChar = entries->Substring(length - 1);
			if(!lastChar->Equals("\n")) {
				entries += "\n";
			} //if
			FileOperations::writeToFile(path, entries);
		} //if
		//refresh and reload entries
		unsigned int index = this->cmbSelection->SelectedIndex;
		readTypesFromFile(index);
		updatedValues = true;
	} //btnSave_Click

	private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	} //btnClose_Click

	private: System::Void cmbSelection_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		try {
			//empty textbox of previous content
			this->rTxtEditContent->Text = "";
			String ^filePath = "";
			if(this->cmbSelection->Text == ADD_NEW_SEARCH_TYPES) {
				filePath = FileOperations::returnFilePath(SharedFunctions::SEARCH_TYPES_FOLDER,
					SharedFunctions::SEARCH_TYPES_FILE);
			} else {
				String ^fileName = this->cmbSelection->Text + ".txt";
				filePath = FileOperations::returnFilePath(SharedFunctions::SEARCH_TYPES_FOLDER, fileName);
			} //if
			List<String ^> ^searchTypesList = FileOperations::readStringFromFile(filePath);
			for each(String ^entry in searchTypesList) {
				this->rTxtEditContent->Text += entry + "\n";
			} //foreach
		} catch(ExceptionClass ^) {
			//to avoid displaying error messages each time a new type is displayed, 
			//the error is caught and ignored
		} //try/catch
	} //cmbSelection_SelectedIndexChanged

	private: System::Void frmEditTypes_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		if(updatedValues) {
			//restart the application to update the list of search types on parent form
			Application::Restart();
		} //if
	} //frmEditTypes_FormClosed
	}; //frmEditTypes
} //namespace