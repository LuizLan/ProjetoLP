#include "FolhaDePagamento.h"

FolhaDePagamento::FolhaDePagamento(){

}

FolhaDePagamento::~FolhaDePagamento(){

}





/*void FolhaDePagamento::calcularFolhaDePagamento(int mes, vector<Funcionario*> listaFuncionarios){
    if (folhasFeitas[mes-1] != 0){
        return;
    }

    int horaExtra, diasTrab;
    double salTotal;

    srand(time(0));

    for (int i = 0; i < listaFuncionarios.size(); i++){
        diasTrab = rand();

        if (rand()%2 == 0){ //50% de chance dele ter trabalhado hora extra
            salTotal = listaFuncionarios.at(i)->getSalario()*8*diasTrab; // trabalha 8 horas por dia nos dias trabalhados
        }else{
            horaExtra = rand()%39 + 1; // calcular o tanto de horas extras trabalhadas

            salTotal = (listaFuncionarios.at(i)->getSalario()*8*diasTrab) + (listaFuncionarios.at(i)->getSalario()*horaExtra*2); //somar o solario do mês mais o salario extra das horas trabalhadas
        }
        listaFuncionarios.at(i)->setPagamentoMes(salTotal, mes-1);
    }
    folhasFeitas[mes-1]++;
}

void FolhaDePagamento::exibirFolhaDePagamento(vector<Funcionario*> listaFuncionarios){
    int menu, menuInter, mes;
    string codigo;

    cout << "Voce deseja exibir a folha salarial:" << endl <<
            "1 - De um funcionario" << endl <<
            "2 - Da empresa" << endl;
    cin >> menu;
    cin.ignore();

    switch (menu){
    case 1:
        cout << "Insira o codigo do funcionario: ";
        getline(cin, codigo);

        cout << "Digite: " << endl <<
                "1 - Para a folha de pagamento mensal" << endl <<
                "2 - para a folha de pagamento anual" << endl;
        cin >> menuInter;
        cin.ignore();

        switch (menuInter){
        case 1:
            cout << "Insira o mes que devera ser impresso: ";
            cin >> mes;
            cin.ignore();

            calcularFolhaDePagamento(mes, listaFuncionarios);

            for (int i = 0; i < listaFuncionarios.size(); i++){
                if (listaFuncionarios.at(i)->getCodigo() == codigo){
                    cout << "Pagamento do funcionario " << listaFuncionarios.at(i)->getNome() << " de codigo: " << listaFuncionarios.at(i)->getCodigo() << endl <<
                    "Pagamento do mes "<< mes << ": " << listaFuncionarios.at(i)->getPagamentoMes().at(i);
                }
            }
            break;
        case 2:
            double salarioAno;

            salarioAno = 0;

            for (int i = 0; i < listaFuncionarios.size(); i++){
                if (listaFuncionarios.at(i)->getCodigo() == codigo){
                    for (int i = 1; i <= 12; i++){
                        calcularFolhaDePagamento(i, listaFuncionarios);
                        salarioAno = listaFuncionarios.at(i)->getPagamentoMes().at(i);
                    }
                    cout << "Pagamento do funcionario " << listaFuncionarios.at(i)->getNome() << " de codigo: " << listaFuncionarios.at(i)->getCodigo() << endl <<
                    "Pagamento do ano: " << salarioAno;
                }
            }
            break;
        default:
            cout << "Opcao invalida" << endl;
            break;
        }

        break;
    case 2:
        cout << "Digite: " << endl <<
                "1 - Para a folha de pagamento mensal" << endl <<
                "2 - para a folha de pagamento anual" << endl;
        cin >> menuInter;
        cin.ignore();

        break;
    default:
        break;
    }

}*/