
// UP_8View.cpp : implementation of the CUP_8View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "UP_8.h"
#endif

#include "UP_8Doc.h"
#include "UP_8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Circle circ(620, 340, 620, 380);
Rectangles rectan(580, 300, 660, 380);
bool cflag = false, rflag = false, cActive = false, rActive = false;
double temp;
char out[20];
wchar_t fout[20];

// CUP_8View

IMPLEMENT_DYNCREATE(CUP_8View, CView)

BEGIN_MESSAGE_MAP(CUP_8View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32775, &CUP_8View::OnCircle)
	ON_COMMAND(ID_32776, &CUP_8View::OnRect)
	ON_COMMAND(ID_32777, &CUP_8View::OnClean)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_32778, &CUP_8View::On32778)
END_MESSAGE_MAP()

// CUP_8View construction/destruction

CUP_8View::CUP_8View()
{
	// TODO: add construction code here

}

CUP_8View::~CUP_8View()
{
}

BOOL CUP_8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CUP_8View drawing

void CUP_8View::OnDraw(CDC* pDC)
{
	CUP_8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (cflag)
	{
		pDC->Ellipse(circ.getLXY(0) - (int)circ.getR(), circ.getLXY(1) + (int)circ.getR(), circ.getLXY(0) + (int)circ.getR(), circ.getLXY(1) - (int)circ.getR());
	}
	if (rflag)
	{
		pDC->Rectangle(rectan.getLXY(0), rectan.getLXY(1), rectan.getRXY(0), rectan.getRXY(1));
	}
}


// CUP_8View printing

BOOL CUP_8View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CUP_8View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CUP_8View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CUP_8View diagnostics

#ifdef _DEBUG
void CUP_8View::AssertValid() const
{
	CView::AssertValid();
}

void CUP_8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUP_8Doc* CUP_8View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUP_8Doc)));
	return (CUP_8Doc*)m_pDocument;
}
#endif //_DEBUG


// CUP_8View message handlers



void CUP_8View::OnCircle()
{
	cflag = true;
	InvalidateRect(0, TRUE);
}


void CUP_8View::OnRect()
{
	rflag = true;
	InvalidateRect(0, TRUE);
}


void CUP_8View::OnClean()
{
	cflag = false;
	rflag = false;
	InvalidateRect(0, TRUE);
}


void CUP_8View::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (cflag && abs(point.x - circ.getLXY(0)) <= circ.getR() && abs(point.y - circ.getLXY(1)) <= circ.getR())
	{
		cActive = true;
	}
	if (rflag && point.x >= rectan.getLXY(0) && point.y >= rectan.getLXY(1)
		&& point.x <= rectan.getRXY(0) && point.y <= rectan.getRXY(1))
	{
		rActive = true;
	}

	CView::OnLButtonDown(nFlags, point);
}


void CUP_8View::OnMouseMove(UINT nFlags, CPoint point)
{
	if (cflag && (nFlags & MK_SHIFT) && (abs(point.x - circ.getRXY(0)) < 20 && abs(point.y - circ.getRXY(1)) < 20))
	{
		SetCursor(LoadCursor(NULL, IDC_SIZENS));
		ShowCursor(TRUE);
	}
	if (rflag && (nFlags & MK_SHIFT) && (abs(point.x - rectan.getRXY(0)) < 20 && abs(point.y - rectan.getRXY(1)) < 20))
	{
		SetCursor(LoadCursor(NULL, IDC_SIZENWSE));
		ShowCursor(TRUE);
	}
	if (nFlags & MK_LBUTTON)
	{
		if (nFlags & MK_SHIFT)
		{
			if (cActive && abs(point.x - circ.getRXY(0)) < 20 && abs(point.y - circ.getRXY(1)) < 20)
			{
				circ.fAlteration(point.x - circ.getRXY(0), point.y - circ.getRXY(1));
				InvalidateRect(0, TRUE);
			}
			if (rActive && abs(point.x - rectan.getRXY(0)) < 20 && abs(point.y - rectan.getRXY(1)) < 20)
			{
				rectan.fAlteration(point.x - rectan.getRXY(0), point.y - rectan.getRXY(1));
				InvalidateRect(0, TRUE);
			}
		}
		else
		{
			if (cActive)
			{
				circ.fMove(point.x - circ.getLXY(0), point.y - circ.getLXY(1));
				InvalidateRect(0, TRUE);
			}
			if (rActive)
			{
				rectan.fMove(point.x - rectan.getLXY(0), point.y - rectan.getLXY(1));
				InvalidateRect(0, TRUE);
			}
		}
	}

	CView::OnMouseMove(nFlags, point);
}


void CUP_8View::OnLButtonUp(UINT nFlags, CPoint point)
{
	cActive = false;
	rActive = false;

	CView::OnLButtonUp(nFlags, point);
}


void CUP_8View::On32778()
{
	//temp = circ.getSquare();
	//sprintf_s(out, "%f", temp);
	//AfxMessageBox(out);
}

