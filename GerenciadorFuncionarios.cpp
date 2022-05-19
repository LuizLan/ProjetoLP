#include "GerenciadorFuncionarios.h"

GerenciadorFuncionarios::GerenciadorFuncionarios(){

}

GerenciadorFuncionarios::~GerenciadorFuncionarios(){

}

int GerenciadorFuncionarios::cadastrarFuncionario(int tipo){
    string codigo, nome, endereco, telefone, dataIni, areaSup, areaForm, nivelFormacao;
    double salario;

    if(tipo==0){
        cout << "Tipo inválido" << endl;
        return -1;
    }

    cout << "__CADASTRAR FUNCIONARIO__" << endl;

    cout << "Codigo do funcionario: "<< endl;
    getline(cin, codigo);
    cout << "Nome: " << endl;
    getline(cin, nome);
    cout << "Endereço: " << endl;
    getline(cin, endereco);
    cout << "Telefone : " << endl;
    getline(cin, telefone);
    cout << "Data de ingresso: " << endl;
    getline(cin, dataIni);
    cout << "Salario: " << endl;
    cin >> salario;
    cin.ignore();


    switch (tipo){
    case 1:
        listaFuncionarios.push_back(new Operador(codigo, nome, endereco, telefone, dataIni, "Operario", salario));
        break;
    case 2:
        cout << "Area de supervisão: " << endl;
        getline(cin, areaSup);

        listaFuncionarios.push_back(new Gerente(codigo, nome, endereco, telefone, dataIni, "Gerente", salario, areaSup));
        break;
    case 3:
        cout << "Area de supervisão: " << endl;
        getline(cin, areaSup);
        cout << "Area de formação: " << endl;
        getline(cin, areaForm);

        listaFuncionarios.push_back(new Diretor(codigo, nome, endereco, telefone, dataIni, "Diretor", salario, areaSup, areaForm));
        break;
    case 4:
        cout << "Area de formação:" << endl;
        getline(cin, areaForm);
        cout << "Nivel de formação" << endl;
        getline(cin, nivelFormacao);

        listaFuncionarios.push_back(new Presidente(codigo, nome, endereco, telefone, dataIni, "Presidente", salario, areaForm, nivelFormacao));
        break;
    default:
        cout << "Erro tipo inválido" << endl;
        return -1;
        break;
    }

    return 0;
}

int GerenciadorFuncionarios::editarFuncionario(){
    string codigo, mudanca;
    int tipo;
    float salario;
    int menu, indice, achado = 0;

    cout << "Insira o codigo do usuario a ser editado: " << endl;
    getline(cin, codigo);

    for (int i = 0; i < listaFuncionarios.size(); i++){
        if(listaFuncionarios.at(i)->getCodigo() == codigo){
            indice = i;
            achado = 1;
        }
    }
    if (achado==0){
        cout << "codigo invalido" << endl;
        return -1;
    }else{
        while (1){
            cout << "Digite oq voce deseja editar: " << endl <<
                    "1 - Numero do código" << endl <<
                    "2 - Data de ingresso" << endl <<
                    "3 - Nome" << endl << 
                    "4 - Endereço" << endl <<
                    "5 - Telefone" << endl <<
                    "6 - Designação" << endl <<
                    "7 - Salario" << endl <<
                    "0 - Sair da edição" << endl;

            cin >> menu;
            cin.ignore();

            switch (menu){
            case 1:
                cout << "Insira o novo código: ";
                getline(cin, mudanca);

                listaFuncionarios.at(indice)->setCodigo(mudanca);        
                break;
            case 2:
                cout << "Insira a nova data de Ingresso: ";
                getline(cin,mudanca);

                listaFuncionarios.at(indice)->setDataIni(mudanca);
                break;
            case 3:
                cout << "Insira o novo nome: ";
                getline(cin,mudanca);

                listaFuncionarios.at(indice)->setNome(mudanca);
                
                break;
            case 4:
                cout << "Insira o novo endereço: ";
                getline(cin,mudanca);

                listaFuncionarios.at(indice)->setEndereco(mudanca);
                
                break;
            case 5:
                cout << "Insira o novo numero: ";
                getline(cin,mudanca);

                listaFuncionarios.at(indice)->setTelefone(mudanca);
                break;
            case 6:
                cout << "Digite a nova designação do funcionario: "<< endl <<
                        "1 - operario." << endl <<
                        "2 - gerente." << endl <<
                        "3 - diretor." << endl << 
                        "4 - presidente." << endl;
                cin >> tipo;

                listaFuncionarios.at(indice)->setTipo(tipo);
                
                switch (tipo){

                case 1:
                    listaFuncionarios.at(indice)->setDesignacao("Operario");
                    break;
                case 2:
                    listaFuncionarios.at(indice)->setDesignacao("Gerente");
                    cout << "Insira area de supervisão: ";
                    getline(cin,mudanca);
                
                    listaFuncionarios.at(indice)->setAreaSup(mudanca);
                    break;
                case 3:
                    listaFuncionarios.at(indice)->setDesignacao("Diretor");
                    cout << "Insira area de supervisão: ";
                    getline(cin,mudanca);
                    listaFuncionarios.at(indice)->setAreaSup(mudanca);
                    
                    cout << "Insira area de formação: ";
                    getline(cin,mudanca);
                    listaFuncionarios.at(indice)->setAreaForm(mudanca);
                    break;
                case 4:
                    listaFuncionarios.at(indice)->setDesignacao("Presidente");
                    cout << "Insira area de formação: ";
                    getline(cin,mudanca);
                    listaFuncionarios.at(indice)->setAreaForm(mudanca);
                    
                    cout << "Insira nivel de formação: ";
                    getline(cin,mudanca);
                    listaFuncionarios.at(indice)->setNivelFormacao(mudanca);
                    break;
                    break;
                default:
                    break;
                }

                break;
            case 7:
                cout << "Insira o novo salario: ";
                cin >> salario;

                listaFuncionarios.at(indice)->setSalario(salario);
                break;
            case 0:
                cout << "Saindo da edição de funcionario..." << endl;
                return 0;       
            default:
                cout << "Entrada invalida... Insira outra do Menu: " << endl;
                break;
            }
        }
    }
}

void GerenciadorFuncionarios::exibirFuncionarios(){
    for (int i = 0; i < listaFuncionarios.size(); i++){
        cout << "Codigo do funcionario: " << listaFuncionarios.at(i)->getCodigo() << endl <<
                "Nome: " << listaFuncionarios.at(i)->getNome() << endl <<
                "Endereço: " << listaFuncionarios.at(i)->getEndereco() << endl <<
                "Telefone : " << listaFuncionarios.at(i)->getTelefone() << endl <<
                "Data de ingresso: " << listaFuncionarios.at(i)->getDataIni() << endl <<
                "Designação: " << listaFuncionarios.at(i)->getDesignacao() << endl <<
                "Salario: " << endl;

        switch (listaFuncionarios.at(i)->getTipo()){
        case 1:
            
            break;
        case 2:
            cout << "Area de supervisão: " << listaFuncionarios.at(i)->getAreaSup();
            break;
        case 3:
            cout << "Area de supervisão: " << listaFuncionarios.at(i)->getAreaSup();
            cout << "Area de formação: " << listaFuncionarios.at(i)->getAreaForm();
            break;
        case 4:
            cout << "Area de formação: " << listaFuncionarios.at(i)->getAreaForm();
            cout << "Nivel de formação: " << listaFuncionarios.at(i)->getNivelFormacao();
            break;    
        default:
            cout << "Erro-Tipo do funcionario exibido" << endl;
            break;
        }
    }
}