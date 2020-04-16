#include "framework.h"
#include "WindowsProject2.h"

#define X_C 19
#define Y_C 19
//가로세로 크기

// 화면의 왼쪽에서 바둑판의 왼쪽면까지의 거리
#define S_X  50
// 화면의 위쪽에서 바둑판의 위쪽면까지의 거리
#define S_Y  50

// 줄 사이의 간격
#define INTER 26
// 바둑 돌의 반지름
#define HALF_INTER   INTER/2

#define XPOS(x)   (S_X + (x) * INTER)
#define YPOS(y)   (S_Y + (y) * INTER)

// 바둑판에 돌이 놓여져 있는지 기억하기 위한 변수 배열의 각 항목의 값이 0이면 돌이 
// 놓여져 있지 않다는 뜻이고 1이면 검은색 돌, 2이면 흰색 돌이 놓여져 있다는것.
unsigned char dol[Y_C][X_C];
// 현재 어떤 돌을 놓을 것인지를 결정하는 변수
unsigned char step;

void OnPaint(HWND ah_wnd)//바둑판의 선과 바둑돌을 그리게해주는 함수
{
	PAINTSTRUCT ps;
	HDC h_dc = BeginPaint(ah_wnd, &ps);

	for (int x = 0; x < X_C; x++) {//바둑판의가로선을그린다
		MoveToEx(h_dc, XPOS(x), YPOS(0), NULL);
		LineTo(h_dc, XPOS(x), YPOS(Y_C - 1));
	}
	for (int y = 0; y < Y_C; y++) {//바둑판의세로선을그린다
		MoveToEx(h_dc, XPOS(0), YPOS(y), NULL);
		LineTo(h_dc, XPOS(X_C - 1), YPOS(y));
	}
	for (int y = 0; y < Y_C; y++) {
		for (int x = 0; x < X_C; x++) {
			if (dol[y][x] > 0) {//바둑돌을 놨을때 
				if (dol[y][x] == 1) SelectObject(h_dc, GetStockObject(BLACK_BRUSH));//dol이 1일경우 검은색돌
				else SelectObject(h_dc, GetStockObject(WHITE_BRUSH));//그외에는 흰색돌
				Ellipse(h_dc, XPOS(x) - HALF_INTER, YPOS(y) - HALF_INTER,//바둑돌+그려질좌표 
					XPOS(x) + HALF_INTER, YPOS(y) + HALF_INTER);
			}
		}
	}
	EndPaint(ah_wnd, &ps);

}

void OnLButtonDown(HWND ah_wnd, int a_x, int a_y)//돌을놓을때 필요한 마우스클릭함수
{
	if (a_x > (XPOS(0) - HALF_INTER) && a_y > (YPOS(0) - HALF_INTER)
		&& a_x < (XPOS(X_C - 1) + HALF_INTER)
		&& a_y < (YPOS(Y_C - 1) + HALF_INTER)) {
		int x = (a_x - S_X + HALF_INTER) / INTER;
		int y = (a_y - S_Y + HALF_INTER) / INTER;
		if (dol[y][x] == 0) {
			dol[y][x] = step + 1;
			step = !step;
			InvalidateRect(ah_wnd, NULL, TRUE);
		}
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	if (umsg == WM_PAINT) {
		OnPaint(hwnd);
		return 0;
	}
	else if (umsg == WM_LBUTTONDOWN) {
		int x = LOWORD(lparam);//마우스x좌표
		int y = HIWORD(lparam);//마우스y좌표
		OnLButtonDown(hwnd, x, y);
	}
	else if (umsg == WM_DESTROY) PostQuitMessage(0);

	return DefWindowProc(hwnd, umsg, wparam, lparam);
}
