#include <windows.h>
//#include <iostream>


int WINAPI WinMain(
    HINSTANCE hInstance, //HINSTANCE - это номер запущенного приложения в памяти
    HINSTANCE hPrev, // hPrevInstance не имеет смысла. Он использовался в 16-разрядной версии Windows, но теперь всегда равен нулю
    LPSTR lpCmdLine, //lpCmdLine - строка char* - аргументы при запуске
    int nCmdShow // nCmdShow — это флаг, указывающий, является ли основное окно приложения свернуто, развернуто или отображается в обычном режиме.
    )
{
    /*
BOOL RegisterHotKey(
HWND hWnd,         // NULL как первый аргумент означает что MSG будет прислылаться не в какое то окно а просто в этот поток
int id,            // ID хоткея 
UINT fsModifiers,  // какие зажать кнопки 
UINT vk            // какую нажать клавишу
);
    */
   //сообщение WM_HOTKEY будет при нажатии
    if (!RegisterHotKey(NULL, 1, MOD_CONTROL, VK_SPACE))//когда будет данная комбинация то только она придет в этот поток и в эту программу
    {
        MessageBox(NULL, "cant regist Hotkey!", "error", MB_ICONERROR);
        return 1;
    }

    MSG msg; //cтруктура сообщения ,cюда windows будет класть информацию о событиях

    while (GetMessage(&msg, NULL, 0, 0)) 
    {
        //понять что делают и почему в while
        TranslateMessage(&msg); 
        DispatchMessage(&msg);
        if (msg.message == WM_HOTKEY)//пришло ли сообщение о том что зажата клавиша
        {
            // Если ID хоткея имеется
            if (msg.wParam == 1) {
                //MessageBox(NULL, "Ты нажал Ctrl + Space!", "Ура", MB_OK);
            }
        }
    }

    UnregisterHotKey(NULL, 1);
    return 0;
}