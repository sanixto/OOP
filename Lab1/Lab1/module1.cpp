#include "framework.h"
#include <math.h>
#include "module1.h"

//объявление внутришних функций модуля
static BOOL CALLBACK  DlgProc_MOD1(HWND, UINT, WPARAM, LPARAM);

//функция для экспорт
int EnterText_MOD1(HINSTANCE hInst, HWND hWnd)
{
    return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_MODE1), hWnd, DlgProc_MOD1);
}

//внутрешняя функция диалогового окна
BOOL CALLBACK DlgProc_MOD1(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    switch (iMessage)
    {
    case WM_INITDIALOG:
        //. . . ініціалізуємо елементи вікна діалогу (якщо потрібно)
        break;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK)
        {
            //. . . зчитуємо вміст елеменітів вікна (якщо потрібно)
            EndDialog(hDlg, 1);
            break;
        }
        if (LOWORD(wParam) == IDCANCEL) EndDialog(hDlg, 0);
        break;
    default: break;
    }
    return FALSE;
}
