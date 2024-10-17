#include <iostream>
#include <fstream>
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

string loadTextFromFile(const string& filename) {
    ifstream file(filename);
    string content;
    if (file.is_open()) {
        getline(file, content, '\0');
        file.close();
    } else {
        content = "Error: Unable to open file " + filename;
    }
    return content;
}

int main() {
    
    dataCriadoPor("Nuno Pepolim");
    mudaLinha();

    int choice;
    cout << "Menu de opcoes: " << endl;
    cout << "1. Exemplo de ponteiro simples" << endl;
    cout << "2. Exemplo de ponteiro com array" << endl;
    cout << "3. Exemplo de ponteiro para ponteiro" << endl;
    cout << "4. Sair" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "You chose option 1" << endl;
            mudaLinha();
            cout << loadTextFromFile("option1.txt") << endl;
            break;
        case 2:
            cout << "You chose option 2" << endl;
            mudaLinha();
            cout << loadTextFromFile("option2.txt") << endl;
            break;
        case 3:
            cout << "You chose option 3" << endl;
            mudaLinha();
            cout << loadTextFromFile("option3.txt") << endl;
            break;
        case 4:
            cout << "You chose option 4" << endl;
            
            break;
        default:
            cout << "Invalid choice" << endl;
    }

    mudaLinha();
return 0; } // Bug free