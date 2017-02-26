#include <Windows.h>
#include <cmath>
#include <cstdio>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void Coord(HDC);
void Teyl(HDC);
int ed = 27;
double koef = 1;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwnd;
	static char szClassName[] = "UP5";
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
	wndclass.lpszClassName = szClassName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wndclass))
	{
		MessageBox(NULL, "Невозможно зарегистрировать класс окна.", "Ошибка", MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CONTROLPARENT, szClassName, "UP5", WS_SYSMENU, 
		CW_USEDEFAULT, 0, 825, 600, NULL, NULL, hInstance, NULL);

	if (!hwnd)
	{
		MessageBox(NULL, "Невозможно создать основное окно.", "Ошибка", MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	LPSTR str = "sin x = x - (x^3)/3! + (x^5)/5! - (x^7)/7! + ...; x - любое, точность - 10^(-k)";

	switch (iMsg)
	{
	/*case WM_CREATE:
		break;*/

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 10, 15, str, strlen(str));
		Coord(hdc);
		Teyl(hdc);
		EndPaint(hwnd, &ps);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ADD:
			if (koef < 4)
			{
				koef *= 2;
				InvalidateRect(hwnd, 0, TRUE);
			}
			break;

		case VK_SUBTRACT:
			if (koef > 0.25)
			{
				koef /= 2;
				InvalidateRect(hwnd, 0, TRUE);
			}
			break;
		}

	case WM_MOUSEWHEEL:
		if (GET_WHEEL_DELTA_WPARAM(wParam) > 0) //прокрутка колёсика мыши вперёд
		{
			if (koef < 4)
			{
				koef *= 2;
				InvalidateRect(hwnd, 0, TRUE);
			}
		}
		if (GET_WHEEL_DELTA_WPARAM(wParam) < 0)
		{
			if (koef > 0.25)
			{
				koef /= 2;
				InvalidateRect(hwnd, 0, TRUE);
			}
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

void Coord(HDC hdc)
{
	HPEN pen1 = CreatePen(PS_SOLID, 2, RGB(155, 155, 155));
	for (int i = 2 * koef; i <= 20 * koef; i++) // разметка
	{
		SelectObject(hdc, pen1);
		MoveToEx(hdc, 10, i * ed / koef, NULL);
		LineTo(hdc, 800, i * ed / koef);
	}
	for (int i = 1 * koef; i <= 29 * koef; i++)
	{
		SelectObject(hdc, pen1);
		MoveToEx(hdc, i * ed / koef, 40, NULL);
		LineTo(hdc, i * ed / koef, 550);
	}
	DeleteObject(pen1);
	HPEN pen2 = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, pen2);
	MoveToEx(hdc, 800, 297, NULL); // Ox
	LineTo(hdc, 10, 297);
	MoveToEx(hdc, 405, 40, NULL); // Oy
	LineTo(hdc, 405, 550);
	MoveToEx(hdc, 805, 297, NULL); // стрелочка Ox
	LineTo(hdc, 795, 292);
	MoveToEx(hdc, 805, 297, NULL);
	LineTo(hdc, 795, 302);
	MoveToEx(hdc, 405, 35, NULL); // стрелочка Oy
	LineTo(hdc, 400, 45);
	MoveToEx(hdc, 405, 35, NULL);
	LineTo(hdc, 410, 45);
	DeleteObject(pen2);
	TextOut(hdc, 390, 30, "y", 1);
	TextOut(hdc, 795, 305, "x", 1);
}

void Teyl(HDC hdc)
{
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	double x, e = 0.001, sum, fuct, s, xs, y;
	double i = koef;
	bool flag = true;
	SelectObject(hdc, pen);
	for (x = -1.4 * koef; x <= 1.4 * koef; x += 0.1)
	{
		sum = 0;
		fuct = 1;
		s = 0;
		xs = 1;
		do
		{
			s++;
			fuct *= s;
			xs *= x;
			sum += (xs / fuct);
			s++;
			fuct *= s;
			xs *= -x;
		} while (abs(xs / fuct) >= e);
		y = 297 - sum * ed * 10 / koef;
		if (y > 40 && y < 550)
		{
			if (flag)
			{
				MoveToEx(hdc, i * ed / koef, y, NULL);
				flag = false;
			}
			else
			{
				LineTo(hdc, i * ed / koef, y);
			}
		}
		i++;
	}
	DeleteObject(pen);
}