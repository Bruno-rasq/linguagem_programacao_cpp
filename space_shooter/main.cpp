#include "./src/core/engine2D.hpp"
#include "./src/core/player.hpp"
#include "./src/core/spaceBoard.hpp"

//compile command -> g++ main.cpp src/core/*.cpp -I src/core -o main.exe

using namespace std;

int main(){

    // board do game, manipula os estados visuais do frame game.
    SpaceBoardHandler::SpaceBoard board = SpaceBoardHandler::SpaceBoard();

    // instancia do objeto do jogador
    PlayerSpaceshipHandler::Player plyr = PlayerSpaceshipHandler::Player();

    // sprite contem coordenada e carcter da nave
    SpaceBoardHandler::Sprite sprite = plyr.getSprite();

    // desenha no frame a sprite do player
    board.draw(sprite.y, sprite.x, sprite.obj_ascii);

    //exibi o frame atual no console
    Engine2D::FrameBuffer::Render(board.getFrameBoard());

    return 0;
}