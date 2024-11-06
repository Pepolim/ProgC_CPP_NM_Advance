#include <iostream>
#include <string>

using namespace std;


/**
 * Represents a generic employee in the company.
 * Provides basic functionality for working and eating lunch.
 */
class Funcionario {
    protected:
        string nome;            ///< The name of the employee.
        int contribuinte;       ///< The tax ID number of the employee.

    public:
        //Constructs a new Funcionario object with the given name and tax ID.
        Funcionario(string _nome, int _contribuinte) {
            nome = _nome;
            contribuinte = _contribuinte;
        }

        //Performs the work-related activities of the employee.
        //This is a virtual function that can be overridden by derived classes.
        virtual void trabalhar() {
            cout << nome << " está a trabalhar." << endl;
        }

        //Indicates that the employee is eating lunch in the cafeteria.
        void almocar() {
            cout << nome << " está a comer no refeitorio." << endl;
        }
        
};

/**
 * Represents an internal employee of the company, who can work on projects.
 * Inherits from the base Funcionario class and adds project-related functionality.
 */
class interno : public Funcionario {
        float salario;          ///< The salary of the internal employee.
        float bonus;            ///< The bonus of the internal employee.
        bool projeto;           ///< Flag indicating if the employee is working on a project.
        string nomeProjeto;     ///< The name of the project the employee is working on.

    public:
        //Constructs a new interno object with the given name, tax ID, salary, and project status.
        interno(string _nome, int _contribuinte, float _salario, bool _projeto = false) : Funcionario(_nome, _contribuinte) {
            salario = _salario;     
        }

        /**
         * Indicates that the internal employee has started working on a new project.
         * @param _nomeProjeto The name of the project the employee is starting to work on.
         */
        void entrarProjeto(string _nomeProjeto) {
            nomeProjeto = _nomeProjeto;
            projeto = true;
            cout << nome << " está a trabalhar no projeto " << nomeProjeto << "." << endl;
        }
        /**
         * Indicates that the internal employee has finished working on a project.
         */
        void sairProjeto() {
            projeto = false;
            cout << nome << " está a saiu no projeto " << nomeProjeto << "." << endl;
        }

        /**
         * Performs the work-related activities of the internal employee.
         * If the employee is working on a project, it will be indicated in the output.
         */
        void trabalhar() {
            if (projeto == true)
            {
                cout << nome << " está a trabalhar no projeto " << nomeProjeto << "." << endl;
            }
            else
                cout << nome << " está a trabalhar." << endl;
        }
};
/// Represents a freelancer employee of the company, who can work on projects.
class freelancer : public Funcionario {
        int horasTrabalhadas = 0;   /// The number of hours the freelancer has worked.
        float valorHora = 5;        /// The hourly rate of the freelancer.
        bool turno;                 /// Flag indicating if the freelancer is working on a turn.
        string nomeTurno;           /// The name of the turn the freelancer is working on.
    public:
        //Constructs a new freelancer object with the given name, tax ID, hourly rate, and turn status.
        freelancer(string _nome, int _contribuinte, float _valorHora, bool _turno = false) : Funcionario(_nome, _contribuinte) {
            valorHora = _valorHora;
            turno = _turno;
        }

        //Indicates that the freelancer has started working on a new turn.
        void entrarTurno(string _nomeTurno) {
            nomeTurno = _nomeTurno;
            turno = true;

            cout << nome << " está a trabalhar no turno " << nomeTurno << "." <<endl;
        }

        //Indicates that the freelancer has finished working on a turn.
        void sairTurno() {
            turno = false;
            cout << nome << " está a saiu do turno " << nomeTurno << "." << endl;
        }

        //Performs the work-related activities of the freelancer.
        void trabalhar() {
            if (turno == true)
                cout << nome << " está a trabalhar no turno " << nomeTurno << "." <<endl;
            else
                cout << nome << " está a trabalhar" << endl;

            horasTrabalhadas++;
        }
};

int main() {
    // Create instances of the Funcionario, interno, and freelancer classes
    interno interno1("João", 123456789, 1000);
    
    // Create instances of the Funcionario, interno, and freelancer classes
    freelancer freelancer1("Pedro", 987654321, 10);

    interno1.trabalhar();
    interno1.almocar();
    interno1.entrarProjeto("Projeto A");
    interno1.trabalhar();
    interno1.sairProjeto();

    freelancer1.trabalhar();
    freelancer1.almocar();
    freelancer1.entrarTurno("Manha");
    freelancer1.trabalhar();
    freelancer1.sairTurno();


    return 0;
}
