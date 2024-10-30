#include <iostream>

using namespace std;

class Carro {
public:
    string nomeCarro;
    
    // Construtor com um argumento
    Carro(string nomeCarro) {
        this -> nomeCarro = nomeCarro;
    }

    // Construtor de cópia
    Carro(Carro &outroCarro) {
        nomeCarro = outroCarro.nomeCarro;
    }

};

int main() {
    Carro carroOriginal("Fusca");
    cout << "Carro original: " << carroOriginal.nomeCarro << endl;

    Carro carroCopiado(carroOriginal);
    cout << "Carro copiado: " << carroCopiado.nomeCarro << endl;

    Carro outroCarroCopiado(carroOriginal);
    cout << "Segundo carro copiado: " << outroCarroCopiado.nomeCarro << endl;

    return 0;
}