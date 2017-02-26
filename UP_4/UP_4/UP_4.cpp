#include <Windows.h>
#include <cmath>
#include <cstdio>
#define BTN 101
#define EDIT1 102
#define EDIT2 103

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HWND hChildX, hChildK;
HINSTANCE hApp;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static char szAppName[] = "UP4";
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;

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
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wndclass))
	{
		MessageBox(NULL, "Невозможно зарегистрировать класс окна.", "Ошибка", MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CONTROLPARENT, szAppName, "Ряд Тейлора", WS_SYSMENU,
		CW_USEDEFAULT, 0, 530, 190,
		NULL, NULL, hInstance, NULL);

	if (!hwnd)
	{
		MessageBox(NULL, "Невозможно создать основное окно.", "Ошибка", MB_OK);
		return 0;
	}

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

HWND editX;
HWND editK;
HWND button;

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC         hdc;
	PAINTSTRUCT ps;
	RECT        rect;
	LPSTR str = "sin x = x - (x^3)/3! + (x^5)/5! - (x^7)/7! + ...; x - любое, точность - 10^(-k)";
	char strx[20], strk[20];

	switch (iMsg)
	{
	case WM_CREATE:
		editX = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 100, 40, 100, 20, hwnd,(HMENU) EDIT1, hApp, NULL); //WS_TABSTOP
		editK = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 100, 70, 100, 20, hwnd,(HMENU) EDIT2, hApp, NULL);
		button = CreateWindow("button", "Вычислить", WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON, 75, 100, 80, 30, hwnd,(HMENU) BTN, hApp, NULL);
		SetFocus(editX);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 10, 15, str, strlen(str));
		TextOut(hdc, 10, 40, "Введите Х:", 10);
		TextOut(hdc, 10, 70, "Введите K:", 10);
		TextOut(hdc, 210, 60, "Стандартный sin:", 16);
		TextOut(hdc, 210, 80, "Разложение sin по Тейлору:", 26);
		EndPaint(hwnd, &ps);
		break;

	case WM_COMMAND:
		switch (wParam)
		{
		case BTN:
			SendMessage(editX, WM_GETTEXT, sizeof(strx) / sizeof(strx[0]), (LPARAM)strx);
			SendMessage(editK, WM_GETTEXT, sizeof(strk) / sizeof(strk[0]), (LPARAM)strk);
			double x, e = 1, k, sum = 0, f = 1, y, b = 1, a = 0;
			char stand[20], teyl[20];
			x = atof(strx);
			k = atof(strk);
			y = sin(x);
			for (int i = 0; i < k; i++)
			{
				e /= 10;
			}
			do
			{
				a++;
				f *= a;
				b *= x;
				sum += (b / f);
				a++;
				f *= a;
				b *= -x;
			} while (abs(b / f) >= e);
			sprintf_s(stand, "%f", y);
			sprintf_s(teyl, "%f", sum);
			hdc = GetDC(hwnd);
			SetTextAlign(hdc, TA_LEFT | TA_TOP);
			//SetBkMode(hdc, TRANSPARENT);
			TextOut(hdc, 410, 60, stand, 8);
			TextOut(hdc, 410, 80, teyl, 8);
			ReleaseDC(hwnd, hdc);
			break;
		}
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