#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/*
Esta tarefa assíncrona tem como objetivo relembrar a função main(). 
Exatamente, é uma "função" e como tal pode aceitar parâmetros de entrada!
Até hoje não o temos feito, certo?
Mas podemos fazer... 
Vejam, em anexo, uma imagem de exemplo.
Então, escrevam código em C/C++ que mostre a utilização de parâmetros (ou argumentos).
Esses parâmetros devem ser visualizados no tradicional ecrã.
Mas também ser ser guardados num ficheiro de texto.
*/

using namespace std;

int main(int argc, char* argv[]) {
    string nome_ficheiro = "argumentos.txt";

    cout << "Número de argumentos: " << argc << endl;

    // Convertendo argv para um vector de strings para facilitar o manuseio
    vector<string> args(argv, argv + argc);

    // Abrir o ficheiro para escrita
    ofstream ficheiro(nome_ficheiro);
    if (!ficheiro.is_open()) {
        cerr << "Erro ao abrir o ficheiro para escrita.\n";
        return 1;
    }

    for (int i = 0; i < args.size(); ++i) {
        /// Prints the current argument index and value to the console.
        /// This line of code is part of a loop that iterates through the command line arguments passed to the program.
        /// The output will be in the format "Argumento i: arg_value", where i is the index of the argument and arg_value is the value of the argument.
        cout << "Argumento " << i << ": " << args[i] << endl;

        // Gravar os dados no ficheiro
        ficheiro << "Argumento " << i << ": " << args[i] << endl;
        
    }

    // Fechar o ficheiro após a escrita
    ficheiro.close();

    return 0;
}

