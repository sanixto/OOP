#include "framework.h"
#include <math.h>
#include "module1.h"

//������������� ��� ��������
char string_MOD1[100];

//���������� ���������� ������� ������
static BOOL CALLBACK  DlgProc_MOD1(HWND, UINT, WPARAM, LPARAM);

//������� ��� ��������
int ToShowDialog_MOD1(HINSTANCE hInst, HWND hWnd)
{
    return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_MOD1), hWnd, DlgProc_MOD1);
}

//���������� ������� ����������� ����
BOOL CALLBACK DlgProc_MOD1(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    switch (iMessage)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK)
        {
            //������� ������ �� ���� ��� �����
            GetDlgItemText(hDlg, IDC_EDIT_MOD1, string_MOD1, 100);

            EndDialog(hDlg, 1);
            break;
        }
        if (LOWORD(wParam) == IDCANCEL) EndDialog(hDlg, 0);
        break;
    default: break;
    }
    return FALSE;
}
