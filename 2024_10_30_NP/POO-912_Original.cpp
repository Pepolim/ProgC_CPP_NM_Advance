// Falta algum código
// Falta implementar métodos
// Tem erros de sintaxe e de lógica

#include<iostream>

using namespace std;

class DVD {
private:
   float preco;
public:
   void adquirir();
   void devolver();
   void recibo();
};

class DVDdeVender : public DVD {
public:
   void adquirir();
   void devolver();
};

class DVDdeAlugar : public DVD {
private:
   Date dataDevolucao;
public:
   void adquirir();
   void devolver();
};

class ColecaoDeDVDs {
private:
   DVD* dvds;
   int numeroDVDs;
public:
   void acrescentarDVD(DVD* d) {
      dvds[numeroDVDs] = *d;
      numeroDVDs++; 
   }

   // Imprimir todos os DVDs 
   void relatorio() {
      for (int i=0; i < numeroDVDs; i++) {
         dvds[i].imprimir();
      }
   }
};

int main() {
   ColecaoDeDVDs c;
   
   c.acrescentarDVD(new DVDdeAlugar());
   c.acrescentarDVD(new DVDdeVender());
   c.relatorio();
   
   return 0;
}