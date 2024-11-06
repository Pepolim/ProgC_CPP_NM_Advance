#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream arquivo_entrada("inteiros.txt");
    ofstream arquivo_saida("resultados.txt");
    int numero;
    int soma_pos = 0;
    int soma_neg = 0;

    if (arquivo_entrada.is_open() && arquivo_saida.is_open()) {
        while (arquivo_entrada >> numero) {
            if (numero > 0) {
                soma_pos += numero;
            } else if (numero < 0) {
                soma_neg += numero;
            }
        }
        arquivo_entrada.close();
        
        arquivo_saida << "Soma dos números positivos: " << soma_pos << endl;
        arquivo_saida << "Soma dos números negativos: " << soma_neg << endl;
        arquivo_saida.close();
        
        cout << "Resultados foram salvos em 'resultados.txt'" << endl;
    } else {
        cout << "Erro ao abrir os arquivos!" << endl;
    }

    return 0;
}
