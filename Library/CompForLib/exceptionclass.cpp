#include "Stdafx.h"
#include "exceptionclass.h"

namespace ComputationalForensics {

	/*
	Default constructor
	*/
	ExceptionClass::ExceptionClass() : Exception() {
		_errorMsg = "";
		_errorTitle = "";
	} //constructor

	/*
	Constructor setting the error message based on the error
	that occurred.
	---------------------------------------------------------
	@param errorMsg: String^ - message containing description of error
	*/
	ExceptionClass::ExceptionClass(String ^ errorMsg) : Exception(errorMsg) {
		setExceptionMessage(errorMsg);
	} //constructor

	/*
	Constructor setting the error message and error title
	based on the error that occurred.
	---------------------------------------------------------
	@param errorMsg: String^ - message containing description of error
	@param errorTitle: String^ - title description of error that occurred
	*/
	ExceptionClass::ExceptionClass(String ^ errorMsg, String ^ errorTitle) : Exception(errorMsg) {
		setExceptionMessage(errorMsg);
		setExceptionTitle(errorTitle);
	} //constructor

	/*
	Destructor
	*/
	ExceptionClass::~ExceptionClass() {

	} //destructor

	/*
	Returns the error message related to this error
	*/
	String ^ ExceptionClass::ToString() {
		return _errorMsg;
	} //ToString

	/*
	Returns the error title related to this error
	(for use in messagebox)
	*/
	String ^ ExceptionClass::getExceptionTitle() {
		return _errorTitle;
	} //getExceptionTitle

	void ExceptionClass::setExceptionMessage(String ^ errorMsg) {
		_errorMsg = errorMsg;
	} //setExceptionMessage

	void ExceptionClass::setExceptionTitle(String ^ errorTitle) {
		_errorTitle = errorTitle;
	} //setExceptionTitle
} //namespace