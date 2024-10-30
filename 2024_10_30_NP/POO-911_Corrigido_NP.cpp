// Estruturar o código
// Compilar e executar
// Corrigir erros

#include <iostream>

using namespace std;

class Retangulo
{
    int altura;
    int largura;
public:
    
    // Construtor.
    Retangulo(int alt, int larg){
        //alterar a altura e largura com os argumentos recebidos
        this -> altura = alt;
        this -> largura = larg;
    }
    //O QUE MUDEI!!!
    // Mudei os metodos que foram recriados depois desta classe de forma desnecessaria para dentro da classe
    // Assim o codigo fica metado do que antes estava como se pode ver no codigo comentado a seguir a classe
    void desenha(){
    for (int i = 0; i < altura; i++)
        {
            for (int j = 0; j < largura; j++)
                cout << '*';
            cout << "\n";
        } // Fim de for(int i = 0...
    }
    void desenha(char c){
    for (int i = 0; i < altura; i++)
        {
            for (int j = 0; j < largura; j++)
                cout << c;
            cout << "\n";
        } // Fim de for(int i = 0...
    }
}; // Fim de class Retangulo.

/* TUDO DESNECESSARIO E MAIS CONFUSO
// Implementação.
// Construtor.
Retangulo::Retangulo(int alt, int larg)
{
    altura = alt;
    largura = larg;
} // Fim de Retangulo::Retangulo()

// Função sobrecarregada.
void Retangulo::desenha()
// Desenha o retângulo preenchendo-o com o caractere '*'
{
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
            cout << '*';
        cout << "\n";
    } // Fim de for(int i = 0...
} // Fim de Retangulo::desenha()

void Retangulo::desenha(char c)
// Desenha o retângulo preenchendo-o
// com o caractere c recebido como argumento.
{
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
            cout << c;
        cout << "\n";
    } // Fim de for(int i = 0...
} // Fim de Retangulo::desenha(char c)*/

int main()
{
    // Cria um objeto da classe Retangulo.
    Retangulo ret(8, 12);
    // Desenha usando as duas versões de desenha()
    ret.desenha();
    cout << "\n\n";
    ret.desenha('A');
    return 0;
} // Fim de main()
//-------------------------------------------------