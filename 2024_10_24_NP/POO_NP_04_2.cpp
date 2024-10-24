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
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << endl;
        cout << "Classificação: " << classificacao << endl;

        if (classificacao > 12 && idade >= 20){
            mudaLinha();
            cout << "Pode inscrever-se" << endl;
        }
        else{
            mudaLinha();
            cout << "Não se pode inscrever" << endl;
        }
    }
}; // fim da classe, com o terminador ";"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Uso: " << argv[0] << " <nome> <idade> <classificacao>" << endl;
        return 1; // Retorna código de erro se o número de argumentos estiver incorreto
    }

    dataCriadoPor("Nuno Pepolim");

    Pessoa eu;

    // Pega os argumentos da linha de comando e converte os tipos necessários
    eu.nome = argv[1]; // Nome (string)
    eu.idade = atoi(argv[2]); // Idade (conversão de string para int)
    eu.classificacao = atof(argv[3]); // Classificação (conversão de string para float)

    mudaLinha();
    eu.podeFrequentar();
    mudaLinha();

    return 0; 
}