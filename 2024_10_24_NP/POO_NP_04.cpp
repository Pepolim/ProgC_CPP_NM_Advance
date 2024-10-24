#include <iostream>
#include <string>

using namespace std;

void mudaLinha() {
    cout << endl;
}

void dataCriadoPor(const string& nome) {
    time_t dataHora;
    time(&dataHora);

    mudaLinha();
    cout << "Este programa foi escrito por " << nome << ", em " << ctime(&dataHora);
}

// Definir a classe
class Pessoa {
public:
    string nome;
    int idade;
    float classificacao;
    
    void podeFrequentar(){
        if (classificacao > 12 && idade >= 20)
            cout << "Pode inscrever-se" << endl;
        
        else
            cout << "Não se pode inscrever" << endl;

    }
}; // fim da classe, com o terminador ";"

int main() {
    dataCriadoPor("Nuno Pepolim");

    Pessoa eu;

    cout << "Nome: ";
    getline(cin, eu.nome);

    cout << "Idade: ";
    cin >> eu.idade;

    cout << "Classificacao: ";
    cin >> eu.classificacao;

    mudaLinha();
    eu.podeFrequentar();
    mudaLinha();

    return 0; 
}