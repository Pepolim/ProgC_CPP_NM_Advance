#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    string nome_ficheiro;
    int hora = 0, min = 0, seg_atual = 0, seg_total = 0;
    
    /**
     * Prompts the user to enter the current hour, minutes, and seconds, and stores the values in the corresponding variables.
     */
    cout << "Introduza a hora atual: ";
    cin >> hora;
    
    cout << "Introduza os minutos atuais: ";
    cin >> min;

    cout << "Introduza os segundos atuais: ";
    cin >> seg_atual;

    if (hora < 23 && hora >= 1 && min < 60 && min >= 0 && seg_atual < 60 && seg_atual >= 0)
    {
        //Calculates the total number of seconds since the start of the day based on the provided hour, minute, and second values.
        seg_total = (hora * 3600) + (min * 60) + seg_atual;

        cout << "O total de segundos desde o inicio do dia ate a hora atual são: " << seg_total << endl;

        // Pedir ao utilizador o nome do ficheiro
        cout << "Introduza o nome do ficheiro a criar: ";
        cin >> nome_ficheiro;

        nome_ficheiro += ".txt";  // concatenar a extensão ao nome

        // Abrir o ficheiro para escrita
        ofstream ficheiro(nome_ficheiro);
        if (!ficheiro.is_open()) {
            cerr << "Erro ao abrir o ficheiro para escrita.\n";
            return 1;
        }

        // Gravar os dados no ficheiro
        ficheiro << "Segundos: " << seg_total << endl;

        // Fechar o ficheiro após a escrita
        ficheiro.close();

    }
    else
    {
        cout << "Valores invalidos!";
    }
    
    return 0;
}