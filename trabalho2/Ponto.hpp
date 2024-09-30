#ifndef PONTO_HPP
#define PONTO_HPP

class Ponto2D {

    private:
        float x, y;

    public:
        Ponto2D(float x, float y);
        ~Ponto2D();

        float getX() const;
        float getY() const;
};

#endif