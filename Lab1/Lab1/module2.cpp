#include "framework.h"
#include "module2.h"
#include <math.h>

//������������� ��� ��������
char result_MOD2[4];

//���������� ���������� ���������������
static int pos = 1;

//���������� ���������� ������� ������
static BOOL CALLBACK DlgProc_MOD2(HWND, UINT, WPARAM, LPARAM);

//������� ��� ��������
int ToShowDialog_MOD2(HINSTANCE hInst, HWND hWnd)
{
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_MOD2), hWnd, DlgProc_MOD2);
}

//���������� ������� ����������� ����
static BOOL CALLBACK DlgProc_MOD2(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM)
{
    HWND hWndScroll = GetDlgItem(hDlg, IDC_SCROLLBAR_MOD2);

    switch (iMessage)
    {
    case WM_INITDIALOG:
        SetScrollRange(hWndScroll, SB_CTL, 1, 100, TRUE);
        break;
    case WM_HSCROLL:
        pos = GetScrollPos(hWndScroll, SB_CTL);
        switch (LOWORD(wParam))
        {
        case SB_LINELEFT: //��������� ������ ������
            pos--;
            break;
        case SB_LINERIGHT: //��������� ������ ��������
            pos++;
            break;
        case SB_THUMBPOSITION: //��������� ������� �������
        case SB_THUMBTRACK: //������� ������� �������
            pos = HIWORD(wParam);
            break;
        default: break;
        }
        SetScrollPos(hWndScroll, SB_CTL, pos, TRUE); //�������� �������
        break;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK) {
            _itoa_s(pos, result_MOD2, 10); // ��������� ����� pos � ������ result_MOD2
            EndDialog(hDlg, 1);
        }
        if (LOWORD(wParam) == IDCANCEL) EndDialog(hDlg, 0);
        break;
    default: break;
    }
    return FALSE;
}