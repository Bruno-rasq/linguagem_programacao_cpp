#include <iostream>
#include "Ingresso.hpp"
#include "IngressoVip.hpp"

using namespace std;

int main(){

    Ingresso ingress_normal("show de rock", 35.50f);
    IngressoVip ingress_vip("show de rock", 35.50f, "primeiroa fila", 25.00f);

    cout << ingress_normal.toString() << endl;
    cout << ingress_vip.toString() << endl;
    
    return 0;
}