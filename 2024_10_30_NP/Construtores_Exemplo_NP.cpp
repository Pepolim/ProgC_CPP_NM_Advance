#include <iostream>

using namespace std;

class umaClasse {
public:
    int valor;
    
    // Construtor por omissão [by default] (sem parâmetros)
    umaClasse() {
        cout << "Evoca o construtor sem parâmetros." << endl;
        valor = 29;
    }

    // Construtor com parâmetros
    umaClasse(int umValor) {
        cout << "Evoca o construtor com um parâmetro (ou argumento)." << endl;
        valor = umValor;
    }

    // Método
    void mostraValor() {
        cout << "valor: " << valor << endl;
    }

};

int main() {
    umaClasse objeto_um;        
       objeto_um.mostraValor();

    umaClasse objeto_dois(10);     
       objeto_dois.mostraValor();

    return 0;
}