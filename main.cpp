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
    
    int menu, menuPesq;

    while (1){
        cout << "______MENU______" << endl << endl;

        cout << "1 - Cadastrar funcionario." << endl <<
                "2 - Editar funcionario." << endl <<
                "3 - Excluir funcionario." << endl <<
                "4 - Exibir todos os funcionarios." << endl <<
                "5 - Buscar funcionario." << endl <<
                "6 - Conceder aumento." << endl <<
                "7 - Calcular folha salarial" << endl <<
                "8 - Exibir folha salarial" << endl <<
                "0 - Sair do programa" << endl;

        cin >> menu;
        cin.ignore();

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
            gerenciador.editarFuncionario();

            break;
        case 3:
            gerenciador.excluirFuncionario();

            break;
        case 4:
            gerenciador.exibirTodosFuncionarios();
            break;
        case 5:
            cout << "Digite como você deseja buscar o funcionario: " << endl <<
                    "1 - Nome: " << endl <<
                    "2 - Data de ingresso: " << endl <<
                    "3 - Endereco" << endl;
            cin >> menuPesq;
            cin.ignore();

            gerenciador.buscarFuncionario(menuPesq);

            break;
        case 6:
            gerenciador.concederAumento();
            cout << "Aumento concedido para todos os funcionarios" << endl;

            break;
        case 7:
            
            break;
        case 0:
            cout << "saindo..." << endl;
            return 1;
        default:

            break;
        }

    }

    return 1;
}