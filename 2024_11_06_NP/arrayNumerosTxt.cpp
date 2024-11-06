#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream ficheiro("inteirosPositivos.txt");
    ofstream abaixoMedia("numerosAbaixoMedia.txt");
    ofstream acimaMedia("numerosAcimaMedia.txt");

    /// Stores a vector of integers read from a file.
    vector<int> numeros;
    int numero;
    double soma = 0;
    
    /// Reads integers from the file "inteirosPositivos.txt" and stores them in the `numeros` vector.
    /// The loop continues until all integers have been read from the file.
    while (ficheiro >> numero) {
        numeros.push_back(numero);
        soma += numero;
    }
    
     /// Calculates the average of the numbers read from the file and stored in the `numeros` vector.
    double media = soma / numeros.size();
    
    cout << "Números lidos do ficheiro:" << endl;
    /// Iterates through each number in the `numeros` vector and performs the following actions:
    /// - Prints the current number to the console.
    /// - Checks if the current number is less than the calculated average.
    ///   - If so, writes the number to the "numerosAbaixoMedia.txt" file.
    /// - Otherwise, writes the number to the "numerosAcimaMedia.txt" file.
    for (int num : numeros) {
        cout << num << " ";
        if (num < media) {
            abaixoMedia << num << endl;
        } else {
            acimaMedia << num << endl;
        }
    }
    cout << endl;
    
    cout << "Média dos números: " << media << endl;
    
    ficheiro.close();
    abaixoMedia.close();
    acimaMedia.close();
    return 0;
}
