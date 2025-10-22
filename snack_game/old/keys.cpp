
#include <iostream>
#include <windows.h> // GetAsyncKeyState, VK_*
#include <cstdlib>

int main() {
    std::cout << "Pressione as setas. Pressione ESC para sair.\n";

    // armazena estado anterior para detectar apenas a transição (não manter pressionado)
    bool prevUp = false, prevDown = false, prevLeft = false, prevRight = false;
    bool running = true;

    while (running) {
        // --- Simula trabalho principal do programa (não-bloqueante) ---
        // aqui você pode atualizar game logic, processar rede, etc.
        // vou só dormir 10ms para não consumir 100% CPU
        Sleep(10);

        // --- Checa teclas de forma não-bloqueante ---
        int16_t up, down, left, right, esc;

        up = GetAsyncKeyState(VK_UP);
        down = GetAsyncKeyState(VK_DOWN);
        left = GetAsyncKeyState(VK_LEFT);
        right = GetAsyncKeyState(VK_RIGHT);
        esc = GetAsyncKeyState(VK_ESCAPE);

        //0x8000 é uma mascata binaria que representa o bit 15 (1 = ligado, 0 desligado)
        //operador bitwise (& and) compara bits em um dupla de binarios e retorna 1 se ambas
        //forem 1.
        bool curUp = (up & 0x8000) != 0;
        bool curDown = (down & 0x8000) != 0;
        bool curLeft = (left & 0x8000) != 0;
        bool curRight = (right & 0x8000) != 0;

        if (curUp && !prevUp) std::cout << "Seta para cima pressionada\n";
        if (curDown && !prevDown) std::cout << "Seta para baixo pressionada\n";
        if (curLeft && !prevLeft) std::cout << "Seta para esquerda pressionada\n";
        if (curRight && !prevRight) std::cout << "Seta para direita pressionada\n";
        
        prevUp = curUp;
        prevDown = curDown;
        prevLeft = curLeft;
        prevRight = curRight;

        // sair com ESC
        if ((esc & 0x8000) != 0) {
            std::cout << "ESC detectado. Saindo...\n";
            running = false;
        }
    }

    return 0;
}
