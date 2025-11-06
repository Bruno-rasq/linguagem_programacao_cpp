#include "./src/core/engine2D.hpp"
#include "./src/core/player.hpp"
#include "./src/core/spaceBoard.hpp"

using namespace std;


int main(){

    // board do game, manipula os estados visuais do frame game.
    SpaceBoardHandler::SpaceBoard board = SpaceBoardHandler::SpaceBoard();

    // instancia do objeto do jogador
    PlayerSpaceshipHandler::Player plyr = PlayerSpaceshipHandler::Player();

    // sprite contem coordenada e carcter da nave
    SpaceBoardHandler::Sprite sprite = plyr.getSprite();

    // desenha no frame a sprite do player
    board.draw(sprite.x, sprite.y, sprite.obj_ascii);

    vector<string> frame = board.getFrameBoard();

    Engine2D::FrameBuffer::Render(frame);

    return 0;
}