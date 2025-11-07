#include "./engine2D.hpp"

namespace Engine2D {

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

    void FrameBuffer::DrawSprite(const GSprite sprite) {
        this->current_frame[sprite.y][sprite.x] = sprite.obj_ascii;
    };

    void FrameBuffer::ClearSprite(GSprite sprite) {
        this->current_frame[sprite.y][sprite.x] = ' ';
    };
}