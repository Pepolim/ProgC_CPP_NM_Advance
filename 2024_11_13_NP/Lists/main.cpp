#include <iostream>
#include "List.h"

using namespace std;

/*
Uma lista é uma estrutura de dados que armazena uma coleção ordenada de elementos, 
onde cada elemento ocupa uma posição específica. Ela pode ser implementada de diferentes formas, 
sendo as mais comuns arrays (listas de tamanho fixo e acesso direto) e listas encadeadas (com tamanho dinâmico e acesso sequencial).

Características principais:
-Ordenação: Os elementos são organizados em sequência, o que permite acessar e manipular os itens pela sua posição.

-Flexibilidade: Em listas dinâmicas, é possível inserir, remover e redimensionar facilmente os elementos.

Uso das Listas:
Listas são ideais para armazenar e organizar dados em sequência e são usadas amplamente em algoritmos, 
gerenciamento de dados e tarefas onde a ordem dos elementos é importante.
*/

int main() {
    List list;
    
    // Insert elements
    list.Insert(0, 10);
    list.Insert(1, 20);
    list.Insert(2, 30);
    
    // Print elements
    cout << "List elements:" << endl;
    for(int i = 0; i < list.Count(); i++) {
        cout << list.Get(i) << " ";
    }
    cout << endl;
    
    // Remove middle element
    list.Remove(1);
    
    // Print updated list
    cout << "After removing index 1:" << endl;
    for(int i = 0; i < list.Count(); i++) {
        cout << list.Get(i) << " ";
    }
    cout << endl;
    
    return 0;
}
