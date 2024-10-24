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
class Utilizador {
private:
    string nome = "Pepolim";
    string palavraPasse = "abc123def456";

public:
    void set(string nome, string palavraPasse) {
        this -> nome = nome;
        this -> palavraPasse = palavraPasse;
    }
    
    void get(){
        cout << nome << " " << palavraPasse << endl;
    }
}; // fim da classe, com o terminador ";"

int main() {
    dataCriadoPor("Nuno Pepolim");

    string nome;
    string pass;

    Utilizador novo_obj;
    cout << "Valores iniciais:" << endl;
    novo_obj.get();
    cout << "Novo nome: ";
    cin >> nome;
    cout << "Nova password: ";
    cin >> pass;
    cout << "Novos Valores:" << endl;
    novo_obj.set(nome,pass);
    novo_obj.get();

    return 0; 
}