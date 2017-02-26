
// Sem2_Lab9_MFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Sem2_Lab9_MFC.h"
#include "Sem2_Lab9_MFCDlg.h"
#include "afxdialogex.h"
#include "Stud3.h"
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSem2_Lab9_MFCDlg dialog



CSem2_Lab9_MFCDlg::CSem2_Lab9_MFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSem2_Lab9_MFCDlg::IDD, pParent)
	, toedit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSem2_Lab9_MFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, toedit);
}

BEGIN_MESSAGE_MAP(CSem2_Lab9_MFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSem2_Lab9_MFCDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSem2_Lab9_MFCDlg message handlers

BOOL CSem2_Lab9_MFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSem2_Lab9_MFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSem2_Lab9_MFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSem2_Lab9_MFCDlg::OnBnClickedButton1()
{
	Stud1 M1;
	Stud2 K1;
	Stud3 R;
	ABS_LIB *A1, *A2, *A3, *A4;
	A1 = &M1;
	A2 = &K1;
	A3 = &R;
	A1->ReadData();
	A2->ReadData();
	A3->Form(A1, A2);
	A3->Sort();
	ostringstream out;
	A1->PutData(out);
	A2->PutData(out);
	A3->PutData(out);
	A3->WriteData();
	toedit = out.str().c_str();
	UpdateData(false);
}
