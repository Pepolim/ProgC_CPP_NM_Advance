#include <iostream>
#include <string>

using namespace std;

// Funçao para mudar de linha
void mudaLinha() {
    cout << endl;
}

// Funçao para mostrar a data e hora de criaçao do programa
void dataCriadoPor(const string& nome) {
    time_t dataHora;
    time(&dataHora);

    mudaLinha();
    cout << "Este programa foi escrito por " << nome << ", em " << ctime(&dataHora);
}

// Definir a classe
class Pessoa {
public:
    //inicializaçao dos atributos
    string nome;
    int idade;
    float classificacao;
    
    //metodo onde diz se pode ou não se inscrever
    void podeFrequentar(){
        //printar os atributos
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << endl;
        cout << "Classificação: " << classificacao << endl;

        if (classificacao > 12 && idade >= 20)
            cout << "Pode inscrever-se" << endl;
        
        else{
            cout << "Não se pode inscrever" << endl;
            
            
        }

    }
}; // fim da classe, com o terminador ";"

int main() {
    dataCriadoPor("Nuno Pepolim");
    mudaLinha();

    //instanciação do objeto
    Pessoa eu;

    cout << "Nome: ";
    //receber a linha inteira
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