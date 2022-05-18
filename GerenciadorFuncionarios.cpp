#include "GerenciadorFuncionarios.h"

GerenciadorFuncionarios::GerenciadorFuncionarios(){

}

GerenciadorFuncionarios::~GerenciadorFuncionarios(){

}

void GerenciadorFuncionarios::cadastrarFuncionario(int tipo){
    string codigo, nome, endereco, telefone, dataIni, areaSup, areaForm, nivelFormacao;
    double salario;

    switch (tipo){

    case 1:
        cout << "insira os dados do funcionario(codigo, nome, endereco, telefone, dataIni, salario):";
            getline(cin, codigo);
            getline(cin, nome);
            getline(cin, endereco);
            getline(cin, telefone);
            getline(cin, dataIni);
            cin >> salario;
            cin.ignore();

        //auto *vet = new Operador(codigo, nome, endereco, telefone, dataIni, "Operario", salario);
        listaFuncionarios.push_back(new Operador(codigo, nome, endereco, telefone, dataIni, "Operario", salario));

        break;
    case 2:
        cout << "insira os dados do funcionario(codigo, nome, endereco, telefone, dataIni, salario, area de supervisão):";
            getline(cin, codigo);
            getline(cin, nome);
            getline(cin, endereco);
            getline(cin, telefone);
            getline(cin, dataIni);
            cin >> salario;
            cin.ignore();
            getline(cin, areaSup);

        //auto *vet = new Gerente(codigo, nome, endereco, telefone, dataIni, "Gerente", salario, areaSup);
        listaFuncionarios.push_back(new Gerente(codigo, nome, endereco, telefone, dataIni, "Gerente", salario, areaSup));
        break;

    case 3:
        cout << "insira os dados do funcionario(codigo, nome, endereco, telefone, dataIni, salario, area de supervisão, area de formação):";
            getline(cin, codigo);
            getline(cin, nome);
            getline(cin, endereco);
            getline(cin, telefone);
            getline(cin, dataIni);
            cin >> salario;
            cin.ignore();
            getline(cin, areaSup);
            getline(cin, areaForm);

        //auto *vet = new Diretor(codigo, nome, endereco, telefone, dataIni, "Diretor", salario, areaSup, areaForm);
        listaFuncionarios.push_back(new Diretor(codigo, nome, endereco, telefone, dataIni, "Diretor", salario, areaSup, areaForm));
        break;
    case 4:
        cout << "insira os dados do funcionario(codigo, nome, endereco, telefone, dataIni, salario, area de formação, nivel de formação):";
            getline(cin, codigo);
            getline(cin, nome);
            getline(cin, endereco);
            getline(cin, telefone);
            getline(cin, dataIni);
            cin >> salario;
            cin.ignore();
            getline(cin, areaForm);
            getline(cin, nivelFormacao);

        //auto *vet = new Presidente(codigo, nome, endereco, telefone, dataIni, "Presidente", salario, areaForm, nivelFormacao);
        listaFuncionarios.push_back(new Presidente(codigo, nome, endereco, telefone, dataIni, "Presidente", salario, areaForm, nivelFormacao));
        break;
    default:
        cout << "Erro tipo inválido" << endl;
        break;
    }
}