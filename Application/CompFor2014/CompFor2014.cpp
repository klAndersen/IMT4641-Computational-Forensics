// CompFor2014.cpp : main project file.

#pragma once

#include "stdafx.h"

#include "frmMain.h"

using namespace CompFor2014;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew frmMain());
	return 0;
}
