#pragma once
#include "frmEditTypes.h"
#include "fuzzysearch.h"

namespace CompFor2014 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;

	using namespace ComputationalForensics;

	/// <summary>
	/// Summary for frmMain
	/// </summary>
	public ref class frmMain : public System::Windows::Forms::Form {
	public:
		frmMain(void) {
			InitializeComponent();
		} //constructor

	protected:
		/// <summary>
		/// Clean up any resources being used
		/// </summary>
		~frmMain() {
			cancelSearch();
			if(components) {
				delete components;
			}
		} //destructor

#pragma region COMPONENT_CREATION

	private: System::Windows::Forms::TreeView^  tvDatabases;
	protected:

	protected:

	private: System::Windows::Forms::ToolTip^  tipLabel;
	private: System::Windows::Forms::ProgressBar^  pbProgress;
	private: System::Windows::Forms::DataGridView^  dgvResults;
	private: System::ComponentModel::BackgroundWorker^  bwDataRetrieval;
	private: System::Windows::Forms::TabControl^  tabWindows;
	private: System::Windows::Forms::TabPage^  tabSearchSetup;
	private: System::Windows::Forms::TabPage^  tabSearchResult;

	private: System::Windows::Forms::HelpProvider^  hpHelper;
	private: System::Windows::Forms::MenuStrip^  menuBar;
	private: System::Windows::Forms::ContextMenuStrip^  ctmTreeview;
	private: System::Windows::Forms::ContextMenuStrip^  ctmDatagridview;
	private: System::Windows::Forms::FolderBrowserDialog^  fbdDatabases;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmFile;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmHelp;
	private: System::Windows::Forms::Button^  btnStartSearch;

	private: System::Windows::Forms::DateTimePicker^  dtpFromDate;
	private: System::Windows::Forms::RichTextBox^  rTxtAdditional;


	private: System::Windows::Forms::Label^  lblDbSelect;

	private: System::Windows::Forms::Label^  lblProgress;
	private: System::Windows::Forms::Label^  lblFromDate;
	private: System::Windows::Forms::Label^  lblSearchTitle;

	private: System::Windows::Forms::Label^  lblNoMatches;

	private: System::Windows::Forms::Label^  lblPath;

	private: System::Windows::Forms::Label^  lblPathDescription;
	private: System::Windows::Forms::Button^  btnBrowse;


	private: System::Windows::Forms::ListBox^  lstInformation;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmNewSearch;

	private: System::Windows::Forms::ToolStripMenuItem^  tsmExit;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmShowHelp;

	private: System::Windows::Forms::Button^  btnReset;
	private: System::Windows::Forms::RadioButton^  rbSpecificDatabases;
	private: System::Windows::Forms::RadioButton^  rbAllDatabases;
	private: System::Windows::Forms::CheckedListBox^  chkLstDatabaseFolders;


	private: System::Windows::Forms::Button^  btnCancel;
	private: System::Windows::Forms::CheckBox^  chkIncludeAdditionalStrings;

	private: System::Windows::Forms::CheckBox^  chkIncludeTimeLine;


	private: System::Windows::Forms::DateTimePicker^  dtpToDate;

	private: System::Windows::Forms::Label^  lblToDate;

	private: System::Windows::Forms::Label^  lblResultTitle;





	private: System::Windows::Forms::ToolStripMenuItem^  tsmCancelSearch;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmOptions;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmLanguage;

	private: System::Windows::Forms::ToolStripMenuItem^  tsmEditSearchData;

	private: System::Windows::Forms::HelpProvider^  helpProvider1;
	private: System::Windows::Forms::RadioButton^  rbSpecificSearchType;

	private: System::Windows::Forms::RadioButton^  rbAllSearchTypes;
	private: System::Windows::Forms::CheckedListBox^  chkLstSelectSearchTypes;
	private: System::Windows::Forms::Label^  lblSelectSearchTypes;
	private: System::Windows::Forms::Panel^  panelSearchTypes;

	private: System::Windows::Forms::Panel^  panelDatabaseSelection;
	private: System::Windows::Forms::CheckBox^  chkSelectAllFolders;
	private: System::Windows::Forms::DateTimePicker^  dtpToTime;
	private: System::Windows::Forms::DateTimePicker^  dtpFromTime;
	private: System::Windows::Forms::Label^  lblAdditionalHelpText;
	private: System::Windows::Forms::Panel^  panelDateTime;
	private: System::Windows::Forms::Label^  lblDatabase;
	private: System::Windows::Forms::Label^  lblSelectedFolder;


	private: System::Windows::Forms::Label^  lblSelectedDatabase;
	private: System::Windows::Forms::Label^  lblTreeViewFolder;



	private: System::Windows::Forms::Label^  lblSearchTreeview;
	private: System::Windows::Forms::TextBox^  txtSearchTreeview;
	private: System::Windows::Forms::Button^  btnSearchTreeview;
	private: System::Windows::Forms::Button^  btnClearTvSearch;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmExpandClose;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmExpandAll;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmCloseAll;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmExpandSelected;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmCloseSelected;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmOpenFolder;
	private: System::Windows::Forms::ComboBox^  cmbEntryType;


	private: System::ComponentModel::IContainer^  components;

#pragma endregion Creation of components used in the WinForm

	private:
		/// <summary>
		/// Required designer variable
		/// </summary>
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor
		/// </summary>
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->btnStartSearch = (gcnew System::Windows::Forms::Button());
			this->dtpFromDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->tvDatabases = (gcnew System::Windows::Forms::TreeView());
			this->ctmTreeview = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->tsmExpandClose = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmExpandAll = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmCloseAll = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmExpandSelected = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmCloseSelected = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmOpenFolder = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipLabel = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->lstInformation = (gcnew System::Windows::Forms::ListBox());
			this->btnBrowse = (gcnew System::Windows::Forms::Button());
			this->rTxtAdditional = (gcnew System::Windows::Forms::RichTextBox());
			this->pbProgress = (gcnew System::Windows::Forms::ProgressBar());
			this->dgvResults = (gcnew System::Windows::Forms::DataGridView());
			this->ctmDatagridview = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->lblDbSelect = (gcnew System::Windows::Forms::Label());
			this->lblProgress = (gcnew System::Windows::Forms::Label());
			this->lblFromDate = (gcnew System::Windows::Forms::Label());
			this->bwDataRetrieval = (gcnew System::ComponentModel::BackgroundWorker());
			this->tabWindows = (gcnew System::Windows::Forms::TabControl());
			this->tabSearchSetup = (gcnew System::Windows::Forms::TabPage());
			this->panelDateTime = (gcnew System::Windows::Forms::Panel());
			this->lblAdditionalHelpText = (gcnew System::Windows::Forms::Label());
			this->dtpToDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->chkIncludeTimeLine = (gcnew System::Windows::Forms::CheckBox());
			this->lblToDate = (gcnew System::Windows::Forms::Label());
			this->dtpToTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->chkIncludeAdditionalStrings = (gcnew System::Windows::Forms::CheckBox());
			this->dtpFromTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->panelSearchTypes = (gcnew System::Windows::Forms::Panel());
			this->rbAllSearchTypes = (gcnew System::Windows::Forms::RadioButton());
			this->rbSpecificSearchType = (gcnew System::Windows::Forms::RadioButton());
			this->lblSelectSearchTypes = (gcnew System::Windows::Forms::Label());
			this->panelDatabaseSelection = (gcnew System::Windows::Forms::Panel());
			this->chkSelectAllFolders = (gcnew System::Windows::Forms::CheckBox());
			this->rbAllDatabases = (gcnew System::Windows::Forms::RadioButton());
			this->rbSpecificDatabases = (gcnew System::Windows::Forms::RadioButton());
			this->chkLstSelectSearchTypes = (gcnew System::Windows::Forms::CheckedListBox());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->chkLstDatabaseFolders = (gcnew System::Windows::Forms::CheckedListBox());
			this->lblPath = (gcnew System::Windows::Forms::Label());
			this->lblPathDescription = (gcnew System::Windows::Forms::Label());
			this->lblSearchTitle = (gcnew System::Windows::Forms::Label());
			this->tabSearchResult = (gcnew System::Windows::Forms::TabPage());
			this->cmbEntryType = (gcnew System::Windows::Forms::ComboBox());
			this->btnClearTvSearch = (gcnew System::Windows::Forms::Button());
			this->lblSearchTreeview = (gcnew System::Windows::Forms::Label());
			this->txtSearchTreeview = (gcnew System::Windows::Forms::TextBox());
			this->btnSearchTreeview = (gcnew System::Windows::Forms::Button());
			this->lblDatabase = (gcnew System::Windows::Forms::Label());
			this->lblSelectedFolder = (gcnew System::Windows::Forms::Label());
			this->lblSelectedDatabase = (gcnew System::Windows::Forms::Label());
			this->lblTreeViewFolder = (gcnew System::Windows::Forms::Label());
			this->lblResultTitle = (gcnew System::Windows::Forms::Label());
			this->lblNoMatches = (gcnew System::Windows::Forms::Label());
			this->hpHelper = (gcnew System::Windows::Forms::HelpProvider());
			this->menuBar = (gcnew System::Windows::Forms::MenuStrip());
			this->tsmFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmNewSearch = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmCancelSearch = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmOptions = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmLanguage = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmEditSearchData = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmShowHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fbdDatabases = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->helpProvider1 = (gcnew System::Windows::Forms::HelpProvider());
			this->ctmTreeview->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvResults))->BeginInit();
			this->tabWindows->SuspendLayout();
			this->tabSearchSetup->SuspendLayout();
			this->panelDateTime->SuspendLayout();
			this->panelSearchTypes->SuspendLayout();
			this->panelDatabaseSelection->SuspendLayout();
			this->tabSearchResult->SuspendLayout();
			this->menuBar->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnStartSearch
			// 
			this->btnStartSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnStartSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStartSearch->Location = System::Drawing::Point(1055, 524);
			this->btnStartSearch->Name = L"btnStartSearch";
			this->btnStartSearch->Size = System::Drawing::Size(208, 31);
			this->btnStartSearch->TabIndex = 18;
			this->btnStartSearch->Text = L"start_seach";
			this->btnStartSearch->UseVisualStyleBackColor = true;
			this->btnStartSearch->Click += gcnew System::EventHandler(this, &frmMain::btnStartSearch_Click);
			// 
			// dtpFromDate
			// 
			this->dtpFromDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dtpFromDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFromDate->Location = System::Drawing::Point(72, 28);
			this->dtpFromDate->Name = L"dtpFromDate";
			this->dtpFromDate->Size = System::Drawing::Size(155, 22);
			this->dtpFromDate->TabIndex = 0;
			// 
			// tvDatabases
			// 
			this->tvDatabases->ContextMenuStrip = this->ctmTreeview;
			this->tvDatabases->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tvDatabases->Location = System::Drawing::Point(8, 6);
			this->tvDatabases->Name = L"tvDatabases";
			this->tvDatabases->Size = System::Drawing::Size(735, 392);
			this->tvDatabases->TabIndex = 1;
			this->tvDatabases->NodeMouseClick += gcnew System::Windows::Forms::TreeNodeMouseClickEventHandler(this, &frmMain::tvDatabases_NodeMouseClick);
			// 
			// ctmTreeview
			// 
			this->ctmTreeview->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->tsmExpandClose,
					this->tsmOpenFolder
			});
			this->ctmTreeview->Name = L"ctmTreeview";
			this->ctmTreeview->Size = System::Drawing::Size(162, 48);
			this->ctmTreeview->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &frmMain::ctmTreeview_Opening);
			// 
			// tsmExpandClose
			// 
			this->tsmExpandClose->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->tsmExpandAll,
					this->tsmCloseAll, this->tsmExpandSelected, this->tsmCloseSelected
			});
			this->tsmExpandClose->Name = L"tsmExpandClose";
			this->tsmExpandClose->Size = System::Drawing::Size(161, 22);
			this->tsmExpandClose->Text = L"tsmExpandClose";
			// 
			// tsmExpandAll
			// 
			this->tsmExpandAll->Name = L"tsmExpandAll";
			this->tsmExpandAll->Size = System::Drawing::Size(176, 22);
			this->tsmExpandAll->Text = L"tsmExpandAll";
			this->tsmExpandAll->Click += gcnew System::EventHandler(this, &frmMain::tsmExpandAll_Click);
			// 
			// tsmCloseAll
			// 
			this->tsmCloseAll->Name = L"tsmCloseAll";
			this->tsmCloseAll->Size = System::Drawing::Size(176, 22);
			this->tsmCloseAll->Text = L"tsmCloseAll";
			this->tsmCloseAll->Click += gcnew System::EventHandler(this, &frmMain::tsmCloseAll_Click);
			// 
			// tsmExpandSelected
			// 
			this->tsmExpandSelected->Name = L"tsmExpandSelected";
			this->tsmExpandSelected->Size = System::Drawing::Size(176, 22);
			this->tsmExpandSelected->Text = L"tsmExpandSelected";
			this->tsmExpandSelected->Click += gcnew System::EventHandler(this, &frmMain::tsmExpandSelected_Click);
			// 
			// tsmCloseSelected
			// 
			this->tsmCloseSelected->Name = L"tsmCloseSelected";
			this->tsmCloseSelected->Size = System::Drawing::Size(176, 22);
			this->tsmCloseSelected->Text = L"tsmCloseSelected";
			this->tsmCloseSelected->Click += gcnew System::EventHandler(this, &frmMain::tsmCloseSelected_Click);
			// 
			// tsmOpenFolder
			// 
			this->tsmOpenFolder->Name = L"tsmOpenFolder";
			this->tsmOpenFolder->Size = System::Drawing::Size(161, 22);
			this->tsmOpenFolder->Text = L"tsmOpenFolder";
			this->tsmOpenFolder->Click += gcnew System::EventHandler(this, &frmMain::tsmOpenFolder_Click);
			// 
			// btnReset
			// 
			this->btnReset->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnReset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnReset->Location = System::Drawing::Point(1055, 598);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(208, 31);
			this->btnReset->TabIndex = 20;
			this->btnReset->Text = L"reset_parameters";
			this->btnReset->UseVisualStyleBackColor = true;
			this->btnReset->Click += gcnew System::EventHandler(this, &frmMain::btnReset_Click);
			// 
			// lstInformation
			// 
			this->lstInformation->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstInformation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lstInformation->FormattingEnabled = true;
			this->lstInformation->HorizontalScrollbar = true;
			this->lstInformation->ItemHeight = 16;
			this->lstInformation->Location = System::Drawing::Point(6, 524);
			this->lstInformation->Name = L"lstInformation";
			this->lstInformation->Size = System::Drawing::Size(1043, 148);
			this->lstInformation->TabIndex = 17;
			this->lstInformation->TabStop = false;
			// 
			// btnBrowse
			// 
			this->btnBrowse->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnBrowse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBrowse->Location = System::Drawing::Point(1167, 42);
			this->btnBrowse->Name = L"btnBrowse";
			this->btnBrowse->Size = System::Drawing::Size(96, 28);
			this->btnBrowse->TabIndex = 3;
			this->btnBrowse->Text = L"browse";
			this->btnBrowse->UseVisualStyleBackColor = true;
			this->btnBrowse->Click += gcnew System::EventHandler(this, &frmMain::btnBrowse_Click);
			// 
			// rTxtAdditional
			// 
			this->rTxtAdditional->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->rTxtAdditional->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rTxtAdditional->Location = System::Drawing::Point(734, 221);
			this->rTxtAdditional->Name = L"rTxtAdditional";
			this->rTxtAdditional->Size = System::Drawing::Size(315, 297);
			this->rTxtAdditional->TabIndex = 16;
			this->rTxtAdditional->Text = L"";
			// 
			// pbProgress
			// 
			this->pbProgress->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->pbProgress->Location = System::Drawing::Point(1123, 646);
			this->pbProgress->Name = L"pbProgress";
			this->pbProgress->Size = System::Drawing::Size(140, 23);
			this->pbProgress->TabIndex = 22;
			// 
			// dgvResults
			// 
			this->dgvResults->AllowUserToAddRows = false;
			this->dgvResults->AllowUserToDeleteRows = false;
			this->dgvResults->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgvResults->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvResults->ContextMenuStrip = this->ctmDatagridview;
			this->dgvResults->Location = System::Drawing::Point(8, 396);
			this->dgvResults->Name = L"dgvResults";
			this->dgvResults->ReadOnly = true;
			this->dgvResults->Size = System::Drawing::Size(1262, 280);
			this->dgvResults->TabIndex = 15;
			// 
			// ctmDatagridview
			// 
			this->ctmDatagridview->Name = L"ctmTreeview";
			this->ctmDatagridview->Size = System::Drawing::Size(61, 4);
			// 
			// lblDbSelect
			// 
			this->lblDbSelect->AutoSize = true;
			this->lblDbSelect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDbSelect->Location = System::Drawing::Point(3, 3);
			this->lblDbSelect->Name = L"lblDbSelect";
			this->lblDbSelect->Size = System::Drawing::Size(127, 16);
			this->lblDbSelect->TabIndex = 4;
			this->lblDbSelect->Text = L"database_selection";
			// 
			// lblProgress
			// 
			this->lblProgress->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->lblProgress->AutoSize = true;
			this->lblProgress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblProgress->Location = System::Drawing::Point(1055, 649);
			this->lblProgress->Name = L"lblProgress";
			this->lblProgress->Size = System::Drawing::Size(62, 16);
			this->lblProgress->TabIndex = 21;
			this->lblProgress->Text = L"progress";
			// 
			// lblFromDate
			// 
			this->lblFromDate->AutoSize = true;
			this->lblFromDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFromDate->Location = System::Drawing::Point(32, 33);
			this->lblFromDate->Name = L"lblFromDate";
			this->lblFromDate->Size = System::Drawing::Size(34, 16);
			this->lblFromDate->TabIndex = 11;
			this->lblFromDate->Text = L"from";
			// 
			// bwDataRetrieval
			// 
			this->bwDataRetrieval->WorkerReportsProgress = true;
			this->bwDataRetrieval->WorkerSupportsCancellation = true;
			this->bwDataRetrieval->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &frmMain::bwDataRetrieval_DoWork);
			this->bwDataRetrieval->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &frmMain::bwDataRetrieval_ProgressChanged);
			this->bwDataRetrieval->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &frmMain::bwDataRetrieval_RunWorkerCompleted);
			// 
			// tabWindows
			// 
			this->tabWindows->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabWindows->Controls->Add(this->tabSearchSetup);
			this->tabWindows->Controls->Add(this->tabSearchResult);
			this->tabWindows->Location = System::Drawing::Point(0, 24);
			this->tabWindows->Name = L"tabWindows";
			this->tabWindows->SelectedIndex = 0;
			this->tabWindows->Size = System::Drawing::Size(1284, 705);
			this->tabWindows->TabIndex = 1;
			// 
			// tabSearchSetup
			// 
			this->tabSearchSetup->Controls->Add(this->panelDateTime);
			this->tabSearchSetup->Controls->Add(this->panelSearchTypes);
			this->tabSearchSetup->Controls->Add(this->panelDatabaseSelection);
			this->tabSearchSetup->Controls->Add(this->chkLstSelectSearchTypes);
			this->tabSearchSetup->Controls->Add(this->btnCancel);
			this->tabSearchSetup->Controls->Add(this->chkLstDatabaseFolders);
			this->tabSearchSetup->Controls->Add(this->btnReset);
			this->tabSearchSetup->Controls->Add(this->lstInformation);
			this->tabSearchSetup->Controls->Add(this->lblPath);
			this->tabSearchSetup->Controls->Add(this->lblPathDescription);
			this->tabSearchSetup->Controls->Add(this->btnBrowse);
			this->tabSearchSetup->Controls->Add(this->lblSearchTitle);
			this->tabSearchSetup->Controls->Add(this->pbProgress);
			this->tabSearchSetup->Controls->Add(this->lblProgress);
			this->tabSearchSetup->Controls->Add(this->btnStartSearch);
			this->tabSearchSetup->Controls->Add(this->rTxtAdditional);
			this->tabSearchSetup->Location = System::Drawing::Point(4, 22);
			this->tabSearchSetup->Name = L"tabSearchSetup";
			this->tabSearchSetup->Padding = System::Windows::Forms::Padding(3);
			this->tabSearchSetup->Size = System::Drawing::Size(1276, 679);
			this->tabSearchSetup->TabIndex = 0;
			this->tabSearchSetup->Text = L"tabSearchSetup";
			this->tabSearchSetup->UseVisualStyleBackColor = true;
			// 
			// panelDateTime
			// 
			this->panelDateTime->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelDateTime->Controls->Add(this->dtpFromDate);
			this->panelDateTime->Controls->Add(this->lblAdditionalHelpText);
			this->panelDateTime->Controls->Add(this->dtpToDate);
			this->panelDateTime->Controls->Add(this->chkIncludeTimeLine);
			this->panelDateTime->Controls->Add(this->lblToDate);
			this->panelDateTime->Controls->Add(this->dtpToTime);
			this->panelDateTime->Controls->Add(this->lblFromDate);
			this->panelDateTime->Controls->Add(this->chkIncludeAdditionalStrings);
			this->panelDateTime->Controls->Add(this->dtpFromTime);
			this->panelDateTime->Location = System::Drawing::Point(734, 84);
			this->panelDateTime->Name = L"panelDateTime";
			this->panelDateTime->Size = System::Drawing::Size(315, 131);
			this->panelDateTime->TabIndex = 13;
			// 
			// lblAdditionalHelpText
			// 
			this->lblAdditionalHelpText->AutoSize = true;
			this->lblAdditionalHelpText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblAdditionalHelpText->Location = System::Drawing::Point(24, 108);
			this->lblAdditionalHelpText->Name = L"lblAdditionalHelpText";
			this->lblAdditionalHelpText->Size = System::Drawing::Size(120, 16);
			this->lblAdditionalHelpText->TabIndex = 15;
			this->lblAdditionalHelpText->Text = L"seperation:newline";
			// 
			// dtpToDate
			// 
			this->dtpToDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dtpToDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpToDate->Location = System::Drawing::Point(72, 56);
			this->dtpToDate->Name = L"dtpToDate";
			this->dtpToDate->Size = System::Drawing::Size(155, 22);
			this->dtpToDate->TabIndex = 2;
			// 
			// chkIncludeTimeLine
			// 
			this->chkIncludeTimeLine->AutoSize = true;
			this->chkIncludeTimeLine->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->chkIncludeTimeLine->Location = System::Drawing::Point(3, 3);
			this->chkIncludeTimeLine->Name = L"chkIncludeTimeLine";
			this->chkIncludeTimeLine->Size = System::Drawing::Size(123, 20);
			this->chkIncludeTimeLine->TabIndex = 10;
			this->chkIncludeTimeLine->Text = L"include_timeline";
			this->chkIncludeTimeLine->UseVisualStyleBackColor = true;
			this->chkIncludeTimeLine->CheckedChanged += gcnew System::EventHandler(this, &frmMain::chkIncludeTimeLine_CheckedChanged);
			// 
			// lblToDate
			// 
			this->lblToDate->AutoSize = true;
			this->lblToDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblToDate->Location = System::Drawing::Point(32, 61);
			this->lblToDate->Name = L"lblToDate";
			this->lblToDate->Size = System::Drawing::Size(19, 16);
			this->lblToDate->TabIndex = 12;
			this->lblToDate->Text = L"to";
			// 
			// dtpToTime
			// 
			this->dtpToTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dtpToTime->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->dtpToTime->Location = System::Drawing::Point(233, 56);
			this->dtpToTime->Name = L"dtpToTime";
			this->dtpToTime->ShowUpDown = true;
			this->dtpToTime->Size = System::Drawing::Size(79, 22);
			this->dtpToTime->TabIndex = 3;
			// 
			// chkIncludeAdditionalStrings
			// 
			this->chkIncludeAdditionalStrings->AutoSize = true;
			this->chkIncludeAdditionalStrings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->chkIncludeAdditionalStrings->Location = System::Drawing::Point(3, 85);
			this->chkIncludeAdditionalStrings->Name = L"chkIncludeAdditionalStrings";
			this->chkIncludeAdditionalStrings->Size = System::Drawing::Size(223, 20);
			this->chkIncludeAdditionalStrings->TabIndex = 14;
			this->chkIncludeAdditionalStrings->Text = L"include_additional_search_string";
			this->chkIncludeAdditionalStrings->UseVisualStyleBackColor = true;
			this->chkIncludeAdditionalStrings->CheckedChanged += gcnew System::EventHandler(this, &frmMain::chkIncludeAdditionalStrings_CheckedChanged);
			// 
			// dtpFromTime
			// 
			this->dtpFromTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dtpFromTime->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->dtpFromTime->Location = System::Drawing::Point(233, 28);
			this->dtpFromTime->Name = L"dtpFromTime";
			this->dtpFromTime->ShowUpDown = true;
			this->dtpFromTime->Size = System::Drawing::Size(79, 22);
			this->dtpFromTime->TabIndex = 1;
			// 
			// panelSearchTypes
			// 
			this->panelSearchTypes->Controls->Add(this->rbAllSearchTypes);
			this->panelSearchTypes->Controls->Add(this->rbSpecificSearchType);
			this->panelSearchTypes->Controls->Add(this->lblSelectSearchTypes);
			this->panelSearchTypes->Location = System::Drawing::Point(490, 84);
			this->panelSearchTypes->Name = L"panelSearchTypes";
			this->panelSearchTypes->Size = System::Drawing::Size(238, 79);
			this->panelSearchTypes->TabIndex = 8;
			// 
			// rbAllSearchTypes
			// 
			this->rbAllSearchTypes->AutoSize = true;
			this->rbAllSearchTypes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->rbAllSearchTypes->Location = System::Drawing::Point(3, 28);
			this->rbAllSearchTypes->Name = L"rbAllSearchTypes";
			this->rbAllSearchTypes->Size = System::Drawing::Size(128, 20);
			this->rbAllSearchTypes->TabIndex = 0;
			this->rbAllSearchTypes->TabStop = true;
			this->rbAllSearchTypes->Text = L"all_search_types";
			this->rbAllSearchTypes->UseVisualStyleBackColor = true;
			this->rbAllSearchTypes->CheckedChanged += gcnew System::EventHandler(this, &frmMain::rbAllSearchTypes_CheckedChanged);
			// 
			// rbSpecificSearchType
			// 
			this->rbSpecificSearchType->AutoSize = true;
			this->rbSpecificSearchType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->rbSpecificSearchType->Location = System::Drawing::Point(3, 54);
			this->rbSpecificSearchType->Name = L"rbSpecificSearchType";
			this->rbSpecificSearchType->Size = System::Drawing::Size(160, 20);
			this->rbSpecificSearchType->TabIndex = 1;
			this->rbSpecificSearchType->TabStop = true;
			this->rbSpecificSearchType->Text = L"specific_search_types";
			this->rbSpecificSearchType->UseVisualStyleBackColor = true;
			// 
			// lblSelectSearchTypes
			// 
			this->lblSelectSearchTypes->AutoSize = true;
			this->lblSelectSearchTypes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblSelectSearchTypes->Location = System::Drawing::Point(3, 3);
			this->lblSelectSearchTypes->Name = L"lblSelectSearchTypes";
			this->lblSelectSearchTypes->Size = System::Drawing::Size(132, 16);
			this->lblSelectSearchTypes->TabIndex = 7;
			this->lblSelectSearchTypes->Text = L"include_search_type";
			// 
			// panelDatabaseSelection
			// 
			this->panelDatabaseSelection->Controls->Add(this->chkSelectAllFolders);
			this->panelDatabaseSelection->Controls->Add(this->rbAllDatabases);
			this->panelDatabaseSelection->Controls->Add(this->rbSpecificDatabases);
			this->panelDatabaseSelection->Controls->Add(this->lblDbSelect);
			this->panelDatabaseSelection->Location = System::Drawing::Point(6, 84);
			this->panelDatabaseSelection->Name = L"panelDatabaseSelection";
			this->panelDatabaseSelection->Size = System::Drawing::Size(473, 79);
			this->panelDatabaseSelection->TabIndex = 5;
			// 
			// chkSelectAllFolders
			// 
			this->chkSelectAllFolders->AutoSize = true;
			this->chkSelectAllFolders->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->chkSelectAllFolders->Location = System::Drawing::Point(300, 54);
			this->chkSelectAllFolders->Name = L"chkSelectAllFolders";
			this->chkSelectAllFolders->Size = System::Drawing::Size(132, 20);
			this->chkSelectAllFolders->TabIndex = 2;
			this->chkSelectAllFolders->Text = L"select_all_folders";
			this->chkSelectAllFolders->UseVisualStyleBackColor = true;
			this->chkSelectAllFolders->CheckedChanged += gcnew System::EventHandler(this, &frmMain::chkSelectAllFolders_CheckedChanged);
			// 
			// rbAllDatabases
			// 
			this->rbAllDatabases->AutoSize = true;
			this->rbAllDatabases->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rbAllDatabases->Location = System::Drawing::Point(3, 28);
			this->rbAllDatabases->Name = L"rbAllDatabases";
			this->rbAllDatabases->Size = System::Drawing::Size(187, 20);
			this->rbAllDatabases->TabIndex = 0;
			this->rbAllDatabases->TabStop = true;
			this->rbAllDatabases->Text = L"select_db_from_all_folders";
			this->rbAllDatabases->UseVisualStyleBackColor = true;
			this->rbAllDatabases->Click += gcnew System::EventHandler(this, &frmMain::rbAllDatabases_Click);
			// 
			// rbSpecificDatabases
			// 
			this->rbSpecificDatabases->AutoSize = true;
			this->rbSpecificDatabases->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->rbSpecificDatabases->Location = System::Drawing::Point(3, 54);
			this->rbSpecificDatabases->Name = L"rbSpecificDatabases";
			this->rbSpecificDatabases->Size = System::Drawing::Size(215, 20);
			this->rbSpecificDatabases->TabIndex = 1;
			this->rbSpecificDatabases->TabStop = true;
			this->rbSpecificDatabases->Text = L"select_specific_db_from folders";
			this->rbSpecificDatabases->UseVisualStyleBackColor = true;
			// 
			// chkLstSelectSearchTypes
			// 
			this->chkLstSelectSearchTypes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->chkLstSelectSearchTypes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->chkLstSelectSearchTypes->FormattingEnabled = true;
			this->chkLstSelectSearchTypes->HorizontalScrollbar = true;
			this->chkLstSelectSearchTypes->Location = System::Drawing::Point(490, 169);
			this->chkLstSelectSearchTypes->Name = L"chkLstSelectSearchTypes";
			this->chkLstSelectSearchTypes->Size = System::Drawing::Size(238, 349);
			this->chkLstSelectSearchTypes->TabIndex = 9;
			// 
			// btnCancel
			// 
			this->btnCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Location = System::Drawing::Point(1055, 561);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(208, 31);
			this->btnCancel->TabIndex = 19;
			this->btnCancel->Text = L"cancel_seach";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmMain::btnCancel_Click);
			// 
			// chkLstDatabaseFolders
			// 
			this->chkLstDatabaseFolders->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->chkLstDatabaseFolders->FormattingEnabled = true;
			this->chkLstDatabaseFolders->HorizontalScrollbar = true;
			this->chkLstDatabaseFolders->Location = System::Drawing::Point(8, 169);
			this->chkLstDatabaseFolders->Name = L"chkLstDatabaseFolders";
			this->chkLstDatabaseFolders->Size = System::Drawing::Size(476, 349);
			this->chkLstDatabaseFolders->TabIndex = 6;
			// 
			// lblPath
			// 
			this->lblPath->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblPath->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblPath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPath->Location = System::Drawing::Point(55, 45);
			this->lblPath->Name = L"lblPath";
			this->lblPath->Size = System::Drawing::Size(1106, 23);
			this->lblPath->TabIndex = 2;
			this->lblPath->Text = L"path_to_database_folder";
			this->lblPath->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lblPathDescription
			// 
			this->lblPathDescription->AutoSize = true;
			this->lblPathDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPathDescription->Location = System::Drawing::Point(8, 48);
			this->lblPathDescription->Name = L"lblPathDescription";
			this->lblPathDescription->Size = System::Drawing::Size(36, 17);
			this->lblPathDescription->TabIndex = 1;
			this->lblPathDescription->Text = L"path";
			// 
			// lblSearchTitle
			// 
			this->lblSearchTitle->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lblSearchTitle->AutoSize = true;
			this->lblSearchTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSearchTitle->Location = System::Drawing::Point(505, 3);
			this->lblSearchTitle->Name = L"lblSearchTitle";
			this->lblSearchTitle->Size = System::Drawing::Size(165, 24);
			this->lblSearchTitle->TabIndex = 0;
			this->lblSearchTitle->Text = L"settings_for_seach";
			// 
			// tabSearchResult
			// 
			this->tabSearchResult->Controls->Add(this->cmbEntryType);
			this->tabSearchResult->Controls->Add(this->btnClearTvSearch);
			this->tabSearchResult->Controls->Add(this->lblSearchTreeview);
			this->tabSearchResult->Controls->Add(this->txtSearchTreeview);
			this->tabSearchResult->Controls->Add(this->btnSearchTreeview);
			this->tabSearchResult->Controls->Add(this->lblDatabase);
			this->tabSearchResult->Controls->Add(this->lblSelectedFolder);
			this->tabSearchResult->Controls->Add(this->lblSelectedDatabase);
			this->tabSearchResult->Controls->Add(this->lblTreeViewFolder);
			this->tabSearchResult->Controls->Add(this->lblResultTitle);
			this->tabSearchResult->Controls->Add(this->lblNoMatches);
			this->tabSearchResult->Controls->Add(this->dgvResults);
			this->tabSearchResult->Controls->Add(this->tvDatabases);
			this->tabSearchResult->Location = System::Drawing::Point(4, 22);
			this->tabSearchResult->Name = L"tabSearchResult";
			this->tabSearchResult->Padding = System::Windows::Forms::Padding(3);
			this->tabSearchResult->Size = System::Drawing::Size(1276, 679);
			this->tabSearchResult->TabIndex = 1;
			this->tabSearchResult->Text = L"tabSearchResult";
			this->tabSearchResult->UseVisualStyleBackColor = true;
			// 
			// cmbEntryType
			// 
			this->cmbEntryType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbEntryType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbEntryType->FormattingEnabled = true;
			this->cmbEntryType->Location = System::Drawing::Point(752, 185);
			this->cmbEntryType->Name = L"cmbEntryType";
			this->cmbEntryType->Size = System::Drawing::Size(195, 24);
			this->cmbEntryType->TabIndex = 16;
			// 
			// btnClearTvSearch
			// 
			this->btnClearTvSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnClearTvSearch->Location = System::Drawing::Point(752, 277);
			this->btnClearTvSearch->Name = L"btnClearTvSearch";
			this->btnClearTvSearch->Size = System::Drawing::Size(195, 28);
			this->btnClearTvSearch->TabIndex = 6;
			this->btnClearTvSearch->Text = L"clear_tv_search";
			this->btnClearTvSearch->UseVisualStyleBackColor = true;
			this->btnClearTvSearch->Click += gcnew System::EventHandler(this, &frmMain::btnClearTvSearch_Click);
			// 
			// lblSearchTreeview
			// 
			this->lblSearchTreeview->AutoSize = true;
			this->lblSearchTreeview->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblSearchTreeview->Location = System::Drawing::Point(749, 166);
			this->lblSearchTreeview->Name = L"lblSearchTreeview";
			this->lblSearchTreeview->Size = System::Drawing::Size(175, 16);
			this->lblSearchTreeview->TabIndex = 3;
			this->lblSearchTreeview->Text = L"search_treeview_for_entries";
			// 
			// txtSearchTreeview
			// 
			this->txtSearchTreeview->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->txtSearchTreeview->Location = System::Drawing::Point(752, 215);
			this->txtSearchTreeview->Name = L"txtSearchTreeview";
			this->txtSearchTreeview->Size = System::Drawing::Size(195, 22);
			this->txtSearchTreeview->TabIndex = 4;
			// 
			// btnSearchTreeview
			// 
			this->btnSearchTreeview->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnSearchTreeview->Location = System::Drawing::Point(752, 243);
			this->btnSearchTreeview->Name = L"btnSearchTreeview";
			this->btnSearchTreeview->Size = System::Drawing::Size(195, 28);
			this->btnSearchTreeview->TabIndex = 5;
			this->btnSearchTreeview->Text = L"search_tv";
			this->btnSearchTreeview->UseVisualStyleBackColor = true;
			this->btnSearchTreeview->Click += gcnew System::EventHandler(this, &frmMain::btnSearchTreeview_Click);
			// 
			// lblDatabase
			// 
			this->lblDatabase->AutoSize = true;
			this->lblDatabase->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblDatabase->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDatabase->Location = System::Drawing::Point(885, 328);
			this->lblDatabase->Name = L"lblDatabase";
			this->lblDatabase->Size = System::Drawing::Size(67, 18);
			this->lblDatabase->TabIndex = 12;
			this->lblDatabase->Text = L"db_name";
			// 
			// lblSelectedFolder
			// 
			this->lblSelectedFolder->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblSelectedFolder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblSelectedFolder->Location = System::Drawing::Point(885, 357);
			this->lblSelectedFolder->Name = L"lblSelectedFolder";
			this->lblSelectedFolder->Size = System::Drawing::Size(383, 18);
			this->lblSelectedFolder->TabIndex = 14;
			this->lblSelectedFolder->Text = L"selecteded_tv_folder_path_displayed_here";
			// 
			// lblSelectedDatabase
			// 
			this->lblSelectedDatabase->AutoSize = true;
			this->lblSelectedDatabase->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblSelectedDatabase->Location = System::Drawing::Point(749, 328);
			this->lblSelectedDatabase->Name = L"lblSelectedDatabase";
			this->lblSelectedDatabase->Size = System::Drawing::Size(125, 16);
			this->lblSelectedDatabase->TabIndex = 11;
			this->lblSelectedDatabase->Text = L"selected_database";
			// 
			// lblTreeViewFolder
			// 
			this->lblTreeViewFolder->AutoSize = true;
			this->lblTreeViewFolder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblTreeViewFolder->Location = System::Drawing::Point(749, 357);
			this->lblTreeViewFolder->Name = L"lblTreeViewFolder";
			this->lblTreeViewFolder->Size = System::Drawing::Size(118, 16);
			this->lblTreeViewFolder->TabIndex = 13;
			this->lblTreeViewFolder->Text = L"selected_tv_folder";
			// 
			// lblResultTitle
			// 
			this->lblResultTitle->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lblResultTitle->AutoSize = true;
			this->lblResultTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblResultTitle->Location = System::Drawing::Point(748, 6);
			this->lblResultTitle->Name = L"lblResultTitle";
			this->lblResultTitle->Size = System::Drawing::Size(116, 24);
			this->lblResultTitle->TabIndex = 2;
			this->lblResultTitle->Text = L"seach_result";
			// 
			// lblNoMatches
			// 
			this->lblNoMatches->AutoSize = true;
			this->lblNoMatches->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNoMatches->ForeColor = System::Drawing::Color::Red;
			this->lblNoMatches->Location = System::Drawing::Point(18, 13);
			this->lblNoMatches->Name = L"lblNoMatches";
			this->lblNoMatches->Size = System::Drawing::Size(139, 17);
			this->lblNoMatches->TabIndex = 0;
			this->lblNoMatches->Text = L"no_results_message";
			this->lblNoMatches->Visible = false;
			// 
			// menuBar
			// 
			this->menuBar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->tsmFile, this->tsmOptions,
					this->tsmHelp
			});
			this->menuBar->Location = System::Drawing::Point(0, 0);
			this->menuBar->Name = L"menuBar";
			this->menuBar->Size = System::Drawing::Size(1284, 24);
			this->menuBar->TabIndex = 0;
			this->menuBar->Text = L"menuStrip1";
			// 
			// tsmFile
			// 
			this->tsmFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->tsmNewSearch,
					this->tsmCancelSearch, this->tsmExit
			});
			this->tsmFile->Name = L"tsmFile";
			this->tsmFile->Size = System::Drawing::Size(40, 20);
			this->tsmFile->Text = L"file_";
			// 
			// tsmNewSearch
			// 
			this->tsmNewSearch->Name = L"tsmNewSearch";
			this->tsmNewSearch->Size = System::Drawing::Size(147, 22);
			this->tsmNewSearch->Text = L"new_search";
			this->tsmNewSearch->Click += gcnew System::EventHandler(this, &frmMain::tsmNewSearch_Click);
			// 
			// tsmCancelSearch
			// 
			this->tsmCancelSearch->Name = L"tsmCancelSearch";
			this->tsmCancelSearch->Size = System::Drawing::Size(147, 22);
			this->tsmCancelSearch->Text = L"cancel_search";
			this->tsmCancelSearch->Click += gcnew System::EventHandler(this, &frmMain::tsmCancelSearch_Click);
			// 
			// tsmExit
			// 
			this->tsmExit->Name = L"tsmExit";
			this->tsmExit->Size = System::Drawing::Size(147, 22);
			this->tsmExit->Text = L"exit";
			this->tsmExit->Click += gcnew System::EventHandler(this, &frmMain::tsmExit_Click);
			// 
			// tsmOptions
			// 
			this->tsmOptions->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->tsmLanguage,
					this->tsmEditSearchData
			});
			this->tsmOptions->Name = L"tsmOptions";
			this->tsmOptions->Size = System::Drawing::Size(59, 20);
			this->tsmOptions->Text = L"options";
			// 
			// tsmLanguage
			// 
			this->tsmLanguage->Name = L"tsmLanguage";
			this->tsmLanguage->Size = System::Drawing::Size(166, 22);
			this->tsmLanguage->Text = L"language";
			// 
			// tsmEditSearchData
			// 
			this->tsmEditSearchData->Name = L"tsmEditSearchData";
			this->tsmEditSearchData->Size = System::Drawing::Size(166, 22);
			this->tsmEditSearchData->Text = L"edit_search_types";
			this->tsmEditSearchData->Click += gcnew System::EventHandler(this, &frmMain::tsmEditSearchData_Click);
			// 
			// tsmHelp
			// 
			this->tsmHelp->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {
				this->tsmShowHelp
			});
			this->tsmHelp->Name = L"tsmHelp";
			this->tsmHelp->Size = System::Drawing::Size(42, 20);
			this->tsmHelp->Text = L"help";
			// 
			// tsmShowHelp
			// 
			this->tsmShowHelp->Name = L"tsmShowHelp";
			this->tsmShowHelp->Size = System::Drawing::Size(130, 22);
			this->tsmShowHelp->Text = L"show_help";
			this->tsmShowHelp->Click += gcnew System::EventHandler(this, &frmMain::tsmShowHelp_Click);
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::MenuBar;
			this->ClientSize = System::Drawing::Size(1284, 730);
			this->Controls->Add(this->tabWindows);
			this->Controls->Add(this->menuBar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->hpHelper->SetHelpNavigator(this, System::Windows::Forms::HelpNavigator::TableOfContents);
			this->MainMenuStrip = this->menuBar;
			this->Name = L"frmMain";
			this->hpHelper->SetShowHelp(this, true);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"program_name";
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->ctmTreeview->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvResults))->EndInit();
			this->tabWindows->ResumeLayout(false);
			this->tabSearchSetup->ResumeLayout(false);
			this->tabSearchSetup->PerformLayout();
			this->panelDateTime->ResumeLayout(false);
			this->panelDateTime->PerformLayout();
			this->panelSearchTypes->ResumeLayout(false);
			this->panelSearchTypes->PerformLayout();
			this->panelDatabaseSelection->ResumeLayout(false);
			this->panelDatabaseSelection->PerformLayout();
			this->tabSearchResult->ResumeLayout(false);
			this->tabSearchResult->PerformLayout();
			this->menuBar->ResumeLayout(false);
			this->menuBar->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		} //InitializeComponent
#pragma endregion

		//function headers - functions are located in frmMain.cpp
	private:
		/*
		set the name of the path to the folder containing
		subfolders with databases
		*/
		void setFolderPath();
		//get the names of the folders that may contain SQLite databases
		List<String ^> ^loadFolders(String ^path);
		void removePreviousSearchData();
		//start searching for evidence if pre-requisites are ok
		void startSearch();
		//cancel running search
		void cancelSearch();
		//if a selection is chosen, check that at least one element is chosen
		bool isSpecifiedSelectionOK();
		//get the name of the databases located in selected folders
		bool loadDatabasesFromFolders();
		//get the search, - file types and extensions from files
		void loadFiletypesFromFiles();
		//fill up treeview and datagridview with the search results
		void fillUpViews(BackgroundWorker ^worker, DoWorkEventArgs ^e);
		//add new node to treeview
		void addNewNode(BackgroundWorker ^worker, String ^nodeName,
			TreeNode ^root, int index, const float total);
		//fill the treeview with folders and database names
		void fillTreeView(BackgroundWorker ^worker, TreeNode ^newNode,
			int index, const float total);
		//add information to listbox (use if invoke is needed)
		void addItemInformation(String ^information);
		//delegate for adding information to listbox
		delegate void invokeAddItemInformation(String ^information);
		//delegate for filling datagridview with results
		delegate void invokeDatagridviewFilling(int folderIndex, int dbIndex, int tableIndex);
		//fill datagridview with results 
		void fillDatagridviewWithResults(int folderIndex, int dbIndex, int tableIndex);
		//backgroundworker completed the search, show results
		void searchCompleted();
		//search through entries in treeview and highlight matches
		void searchAndHighlightTreeviewEntries(String ^search);
		//highlight all matching entries only
		void searchThroughAllTreeviewEntries(String ^searchText);
		//highlight matching folders only
		void searchThroughTreeviewFolderEntries(String ^searchText);
		//highlight matching databases only
		void searchThroughTreeviewDatabaseEntries(String ^searchText);
		//highlight matching tables only
		void searchThroughTreeviewTableEntries(String ^searchText);
		//remove highlights from all entries
		void clearHighlightedEntries();


		//global variables
	private:
		//root of the treeview
		TreeNode ^root;
		//fuzzy search object containing search results
		FuzzySearch ^fuzzyObj;
		/*
		List containing the folder path to selected
		folders that contain databases
		*/
		List<String ^> ^pathToDatabaseList;
		//List containing additional search strings
		List<String ^> ^additionalStringsList;
		//List containing the selected search types
		List<String ^> ^selectedSearchTypesList;
		/*
		List containing the database files (name + extension)
		index1: path index (pathToDatabaseList)
		index2: database file (e.g. "database.db")
		*/
		List<List<String ^> ^> ^databaseFileList;
		//default path text displayed in label
		static String ^DEFAULT_PATH_TEXT = "Select the path to the parent folder of the SQLite databases...";

	private: System::Void frmMain_Load(System::Object^  sender, System::EventArgs^  e) {
		this->tsmLanguage->Click += gcnew System::EventHandler(this, &frmMain::ChangeLanguage_Click);
		setDefaultTextMenuStrip();
		setDefaultTextRightClick();
		this->Text = "CompFor2014 - Android/SQLite Forensics";
		loadHelpFile();
		loadSearchTypes();
		setDateTimeFormat();
		InitializeControls();
		//fill combobox with values (used for searching through results)
		this->cmbEntryType->Items->AddRange(gcnew array < String ^ > {
			"All",
				"Folders",
				"Databases",
				"Tables"
		});
		this->cmbEntryType->SelectedIndex = 0;
	} //frmMain_Load

	private: void ChangeLanguage_Click(Object^ sender, EventArgs^ e) {
		ToolStripItem^ item = (ToolStripItem^)sender;
		System::String^ language = item->Text;
		String ^notImplemented = "Changing language is currently not supported!";
		this->lstInformation->Items->Add(notImplemented);
		//...do something to change to selected language...
		//not implemented due to time and not being priority
	} //ChangeLanguage_Click

			 /*
			 Loads the helpfile used when pressing F1
			 or using the menustrip option for Help
			 */
	private: void loadHelpFile() {
		try {
			//get the helpfile and set namespace
			String ^helpFile = "CompFor2014.chm";
			this->hpHelper->HelpNamespace = helpFile;
		} catch(ExceptionClass ^ex) {
			MessageBox::Show(ex->ToString(), "Error loading help",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		} //try/catch
	} //loadHelpFile

			 /*
			 Reads search types from file and adds them to the
			 checkedlistbox.
			 */
	private: void loadSearchTypes() {
		try {
			String ^filePath = "";
			filePath = FileOperations::returnFilePath(SharedFunctions::SEARCH_TYPES_FOLDER,
				SharedFunctions::SEARCH_TYPES_FILE);
			List<String ^> ^searchTypes = FileOperations::readStringFromFile(filePath);
			//fill checkedlistbox with the search types
			for each(String ^type in searchTypes) {
				this->chkLstSelectSearchTypes->Items->Add(type);
			} //foreach
		} catch(Exception ^) {
			//if the file is empty, an error is thrown
			//this error is catched and ignored
		} //try/catch
	} //loadSearchTypes

	private: void setDateTimeFormat() {
		String ^timeFormat = "HH:mm";
		String ^dateFormat = "dd.MMMM.yyyy";
		//set datetimepicker to show time only
		this->dtpFromTime->ShowUpDown = true;
		this->dtpToTime->ShowUpDown = true;
		//set custom format
		this->dtpFromDate->Format = DateTimePickerFormat::Custom;
		this->dtpFromTime->Format = DateTimePickerFormat::Custom;
		this->dtpToDate->Format = DateTimePickerFormat::Custom;
		this->dtpToTime->Format = DateTimePickerFormat::Custom;
		//set format value
		this->dtpFromDate->CustomFormat = dateFormat;
		this->dtpFromTime->CustomFormat = timeFormat;
		this->dtpToDate->CustomFormat = dateFormat;
		this->dtpToTime->CustomFormat = timeFormat;
	} //setDateTimeFormat

#pragma region INITIALIZATION AND DEFAULT SETTINGS
			 /*
			 Initializes the controls on the WinForm.
			 Not to be confused with the default
			 InitializeComponent() function.
			 */
	private: void InitializeControls() {
		emptyListsAndTextBoxes();
		setDefaultTime();
		this->chkSelectAllFolders->Checked = false;
		this->rbAllDatabases->Checked = true;
		this->rbAllSearchTypes->Checked = true;
		this->chkIncludeTimeLine->Checked = false;
		this->chkIncludeAdditionalStrings->Checked = false;
		setDefaultTextTabSettings();
		setDefaultTextTabResults();
		setToolTipText();
		setEnabledAndHiddenControls(false);
		pathToDatabaseList = gcnew List<String ^>();
		additionalStringsList = gcnew List<String ^>();
		selectedSearchTypesList = gcnew List<String ^>();
	} //InitializeControls

	private: void setDefaultTime() {
		String ^startDay = "00:00";
		String ^endDay = "23:59";
		//set default time 
		this->dtpFromTime->Value = DateTime::Parse(startDay);
		this->dtpToTime->Value = DateTime::Parse(endDay);
	} //setDefaultTime

	private: void setDefaultTextMenuStrip() {
		//menustrip - file
		this->tsmFile->Text = "File";
		this->tsmNewSearch->Text = "New search";
		this->tsmCancelSearch->Text = "Cancel search";
		this->tsmExit->Text = "Exit";
		//menustrip - options
		this->tsmOptions->Text = "Options";
		this->tsmLanguage->Text = "Language";
		this->tsmEditSearchData->Text = "Edit search types";
		//menustrip - help
		this->tsmHelp->Text = "Help";
		this->tsmShowHelp->Text = "Show Help";
	} //setDefaultTextMenuStrip

	private: void setDefaultTextRightClick() {
		//righclick - treeview
		this->tsmExpandClose->Text = "Expand/Close";
		this->tsmExpandAll->Text = "Expand all";
		this->tsmCloseAll->Text = "Close all";
		this->tsmExpandSelected->Text = "Expand selected";
		this->tsmCloseSelected->Text = "Close selected";
		this->tsmOpenFolder->Text = "Open folder";
		//righclick - datagridview

	} //setDefaultTextMenuStrip

	private: void setDefaultTextTabSettings() {
		//tab
		this->tabSearchSetup->Text = "Search menu";
		//labels
		this->lblSearchTitle->Text = "Settings for search";
		this->lblPathDescription->Text = "Path:";
		this->lblPath->Text = DEFAULT_PATH_TEXT;
		this->lblDbSelect->Text = "Retrieve data from:";
		this->lblSelectSearchTypes->Text = "Select search types:";
		this->lblFromDate->Text = "From:";
		this->lblToDate->Text = "To: ";
		this->lblAdditionalHelpText->Text = "(seperate strings with newline)";
		this->lblProgress->Text = "Progress:";
		//checkboxes
		this->chkSelectAllFolders->Text = "Select all folders";
		this->chkIncludeTimeLine->Text = "Include timeline in search?";
		this->chkIncludeAdditionalStrings->Text = "Include additional search strings?";
		//buttons
		this->btnBrowse->Text = "Browse...";
		this->btnStartSearch->Text = "Start search";
		this->btnCancel->Text = "Cancel search";
		this->btnReset->Text = "Reset parameters";
		//radiobuttons
		this->rbAllDatabases->Text = "Select databases from all folders";
		this->rbSpecificDatabases->Text = "Selected databases from specific folders";
		this->rbAllSearchTypes->Text = "All search types";
		this->rbSpecificSearchType->Text = "Specific search types";
		//listbox
		this->lstInformation->Items->Add("If any errors occur, they will be displayed here.");
	} //setDefaultTextTabSettings

	private: void setDefaultTextTabResults() {
		//tab
		this->tabSearchResult->Text = "Search results";
		//buttons
		this->btnSearchTreeview->Text = "Search treeview";
		this->btnClearTvSearch->Text = "Clear marked entries";
		//labels
		this->lblResultTitle->Text = "Search result";
		this->lblSearchTreeview->Text = "Search treeview for entries:";
		this->lblTreeViewFolder->Text = "Selected folder:";
		this->lblSelectedFolder->Text = "N/A";
		this->lblSelectedDatabase->Text = "Selected database:";
		this->lblDatabase->Text = "N/A";
		this->lblNoMatches->Text = "No results matching search criteria.";
	} //setDefaultTextTabResults

	private: void setToolTipText() {
		this->tipLabel->ShowAlways = true;
		//buttons
		String ^tipText = "";
		tipText = "Look for the parent folder containing the databases (where the subfolders contain the database(s))";
		this->tipLabel->SetToolTip(this->btnBrowse, tipText);
		tipText = "Sets the search parameters back to default";
		this->tipLabel->SetToolTip(this->btnReset, tipText);
		tipText = "Search for entries within the treeview";
		this->tipLabel->SetToolTip(this->btnSearchTreeview, tipText);
		tipText = "Remove all marked entries in treeview";
		this->tipLabel->SetToolTip(this->btnClearTvSearch, tipText);
		//treeview
		tipText = "Lists the folders and databases containing hits based on search parameter";
		this->tipLabel->SetToolTip(this->tvDatabases, tipText);
		//listbox
		tipText = "Lists the folder containing the SQLite databases";
		this->tipLabel->SetToolTip(this->chkLstDatabaseFolders, tipText);
		tipText = "Displays information about search and potential errors";
		this->tipLabel->SetToolTip(this->lstInformation, tipText);
		//radiobuttons
		tipText = "Includes all searchtypes";
		this->tipLabel->SetToolTip(this->rbAllSearchTypes, tipText);
		tipText = "Include selected searchtypes only";
		this->tipLabel->SetToolTip(this->rbSpecificSearchType, tipText);
		//textbox
		tipText = "Add additional string data seperated by newline. \nExample: \"Gjøvik\" (without the goose eyes).";
		this->tipLabel->SetToolTip(this->rTxtAdditional, tipText);
		tipText = "Enter a database to search for. \nExample: \"webview\" or \"webview.db\"  (without the goose eyes).";
		this->tipLabel->SetToolTip(this->txtSearchTreeview, tipText);
		//checkedlistbox
		tipText = "Different search types for narrowing down the result";
		this->tipLabel->SetToolTip(this->chkLstSelectSearchTypes, tipText);
		//label for selected folder when search result is displayed in treeview
		tipText = this->lblSelectedFolder->Text;
		this->tipLabel->SetToolTip(this->lblSelectedFolder, tipText);
	} //setToolTipText

	private: void setEnabledAndHiddenControls(bool enabled) {
		//enable/disable controls
		this->chkLstDatabaseFolders->Enabled = enabled;
		this->lblDbSelect->Enabled = enabled;
		this->lblSelectSearchTypes->Enabled = enabled;
		this->rbAllDatabases->Enabled = enabled;
		this->rbSpecificDatabases->Enabled = enabled;
		this->chkSelectAllFolders->Enabled = enabled;
		this->rbAllSearchTypes->Enabled = enabled;
		this->rbSpecificSearchType->Enabled = enabled;
		this->chkLstSelectSearchTypes->Enabled = enabled;
		this->chkIncludeTimeLine->Enabled = enabled;
		this->chkIncludeAdditionalStrings->Enabled = enabled;
		this->btnStartSearch->Enabled = enabled;
		this->btnCancel->Enabled = enabled;
		this->btnReset->Enabled = enabled;
		//hidden components
		this->lblNoMatches->Visible = false;
		//set to disabled by default - tabSettings
		this->lblFromDate->Enabled = false;
		this->dtpFromDate->Enabled = false;
		this->dtpFromTime->Enabled = false;
		this->lblToDate->Enabled = false;
		this->dtpToDate->Enabled = false;
		this->dtpToTime->Enabled = false;
		this->rTxtAdditional->Enabled = false;
		this->lblAdditionalHelpText->Enabled = false;
		//set to disabled by default - tabResults
		this->cmbEntryType->Enabled = false;
		this->txtSearchTreeview->Enabled = false;
		this->btnSearchTreeview->Enabled = false;
		this->btnClearTvSearch->Enabled = false;
	} //setEnabledControls

	private: void emptyListsAndTextBoxes() {
		this->rTxtAdditional->Text = "";
		this->lstInformation->Items->Clear();
		this->chkLstDatabaseFolders->Items->Clear();
		this->tvDatabases->Nodes->Clear();
		this->dgvResults->Rows->Clear();
	} //emptyListBoxes

	private: System::Void rbAllDatabases_Click(System::Object^  sender, System::EventArgs^  e) {
		this->chkSelectAllFolders->Checked = false;
		this->chkSelectAllFolders->Checked = this->rbAllDatabases->Checked;
	} //rbAllDatabases_Click

	private: System::Void chkIncludeTimeLine_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		//get the status of this checkbox
		bool enabled = this->chkIncludeTimeLine->Checked;
		//enable labels and datetimepickers 
		this->lblFromDate->Enabled = enabled;
		this->dtpFromDate->Enabled = enabled;
		this->dtpFromTime->Enabled = enabled;
		this->lblToDate->Enabled = enabled;
		this->dtpToDate->Enabled = enabled;
		this->dtpToTime->Enabled = enabled;
	} //chkIncludeTimeLine_CheckedChanged

	private: System::Void chkIncludeAdditionalStrings_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		//get the status of this checkbox
		bool enabled = this->chkIncludeAdditionalStrings->Checked;
		//enable textbox and set focus
		this->lblAdditionalHelpText->Enabled = enabled;
		this->rTxtAdditional->Enabled = enabled;
		this->rTxtAdditional->Focus();
	} //chkIncludeAdditionalStrings_CheckedChanged

	private: System::Void chkSelectAllFolders_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		bool selected = this->chkSelectAllFolders->Checked;
		selectAllInCheckedListBox(chkLstDatabaseFolders, selected);
	} //chkSelectAllFolders_CheckedChanged

	private: System::Void rbAllSearchTypes_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		bool selected = this->rbAllSearchTypes->Checked;
		if(selected) {
			selectAllInCheckedListBox(chkLstSelectSearchTypes, true);
		} //if
	} //rbAllSearchTypes_CheckedChanged

	private: void selectAllInCheckedListBox(CheckedListBox ^chkList, bool checkStatus) {
		int numFolders = chkList->Items->Count;
		for(int i = 0; i < numFolders; i++) {
			chkList->SetItemChecked(i, checkStatus);
		} //for
	} //selectAllInCheckedListBox

	private: System::Void tsmNewSearch_Click(System::Object^  sender, System::EventArgs^  e) {
		//show the tabpage for search settings
		this->tabWindows->SelectedIndex = 0;
	} //tsmNewSearch_Click

	private: System::Void tsmCancelSearch_Click(System::Object^  sender, System::EventArgs^  e) {
		cancelSearch();
	} //tsmCancelSearch_Click

	private: System::Void tsmExit_Click(System::Object^  sender, System::EventArgs^  e) {
		//close the form and exit the program
		this->Close();
	} //tsmExit_Click

	private: System::Void tsmEditSearchData_Click(System::Object^  sender, System::EventArgs^  e) {
		frmEditTypes ^editWindow = gcnew frmEditTypes(this);
		editWindow->ShowDialog();
	} //tsmEditSearchData_Click

	private: System::Void tsmShowHelp_Click(System::Object^  sender, System::EventArgs^  e) {
		String ^errorTitle = "Error!";
		String ^errorMSg = "Can not view helpfile.\n";
		try {
			//show the help
			System::Diagnostics::Process::Start(this->hpHelper->HelpNamespace);
		} catch(Win32Exception ^ex) {
			MessageBox::Show(errorMSg + ex->Message, errorTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		} catch(ExceptionClass ^ex) {
			MessageBox::Show(errorMSg + ex->Message, errorTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		} //try/catch
	} //tsmShowHelp_Click

	private: System::Void tvDatabases_NodeMouseClick(System::Object^  sender, System::Windows::Forms::TreeNodeMouseClickEventArgs^  e) {
		int dbIndex = 0,
			tableIndex = 0,
			folderIndex = 0;
		setSelectedEntryText(e);
		bool canFillDatagridview = getSelectedTreeviewIndexes(e, folderIndex, dbIndex, tableIndex);
		//clear previous content from datagridview and show new content
		this->dgvResults->Rows->Clear();
		this->dgvResults->Columns->Clear();
		if(canFillDatagridview)
			fillDatagridviewWithResults(folderIndex, dbIndex, tableIndex);
	} //tvDatabases_NodeMouseClick

	private: void setSelectedEntryText(System::Windows::Forms::TreeNodeMouseClickEventArgs^  e) {
		String ^dbFileExtension = ".db";
		String ^selectedFolder = e->Node->Text;
		String ^selectedDatabase = e->Node->Text;
		//is the selected node a database node?
		if(selectedFolder->Contains(dbFileExtension)) {
			selectedFolder = e->Node->Parent->Text;
		} else if((e->Node->Parent != nullptr) && (e->Node->Parent->Text->Contains(dbFileExtension))) {
			//the selected node is a table node
			selectedDatabase = e->Node->Parent->Text;
			selectedFolder = e->Node->Parent->Parent->Text;
		} else {
			//is a folder selected?
			if(e->Node->Parent != nullptr) {
				selectedDatabase = e->Node->Nodes[0]->Text;
			} else {
				//root is selected, set selected db to grandchild
				selectedDatabase = e->Node->Nodes[0]->Nodes[0]->Text;
			} //if
		} //if
		this->lblSelectedFolder->Text = selectedFolder;
		this->lblDatabase->Text = selectedDatabase;
		this->tipLabel->SetToolTip(this->lblSelectedFolder, selectedFolder);
	} //setSelectedEntryText

	private: bool getSelectedTreeviewIndexes(System::Windows::Forms::TreeNodeMouseClickEventArgs^  e,
		int &folderIndex, int &dbIndex, int &tableIndex) {
		String ^dbFileExtension = ".db";
		TreeNode ^selectedNode = e->Node;
		bool canFillDatagridview = true;
		//is the selected node a database
		if(selectedNode->Text->Contains(dbFileExtension)) {
			dbIndex = e->Node->Index;
			folderIndex = e->Node->Parent->Index;
			if(e->Node->Nodes->Count > 0) {
				tableIndex = e->Node->Nodes[0]->Index;
			} else {
				canFillDatagridview = false;
			} //if
		} else if((selectedNode->Parent != nullptr)
			&& (selectedNode->Parent->Text->Contains(dbFileExtension))) {
			//the selected node is a table node
			tableIndex = e->Node->Index;
			dbIndex = e->Node->Parent->Index;
			folderIndex = e->Node->Parent->Parent->Index;
		} else {
			//is the selected node a folder?
			if(e->Node->Parent != nullptr) {
				folderIndex = e->Node->Index;
				dbIndex = e->Node->Nodes[0]->Index;
				tableIndex = e->Node->Nodes[0]->Nodes[0]->Index;
			} else {
				//root is selected
				folderIndex = e->Node->Nodes[0]->Index;
				dbIndex = e->Node->Nodes[0]->Nodes[0]->Index;
				tableIndex = e->Node->Nodes[0]->Nodes[0]->Nodes[0]->Index;
			} //if
		} //if
		return canFillDatagridview;
	} //getSelectedTreeviewIndexes

	private: System::Void ctmTreeview_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		//get number of nodes in treeview and check if at least one node exists
		int countNodes = this->tvDatabases->GetNodeCount(true);
		if(countNodes > 0) {
			//enable the options
			this->tsmExpandClose->Enabled = true;
			this->tsmOpenFolder->Enabled = true;
		} else { //no nodes, disable options
			this->tsmExpandClose->Enabled = false;
			this->tsmOpenFolder->Enabled = false;
		} //if 
	} //ctmTreeview_Opening

	private: System::Void tsmExpandAll_Click(System::Object^  sender, System::EventArgs^  e) {
		//expand all nodes in treeview
		this->tvDatabases->ExpandAll();
	} //tsmExpandAll_Click

	private: System::Void tsmCloseAll_Click(System::Object^  sender, System::EventArgs^  e) {
		//close all nodes in treeview
		this->tvDatabases->CollapseAll();
	} //tsmExpandAll_Click

	private: System::Void tsmExpandSelected_Click(System::Object^  sender, System::EventArgs^  e) {
		//expand the selected node and its child nodes
		this->tvDatabases->SelectedNode->ExpandAll();
	} //tsmExpandSelected_Click

	private: System::Void tsmCloseSelected_Click(System::Object^  sender, System::EventArgs^  e) {
		//close the selected node and its child nodes
		this->tvDatabases->SelectedNode->Collapse();
	} //tsmCloseSelected_Click

	private: System::Void tsmOpenFolder_Click(System::Object^  sender, System::EventArgs^  e) {
		TreeNode ^selectedNode = this->tvDatabases->SelectedNode;
		String ^folderName = selectedNode->Text;
		try {
			//check that a folder and not database/table was selected
			String ^extension = ".db";
			if(folderName->Contains(extension)) {
				folderName = selectedNode->Parent->Text;
			} else if((selectedNode->Parent != nullptr) && (selectedNode->Parent->Text->Contains(extension))) {
				//the selected node is a table node, set to grandparent (folder)
				folderName = selectedNode->Parent->Parent->Text;
			} //if
			System::Diagnostics::Process::Start(folderName);
		} catch(Win32Exception^) {
			String ^errorMsg = "Failed to open folder " + folderName + ".";
			MessageBox::Show(errorMsg, "Open Folder",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->lstInformation->Items->Add(errorMsg);
		} // try/catch
	} //tsmOpenFolder_Click

#pragma endregion Enabling controls, menustrip, setting textvalues and changing status for checkboxes

	private: System::Void btnBrowse_Click(System::Object^  sender, System::EventArgs^  e) {
		setFolderPath();
	} //btnBrowse_Click

	private: System::Void btnStartSearch_Click(System::Object^  sender, System::EventArgs^  e) {
		startSearch();
	} //btnStartSearch_Click

	private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) {
		cancelSearch();
	} //btnCancel_Click

	private: System::Void btnReset_Click(System::Object^  sender, System::EventArgs^  e) {
		cancelSearch();
		InitializeControls();
	} //btnReset_Click

	private: System::Void bwDataRetrieval_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		// Get the BackgroundWorker that raised this event.
		BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);
		fuzzyObj = gcnew FuzzySearch();
		// search for potential evidence; 
		fuzzyObj->runFilteredSearch(worker, e, pathToDatabaseList, databaseFileList, selectedSearchTypesList, additionalStringsList);
		//fill views with the results
		fillUpViews(worker, e);
	} //bwDataRetrieval_DoWork

	private: System::Void bwDataRetrieval_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
		//update the progress bar
		this->pbProgress->Value = e->ProgressPercentage;
	} //bwDataRetrieval_ProgressChanged

	private: System::Void bwDataRetrieval_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
		//was the backgroundwork interrupted by an error?
		if(e->Error != nullptr) {
			//display error and stacktrace
			this->lstInformation->Items->Add("StackTrace:\n" + e->Error->StackTrace);
			MessageBox::Show(e->Error->Message, "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		} else {
			//was the backgroundwork cancelled?
			if(e->Cancelled) {
				String ^message = "The search was cancelled!";
				this->lblNoMatches->Visible = true;
				this->lblNoMatches->Text = message;
				this->lstInformation->Items->Add(message);
			} else {
				searchCompleted();
			} //if
		} //if
		this->btnStartSearch->Enabled = true;
		this->btnBrowse->Enabled = true;
	} //bwDataRetrieval_RunWorkerCompleted

	private: System::Void btnSearchTreeview_Click(System::Object^  sender, System::EventArgs^  e) {
		String ^search = this->txtSearchTreeview->Text;
		if(!search->Equals("")) {
			//clear previously marked entries and then mark the new ones
			clearHighlightedEntries();
			searchAndHighlightTreeviewEntries(search);
		} //if
	} //btnSearchTreeview_Click

	private: System::Void btnClearTvSearch_Click(System::Object^  sender, System::EventArgs^  e) {
		this->txtSearchTreeview->Text = "";
		clearHighlightedEntries();
	} //btnClearTvSearch_Click
	}; //frmMain
} //namespace