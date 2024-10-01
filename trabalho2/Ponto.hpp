#ifndef PONTO_HPP
#define PONTO_HPP

class Ponto {

    private:
        float x, y;

    public:
        float getX() const;
        float getY() const;

        void setXY(float x, float y);
};

#endif