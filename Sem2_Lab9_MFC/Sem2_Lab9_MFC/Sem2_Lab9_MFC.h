
// Sem2_Lab9_MFC.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSem2_Lab9_MFCApp:
// See Sem2_Lab9_MFC.cpp for the implementation of this class
//

class CSem2_Lab9_MFCApp : public CWinApp
{
public:
	CSem2_Lab9_MFCApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CSem2_Lab9_MFCApp theApp;