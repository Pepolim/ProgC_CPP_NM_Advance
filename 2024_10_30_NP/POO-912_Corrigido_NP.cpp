// Falta algum código
// Falta implementar métodos
// Tem erros de sintaxe e de lógica

#include <iostream>

using namespace std;

class DVD
{
private:
   float preco;

public:
   //MUDEI ISTO
   //pus Virtual porque o metodo é repetido nos filhos
   DVD(){
      preco = 10;
   }

   DVD(int preco){
      this -> preco = preco;
   }

   virtual void adquirir();
   virtual void devolver();
   void recibo();
   void imprimir(){
      cout << "algo" << endl;
   }
   
};

class DVDdeVender : public DVD
{
public:
   void adquirir();
   void devolver();
};

class DVDdeAlugar : public DVD
{
private:
   //Mudei Date para string
   string dataDevolucao;

public:
   void adquirir();
   void devolver();
};


class ColecaoDeDVDs
{
private:
   /// Pointer to an array of DVD objects.
   /// This array is used to store the DVDs in the ColecaoDeDVDs class.
   DVD *dvds;
   int numeroDVDs;

public:

   void acrescentarDVD(DVD *d)
   {
      dvds[numeroDVDs] = *d;
      numeroDVDs++;
   }

   // Imprimir todos os DVDs
   /*
   void relatorio()
   {
      for (int i = 0; i < numeroDVDs; i++)
      {
         dvds[i].imprimir();
      }
   }*/
};

int main()
{
   ColecaoDeDVDs c;

   
   c.acrescentarDVD(new DVDdeAlugar());
   c.acrescentarDVD(new DVDdeVender());
   //c.relatorio();

   return 0;
}