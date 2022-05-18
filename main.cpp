#include"Funcionario.h"
#include"Operador.h"
#include"Gerente.h"
#include"Diretor.h"
#include"Presidente.h"
#include"GerenciadorFuncionarios.h"

using namespace std;

int main(){
    
    int i;

    GerenciadorFuncionarios gerenciador;
    string codigo, nome, endereco, telefone, dataIni, designacao;
    double salario;
    int tipo;
    
    int menu;

    cout << "______MENU______" << endl << endl;

    cout << "1 - Cadastrar funcionario." << endl <<
            "2 - Editar funcionario." << endl <<
            "3 - Excluir funcionario." << endl <<
            "4 - Exibir funcionario." << endl <<
            "5 - Buscar funcionario." << endl <<
            "6 - Conceder aumento." << endl <<
            "7 - Calcular folha salarial" << endl <<
            "8 - Exibir folha salarial" << endl;

    cin >> menu;

    switch (menu){

    case 1:
        cout << "Digite o tipo do Funcionario: "<< endl <<
                "1 - operario." << endl <<
                "2 - gerente." << endl <<
                "3 - diretor." << endl << 
                "4 - presidente." << endl;

        cin >> tipo;
        cin.ignore();

        gerenciador.cadastrarFuncionario(tipo);
        break;    
    case 2:

        break;

    case 3:

        break;
    case 4:

        break;
    default:

        break;
    }

    return 1;
}