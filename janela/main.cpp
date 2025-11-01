#include <windows.h>
using namespace std;


// hwnd -> handler to a window (identificador ou ponteiro) para uma janela
// uMsg -> representa o tipo de mensagem que chegou.
// wparam -> info especificas de eventos (teclas) 
// lparam -> info especificas de eventos (mouse)
// hInstance -> handle to a instance (identificador do programa executando)
// LPSTR -> tipos de ponteiros de string variando ANSI e unicode
//      LPSTR - (LP) long pointer - (S) string
//      LPCTR - (LP) long pointer - (C) const
//      LPWSTR - (LP) long pointer - (WS) string wide

// ncmdShow -> vem do SO, indica como a janela deve ser exibida.
//      maximizada -> SW_SHOWMAXIMIZED
//      minimizada -> SW_SHOWMINIMIZED
//      normal -> SW_SHOWNORMAL

// funcao de call back que trata as mensagens da janela.
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wpm, LPARAM lpm){
    switch(uMsg){

        // caso o usuario feche a janela.
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, uMsg, wpm, lpm);
}

// ponto de entrada de uma aplicação
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int ncmdShow){
    const char CLASS_NAME[] = "hello world";

    // estruturas que definem as cracteristicas da janela.
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;    // função que processa mentagens
    wc.hInstance = hInstance;       // ID do programa em execução
    wc.lpszClassName = CLASS_NAME;  // nome da classe instanciada

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,                          // estilos estendidos
        CLASS_NAME,                 // nome da classe registrada
        "titulo da janela",         // titulo
        WS_OVERLAPPEDWINDOW,        //
        CW_USEDEFAULT, 
        CW_USEDEFAULT, 
        300, 200,                   // tamanho da janela width e height
        NULL,                       // possue janela pai (null)
        NULL,                       // menu ou ID do controle
        hInstance,                  // instancia do APP
        NULL                        // dados extras (geralmente null)
    );

    // se der merda.
    if(hwnd == NULL){
        return 0;
    }

    ShowWindow(hwnd, ncmdShow);

    // exibe uma mensagem "hello world" assim que a janela aparece.
    MessageBox(
        hwnd,                       // janela pai
        "oi meu amor",              // texto da janela
        "fuck you",                 // titulo da janela
        MB_OK | MB_ICONINFORMATION  // tipo de caixa()
    );

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;

}