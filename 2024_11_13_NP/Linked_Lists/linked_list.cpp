#include <iostream>
using namespace std;

/*
Uma linked list (lista encadeada) é uma estrutura de dados linear composta por uma sequência de nós, 
onde cada nó armazena um valor e um ponteiro para o próximo nó da sequência. Diferente de um array, 
os elementos em uma linked list não ocupam posições contíguas na memória; cada nó pode estar em qualquer posição, 
pois eles são ligados entre si pelos ponteiros.

Características principais:
-Inserção e remoção dinâmicas: Adicionar ou remover elementos é eficiente, pois basta ajustar os ponteiros entre os nós.
-Sem tamanho fixo: Diferente de arrays, uma linked list cresce ou reduz conforme necessário, não ocupando espaço adicional.

Tipos de Linked Lists
-Singly Linked List: Cada nó aponta apenas para o próximo.
-Doubly Linked List: Cada nó aponta para o próximo e o anterior, facilitando a navegação em ambas as direções.
-Circular Linked List: O último nó aponta para o primeiro, criando um ciclo.

Vantagens e Desvantagens
-Vantagens: Flexibilidade no tamanho e facilidade para inserções e remoções.
-Desvantagens: Acesso sequencial (não se pode acessar diretamente um índice como em arrays) e uso de mais memória devido aos ponteiros extras.
*/

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    
public:
    LinkedList() : head(nullptr) {}
    
    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    void display() {
        Node<T>* current = head;
        while (current) {
            cout << current->data;
            if (current->next) cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }
    
    bool remove(T value) {
        if (!head) return false;
        
        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        
        Node<T>* current = head;
        while (current->next) {
            if (current->next->data == value) {
                Node<T>* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList<int> list;
    
    // Insert some values
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    
    cout << "Original list: ";
    list.display();
    
    // Remove a value
    list.remove(20);
    cout << "After removing 20: ";
    list.display();
    
    // Add more values
    list.insert(50);
    cout << "After adding 50: ";
    list.display();
    
    return 0;
}
