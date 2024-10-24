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
class Estudante {
// Declaracao de membros publicos (dados e funcoes) da classe
public:
    string nome;
    int idade;

    void mostrar() {
        cout << "Nome: " << nome << endl << "idade: " << idade << endl;
    }
}; // fim da classe, com o terminador ";"

int main() {
    dataCriadoPor("Nuno Pepolim");

    // Criar um objeto da classe
    Estudante novoEstudadnte;

    cin >> novoEstudadnte.nome >> novoEstudadnte.idade;
    novoEstudadnte.mostrar();

    return 0; 
}

