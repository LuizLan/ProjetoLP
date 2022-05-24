#include "FolhaDePagamento.h"

FolhaDePagamento::FolhaDePagamento(){

}

FolhaDePagamento::~FolhaDePagamento(){

}

void FolhaDePagamento::calcularFolhaDePagamento(GerenciadorFuncionarios gerenciador){
    int menu, horas;

    cout << "você deseja calcular uma folha de pagamento: " << endl <<
            "1 - Mensal" << endl <<
            "2 - Anual" << endl;
    cin >> menu;
    cin.ignore();

    switch (menu){
    case 1:
        srand(time(0));
        for (int i = 0; i < gerenciador.getListaFuncionarios().size(); i++){
            
        }
        break;
    case 2:
        
        break;
    default:
        break;
    }
}