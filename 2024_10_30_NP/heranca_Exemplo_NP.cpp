#include <iostream>
#include <string>

using namespace std;

class Animal {
    protected:
        string nome;

    public:
        Animal(string _nome) : nome(_nome) {}

        void come() {
            cout << nome << " está a comer." << endl;
        }
        
};

class mamifero : public Animal {
    protected:
        int numPatas;

    public:
        mamifero(string _nome, int _numPatas) : Animal(_nome) 
        {
            numPatas = _numPatas;
        }

        void anda() {
            cout << nome << " está a caminhar em " << numPatas << " patas." << endl;
        }
};

class gato : public mamifero {
    public:
        gato(string _nome, int _numPatas) : mamifero(_nome, _numPatas) {}

        void mia() {
            cout << nome << " está a miar." << endl;
        }
};

int main() {

    gato meuGato("Loki", 4);

    meuGato.come();
    meuGato.anda();
    meuGato.mia();

    return 0;
}
