#pragma once
#include "stdafx.h"

using namespace System::ComponentModel;

namespace CompFor2014 {

#ifndef SHAREDFUNCTIONS_H

#define SHAREDFUNCTIONS_H
	/*
	Shared functions that are used between the user interfaces,
	@author: Knut Lucas Andersen
	*/
	public ref class SharedFunctions sealed {
	public:
		//the name of the folder containing the stored search types
		static System::String ^SEARCH_TYPES_FOLDER = "SearchTypes";
		//the name of the file containing the search types
		static System::String ^SEARCH_TYPES_FILE = "SearchTypes.txt";
		//convert String^ to std::string
		static void MarshalString(System::String ^ s, std::string& os);
		//convert String^ to std::wstring
		static void MarshalString(System::String ^ s, std::wstring& os);
		//update the progressbar while backgroundworker is working
		static void updateProgressBar(int status, float total, BackgroundWorker ^worker);
		//set the updated progress
		static void setProgressFinished(int progressFinished);
	private:
		static int _progressFinished;
	}; //SharedFunctions
#endif 

} //namespace