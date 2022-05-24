#include "GerenciadorFuncionarios.h"
#include<string.h>

GerenciadorFuncionarios::GerenciadorFuncionarios(){

}

GerenciadorFuncionarios::~GerenciadorFuncionarios(){

}

vector<Funcionario*> GerenciadorFuncionarios::getListaFuncionarios(){
    return listaFuncionarios;
}

int GerenciadorFuncionarios::cadastrarFuncionario(int tipo){// função que recebe o tipo do funcionario e lê os dados do funcionario que vai ser cadastrado, chamando o construtor depndendo do tipo de funcionario
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

int GerenciadorFuncionarios::editarFuncionario(){ //Função que lê o codigo do funcionario e entra no menu de edição para aquele funcionario, 
                                                  //podendo mudar codigo, data de ingresso, nome, endereço, telefone, designação e salario;
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
                    cout << "Erro - Designação imprópria" << endl;
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

int GerenciadorFuncionarios::excluirFuncionario(){ //função que lê o codigo do funcionario e o exclui da lista de funcionarios
    string codigo;
    char confirmacao;

    cout << "Digite o código do funcionário que você deseja excluir:" << endl;
    getline(cin, codigo);

    for (int i = 0; i < listaFuncionarios.size(); i++){
        if (listaFuncionarios.at(i)->getCodigo() == codigo){
            if (listaFuncionarios.at(i)->getTipo() == 3 || listaFuncionarios.at(i)->getTipo() == 4){
                cout << "Gerentes e presidentes não podem ser excluidos" << endl;
            }else{
                cout << "Voce deseja excluir o funcionaro de codigo :" << listaFuncionarios.at(i)->getCodigo() << ":(y/n) " << endl;
                cin >> confirmacao;
                cin.ignore();
            }
            if(confirmacao == 'y'){
                listaFuncionarios.erase(listaFuncionarios.begin()+i);
                cout << "Funcionario apagado com sucesso" << endl;
            }else{
                cout << "Exclusão de funcionario cancelada" << endl;
            }
        }
    }
}

void GerenciadorFuncionarios::exibirFuncionario(int i){ //Função que recebe um indice como parametro e mostra os dados do funcionario naquele indice

    cout << "\nCodigo do funcionario: " << listaFuncionarios.at(i)->getCodigo() << endl <<
            "   Nome: " << listaFuncionarios.at(i)->getNome() << endl <<
            "   Endereço: " << listaFuncionarios.at(i)->getEndereco() << endl <<
            "   Telefone : " << listaFuncionarios.at(i)->getTelefone() << endl <<
            "   Data de ingresso: " << listaFuncionarios.at(i)->getDataIni() << endl <<
            "   Designação: " << listaFuncionarios.at(i)->getDesignacao() << endl <<
            "   Salario: " << listaFuncionarios.at(i)->getSalario() << endl;

        switch (listaFuncionarios.at(i)->getTipo()){
        case 1:
            
            break;
        case 2:
            cout << "   Area de supervisão: " << listaFuncionarios.at(i)->getAreaSup() << endl;
            break;
        case 3:
            cout << "   Area de supervisão: " << listaFuncionarios.at(i)->getAreaSup() << endl;
            cout << "   Area de formação: " << listaFuncionarios.at(i)->getAreaForm() << endl;
            break;
        case 4:
            cout << "   Area de formação: " << listaFuncionarios.at(i)->getAreaForm() << endl;
            cout << "   Nivel de formação: " << listaFuncionarios.at(i)->getNivelFormacao() << endl;
            break;    
        default:
            cout << "Erro-Tipo do funcionario exibido" << endl;
            break;
        }
}

void GerenciadorFuncionarios::exibirTodosFuncionarios(){ //função que exibe todos os funcionarios
    for (int i = 0; i < listaFuncionarios.size(); i++){

        exibirFuncionario(i);

        /*cout << "Codigo do funcionario: " << listaFuncionarios.at(i)->getCodigo() << endl <<
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
        }*/
    }
}

void GerenciadorFuncionarios::buscarFuncionario(int menu){
    
    string nome, endereco;
    int encontrado = 0;

    switch (menu){
    case 1: //nome
        cout << "Insira o nome do Funcionario a ser procurado: " << endl;
        getline(cin,nome);

        cout << "Exibindo funcionarios com " << nome << " no nome..." << endl;

        for(int i = 0; i < listaFuncionarios.size(); i++){
            if (listaFuncionarios.at(i)->getNome().find(nome) != string::npos){
                exibirFuncionario(i);

                encontrado += 1;
            }
        }
        if (encontrado==0){
            cout << "nenhum funcionario encontrado" << endl;
        }else{
            cout << "foram encontrados: " << encontrado << "funcionario(s)." << endl;
        }

        break;
    case 2: //data de ingresso, em progresso
    /*    
        int dia, mes, ano, diaI, mesI, anoI, diaF, mesF, anoF;
        char data[11];

        cout << "Insira o intervalo da data de ingresso a ser procurada: " << endl <<
                "Data inicial: ";
        cin >> diaI; // read the day
        if ( std::cin.get() != '/' ) // make sure there is a slash between DD and MM
        {
            std::cout << "esperado /\n";
            break;
        }
        cin >> mesI; // read the month
        if ( std::cin.get() != '/' ) // make sure there is a slash between MM and YYYY
        {
            std::cout << "esperado /\n";
            break;
        }
        cin >> anoI; // read the year
        cin.ignore();
        cout << "Data final: ";
        cin >> diaF; // read the day
        if ( std::cin.get() != '/' ) // make sure there is a slash between DD and MM
        {
            std::cout << "esperado /\n";
            break;
        }
        cin >> mesF; // read the month
        if ( std::cin.get() != '/' ) // make sure there is a slash between MM and YYYY
        {
            std::cout << "esperado /\n";
            break;
        }
        cin >> anoF; // read the year
        cin.ignore();

        for (int i = 0; i < listaFuncionarios.size(); i++){
            strcpy(data, listaFuncionarios.at(i)->getDataIni().c_str());
            // data: 1, 2, /, 1, 0, /, 2, 0, 0, 4, /0
            dia = ((int)data[0])*10 + (int)data[1];
            mes = ((int)data[3])*10 + (int)data[4];
            ano = ((int)data[6])*1000 + ((int)data[7])*100 + ((int)data[8])*10 + (int)data[9];

            cout << "(debbuging)dia mes e ano do funcionario: " << dia << "/" << mes << "/" << ano << endl;
            
            if (ano >= anoI && ano <= anoF){
                if (mes>= mesI && mes <= mesF){
                    if (dia>=diaI && dia<=diaF){
                        exibirFuncionario(i);
                        encontrado += 1;
                    }
                }
            }
        }
        if (encontrado==0){
            cout << "nenhum funcionario encontrado" << endl;
        }else{
            cout << "foram encontrados: " << encontrado << "funcionario(s)." << endl;
        }
    */
    cout << "In construction" << endl;
        break;
    case 3: //endereço
        cout << "Insira a cidade ou o bairro em que você deseja procurar: " << endl;
        getline(cin, endereco);

        for (int i = 0; i < listaFuncionarios.size(); i++){
            if (listaFuncionarios.at(i)->getEndereco().find(endereco) != string::npos){
                exibirFuncionario(i);
                encontrado+=1;
            }
        }
        if (encontrado==0){
            cout << "nenhum funcionario encontrado" << endl;
        }else{
            cout << "foram encontrados: " << encontrado << "funcionario(s)." << endl;
        }

        break;
    default:

        cout << "Opção Inválida para busca de funcionários" << endl;

        break;
    }
}

void GerenciadorFuncionarios::concederAumento(){
    for (int i = 0; i < listaFuncionarios.size(); i++){
        listaFuncionarios.at(i)->concederAumento();
    }
}