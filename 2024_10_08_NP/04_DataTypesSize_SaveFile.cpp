#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    string nome_ficheiro;
    /**
     * Prints the message "Olá Mundo!" to the console.
     * This is a simple example of printing a message to the console.
     */
    cout << "Olá Mundo!" << endl << endl;

    /**
     * Prints the size in bytes of various data types to the console.
     * This code is used to demonstrate the memory usage of different C++ data types.
     */
    cout << "Tamanho em bytes dos tipos de dados:" << endl;
    cout << "char: " << sizeof(char) << " bytes" << endl;
    cout << "short: " << sizeof(short) << " bytes" << endl;
    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "long: " << sizeof(long) << " bytes" << endl;
    cout << "long long: " << sizeof(long long) << " bytes" << endl;
    cout << "float: " << sizeof(float) << " bytes" << endl;
    cout << "double: " << sizeof(double) << " bytes" << endl;
    cout << "long double: " << sizeof(long double) << " bytes" << endl;

    // Pedir ao utilizador o nome do ficheiro
    cout << "Introduza o nome do ficheiro a criar: ";
    cin >> nome_ficheiro;

    // concatenar a extensão ao nome
    nome_ficheiro += ".txt";  

    // Abrir o ficheiro para escrita
    ofstream ficheiro(nome_ficheiro);
    if (!ficheiro.is_open()) {
        cerr << "Erro ao abrir o ficheiro para escrita.\n";
        return 1;
    }

    // Gravar os dados no ficheiro
    ficheiro << "Olá Mundo!" << endl << endl;
    ficheiro << "Tamanho em bytes dos tipos de dados:" << endl;
    ficheiro << "char: " << sizeof(char) << " bytes" << endl;
    ficheiro << "short: " << sizeof(short) << " bytes" << endl;
    ficheiro << "int: " << sizeof(int) << " bytes" << endl;
    ficheiro << "long: " << sizeof(long) << " bytes" << endl;
    ficheiro << "long long: " << sizeof(long long) << " bytes" << endl;
    ficheiro << "float: " << sizeof(float) << " bytes" << endl;
    ficheiro << "double: " << sizeof(double) << " bytes" << endl;
    ficheiro << "long double: " << sizeof(long double) << " bytes" << endl;

    // Fechar o ficheiro após a escrita
    ficheiro.close();

    return 0;
}

