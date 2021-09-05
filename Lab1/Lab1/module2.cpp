#include "framework.h"
#include "module2.h"
#include <math.h>

//������������� ��� ��������
int nScroll;

//���������� ���������� ������� ������
static BOOL CALLBACK DlgProc_MOD2(HWND, UINT, WPARAM, LPARAM);

//������� ��� ��������
int ToShowDialog_MOD2(HINSTANCE hInst, HWND hWnd)
{
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_MOD2), hWnd, DlgProc_MOD2);
}

//���������� ������� ����������� ����
BOOL CALLBACK DlgProc_MOD2(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    switch (iMessage)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK)
        {

            EndDialog(hDlg, 1);
            break;
        }
        if (LOWORD(wParam) == IDCANCEL) EndDialog(hDlg, 0);
        break;
    default: break;
    }
    return FALSE;
}
