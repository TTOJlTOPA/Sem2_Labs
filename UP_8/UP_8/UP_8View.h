
// UP_8View.h : interface of the CUP_8View class
//

#pragma once
#include "Circle.h"
#include "Rectangle.h"
#include <cstdio>

//Circle circ(620, 340, 620, 380);
//Rectangles rectan(580, 300, 660, 380);

class CUP_8View : public CView
{
protected: // create from serialization only
	CUP_8View();
	DECLARE_DYNCREATE(CUP_8View)

// Attributes
public:
	CUP_8Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CUP_8View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCircle();
	afx_msg void OnRect();
	afx_msg void OnClean();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void On32778();
};

#ifndef _DEBUG  // debug version in UP_8View.cpp
inline CUP_8Doc* CUP_8View::GetDocument() const
   { return reinterpret_cast<CUP_8Doc*>(m_pDocument); }
#endif

