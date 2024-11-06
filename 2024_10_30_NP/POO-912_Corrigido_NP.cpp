// Falta algum código
// Falta implementar métodos
// Tem erros de sintaxe e de lógica

#include <iostream>

using namespace std;

class DVD
{
protected:
   string titulo;
   float preco;
public:
   DVD(string t, float p)
   {
      this->titulo = t;
      this->preco = p;
   }

   virtual void adquirir()
   {
      cout << "Não é possivel adquirir o DVD por este meio" << endl;
   }
   virtual void devolver()
   {
      cout << "Não é possivel devolver o DVD por este meio" << endl;
   }
   void getTitulo()
   {
      cout << "Titulo: " << titulo << endl;
   }
   virtual void recibo()
   {
      cout << "Titulo: " << titulo << endl;
      cout << "Preço: " << preco << endl;
   }
};

class DVDdeVender : public DVD
{
   string tipo = "Venda";

public:
   DVDdeVender(string t, float p) : DVD(t, p)
   {
   }

   void adquirir()
   {
      cout << "DVD adquirido com sucesso" << endl
           << "\t" << titulo << " - " << preco << endl;
   }
   void devolver()
   {
      cout << "Nao é possivel devolver DVDs comprados" << endl;
   }
   void recibo()
   {
      cout << "Tipo: " << tipo << endl;
      cout << "Titulo: " << titulo << endl;
      cout << "Preço: " << preco << endl;
   }
};

class DVDdeAlugar : public DVD
{
private:
   int diasAluguer = 10;
   time_t dataDePedido;
   time_t dataDevolucao;
   // double diferencaSegundos;
   string tipo = "Aluguer";

public:
   DVDdeAlugar(string t, float p) : DVD(t, p)
   {
   }

   void adquirir()
   {
      time(&dataDePedido);

      dataDevolucao = dataDePedido;
      // Adiciona os dias de aluguer em segundos
      dataDevolucao += diasAluguer * 24 * 60 * 60;

      // diferencaSegundos = difftime(dataDevolucao, dataDePedido);

      cout << "DVD adquirido com sucesso" << endl
           << "\t" << titulo << " - " << preco << endl;
      cout << "Data de devolucao: " << ctime(&dataDevolucao) << endl;
   }
   void devolver()
   {
      time_t dataHora;
      time(&dataHora);

      // diferencaSegundos = difftime(dataDevolucao, dataHora);

      // se for superior ainda falta para chegar ao tempo de devoluçao
      if (/*diferencaSegundos >= 0*/ ctime(&dataDevolucao) >= ctime(&dataHora))
         cout << "DVD devolvido com sucesso" << endl;
      else
         cout << "Ultrapassou o tempo de devoluçao. Tem que pagar mais 20'%' do valor pretendido" << endl;
   }
   void recibo()
   {
      cout << "Tipo: " << tipo << endl;
      cout << "Titulo: " << titulo << endl;
      cout << "Preço: " << preco << endl;
   }
};

class ColecaoDeDVDs
{
private:
   DVD **dvds; // Array of DVD pointers to support polymorphism
   int capacidade;
   int numeroDVDs;

public:
   ColecaoDeDVDs(int capacidadeInicial = 10)
   {
      capacidade = capacidadeInicial;
      numeroDVDs = 0;
      dvds = new DVD *[capacidade];
   }
   /*
   ~ColecaoDeDVDs()
   {
      // Clean up memory
      for (int i = 0; i < numeroDVDs; i++)
      {
         delete dvds[i];
      }
      delete[] dvds;
   }
   */
   void acrescentarDVD(DVD *d)
   {
      if (numeroDVDs >= capacidade)
      {
         // Expand array if needed
         /// Dynamically allocates a new array of DVD pointers with twice the current capacity.
         /// This is used to expand the array when the number of DVDs exceeds the current capacity.
         DVD **temp = new DVD *[capacidade * 2];
         for (int i = 0; i < numeroDVDs; i++)
         {
            temp[i] = dvds[i];
         }
         delete[] dvds;
         dvds = temp;
         capacidade *= 2;
      }
      dvds[numeroDVDs++] = d;
   }
   void colecao()
   {
      cout << "\n=== DVDs na Coleção ===" << endl;
      for (int i = 0; i < numeroDVDs; i++)
      {
         cout << "\nDVD #" << (i + 1) << ":" << endl;
         dvds[i]->getTitulo();
      }
   }

   void consultar(int indice)
   {
      cout << "\n=== Relatório do DVDs na Coleção ===" << endl;
      dvds[indice]->recibo();
   }

   void relatorio()
   {
      cout << "\n=== Relatório de DVDs na Coleção ===" << endl;
      for (int i = 0; i < numeroDVDs; i++)
      {
         cout << "\nDVD #" << (i + 1) << ":" << endl;
         //dvds[i]->getTitulo();
         dvds[i]->recibo();
         // dvds[i]->adquirir();
         // dvds[i]->devolver();
      }
   }
};

int main()
{
   /*
   DVD um("Um", 10.0);
   DVDdeVender dois("Dois", 20.0);
   DVDdeAlugar tres("Tres", 10.0);

   um.adquirir();
   um.devolver();
   um.recibo();
   dois.adquirir();
   dois.devolver();
   dois.recibo();
   tres.adquirir();
   tres.devolver();
   tres.recibo();
   */
   string titulo;
   float preco;
   char tipo;
   char insercao = 's';
   int indice;

   ColecaoDeDVDs colecao;

   while (insercao == 's' || insercao == 'S')
   {
      cout << "Deseja inserir um DVD para vender ou alugar? (V/A): ";
      cin >> tipo;
      if (tipo == 'V' || tipo == 'v'){
         cout << "Insira o titulo do DVD: ";
         cin >> titulo;
         cout << "Insira o preco do DVD: ";
         cin >> preco;
         colecao.acrescentarDVD(new DVDdeVender(titulo, preco));
      }
      else if (tipo == 'A' || tipo == 'a'){
         cout << "Insira o titulo do DVD: ";
         cin >> titulo;
         cout << "Insira o preco do DVD: ";
         cin >> preco;
         colecao.acrescentarDVD(new DVDdeAlugar(titulo, preco));
      }
      else{
         cout << "Tipo de DVD inválido. Por favor, insira V ou A." << endl;
      }
      cout << "Deseja continuar a insercao de DVDs? (S/N): ";
      cin >> insercao;
   }

   colecao.colecao();
   
   cout << "\nDeseja consultar um Dvd? (S/N): ";
   cin >> insercao;
   while (insercao == 's' || insercao == 'S'){
      cout << "Insira o indice do DVD: ";
      cin >> indice;
      colecao.consultar(indice - 1);

      cout << "\nDeseja continuar a consulta? (S/N): ";
      cin >> insercao;
   }
   cout << "\nDeseja ver o relatório da colecao? (S/N): ";
   cin >> insercao;
   if (insercao == 'S' || insercao == 's')
      colecao.relatorio();

   return 0;
}