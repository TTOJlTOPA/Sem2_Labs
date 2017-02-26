
// UP_8.h : main header file for the UP_8 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CUP_8App:
// See UP_8.cpp for the implementation of this class
//

class CUP_8App : public CWinApp
{
public:
	CUP_8App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CUP_8App theApp;
