#include <iostream>
using namespace std;

/*
Um stack (pilha) é uma estrutura de dados que segue o princípio LIFO (Last In, First Out), 
onde o último elemento inserido é o primeiro a ser removido. 
Imagine uma pilha de pratos: o último prato colocado em cima é o primeiro a ser retirado.

Operações principais:
-Push: Adiciona um elemento ao topo da pilha.
-Pop: Remove o elemento do topo.
-Peek: Permite visualizar o elemento no topo sem removê-lo.

Características:
-Uso em Recursão: Stacks são amplamente usadas em chamadas recursivas, 
pois armazenam o histórico das chamadas em uma estrutura LIFO.

-Controle de Fluxo: Comum em algoritmos de navegação, como backtracking, 
e também em operações como desfazer (undo) em editores de texto.

*/

class Stack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow!" << endl;
            return false;
        }
        arr[++top] = value;
        return true;
    }

    bool pop() {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
            return false;
        }
        top--;
        return true;
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return (top < 0);
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    
    // Adding elements
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    // Display stack
    cout << "After pushing elements:" << endl;
    stack.display();
    
    // Peek top element
    cout << "Top element: " << stack.peek() << endl;
    
    // Remove element
    stack.pop();
    
    cout << "After popping one element:" << endl;
    stack.display();
    
    // Check if empty
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}
