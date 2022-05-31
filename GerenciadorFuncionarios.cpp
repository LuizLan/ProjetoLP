#include "GerenciadorFuncionarios.h"
#include<exception>
#include<iostream>
#include<stdlib.h>
#include<fstream>

GerenciadorFuncionarios::GerenciadorFuncionarios(){

}

GerenciadorFuncionarios::~GerenciadorFuncionarios(){

}

vector<Funcionario*> GerenciadorFuncionarios::getListaFuncionarios(){ //get para o vetor listaFuncionarios
    return listaFuncionarios;
}

void GerenciadorFuncionarios::gerarEndereco(string cep){
    string url;

    url = "https://viacep.com.br/ws/" + cep +"/json/";
    system(("wget -q -O cep.txt " + url).c_str());
}

string GerenciadorFuncionarios::enderecoToString(string numeroCasa){
    fstream fs;
    string json, rua, bairro, cidade, estado, endereco;
    int i = 0;

    fs.open("cep.txt", fstream::in);
    if (fs.is_open()){
        while (!fs.eof()){
            getline(fs, json);

            if (i ==2){
                rua = json.substr(17, json.size()-19);
            }else if (i == 4){
                bairro = json.substr(13, json.size()-15);
            }else if (i == 5){
                cidade = json.substr(17, json.size() - 19);
            }else if (i ==6){
                estado = json.substr(9, json.size()- 11);
            }
            i++;
        }
        endereco = rua + ", numero " + numeroCasa + ", " + bairro + ", " + cidade + ", " + estado;
        fs.close();
    }else{
        return "Erro ao ler endereco gerado \n";
    }
    remove("cep.txt");

    return endereco;
}

int VerificaFuncionario(int quantidade){ //função para verificar se existem funcionarios na empresa, caso nao exista o usuario volta ao menu

    if(quantidade == 0){
        string mensagem = "\nNão existem funcionarios disponiveis\n"
                "Redirencionando ao Menu...";
        throw logic_error(mensagem);
    }
    else
        return 0;
}

bool VerificaSeTemLetras(string str) { //função para verificar se uma string possui letras, usada para tratamento de excessão

    string mensagem = "\nDigite uma opcao valida!\n";

    for (int i = 0; i < str.length(); i++){
        if (isdigit(str[i]) == false){
            throw invalid_argument(mensagem);
        }
        return true;
    }
}

bool VerificaNumero(int tipo){ //função para verificar se uma opção de menu é válida

    string mensagem = "\nDigite uma opcao valida!\n";

    if(tipo < 1 || tipo > 4){
        throw invalid_argument(mensagem);
    }

    return 1;
}

int GerenciadorFuncionarios::cadastrarFuncionario(){// função que recebe o tipo do funcionario e lê os dados do funcionario que vai ser cadastrado, chamando o construtor depndendo do tipo de funcionario
    string codigo, nome, CEP, numeroCasa, telefone, dataIni, areaSup, areaForm, nivelFormacao; //informações que serão enviadas no construtor dependendo do tipo de funcionario
    double salario;
    string tipo;
    int tipoFuncionario;

    while(1){
        bool saiu = true;
        cout << "Digite o tipo do Funcionario: "<< endl << // menu para o cadastro de funcionarios
                "1 - operario." << endl <<
                "2 - gerente." << endl <<
                "3 - diretor." << endl <<
                "4 - presidente." << endl <<
                "0 - voltar" << endl;

        getline(cin, tipo); // ler o tipo de funcionario

            try{
                VerificaSeTemLetras(tipo); //verifica se a opção do menu tem letras
                tipoFuncionario = stoi(tipo);
                if(tipoFuncionario == 0){ //se nao houver verifica se é 0 para retornar ao menu
                    cout << "voltando...\n\n";
                    return 0;
                }
                VerificaNumero(tipoFuncionario); //se n for 0 verifica se é um numero válido do menu
            }
            catch(const invalid_argument e){ //catch no posível throw do VerificaNumero
                std::cout << e.what() << endl;
                saiu = false; //altera a flag para que o usuario insira outra opção no menu
            }

        if(saiu){ //sai do loop se o usuario colocou uma opção válida
            break;
        }
    }

    cout << "__CADASTRAR FUNCIONARIO__" << endl; //menu para ler as informações do cadastro de funcionario

    cout << "Codigo do funcionario: "<< endl;

    while(1){ //laço de repetição que verifica se o codigo digitado já existe ou não
        int indice = 0; // indice que utilizado para sair do laço caso o valor seja diferente de 0, ele sempre vai ser definido como 0 no inicio do laço
        getline(cin, codigo);

        for (int i = 0; i < listaFuncionarios.size(); i++){ //procura o codigo entre os usuarios cadastrados
            if(listaFuncionarios.at(i)->getCodigo() == codigo){
                cout << "Esse código já existe, por favor digite outro." << endl;
                indice++; //caso o codigo seja repetido o valor do indice aumenta, fazendo com que o usuario digite novamente o codigo
            }
            else{
                break; // caso o codigo digitado nao seja repetido, ele sai do laço for, sem alterar o indice
            }
        }
        if(indice == 0){ // caso o valor do incice nao se altere, significa que nao existe codigos de funcionario repetidos
            break; //aqui é onde saimos do laço while, e progredimos com o cadastramento do funcionario
        }
    }

    cout << "Nome: " << endl;
    getline(cin, nome);
    cout << "CEP: " << endl;
    getline(cin, CEP);
    cout << "Numero da casa: " << endl;
    getline(cin, numeroCasa);
    cout << "Telefone : " << endl;
    getline(cin, telefone);
    cout << "Data de ingresso: " << endl;
    getline(cin, dataIni);
    cout << "Salario: " << endl;
    cin >> salario;
    cin.ignore();

    switch (tipoFuncionario){ //switch dependendo do tipo de usuario informado
    case 1:
        listaFuncionarios.push_back(new Operador(codigo, nome, CEP, numeroCasa, telefone, dataIni, "Operario", salario)); //cria um objeto operador
        break;
    case 2:
        cout << "Area de supervisão: " << endl;
        getline(cin, areaSup); //le area de supervisão

        listaFuncionarios.push_back(new Gerente(codigo, nome, CEP, numeroCasa, telefone, dataIni, "Gerente", salario, areaSup));//cria um objeto gerente
        break;
    case 3:
        cout << "Area de supervisão: " << endl;
        getline(cin, areaSup); //le area de supervisao
        cout << "Area de formação: " << endl;
        getline(cin, areaForm); //le area de formacao

        listaFuncionarios.push_back(new Diretor(codigo, nome, CEP, numeroCasa, telefone, dataIni, "Diretor", salario, areaSup, areaForm));//cria um objeto diretor
        break;
    case 4:
        cout << "Area de formação:" << endl;
        getline(cin, areaForm); //le area de formação
        cout << "Nivel de formação" << endl;
        getline(cin, nivelFormacao); //le nivel de formaçao

        listaFuncionarios.push_back(new Presidente(codigo, nome, CEP, numeroCasa, telefone, dataIni, "Presidente", salario, areaForm, nivelFormacao));//cria um objeto presidente
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
    //informações que podem ser editadas
    string tipo, codigo, nome, CEP, numeroCasa, telefone, dataIni, designacao, areaSup, areaForm, nivelFormacao;
    double salario;

    int menu, indice, achado = 0;//menu = variavel para escolha do menu de edicao, indice = indice do usuario que esta sendo editado, achado = variavel para informar se um usuario foi achado para edicao
    int tipoFuncionario; // usada para se a ocupação do usuario for editada

    try{
        VerificaFuncionario(listaFuncionarios.size()); //chamada de função para verificar se existem funcionarios na empresa
    }
    catch(const logic_error e){
        std::cout << e.what() << endl;
        return 0;
    }

    cout << "Há um total de: " << listaFuncionarios.size() << " funcionarios na empresa" << endl; // mostrar numero de funcionarios cadastrados na empresa
    cout << "Insira o codigo do usuario a ser editado: " << endl;
    getline(cin, codigo); //le o codigo do usuario a ser editado

    for (int i = 0; i < listaFuncionarios.size(); i++){ //procura o codigo entre os usuarios cadastrados
        if(listaFuncionarios.at(i)->getCodigo() == codigo){
            indice = i; // salva o indice
            achado++; // indica que encontrou um funcionario
        }
    }
    if (achado==0){
        cout << "codigo invalido" << endl;
        return -1;
    }else{
        while (1){
            cout << "Digite oq voce deseja editar: " << endl << //Menu de opções de edição
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

            switch (menu){ //switch case para cada opção do menu
            case 1:
                cout << "Insira o novo código: ";

                while(1){ //laço de repetição que verifica se o codigo digitado já existe ou não
                    int indice = 0; // indice que utilizado para sair do laço caso o valor seja diferente de 0, ele sempre vai ser definido como 0 no inicio do laço
                    getline(cin, codigo);

                    for (int i = 0; i < listaFuncionarios.size(); i++){ //procura o codigo entre os usuarios cadastrados

                        if(listaFuncionarios.size() > 1 && listaFuncionarios.at(i+1)->getCodigo() == codigo){ //caso o primeiro codigo digitado seja alterado para um codigo ja existente, esse if nao permite a mudança
                            cout << "Esse código já existe, por favor digite outro." << endl;
                            indice++;
                        }
                        if(listaFuncionarios.at(i)->getCodigo() == codigo){
                            cout << "Esse código já existe, por favor digite outro: " << endl;
                            indice++; //caso o codigo seja repetido o valor do indice aumenta, fazendo com que o usuario digite novamente o codigo
                        }
                        else{
                            break; // caso o codigo digitado nao seja repetido, ele sai do laço for, sem alterar o indice
                        }
                    }
                    if(indice == 0){ // caso o valor do incice nao se altere, significa que nao existe codigos de funcionario repetidos
                        break; //aqui é onde saimos do laço while, e progredimos com o cadastramento do funcionario
                    }
                }

                listaFuncionarios.at(indice)->setCodigo(codigo); //le e cadastra o novo codigo do funcionario
                cout << "\nEdição concluida com sucesso\n" << endl;
                break;
            case 2:
                cout << "Insira a nova data de Ingresso: ";
                getline(cin,dataIni);

                listaFuncionarios.at(indice)->setDataIni(dataIni); //le e cadastra a nova data de inicialização do funcionario
                cout << "Edição concluida com sucesso" << endl;
                break;
            case 3:
                cout << "Insira o novo nome: ";
                getline(cin,nome);

                listaFuncionarios.at(indice)->setNome(nome);
                cout << "Edição concluida com sucesso" << endl; //le e cadastra o novo nome do funcionario
                break;
            case 4:
                cout << "Insira o novo CEP: ";
                getline(cin,CEP);
                cout << "Insira o novo numero da casa: ";
                getline(cin, numeroCasa);

                listaFuncionarios.at(indice)->setCEP(CEP);//le e cadastra o novo CEP do funcionario
                listaFuncionarios.at(indice)->setNumeroCasa(numeroCasa);
                cout << "Edição concluida com sucesso" << endl;
                break;
            case 5:
                cout << "Insira o novo numero: ";
                getline(cin,telefone);

                listaFuncionarios.at(indice)->setTelefone(telefone);//le e cadastra o novo telefone do funcionario
                break;
            case 6:
                while(1){
                    bool saiu = true;
                        cout << "Digite a nova designação do funcionario: "<< endl << //opçao de designações possiveis para edição
                                "1 - operario." << endl <<
                                "2 - gerente." << endl <<
                                "3 - diretor." << endl <<
                                "4 - presidente." << endl;
                        getline(cin, tipo);
                        try{ //tratamento de erro para o menu
                            VerificaSeTemLetras(tipo);
                            tipoFuncionario = stoi(tipo);
                            if(tipoFuncionario == 0){
                                cout << "voltando...\n\n";
                                return 0;
                            }
                            VerificaNumero(tipoFuncionario);
                        }
                        catch(const invalid_argument e){
                            std::cout << e.what() << endl;
                            saiu = false;
                        }
                    if(saiu){
                        break;
                    }
                }

                listaFuncionarios.at(indice)->setTipo(tipoFuncionario); //salvando todas as informações comuns para serem colocadas em um construtor do novo tipo do objeto
                codigo = listaFuncionarios.at(indice)->getCodigo();
                nome = listaFuncionarios.at(indice)->getNome();
                CEP = listaFuncionarios.at(indice)->getCEP();
                numeroCasa = listaFuncionarios.at(indice)->getNumeroCasa();
                telefone = listaFuncionarios.at(indice)->getTelefone();
                dataIni = listaFuncionarios.at(indice)->getDataIni();
                salario = listaFuncionarios.at(indice)->getSalario();

                switch (tipoFuncionario){

                case 1:
                    listaFuncionarios.erase(listaFuncionarios.begin()+indice); //deletando o objeto antigo
                    listaFuncionarios.push_back(new Operador(codigo, nome, CEP, numeroCasa, telefone, dataIni, "Operario", salario)); //criando o novo objeto de tipo operador
                    cout << "Edição concluida com sucesso" << endl;
                    indice = listaFuncionarios.size()-1;
                    break;
                case 2:
                    listaFuncionarios.at(indice)->setDesignacao("Gerente");
                    cout << "Insira area de supervisão: ";
                    getline(cin,areaSup);

                    listaFuncionarios.erase(listaFuncionarios.begin()+indice);//deletando o objeto antigo
                    listaFuncionarios.push_back(new Gerente(codigo, nome, CEP, numeroCasa, telefone, dataIni, "Gerente", salario, areaSup)); //criando objeto do tipo gerente
                    cout << "Edição concluida com sucesso" << endl;
                    indice = listaFuncionarios.size()-1;
                    break;
                case 3:
                    listaFuncionarios.at(indice)->setDesignacao("Diretor");
                    cout << "Insira area de supervisão: ";
                    getline(cin,areaSup);
                    cout << "Insira area de formação: ";
                    getline(cin,areaForm);

                    listaFuncionarios.erase(listaFuncionarios.begin()+indice);//deletando o objeto antigo
                    listaFuncionarios.push_back(new Diretor(codigo, nome, CEP, numeroCasa, telefone, dataIni, "Diretor", salario, areaSup, areaForm)); //craindo objeto do tipo diretor
                    cout << "Edição concluida com sucesso" << endl;
                    indice = listaFuncionarios.size()-1;
                    break;
                case 4:
                    listaFuncionarios.at(indice)->setDesignacao("Presidente");
                    cout << "Insira area de formação: ";
                    getline(cin,areaForm);

                    cout << "Insira nivel de formação: ";
                    getline(cin,nivelFormacao);
                    listaFuncionarios.erase(listaFuncionarios.begin()+indice);//deletando o objeto antigo
                    listaFuncionarios.push_back(new Presidente(codigo, nome, CEP, numeroCasa, telefone, dataIni, "Presidente", salario, areaForm, nivelFormacao)); //criando objeto do tipo presidente
                    cout << "Edição concluida com sucesso" << endl;
                    indice = listaFuncionarios.size()-1;
                    break;
                default:
                    cout << "Erro - Designação imprópria" << endl;
                    break;
                }
            break;

            case 7:
                cout << "Insira o novo salario: ";
                cin >> salario;

                listaFuncionarios.at(indice)->setSalario(salario);//le e cadastra o novo salario do funcionario
                cout << "Edição concluida com sucesso" << endl;
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

    try{ //método try catch para capturar qualquer erro e retornar ao menu
        VerificaFuncionario(listaFuncionarios.size()); //chamada de função para verificar se existem funcionarios na empresa
    }
    catch(const logic_error e){
        std::cout << e.what() << endl;
        return 0;
    }

    cout << "Há um total de: " << listaFuncionarios.size() << " funcionarios na empresa" << endl; // mostrar numero de funcionarios cadastrados na empresa
    cout << "Digite o código do funcionário que você deseja excluir:" << endl;

    getline(cin, codigo);

    for (int i = 0; i < listaFuncionarios.size(); i++){ //procura na lsita de funcionarios cadastrados o codigo lido
        if (listaFuncionarios.at(i)->getCodigo() == codigo){
            if (listaFuncionarios.at(i)->getTipo() == 3 || listaFuncionarios.at(i)->getTipo() == 4){ //se o funcionario achado for um diretor ou presidente é impossivel deletar
                cout << "Gerentes e presidentes não podem ser excluidos" << endl;
            }else{
                cout << "Voce deseja excluir o funcionaro de codigo: " << listaFuncionarios.at(i)->getCodigo() << " e nome: " << listaFuncionarios.at(i)->getNome() << ":(y/n) " << endl; //mensagem de confirmação de deleção
                cin >> confirmacao;
                cin.ignore();
            }
            if(confirmacao == 'y'){
                listaFuncionarios.erase(listaFuncionarios.begin()+i); //deletando o funcionario
                cout << "Funcionario apagado com sucesso" << endl;
            }else if(confirmacao == 'n'){
                cout << "Exclusão de funcionario cancelada" << endl;
            }
        }
    }
}

void GerenciadorFuncionarios::exibirFuncionario(int i){ //Função que recebe um indice como parametro e mostra os dados do funcionario naquele indice

    try{ //método try catch para capturar qualquer erro e retornar ao menu
        VerificaFuncionario(listaFuncionarios.size()); //chamada de função para verificar se existem funcionarios na empresa
    }
    catch(const logic_error e){
        std::cout << e.what() << endl;
        return;
    }

    gerarEndereco(listaFuncionarios.at(i)->getCEP());
    
    cout << "\nCodigo do funcionario: " << listaFuncionarios.at(i)->getCodigo() << endl <<
            "   Nome: " << listaFuncionarios.at(i)->getNome() << endl <<
            "   Endereço: " << enderecoToString(listaFuncionarios.at(i)->getNumeroCasa()) << endl <<
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

    try{ //método try catch para capturar qualquer erro e retornar ao menu
        VerificaFuncionario(listaFuncionarios.size()); //chamada de função para verificar se existem funcionarios na empresa
    }
    catch(const logic_error e){
        std::cout << e.what() << endl;
        return;
    }

    for (int i = 0; i < listaFuncionarios.size(); i++){
        exibirFuncionario(i);
    }
}

void GerenciadorFuncionarios::buscarFuncionario(){ //funcao que busca um funcionario baseado em uma das tres opcoes exibidas

    try{ //método try catch para capturar qualquer erro e retornar ao menu
        VerificaFuncionario(listaFuncionarios.size()); //chamada de função para verificar se existem funcionarios na empresa
    }
    catch(const logic_error e){
        std::cout << e.what() << endl;
        return;
    }

    string nome, enderecoBusca;
    int encontrado = 0, menu;

    cout << "Digite como você deseja buscar o funcionario: " << endl <<
                    "1 - Nome: " << endl <<
                    "2 - Data de ingresso: " << endl <<
                    "3 - Endereco" << endl;
    cin >> menu;
    cin.ignore();

    switch (menu){
    case 1: //nome
        cout << "Insira o nome do Funcionario a ser procurado: " << endl;
        getline(cin,nome);

        cout << "Exibindo funcionarios com " << nome << " no nome..." << endl;

        for(int i = 0; i < listaFuncionarios.size(); i++){//busca na lista de funcionarios o nome lido usando .find()
            if (listaFuncionarios.at(i)->getNome().find(nome) != string::npos){
                exibirFuncionario(i);

                encontrado += 1;
            }
        }
        if (encontrado==0){
            cout << "nenhum funcionario encontrado" << endl;
        }else{
            cout << "foram encontrados: " << encontrado << " funcionario(s)." << endl;
        }

        break;
    case 2: //data de ingresso, NAO FINALIZADO, MAL COMEÇADO
        cout << "In construction" << endl;
        break;

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

        cout << "dia ini: " << diaI << "mes ini: " << mesI << "ano ini: " << anoI << endl;
        cout << "dia fim: " << diaF << "mes fim: " << mesF << "ano fim: " << anoF << endl;
        /*for (int i = 0; i < listaFuncionarios.size(); i++){
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
        break;
    case 3: //endereço, SERA ALTERADO QUANDO COMEÇAR A USAR CEP
        cout << "Insira a cidade ou o bairro em que você deseja procurar: " << endl;
        getline(cin, enderecoBusca);

        for (int i = 0; i < listaFuncionarios.size(); i++){
            gerarEndereco(listaFuncionarios.at(i)->getCEP());
            if (enderecoToString(listaFuncionarios.at(i)->getNumeroCasa()).find(enderecoBusca) != string::npos){
                exibirFuncionario(i);
                encontrado+=1;
            }
        }
        if (encontrado==0){
            cout << "nenhum funcionario encontrado" << endl;
        }else{
            cout << "foram encontrados: " << encontrado << " funcionario(s)." << endl;
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
