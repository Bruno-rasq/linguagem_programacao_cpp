#include <cmath>
#include "Triangulo.hpp"
#include "Ponto.hpp"

using namespace std;

Ponto criarPonto(float x, float y){
    Ponto ponto;
    ponto.setXY(x, y);
    return ponto;
}

float calcularSemiPerimetro(float l1, float l2, float l3){
    return (l1 + l2 + l3) / 2;
}

float quadrado(float a){
    return a * a;
}

float calcularLado(const Ponto p1, const Ponto p2){
    float vertice = sqrt(
        quadrado(p2.getX() - p1.getX()) + quadrado(p2.getY() - p1.getY())
    );

    return vertice;
}

float calcularArea(float l1, float l2, float l3){

    float s = calcularSemiPerimetro(l1, l2, l3); //semi perimetro;

    float area = sqrt(s * (s - l1) * (s - l2) * (s - l3)); 

    return area;
}

float Triangulo::getArea() const {
    return this->area;
}

float Triangulo::getPerimetro() const {
    return this->perimetro;
}

Triangulo::Triangulo(float lado1, float lado2, float lado3){

    //verificar se os valores formam um triangulo valido
    if(lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1){
        this->vertice1 = lado1;
        this->vertice2 = lado2;
        this->vertice3 = lado3;

        this->perimetro = lado1 + lado2 + lado3;
        this->area = calcularArea(this->vertice1, this->vertice2, this->vertice3);
    }
}

Triangulo::Triangulo(const Ponto p1, const Ponto p2, const Ponto p3): Triangulo(
    //delegação de construtores... enviando os dados para o construtor de vertices
    calcularLado(p1, p2), calcularLado(p2, p3), calcularLado(p3, p1)
){}

Triangulo::Triangulo(float x1, float y1, float x2, float y2, float x3, float y3): Triangulo(
    //delegação de construtores... enviando os dados para o construtor de pontos
    criarPonto(x1, y1), criarPonto(x2, y2), criarPonto(x3, y3)
){}