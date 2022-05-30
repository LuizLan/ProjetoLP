#include"Funcionario.h"
#include"Operador.h"
#include"Gerente.h"
#include"Diretor.h"
#include"Presidente.h"
#include"GerenciadorFuncionarios.h"

using namespace std;

int main(){
    int i;
    int menu, menuFolha;
    
    GerenciadorFuncionarios gerenciador;


    while (1){
        cout << "______MENU______" << endl << endl;

        cout << "1 - Cadastrar funcionario." << endl <<
                "2 - Editar funcionario." << endl <<
                "3 - Excluir funcionario." << endl <<
                "4 - Exibir todos os funcionarios." << endl <<
                "5 - Buscar funcionario." << endl <<
                "6 - Conceder aumento." << endl <<
                "7 - Exibir folha salarial" << endl <<
                "0 - Sair do programa" << endl;

        cin >> menu;
        cin.ignore();

        switch (menu){
        case 1:

            gerenciador.cadastrarFuncionario();
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
            gerenciador.buscarFuncionario();
            break;
        case 6:
            gerenciador.concederAumento();
            cout << "Aumento concedido para todos os funcionarios" << endl;

            break;
        case 7:
        
            
            break;
        case 8:

            break;
        case 0:
            cout << "saindo..." << endl;
            return 1;
        default:
            cout << "Opção inválida, insira um valor de 1 a 8." << endl;
            break;
        }
    }
    return 1;
}