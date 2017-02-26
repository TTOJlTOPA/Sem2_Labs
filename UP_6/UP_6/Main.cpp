#include "Windows.h"
#include "cstdio"
#include "Circle.h"
#include "Rectangle.h"
#include <io.h>	// ��� _open_osfhandle
#include <fcntl.h> // ��� _O_TEXT

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
Circle circ(640, 360, 640, 400);
Rectangles rectan(600, 320, 680, 400);
bool cflag = false, rflag = false, cActive = false, rActive = false;
int i = 0;
double temp;
char out[20];

BOOL CreateConsole(void)  // �������� �������
{
	FreeConsole();	// ��������� ��� �������� �� ������ ������� 
	if (AllocConsole())	// ��������� ����� ������� ��� ������� ��������
	{
		int hCrt = _open_osfhandle((long)	// ���������� ������������� ����� ������� ����������
			GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);	/* ��������� ���������� ��� ������������ ����� ������, ������������ ������ ��� 
														����������� ������ ����������*/
		*stdout = *(::_fdopen(hCrt, "w"));	// ��������������� ������������ ������ ������ | _fdopen	// ���������� ������ � ������
		::setvbuf(stdout, NULL, _IONBF, 0);
		*stderr = *(::_fdopen(hCrt, "w"));	// ��������������� ������������ ������ ������
		::setvbuf(stderr, NULL, _IONBF, 0);
		return TRUE;
	}return FALSE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwnd;
	static char szClassName[] = "UP6";
	MSG msg;
	WNDCLASSEX wndclass;
	HMENU hMenu;
	HMENU hPopUpMenu;
	HMENU hPopUpPerim;
	HMENU hPopUpSquare;

	wndclass.cbSize = sizeof (wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(DC_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szClassName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wndclass))
	{
		MessageBox(NULL, "���������� ���������������� ����� ����.", "������", MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CONTROLPARENT, szClassName, "UP6", WS_SYSMENU,
		150, 100, 1280, 720, NULL, NULL, hInstance, NULL);

	if (!hwnd)
	{
		MessageBox(NULL, "���������� ������� �������� ����.", "������", MB_OK);
		return 0;
	}

	hMenu = CreateMenu();
	hPopUpMenu = CreateMenu();
	hPopUpPerim = CreateMenu();
	hPopUpSquare = CreateMenu();
	AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hPopUpMenu, "������");	
	AppendMenu(hPopUpMenu, MF_STRING, 101, "����");
	AppendMenu(hPopUpMenu, MF_STRING, 102, "�������������");
	AppendMenu(hPopUpMenu, MF_STRING, 103, "��������");
	AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hPopUpSquare, "�������");
	AppendMenu(hPopUpSquare, MF_STRING, 104, "����");
	AppendMenu(hPopUpSquare, MF_STRING, 105, "�������������");
	AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hPopUpPerim, "��������");
	AppendMenu(hPopUpPerim, MF_STRING, 106, "����");
	AppendMenu(hPopUpPerim, MF_STRING, 107, "�������������");
	AppendMenu(hMenu, MF_STRING, 108, "�����");
	SetMenu(hwnd, hMenu);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	CreateConsole();	// �������� �������

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, hdcMem;
	PAINTSTRUCT ps;
	RECT rect;

	switch (iMsg)
	{
	case WM_CREATE:
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		if (cflag)
		{
			circ.fDraw(hdc);
		}
		if (rflag)
		{
			rectan.fDraw(hdc);
		}
		EndPaint(hwnd, &ps);
		break;

	case WM_COMMAND:
		switch (wParam)
		{
		case 101:
			hdc = GetDC(hwnd);
			circ.fDraw(hdc);
			cflag = true;
			ReleaseDC(hwnd, hdc);
			break;

		case 102:
			hdc = GetDC(hwnd);
			rectan.fDraw(hdc);
			rflag = true;
			ReleaseDC(hwnd, hdc);
			break;

		case 103:
			cflag = false;
			rflag = false;
			InvalidateRect(hwnd, 0, TRUE);
			break;

		case 104:
			temp = circ.getSquare();
			sprintf_s(out, "%f", temp);
			MessageBox(hwnd, out, "������� �����", 0);
			break;

		case 105:
			temp = rectan.getSquare();
			sprintf_s(out, "%f", temp);
			MessageBox(hwnd, out, "������� �������������", 0);
			break;

		case 106:
			temp = circ.getPerimeter();
			sprintf_s(out, "%f", temp);
			MessageBox(hwnd, out, "�������� ����", 0);
			break;

		case 107:
			temp = rectan.getPerimeter();
			sprintf_s(out, "%f", temp);
			MessageBox(hwnd, out, "�������� ��������������", 0);
			break;

		case 108:
			DestroyWindow(hwnd);
			break;
		}
		break;

	case WM_LBUTTONDOWN:
		if (cflag && abs(LOWORD(lParam) - circ.getLXY(0)) <= circ.getR() && abs(HIWORD(lParam) - circ.getLXY(1)) <= circ.getR())
		{
			cActive = true;
		}
		if (rflag && LOWORD(lParam) >= rectan.getLXY(0) && HIWORD(lParam) >= rectan.getLXY(1)
			&& LOWORD(lParam) <= rectan.getRXY(0) && HIWORD(lParam) <= rectan.getRXY(1))
		{
			rActive = true;
		}
		break;

	case WM_MOUSEMOVE:
		if (wParam & MK_SHIFT && (abs(LOWORD(lParam) - circ.getRXY(0)) < 20 && abs(HIWORD(lParam) - circ.getRXY(1)) < 20))
		{
			SetCursor(LoadCursor(NULL, IDC_SIZENS));
			ShowCursor(TRUE);
		}
		if (wParam & MK_SHIFT && (abs(LOWORD(lParam) - rectan.getRXY(0)) < 20 && abs(HIWORD(lParam) - rectan.getRXY(1)) < 20))
		{
			SetCursor(LoadCursor(NULL, IDC_SIZENWSE));
			ShowCursor(TRUE);
		}
		if (wParam & MK_LBUTTON)
		{
			if (wParam & MK_SHIFT)
			{
				if (cActive && abs(LOWORD(lParam) - circ.getRXY(0)) < 20 && abs(HIWORD(lParam) - circ.getRXY(1)) < 20)
				{
					circ.fAlteration(LOWORD(lParam) - circ.getRXY(0), HIWORD(lParam) - circ.getRXY(1));
					InvalidateRect(hwnd, 0, TRUE);
				}
				if (rActive && abs(LOWORD(lParam) - rectan.getRXY(0)) < 20 && abs(HIWORD(lParam) - rectan.getRXY(1)) < 20)
				{
					rectan.fAlteration(LOWORD(lParam) - rectan.getRXY(0), HIWORD(lParam) - rectan.getRXY(1));
					InvalidateRect(hwnd, 0, TRUE);
				}
			}
			else
			{
				if (cActive)
				{
					circ.fMove(LOWORD(lParam) - circ.getLXY(0), HIWORD(lParam) - circ.getLXY(1));
					InvalidateRect(hwnd, 0, TRUE);
				}
				if (rActive)
				{
					rectan.fMove(LOWORD(lParam) - rectan.getLXY(0), HIWORD(lParam) - rectan.getLXY(1));
					InvalidateRect(hwnd, 0, TRUE);
				}
			}
		}
		break;

	case WM_LBUTTONUP:
		cActive = false;
		rActive = false;
		break;

	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, iMsg, wParam, lParam);
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}