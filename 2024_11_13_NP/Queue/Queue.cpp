#include <iostream>
using namespace std;

/*
Uma queue (fila) é uma estrutura de dados que segue o princípio FIFO (First In, First Out), 
onde o primeiro elemento inserido é o primeiro a ser removido. 
Ela é como uma fila de pessoas: o primeiro a entrar é o primeiro a sair.

Operações principais:
-Enqueue: Adiciona um elemento ao final da fila.
-Dequeue: Remove o elemento do início da fila.
-Front/Peek: Permite visualizar o elemento no início sem removê-lo.

Características:
-Uso em Processamento de Tarefas: Filas são ideais para gerenciar processos em ordem de chegada, 
como em sistemas de impressão, processamento de tarefas e algoritmos de busca em largura (BFS) em grafos.
*/

class Queue {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool enqueue(int value) {
        if (rear >= MAX_SIZE - 1) {
            cout << "Queue is full!" << endl;
            return false;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = value;
        return true;
    }

    bool dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return false;
        }
        front++;
        return true;
    }

    int peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    
    // Adding elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    // Display queue
    cout << "After enqueueing elements:" << endl;
    queue.display();
    
    // Peek front element
    cout << "Front element: " << queue.peek() << endl;
    
    // Remove element
    queue.dequeue();
    
    cout << "After dequeuing one element:" << endl;
    queue.display();
    
    // Check if empty
    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}
