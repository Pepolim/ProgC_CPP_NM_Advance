#include <iostream>
#include <string>

using namespace std;

// Definir a classe
class outraClass {
public:
    int xInt;
    string sString;
}; // fim da classe, com o terminador ";"

int main() {
    outraClass outro_objeto;
    cout << sizeof(outro_objeto) << endl;

    return 0; 
}

