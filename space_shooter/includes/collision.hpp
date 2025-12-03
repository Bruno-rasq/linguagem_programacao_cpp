#ifndef __COLLISIONS__HPP__
#define __COLLISIONS__HPP__

#include "core_std.hpp"
#include "core_types.hpp"

#include "moviment.hpp"
#include "framer.hpp"
#include "asteroids.hpp"
#include "game.hpp"

using namespace TYPING;


/**
 *  Para checar colisão é criado um hashmapque armazena as coordenadas
 *  dos objetos do game, e um vetor de IDS. Quando uma chave possue 
 *  mais de um objeto ocorre uma colisão. 
 * 
 *  Coodenadas xy passam por uma função hash que tranforma em um
 *  inteiro.
 * 
 *  Alem disso é criado um hash de objetos já processados para cada co-
 *  lisão, assim evita multiplas aplicações de colisão em um omesmo ob-
 *  jeto por instancia do frame
*/
Collisions checkCollisions(
    Sprite& player, Asteroids& asteroids, Shoots& shoots);

#endif