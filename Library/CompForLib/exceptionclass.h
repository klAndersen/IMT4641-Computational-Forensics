#pragma once
#include "Stdafx.h"

namespace ComputationalForensics {

#ifndef EXCEPTION_CLASS_H

#define EXCEPTION_CLASS_H	
	/*
	Class that handles the exceptions occuring for the different classes.
	Mainly made to create more readable code and keep all exception messages
	created within one class.
	-----------------------------------------
	@Author: Knut Lucas Andersen
	*/
	public ref class ExceptionClass sealed : public Exception {
	public:
		//default constructor
		ExceptionClass();
		//constructor setting error message
		ExceptionClass(String ^ errorMsg);
		//constructor setting error message and title
		ExceptionClass(String ^ errorMsg, String ^ errorTitle);
		//destructor
		~ExceptionClass();
		//override error message retrieval (returns error message)
		virtual String ^ ToString() override;
		//returns the error title
		String ^ getExceptionTitle();

	private:
		String ^ _errorMsg;
		String ^ _errorTitle;
		void setExceptionMessage(String ^ errorMsg);
		void setExceptionTitle(String ^ errorTitle);
	};
#endif
} //namespace