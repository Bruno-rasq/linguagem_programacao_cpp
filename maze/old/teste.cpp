#include <conio.h>
#include <windows.h>
#include <cstdint>
#include <iostream>

uint16_t WaitForKeyBlockingConsole() {

    int ch = _getch(); // bloqueia console ate aparecer um caracter;

    // teclas "especiais" (setas, f-keys, etc..) retornam 0 ou 224 primeiro
    if(ch == 0 || ch == 224){
        int code = _getch();

        if(code == 72) return VK_UP;
        if(code == 80) return VK_DOWN;
        if(code == 75) return VK_LEFT;
        if(code == 77) return VK_RIGHT;

        return static_cast<uint16_t>(code);
    }

    if(ch == 27) return VK_ESCAPE;

    return static_cast<uint16_t>(ch);
}

int main(){

    std::cout << "esperando por teclas...\n";

    while(true){
        uint16_t key = WaitForKeyBlockingConsole();

        if(key == VK_ESCAPE) break;
        else if(key == VK_UP) std::cout << " cima \n";
        else if(key == VK_DOWN) std::cout << " baixo\n";
        else if(key == VK_LEFT) std::cout << " esquerda\n";
        else if(key == VK_RIGHT) std::cout << " direita\n";
        else std::cout << "outra tecla\n";
    }

    return 0;
}