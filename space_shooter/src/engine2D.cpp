#include "../headers/engine2D.hpp"

namespace Engine2D {

    //============================================================================
    //
    //  Estrutura dos sprites
    //
    //============================================================================

    Sprite::Sprite(): row(0), col(0){};

    Sprite::Sprite(uint8_t row, uint8_t col, const char obj){
        this->row = row;
        this->col = col;
        this->obj = obj;
    };

    //============================================================================
    //
    //  Estrutura das coordenadas
    //
    //============================================================================

    Coordinates::Coordinates(): row(0), col(0){};
    
    Coordinates::Coordinates(uint8_t row, uint8_t col){
        this->row = row;
        this->col = col;
    };

    void Coordinates::MOV(const uint16_t& key){

        int dy = this->row;
        int dx = this->col;

        if(key == VK_UP)    { dy--; }
        if(key == VK_DOWN)  { dy++; }
        if(key == VK_LEFT)  { dx--; }
        if(key == VK_RIGHT) { dx++; }

        if(inBounds(dy, dx)){
            this->row = dy;
            this->col = dx;
        }
    };


    bool inBounds(const uint8_t row, const uint8_t col){

        return (0 <= row && row < BOARDHEIGTH 
                && 0 <= col && col < BOARDWIDTH);
    };

    //desabilitei...
    void wrapAround(uint8_t& row, uint8_t& col){

        if(col < 0)               col = BOARDWIDTH - 1;
        if(col >= BOARDWIDTH)     col = 0;
        if(row < 0)               row = BOARDHEIGTH - 1;
        if(row >= BOARDHEIGTH)    row = 0;
    };


    //============================================================================
    //
    //  Controles
    //
    //============================================================================


    uint16_t KeyboardInput::capturePressedKey(){

        const int KEY_MSB_MASK = 0x8000; //MSB -> most significant bit

        if((GetAsyncKeyState(VK_UP)     & KEY_MSB_MASK) != 0) return VK_UP;
        if((GetAsyncKeyState(VK_DOWN)   & KEY_MSB_MASK) != 0) return VK_DOWN;
        if((GetAsyncKeyState(VK_LEFT)   & KEY_MSB_MASK) != 0) return VK_LEFT;
        if((GetAsyncKeyState(VK_RIGHT)  & KEY_MSB_MASK) != 0) return VK_RIGHT;
        if((GetAsyncKeyState(VK_SPACE)  & KEY_MSB_MASK) != 0) return VK_SPACE;
        if((GetAsyncKeyState(VK_ESCAPE) & KEY_MSB_MASK) != 0) return VK_ESCAPE;

        return 0;
    };

    //============================================================================
    //
    //  Frames
    //
    //============================================================================

    FrameBuffer::FrameBuffer(){
        for(size_t i = 0; i < BOARDHEIGTH; i++)
            this->current_frame.push_back(std::string(BOARDWIDTH, ' '));
    };

    void FrameBuffer::Render() const {
        
        std::stringstream buff;

        buff << std::string(BOARDWIDTH + 2, '_') << "\n";

        for(const std::string& line : this->current_frame)
            buff <<  "|" << line << "|\n";
        
        buff << "|" << std::string(BOARDWIDTH, '_') << "|\n";

        std::cout << buff.str();
    };

    void FrameBuffer::DrawSprite(const Sprite sprite) {
        this->current_frame[sprite.row][sprite.col] = sprite.obj;
    };

    void FrameBuffer::ClearSprite(Sprite sprite) {
        this->current_frame[sprite.row][sprite.col] = ' ';
    };


    //============================================================================
    //
    //  game principal loop (motor)
    //
    //============================================================================

    
}