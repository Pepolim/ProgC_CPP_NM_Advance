#include <iostream>
#include <ctime>
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

int main() {
   
    dataCriadoPor("Nuno Pepolim");
    mudaLinha();

    int numeros[5] = {10, 20, 30, 40, 50};

    cout << "Array criado com 5 elementos (10, 20, 30, 40, 50)" << endl;
    mudaLinha();
   
    /**
     * Initializes a pointer `ptr` to the first element of the `numeros` array.
     */
    cout << "Incializamos 1 ponteiro apontado ao primeiro elemento do array" << endl;
    int *ptr = numeros;

    mudaLinha();
    cout << numeros[0] << endl;
    cout << *ptr << endl;
    
    mudaLinha();
    ptr++;
    cout << "+1 no ponteiro" << endl;
    cout << *ptr << endl;

    mudaLinha();
    ptr--;
    cout << "-1 no ponteiro" << endl;
    cout << *ptr << endl;

    mudaLinha();
    cout << "+2 no ponteiro" << endl;
    cout << *(ptr + 2) << endl;

    mudaLinha();
    return 0;
}