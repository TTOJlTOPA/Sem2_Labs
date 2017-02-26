
// Sem2_Lab9_MFCDlg.h : header file
//

#pragma once


// CSem2_Lab9_MFCDlg dialog
class CSem2_Lab9_MFCDlg : public CDialogEx
{
// Construction
public:
	CSem2_Lab9_MFCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SEM2_LAB9_MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString toedit;
	afx_msg void OnBnClickedButton1();
};
