#include "stdafx.h"
#include "sharedFunctions.h"

using namespace System;

namespace CompFor2014 {

	/*
	Updates the progressbar with the current status of the operation.
	-------------------------------------------------------
	@param status: int - The progress of the operation
	@param total: float - Total progress value
	@param worker: BackgroundWorker^ - The worker that reports the update
	*/
	void SharedFunctions::updateProgressBar(int status, float total, BackgroundWorker ^worker) {
		int percentComplete = 0;
		if(status > 100) {
			status = 100;
		} //if
		percentComplete = (int)((float)status / total * 100);
		if(percentComplete > _progressFinished) {
			setProgressFinished(percentComplete);
			worker->ReportProgress(percentComplete);
		} //if
	} //updateProgressBar

	void SharedFunctions::setProgressFinished(int progressFinished) {
		_progressFinished = progressFinished;
	} //

	/*
	Converts value of type System::String^ to std::string.
	http://msdn.microsoft.com/en-us/library/1b4az623(v=vs.100).aspx
	---------------------------------------------------------
	@param s: String ^ - Value to convert to std::string
	@param os: std::string - Referenced result in a std::string
	*/
	void SharedFunctions::MarshalString(String ^ s, std::string& os) {
		using namespace Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	} //MarshalString

	/*
	Converts value of type String^ to std::wstring.
	http://msdn.microsoft.com/en-us/library/1b4az623(v=vs.100).aspx
	---------------------------------------------------------
	@param s: String ^ - Value to convert to std::wstring
	@param os: std::wstring - Referenced result in a std::wstring
	*/
	void SharedFunctions::MarshalString(String ^ s, std::wstring& os) {
		using namespace Runtime::InteropServices;
		const wchar_t* chars = (const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	} //MarshalString
} //namespace