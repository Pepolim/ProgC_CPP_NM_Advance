#include <iostream>
#include <string>

using namespace std;

// Função para mudar de linha
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


/**
 * The main entry point of the program. This function takes command-line arguments and creates a 
 * Pessoa object with the provided name, age, and classification. It then calls the podeFrequentar() 
 * method on the Pessoa object to determine if the person can enroll.
 */
int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Uso: " << argv[0] << " <nome> <idade> <classificacao>" << endl;
        return 1; // Retorna código de erro se o número de argumentos estiver incorreto
    }
    //função para mostrar a data e hora de criaçao do programa
    dataCriadoPor("Nuno Pepolim");

    //instanciação do objeto
    Pessoa eu;

    // Pega os argumentos da linha de comando e converte os tipos necessários
    eu.nome = argv[1]; // Nome (string)
    eu.idade = atoi(argv[2]); // Idade (conversão de string para int)
    eu.classificacao = atof(argv[3]); // Classificação (conversão de string para float)

    mudaLinha();
    // Chama o método podeFrequentar() no objeto eu
    eu.podeFrequentar();
    mudaLinha();

    return 0; 
}