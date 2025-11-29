#include "./core_std.hpp"

/**
 *  Estrutura timer gerencia tempos para cada objeto, alguns possuem menos
 *  tempo, outros mais e isso dá sensação de velocidade no movimento dos 
 *  objetos.
*/
struct Timer
{
    /* Tempos de cada objeto: */
    const int8_t asteroid_speed = 3;
    const int8_t player_spped = 1;

    /* Relogio interno de cada objeto:*/
    int8_t asteroid_clock = 3;
    int8_t player_clock = 3;

    /**
     * Cada iteração do loop principal do game chama o clock 
     * reduzindo em 1 todos os relogios, quando um relogio chega em zero
     * habilita o movimento e reseta o tempo.
    */
    void clock();

    void resetAsteroid();
    void resetPlayer();
};