#include "framework.h"
#include "WindowsProject2.h"

#define X_C 19
#define Y_C 19
//���μ��� ũ��

// ȭ���� ���ʿ��� �ٵ����� ���ʸ������ �Ÿ�
#define S_X  50
// ȭ���� ���ʿ��� �ٵ����� ���ʸ������ �Ÿ�
#define S_Y  50

// �� ������ ����
#define INTER 26
// �ٵ� ���� ������
#define HALF_INTER   INTER/2

#define XPOS(x)   (S_X + (x) * INTER)
#define YPOS(y)   (S_Y + (y) * INTER)

// �ٵ��ǿ� ���� ������ �ִ��� ����ϱ� ���� ���� �迭�� �� �׸��� ���� 0�̸� ���� 
// ������ ���� �ʴٴ� ���̰� 1�̸� ������ ��, 2�̸� ��� ���� ������ �ִٴ°�.
unsigned char dol[Y_C][X_C];
// ���� � ���� ���� �������� �����ϴ� ����
unsigned char step;

void OnPaint(HWND ah_wnd)//�ٵ����� ���� �ٵϵ��� �׸������ִ� �Լ�
{
	PAINTSTRUCT ps;
	HDC h_dc = BeginPaint(ah_wnd, &ps);

	for (int x = 0; x < X_C; x++) {//�ٵ����ǰ��μ����׸���
		MoveToEx(h_dc, XPOS(x), YPOS(0), NULL);
		LineTo(h_dc, XPOS(x), YPOS(Y_C - 1));
	}
	for (int y = 0; y < Y_C; y++) {//�ٵ����Ǽ��μ����׸���
		MoveToEx(h_dc, XPOS(0), YPOS(y), NULL);
		LineTo(h_dc, XPOS(X_C - 1), YPOS(y));
	}
	for (int y = 0; y < Y_C; y++) {
		for (int x = 0; x < X_C; x++) {
			if (dol[y][x] > 0) {//�ٵϵ��� ������ 
				if (dol[y][x] == 1) SelectObject(h_dc, GetStockObject(BLACK_BRUSH));//dol�� 1�ϰ�� ��������
				else SelectObject(h_dc, GetStockObject(WHITE_BRUSH));//�׿ܿ��� �����
				Ellipse(h_dc, XPOS(x) - HALF_INTER, YPOS(y) - HALF_INTER,//�ٵϵ�+�׷�����ǥ 
					XPOS(x) + HALF_INTER, YPOS(y) + HALF_INTER);
			}
		}
	}
	EndPaint(ah_wnd, &ps);

}

void OnLButtonDown(HWND ah_wnd, int a_x, int a_y)//���������� �ʿ��� ���콺Ŭ���Լ�
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
		int x = LOWORD(lparam);//���콺x��ǥ
		int y = HIWORD(lparam);//���콺y��ǥ
		OnLButtonDown(hwnd, x, y);
	}
	else if (umsg == WM_DESTROY) PostQuitMessage(0);

	return DefWindowProc(hwnd, umsg, wparam, lparam);
}
