#include"GerenciadorFuncionarios.h"
#include<exception>
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<locale>
#include<locale.h>
#include<fstream>

const int anoMAXIMO = 9999;
const int anoMINIMO = 1940;

using namespace std;

GerenciadorFuncionarios::GerenciadorFuncionarios(){

}

GerenciadorFuncionarios::~GerenciadorFuncionarios(){

}

vector<Funcionario*> GerenciadorFuncionarios::getListaFuncionarios(){ //get para o vetor listaFuncionarios
    return listaFuncionarios;
}

void GerenciadorFuncionarios::lerArquivo(){ //le o arquivo linha por linha e cria um objeto operador, gerente, diretor, presidente dependendo do tipo
    fstream fs;
    Funcionario* funcionario01;
    string codigo, nome, CEP, numeroCasa, telefone, dataIni, designacao, areaSup, areaForm, nivelFormacao; // dataIni = data inicialização, designação = operador, gerente, diretor, presidente
    double salario;
    int tipo; // 1 = operador,2 = gerente,3 = diretor,4 = presidente

    fs.open("listaDeFuncionarios.txt", fstream::in);
    if(!fs.is_open()){
        std::cout << "Erro ao abrir arquivo para leitura\n";
        return;
    }
    while (!fs.eof()){ //fazendo a leitura de cada linha do arquivo para depois criar o objeto funcionario
        fs >> tipo;
        if (fs.eof())
            break;
        fs.ignore();
        getline(fs, designacao);
        getline(fs, codigo);
        getline(fs, nome);
        getline(fs, CEP);
        getline(fs, numeroCasa);
        getline(fs, telefone);
        getline(fs, dataIni);
        fs >> salario;
        fs.ignore();
        switch (tipo){ //switch case para criar o objeto especifico, e obter mais informações se necessário
        case 1:
            listaFuncionarios.push_back(new Operador(codigo, nome, CEP, numeroCasa, telefone, dataIni, designacao, salario));
            break;
        case 2:
            getline(fs, areaSup);
            listaFuncionarios.push_back(new Gerente(codigo, nome, CEP, numeroCasa, telefone, dataIni, designacao, salario, areaSup));
            break;
        case 3:
            getline(fs, areaSup);
            getline(fs, areaForm);

            listaFuncionarios.push_back(new Diretor(codigo, nome, CEP, numeroCasa, telefone, dataIni, designacao, salario, areaSup, areaForm));
            break;
        case 4:
            getline(fs, areaForm);
            getline(fs, nivelFormacao);

            listaFuncionarios.push_back(new Presidente(codigo, nome, CEP, numeroCasa, telefone, dataIni, designacao, salario, areaForm, nivelFormacao));
            break;
        default:
            break;
        }
    }
}
void GerenciadorFuncionarios::salvarArquivo(){ //salva a listaDeFuncionarios em um arquivo
    fstream fs;

    fs.open("listaDeFuncionarios.txt", fstream::out);
    if (!fs.is_open()){
        std::cout << "Erro ao abrir arquivo para escrita" << endl;
    }

    for (int i = 0; i < listaFuncionarios.size(); i++){
        fs << listaFuncionarios.at(i)->getTipo() << endl;           //
        fs << listaFuncionarios.at(i)->getDesignacao() << endl;     //
        fs << listaFuncionarios.at(i)->getCodigo() << endl;         //LEITURA DAS VARIAVEIS COMUNS A TODOS OS FUNCIONARIOS
        fs << listaFuncionarios.at(i)->getNome() << endl;           //
        fs << listaFuncionarios.at(i)->getCEP() << endl;
        fs << listaFuncionarios.at(i)->getNumeroCasa() << endl;
        fs << listaFuncionarios.at(i)->getTelefone() << endl;
        fs << listaFuncionarios.at(i)->getDataIni() << endl;
        fs << listaFuncionarios.at(i)->getSalario() << endl;

        switch (listaFuncionarios.at(i)->getTipo()){ //switch case para leitura de funções específicas para cada funcionario

        case 1:

            break;
        case 2:
            fs << listaFuncionarios.at(i)->getAreaSup() << endl;

            break;
        case 3:
            fs << listaFuncionarios.at(i)->getAreaSup() << endl;
            fs << listaFuncionarios.at(i)->getAreaForm() << endl;

            break;
        case 4:
            fs << listaFuncionarios.at(i)->getAreaForm() << endl;
            fs << listaFuncionarios.at(i)->getNivelFormacao() << endl;

            break;
        default:

            break;
        }
    }
}

string GerenciadorFuncionarios::gerarEndereco(string cep, string numeroCasa){
    string url;

    url = "https://viacep.com.br/ws/" + cep +"/json/";
    system(("wget -q -O cep.txt " + url).c_str());

    return enderecoToString(numeroCasa);
}

string GerenciadorFuncionarios::enderecoToString(string numeroCasa){
    fstream fs;
    string json, rua, bairro, cidade, estado, endereco;
    int i = 0;

    fs.open("cep.txt", fstream::in);
    if (fs.is_open()){
        while (!fs.eof()){
            std::getline(fs, json);

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
        cout << "Erro ao ler endereco gerado \n";
    }
    remove("cep.txt");

    return endereco;
}

int verificaFuncionario(int quantidade){ //função para verificar se existem funcionarios na empresa, caso nao exista o usuario volta ao menu

    if(quantidade == 0){
        string mensagem = "\nNão existem funcionarios disponiveis\n"
                "Redirecionando ao Menu...";
        throw logic_error(mensagem);
    }
    else
        return 0;
}

bool verificaSeTemLetras(string str) { //função para verificar se uma string possui letras, usada para tratamento de excessão

    string mensagem = "\nEssa entrada não permite nenhum tipo de letras!!\n";

    for (int i = 0; i < str.size(); i++){
        if (std::isdigit(str[i]) == 0){
            throw invalid_argument(mensagem);
        }
    }
        return true;
}

bool verificaNumero(int tipo, int tam){ //função para verificar se uma opção de menu é válida

    string mensagem = "\nEsse número não é válido!\n";

    if(tipo < 1 || tipo > tam){
        throw invalid_argument(mensagem);
    }

    return 1;
}

bool analisaDataValida(string data){

    while(1){ // laço de repetição para verificar se a data inserida é inválida

        string mensagem = "Data inválida, por favor digite a data no seguinte formato: DD/MM/AAAA\n"; // mensagem de erro


        if(data.size() != 10){ // if para verificar se a data foi inserida da meneira correta DD/MM/AAAA = 10 caracteres
            cout << mensagem; // mensagem de erro que sera transmitida ao usuário caso a data seja inserida incorretamente
            return false; // e o programa entra novamente no laço de repetição pedindo ao usuário que digite uma data válida, se aplicando a todos os "return false" desta função
        }
        else{
            for(int i = 0; i < data.size(); i++){

                if(i == 2 || i == 5){ // caso exista '/' na posição 2 e 5 dd/mm/aaaa, esse caractere é pulado para a verificação abaixo
                    i++; // incrementa o valor de "i" no laço for
                }
                if (std::isdigit(data[i]) == 0){ // verifica se em qualquer posição da string data há algum caractere que não seja um número
                    cout << mensagem << endl; // caso não haja número em qualquer posição da string data, uma mensagem de erro retorna ao usuário
                    return false;
                }
            }
            if(data[2] == '/' && data[5] == '/'){ // pra verificar se a "/" está colocada de maneira correta na data inserida
                    return true; // caso sim, o programa funciona normalmente
            }
            else{
                cout << mensagem; // caso não, a mensagem de erro é passada
                return false;
            }
        }
    }
}

bool verificaSeDataExiste(int dia, int mes, int ano){ // função que verifica se o dia, mês, ou ano inserido existe, caso não, o usuário recebe uma mensagem de erro

    string mensagem = "A data está incorreta, verifique se digitou corretamente"; // mensagem de erro

    if (ano > anoMAXIMO || ano < anoMINIMO){ // anoMAXIMO definido como 9999 e anoMINIMO definido como 1950, pois ultrapassa a idade de trabalho
        cout << "Você ultrapassou a idade para trabalhar.\nTente digitar uma data acima de 1940\n";
        return false; // e o programa entra novamente no laço de repetição pedindo ao usuário que digite uma data válida, se aplicando a todos os "return false" desta função
    }
    if (mes < 1 || mes > 12){ // verifica se o mês inserido está entre 1 e 12
        cout << mensagem << endl;
        return false;
    }
    if (dia < 1 || dia > 31){ // verifica se o dia inserido está entre 0 e 31
        cout << mensagem << endl;
        return false;
    }
    if (mes == 2){ // caso o mês inserido seja, fevereiro, o programa não permite dias acima do valor 28
        if(dia > 28){
            cout << mensagem << endl;
            return false;
        }
    }
    else if(mes == 1 || mes == 3|| mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){ // todos os meses com dias até 31
        if(dia >= 31){
            cout << mensagem << endl;
            return false;
        }
    }
    else // como todos os outros meses fora fevereiro, possuem dia até no máximo 31, os outros meses possuem dias até 30
        if(dia >= 30){
            cout << mensagem << endl;
            return false;
        }
    return true;
}

bool verificaCEP(string CEP){

    string mensagem = "O CEP está incorreto, verifique se digitou corretamente"; // mensagem de erro

    if(CEP.size() < 8 || CEP.size() > 9){
        cout << mensagem << endl;
        return false;
    }

    for(int i = 0; i < CEP.size(); i++){

        if(CEP.size() == 9){
            if(CEP[5] != '-'){
                cout << mensagem << endl;
                return false;
            }
            else{
                if (std::isdigit(CEP[i]) == 0 && i != 5){
                    cout << mensagem << endl;
                    return false;
                }
            }
        }
        else{
            if (std::isdigit(CEP[i]) == 0){ // verifica se em qualquer posição da string data há algum caractere que não seja um número
                cout << mensagem << endl; // caso não haja número em qualquer posição da string data, uma mensagem de erro retorna ao usuário
                return false;
            }
        }
    }
}

bool trataSalario(string salario){

    for(int i = 0; i < salario.size(); i++){
        if (std::isdigit(salario[i]) == 0 && salario[i] != ','){
            if(salario[i] == '.'){
                cout << "Caso haja casas decimais após o salário utilize ',' e não '.'\n";
                return false;
            }
            else{
                cout << "Salário inválido, tente digitar um salário válido!" << endl;
                return false;
            }
        }
    }
    return true;
}

int GerenciadorFuncionarios::cadastrarFuncionario(){// função que recebe o tipo do funcionario e lê os dados do funcionario que vai ser cadastrado, chamando o construtor depndendo do tipo de funcionario
    
    string codigo, nome, CEP, numeroCasa, telefone, dataIni, areaSup, areaForm, nivelFormacao; //informações que serão enviadas no construtor dependendo do tipo de funcionario
    double salario;
    string tipo, salarioCerto;
    int dia, mes, ano, tipoFuncionario; // variaveis tipo int, como dia mes e ano, e tipoFuncionario, para saber se o funcionario é operario, gerente, etc
    bool executando = true; // AGUARDANDO CLASSE TRATA ERROS variável tipo bool utilizada para sair de todos os laços while de repetição utilizados para a entrada do usuário
    int i;

    while(1){
        bool saiu = true;
        cout << "______MENU DE CADASTRO DE FUNCIONARIOS______" << endl << endl << // menu para o cadastro de funcionarios
                "   Digite o tipo do Funcionario a ser cadastrado(0-4): " << endl << 
                "   1 - operario." << endl <<
                "   2 - gerente." << endl <<
                "   3 - diretor." << endl <<
                "   4 - presidente." << endl <<
                "   0 - voltar" << endl;
        
        cout << "-> ";
        getline(cin, tipo); // ler o tipo de funcionario

        system("cls");

            try{
                verificaSeTemLetras(tipo); //verifica se a opção do menu tem letras
                tipoFuncionario = stoi(tipo);
                if(tipoFuncionario == 0){ //se nao houver verifica se é 0 para retornar ao menu
                    cout << "voltando...\n\n";
                    return 0;
                }
                verificaNumero(tipoFuncionario, 4); //se n for 0 verifica se é um numero válido do menu + o valor da quantidade de opções do menu
            }
            catch(const invalid_argument e){ //catch no posível throw do VerificaNumero
                std::cout << e.what() << endl;
                saiu = false; //altera a flag para que o usuario insira outra opção no menu
            }

        if(saiu){ //sai do loop se o usuario colocou uma opção válida
            break;
        }
    }

    cout << "__INSIRA AS INFORMAÇÕES DO FUNCIONARIO__" << endl << endl; //menu para ler as informações do cadastro de funcionario

    cout << "Codigo do funcionario: "<< endl;

    while(1){ //laço de repetição que verifica se o codigo digitado já existe ou não
        int indice = 0; // indice que utilizado para sair do laço caso o valor seja diferente de 0, ele sempre vai ser definido como 0 no inicio do laço
        getline(cin, codigo);

        for (i = 0; i < listaFuncionarios.size(); i++){ //procura o codigo entre os usuarios cadastrados
            if(listaFuncionarios.at(i)->getCodigo() == codigo){
                cout << "Esse código já existe, por favor digite outro." << endl;
                indice++; //caso o codigo seja repetido o valor do indice aumenta, fazendo com que o usuario digite novamente o codigo
            }
            //else{
            //    break; // caso o codigo digitado nao seja repetido, ele sai do laço for, sem alterar o indice
            //}
        }
        if(indice == 0){ // caso o valor do incice nao se altere, significa que nao existe codigos de funcionario repetidos
            break; //aqui é onde saimos do laço while, e progredimos com o cadastramento do funcionario
        }
    }

    cout << "Nome: " << endl;
    getline(cin, nome);
    cout << "CEP: " << endl;
    while(1){

        getline(cin, CEP);

        if(verificaCEP(CEP)){
            break;
        }
    }

    cout << "Numero da casa: " << endl;

    while(1){
        bool saiu = true;
        getline(cin, numeroCasa);
        try{
            verificaSeTemLetras(numeroCasa);
        }
        catch(const invalid_argument e){ //catch no posível throw do VerificaNumero
            std::cout << e.what() << endl;
            saiu = false; //altera a flag para que o usuario insira outra opção no menu
        }

        if(saiu){
            break;
        }
    }
    cout << "Telefone : " << endl;

    while(1){
        bool saiu = true;
        getline(cin, telefone);
        try{
            verificaSeTemLetras(numeroCasa);
        }
        catch(const invalid_argument e){ //catch no posível throw do VerificaNumero
            std::cout << e.what() << endl;
            saiu = false; //altera a flag para que o usuario insira outra opção no menu
        }

        if(saiu){
            break;
        }
    }

    cout << "Data de ingresso DD/MM/AAAA: " << endl;

    while(1){ // laço de repetição que verifica a data inserida até que ela esteja correta
        getline(cin, dataIni); // escaneia a data inicial na qual o funcionario foi contratado
        if(analisaDataValida(dataIni)){ // chamada da função que analisa se a data digitada não possui caracteres ou erros de digitação

            for (i = 0; i < dataIni.size(); i++){ //caso a função acima funcione corretamente, cada posição da string representando dia, mes e ano, se tornam tipo int, e são enviadas a próxima função
                dia = stoi(dataIni.substr(0, 2)); // primeira e segunda posição da string >dd</mm/aaaa
                mes = stoi(dataIni.substr(3, 4)); // terceira e quarta posição da string dd/>mm</aaaa
                ano = stoi(dataIni.substr(6)); // da posição 6 e adiante da string dd/mm/>aaaa<
            }
            if(verificaSeDataExiste(dia, mes, ano)){ // por fim, caso a data inserida seja totalmente válida, o programa sai do laço de repetição e recebe as outras informações do usuário
                break;
            }
        }
    }

    cout << "Salario: " << endl;

    while(1){
        getline(cin, salarioCerto);

        if(trataSalario(salarioCerto)){
            salario = std::stod(salarioCerto);
            break;
        }
    }

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
        verificaFuncionario(listaFuncionarios.size()); //chamada de função para verificar se existem funcionarios na empresa
    }
    catch(const logic_error e){
        std::cout << e.what() << endl;
        return 0;
    }
    cout << "______MENU DE EDIÇÃO DE FUNCIONARIOS______" << endl <<
            "Há um total de: " << listaFuncionarios.size() << " funcionarios na empresa" << endl << endl; // mostrar numero de funcionarios cadastrados na empresa
    cout << "Insira o codigo do usuario a ser editado: " << endl;
    cout << "-> ";
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
        system("cls");
        while (1){
            cout << "EDITANDO O FUNCIONARIO DE CODIGO: " << codigo << endl <<
                    "Digite oq voce deseja editar: " << endl << //Menu de opções de edição
                    "1 - Numero do código" << endl <<
                    "2 - Data de ingresso" << endl <<
                    "3 - Nome" << endl <<
                    "4 - Endereço" << endl <<
                    "5 - Telefone" << endl <<
                    "6 - Designação" << endl <<
                    "7 - Salario" << endl <<
                    "0 - Voltar para o menu Principal" << endl;

            cout << "-> ";
            cin >> menu;
            cin.ignore();

            system("cls");

            switch (menu){ //switch case para cada opção do menu
            case 1:
                cout << "EDITANDO O FUNCIONARIO DE CODIGO: " << codigo << endl << endl <<
                        "Insira o novo código: " << endl;

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
                system("pause");
                system("cls");
                break;
            case 2:
                cout << "EDITANDO O FUNCIONARIO DE CODIGO: " << codigo << endl << endl <<
                        "Insira a nova data de Ingresso: " << endl;
                getline(cin,dataIni);

                listaFuncionarios.at(indice)->setDataIni(dataIni); //le e cadastra a nova data de inicialização do funcionario
                cout << "Edição concluida com sucesso" << endl;
                system("pause");
                system("cls");
                break;
            case 3:
                cout << "EDITANDO O FUNCIONARIO DE CODIGO: " << codigo << endl << endl <<
                        "Insira o novo nome: " << endl;
                getline(cin,nome);

                listaFuncionarios.at(indice)->setNome(nome);
                cout << "Edição concluida com sucesso" << endl; //le e cadastra o novo nome do funcionario
                system("pause");
                system("cls");
                break;
            case 4:
                cout << "EDITANDO O FUNCIONARIO DE CODIGO: " << codigo << endl << endl <<
                        "Insira o novo CEP: " << endl;
                getline(cin,CEP);
                cout << "Insira o novo numero da casa: " << endl;
                getline(cin, numeroCasa);

                listaFuncionarios.at(indice)->setCEP(CEP);//le e cadastra o novo CEP do funcionario
                listaFuncionarios.at(indice)->setNumeroCasa(numeroCasa);
                cout << "Edição concluida com sucesso" << endl;
                system("pause");
                system("cls");
                break;
            case 5:
                cout << "EDITANDO O FUNCIONARIO DE CODIGO: " << codigo << endl << endl <<
                        "Insira o novo numero: " << endl;
                getline(cin,telefone);

                listaFuncionarios.at(indice)->setTelefone(telefone);//le e cadastra o novo telefone do funcionario
                system("pause");
                system("cls");
                break;
            case 6:
                while(1){
                    bool saiu = true;
                        cout << "EDITANDO O FUNCIONARIO DE CODIGO: " << codigo << endl << endl <<
                                "Digite a nova designação do funcionario(0-4): "<< endl << //opçao de designações possiveis para edição
                                "1 - operario." << endl <<
                                "2 - gerente." << endl <<
                                "3 - diretor." << endl <<
                                "4 - presidente." << endl;
                        cout << "-> ";
                        getline(cin, tipo);
                        try{ //tratamento de erro para o menu
                            verificaSeTemLetras(tipo);
                            tipoFuncionario = stoi(tipo);
                            if(tipoFuncionario == 0){
                                cout << "voltando...\n\n";
                                return 0;
                            }
                            verificaNumero(tipoFuncionario, 4);
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
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    listaFuncionarios.at(indice)->setDesignacao("Gerente");
                    cout << "EDITANDO O FUNCIONARIO DE CODIGO: " << codigo << endl << endl <<
                            "Insira a nova area de supervisão: " << endl;
                    getline(cin,areaSup);

                    listaFuncionarios.erase(listaFuncionarios.begin()+indice);//deletando o objeto antigo
                    listaFuncionarios.push_back(new Gerente(codigo, nome, CEP, numeroCasa, telefone, dataIni, "Gerente", salario, areaSup)); //criando objeto do tipo gerente
                    cout << "Edição concluida com sucesso" << endl;
                    indice = listaFuncionarios.size()-1;
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    listaFuncionarios.at(indice)->setDesignacao("Diretor");
                    cout << "EDITANDO O FUNCIONARIO DE CODIGO: " << codigo << endl << endl <<
                            "Insira a nova area de supervisão: " << endl;
                    getline(cin,areaSup);
                    cout << "Insira a nova area de formação: " << endl;
                    getline(cin,areaForm);

                    listaFuncionarios.erase(listaFuncionarios.begin()+indice);//deletando o objeto antigo
                    listaFuncionarios.push_back(new Diretor(codigo, nome, CEP, numeroCasa, telefone, dataIni, "Diretor", salario, areaSup, areaForm)); //craindo objeto do tipo diretor
                    cout << "Edição concluida com sucesso" << endl;
                    indice = listaFuncionarios.size()-1;
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    listaFuncionarios.at(indice)->setDesignacao("Presidente");
                    cout << "EDITANDO O FUNCIONARIO DE CODIGO: " << codigo << endl << endl <<
                            "Insira a nova area de formação: " << endl;
                    getline(cin,areaForm);

                    cout << "Insira o novo nivel de formação: " << endl;
                    getline(cin,nivelFormacao);
                    listaFuncionarios.erase(listaFuncionarios.begin()+indice);//deletando o objeto antigo
                    listaFuncionarios.push_back(new Presidente(codigo, nome, CEP, numeroCasa, telefone, dataIni, "Presidente", salario, areaForm, nivelFormacao)); //criando objeto do tipo presidente
                    cout << "Edição concluida com sucesso" << endl;
                    indice = listaFuncionarios.size()-1;
                    system("pause");
                    system("cls");
                    break;
                default:
                    cout << "Erro - Designação imprópria" << endl;
                    break;
                }
            break;

            case 7:
                cout << "EDITANDO O FUNCIONARIO DE CODIGO: " << codigo << endl << endl <<
                        "Insira o novo salario: " << endl; 
                cin >> salario;

                listaFuncionarios.at(indice)->setSalario(salario);//le e cadastra o novo salario do funcionario
                cout << "Edição concluida com sucesso" << endl;
                system("pause");
                system("cls");
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
    string confirmacao;

    try{ //método try catch para capturar qualquer erro e retornar ao menu
        verificaFuncionario(listaFuncionarios.size()); //chamada de função para verificar se existem funcionarios na empresa
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
                getline(cin,confirmacao);
            }
            if(confirmacao == "y"){
                listaFuncionarios.erase(listaFuncionarios.begin()+i); //deletando o funcionario
                cout << "Funcionario apagado com sucesso" << endl;
            }else if(confirmacao == "n"){
                cout << "Exclusão de funcionario cancelada" << endl;
            }
            else{
                cout << "Entrada Invalida\nRetornando ao menu...\n";
            }
        }
    }
}

void GerenciadorFuncionarios::exibirFuncionario(int i){ //Função que recebe um indice como parametro e mostra os dados do funcionario naquele indice

    try{ //método try catch para capturar qualquer erro e retornar ao menu
        verificaFuncionario(listaFuncionarios.size()); //chamada de função para verificar se existem funcionarios na empresa
    }
    catch(const logic_error e){
        std::cout << e.what() << endl;
        return;
    }

    cout << "\nCodigo do funcionario: " << listaFuncionarios.at(i)->getCodigo() << endl <<
            "   Nome: " << listaFuncionarios.at(i)->getNome() << endl <<
            "   Endereço: " << gerarEndereco(listaFuncionarios.at(i)->getCEP(), listaFuncionarios.at(i)->getNumeroCasa()) << endl <<
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
        verificaFuncionario(listaFuncionarios.size()); //chamada de função para verificar se existem funcionarios na empresa
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
        verificaFuncionario(listaFuncionarios.size()); //chamada de função para verificar se existem funcionarios na empresa
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
    case 2:

        int dia, mes, ano, diaI, mesI, anoI, diaF, mesF, anoF;

        cout << "Insira o intervalo da data de ingresso a ser procurada: " << endl <<
                "Data inicial: ";
        cin >> diaI; // le dia inicial
        if ( std::cin.get() != '/' ) // checando '/'
        {
            std::cout << "esperado /\n";
            break;
        }
        cin >> mesI; // le mes inicial
        if ( std::cin.get() != '/' ) // checando '/'
        {
            std::cout << "esperado /\n";
            break;
        }
        cin >> anoI; // le ano final
        cin.ignore();
        cout << "Data final: ";
        cin >> diaF; // le dia final
        if ( std::cin.get() != '/' ) // checando '/'
        {
            std::cout << "esperado /\n";
            break;
        }
        cin >> mesF; // le mes final
        if ( std::cin.get() != '/' ) // checando '/'
        {
            std::cout << "esperado /\n";
            break;
        }
        cin >> anoF; // le ano final
        cin.ignore();

        for (int i = 0; i < listaFuncionarios.size(); i++){
            dia = stoi(listaFuncionarios.at(i)->getDataIni().substr(0, listaFuncionarios.at(i)->getDataIni().size() - 8));
            mes = stoi(listaFuncionarios.at(i)->getDataIni().substr(3, listaFuncionarios.at(i)->getDataIni().size() - 8));
            ano = stoi(listaFuncionarios.at(i)->getDataIni().substr(6));

            if (anoI == anoF){
                if (mesI == mesF){
                    if (dia>=diaI && dia<= diaF){
                        exibirFuncionario(i);
                        encontrado += 1;
                    }
                }else if(mes>mesI && mes<mesF){
                    exibirFuncionario(i);
                    encontrado += 1;
                }
            }else if (ano>anoI && ano<anoF){
                exibirFuncionario(i);
                encontrado += 1;
            }else if(ano == anoI){
                if (mes > mesI){
                    exibirFuncionario(i);
                    encontrado += 1;
                }else if (mes == mesI){
                    if (dia>=diaI){
                        exibirFuncionario(i);
                        encontrado += 1;
                    }
                }
            }else if (ano == anoF){
                if (mes < mesF){
                    exibirFuncionario(i);
                    encontrado += 1;
                }else if (mes == mesF){
                    if (dia<=diaF){
                        exibirFuncionario(i);
                        encontrado += 1;
                    }
                }
            }
        }

        if (encontrado==0){
            cout << "nenhum funcionario encontrado" << endl;
        }else{
            cout << "foram encontrados: " << encontrado << " funcionario(s)." << endl;
        }

        break;
    case 3: //endereço, SERA ALTERADO QUANDO COMEÇAR A USAR CEP
        cout << "Insira a cidade ou o bairro em que você deseja procurar: " << endl;
        getline(cin, enderecoBusca);

        for (int i = 0; i < listaFuncionarios.size(); i++){
            if (gerarEndereco(listaFuncionarios.at(i)->getCEP(), listaFuncionarios.at(i)->getNumeroCasa()).find(enderecoBusca) != string::npos){
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

    string confirmacao;
    double salario;

    cout << "Deseja realmente conceder aumento a todos os funcionarios? (y/n)\n";

    getline(cin, confirmacao);

    if(confirmacao == "y"){
        for (int i = 0; i < listaFuncionarios.size(); i++){
            salario = listaFuncionarios.at(i)->getSalario() + (listaFuncionarios.at(i)->getSalario()*listaFuncionarios.at(i)->getPorcentagem());
            listaFuncionarios.at(i)->setSalario(salario);
        }
        cout << "Aumento concedido para todos os funcionarios\n";
    }
    else if(confirmacao == "n"){
        cout << "Aumento Negado\nRetornando ao menu...\n";
    }
    else{
        cout << "Entrada invalida\nRetornando ao menu...\n";
    }
}