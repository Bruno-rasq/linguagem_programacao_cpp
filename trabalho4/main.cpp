#include <iostream>
#include <sstream>

using namespace std;

string menu(){
    ostringstream oss;
    
    oss << "UFSC VEHICLE MANAGER SYSTEM (UVMS)\n";
    oss << "----------------------------------\n";
    oss << "1.cadastrar novo veiculo.\n";
    oss << "2.Cadastrar viagem para um veiculo.\n";
    oss << "3.Mostrar relatorio (geral).\n";
    oss << "4.Pesquisar veiculo (por placa).\n";
    oss << "5.sair.\n";

    return oss.str();
}

void menuTiposDeVeiculos(){
    ostringstream oss;
    
    oss << "ESCOLHA UM TIPO DE VEICULO PARAR CADASTRAR:\n";
    oss << "-------------------------------------------\n";
    oss << "1 - carro              (comporta ate 4 passageiros)\n";
    oss << "2 - onibus             (comporta ate 32 passageiros)\n";
    oss << "3 - caminhao leve      (carga maxima de 15000kg)\n";
    oss << "4 - caminhao pesado    (carga maxima de 30000kg)\n";

    cout << oss.str();
}

int main(){

    while(true){
        cout << menu() << endl;

        int opcao;
        cin >> opcao;

        switch (opcao){

            case 1:{

                cout << "cadastrar veiculo" << endl;
                break;
            }

            case 2:{

                cout << "cadastrar viagem" << endl;
                break;
            }

            case 3:{

                cout << "exibir relatorio" << endl;
                break;
            }

            case 4:{

                cout << "pesquisar veiculo" << endl;
                break;
            }

            case 5:{

                return;
            }
            
            default:
                break;
        }
    }

    return 0;
}