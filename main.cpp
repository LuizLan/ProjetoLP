#include"Funcionario.h"
#include"Operador.h"
#include"Gerente.h"
#include"Diretor.h"
#include"Presidente.h"

using namespace std;

int main(){
    
    int i;

    vector<Funcionario*> funcionario;
    string codigo, nome, endereco, telefone, dataIni, designacao;
    double salario;
    
    int menu;

    cout << "1 - Cadastrar funcionario" << endl <<
            "2 - Exibir funcionario" << endl <<
            "3 - Exibir funcionario por tipo" << endl;


    switch (menu){

    case 1:
        cout << "Digite o tipo do Funcionario: ";
        //getline(cin, tipo);
        break;
    
    case 2:

        break;

    case 3:

        break;

    default:

        break;
    }

    return 1;
}