#include <iostream>

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
class nomeClass {
// Declaracao de membros privados (dados e funcoes) da classe
private:
    int valorPrivado;

// Declaracao de membros publicos (dados e funcoes) da classe
public:
    int valorPublico;

    void funcaoPublica() {
        cout << "Funcao publica" << endl;
    }
}; // fim da classe, com o terminador ";"

int main() {
    dataCriadoPor("Nuno Pepolim");

    // Criar um objeto da classe
    nomeClass objetoNovo;

    // Podemos aceder e modificar os dados de um objeto publico
    objetoNovo.valorPublico = 10;

    // E tambem podemos usar as funcoes definidas dentro da classe
    objetoNovo.funcaoPublica();

    return 0; 
}

