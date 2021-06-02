#include "estruturas.c"

/*  Trabalho realizado por Gabriel Alexandre Araujo Ribeiro nº41235, aluno de Engenharia Informatica na Universidade da Beira Interior, e Miguel Vieira Santos nº 41710 

Algoritmos e Estruturas de Dados 2020/2021-Gestao de uma Livraria

Implementacao em C


*/
int main(){

/*LIVRO livro;

livro=NovoLivro(); */

PNodoABL livros=NULL;
PNodoCliente clientes=NULL;
PNodoLC listadecompras=NULL;
PNodoFilaEncomendas encomendas=NULL;

time_t s, val = 1;
struct tm* current_time;

s = time(NULL);
    
current_time = localtime(&s);
int diaAtual=current_time->tm_mday;
int mesAtual=current_time->tm_mon + 1;
int anoAtual=current_time->tm_year + 1900;
int diaDoAnoAtual=current_time->tm_yday;

int x=0;
while(x!=6){

encomendas=ComprasToEncomendas(clientes,encomendas);

printf("-------Gestao de uma Livraria-------\n");

printf("Pretende ir para que seccao?\n");
printf("1.Ficheiro\n");
printf("2.Livros\n");
printf("3.Clientes\n");
printf("4.Encomendas\n");
printf("5.Operacões\n");
printf("6.Sair\n");



scanf("%d",&x);

switch(x){  //Primeiro Switch para escolher a seccao
    case 1: //FICHEIROS
        printf("-------Ficheiros-------\n");
        printf("1.Novo\n");
        printf("2.Abrir\n");
        printf("3.Guardar\n");
        printf("4.Voltar\n");
        int x1=0;
        scanf("%d",&x1);
        //getchar();
        switch(x1){  //Switch para escolher o que fazer com ficheiros
            case 1:  //Nova ED. Destroi as ED's de momento, e tornam-se nulas
                livros=DestruirAB(livros);
                clientes=DestruirListaClientes(clientes);
                //listadecompras=DestruirListaCompras(listadecompras);
                encomendas=DestruirFila(encomendas);
                break;
            case 2:{
                FILE *f= fopen("ficheiroClientes.txt","r");  //Abre o ficheiro
                CLIENTE aux;
                int count=0;
                while(!feof(f)){
                    count+=fscanf(f," %ld",&aux.NIF);
                    //printf("Aqui ele vem\n");
                    count+=fscanf(f," %s",aux.nome);
                    //printf("Entrei aqui\n");  //Nao entra aqui por alguma razao
                    count+=fscanf(f," %ld",&aux.telefone);
                    count+=fscanf(f," %s",aux.morada);
                    COMPRA aux2;
                    aux.compras=NULL;
                    while(fscanf(f," %s %d %d %d %d %f %d",aux2.codigo,&aux2.datadecompra.dia,&aux2.datadecompra.mes,&aux2.datadecompra.ano,&aux2.NumeroDeUnidadesCompradas,&aux2.PrecoTotal,&aux2.Produto)==7){
                        aux.compras=InserirFimLC(aux2,aux.compras);
                    }
                if(count==4) clientes=InserirFim(aux,clientes);
                else break;
                }
                fclose(f);
                //printf("Entrei aqui\n");
                f=fopen("ficheiroLivros.txt","r");
                livros=LerNodoABL(f,livros);
                livros=CriarArvoreEquilibrada(livros);
                fclose(f);
                //TODO FILA
                f=fopen("ficheiroEncomendas.txt","r");
                ENCOMENDA auxiliar;
                count=0;
                while(!feof(f)){
                    count+=fscanf(f," %s",auxiliar.codigo);
                    count+=fscanf(f," %d %d %d",&auxiliar.DataDeCompra.dia,&auxiliar.DataDeCompra.mes,&auxiliar.DataDeCompra.ano);
                    count+=fscanf(f," %d %d %d",&auxiliar.DataDeEncomenda.dia,&auxiliar.DataDeEncomenda.mes,&auxiliar.DataDeEncomenda.ano);
                    //fscanf(f," %d %d %d",&auxiliar.DataDeVenda.dia,&auxiliar.DataDeVenda.mes,&auxiliar.DataDeVenda.ano);
                    count+=fscanf(f," %d",&auxiliar.ISBN);
                    count+=fscanf(f," %d",&auxiliar.NIF);
                    count+=fscanf(f," %d",&auxiliar.nmr);
                    count+=fscanf(f," %f",&auxiliar.precoTotal);
                    if(count==11) encomendas=Juntar(auxiliar,encomendas);
                    else break;
                }
                fclose(f);
            }
             break;
            case 3:{  //Guardar E.D's em ficheiros
                FILE *f= fopen("ficheiroClientes.txt","w");  //Abre o ficheiro
                PNodoCliente auxCliente=clientes;
                while(auxCliente!=NULL){
                    fprintf(f,"%ld\n",auxCliente->cliente.NIF);
                    fprintf(f,"%s\n",auxCliente->cliente.nome);
                    fprintf(f,"%ld\n",auxCliente->cliente.telefone);
                    fprintf(f,"%s\n",auxCliente->cliente.morada);
                    PNodoLC auxLC=auxCliente->cliente.compras;
                    while(auxLC!=NULL){
                        fprintf(f,"%s ",auxLC->compra.codigo);
                        fprintf(f,"%d %d %d ",auxLC->compra.datadecompra.dia,auxLC->compra.datadecompra.mes,auxLC->compra.datadecompra.ano);
                        fprintf(f,"%d ",auxLC->compra.NumeroDeUnidadesCompradas);
                        fprintf(f,"%f ",auxLC->compra.PrecoTotal);
                        fprintf(f,"%d ",auxLC->compra.Produto);
                        auxLC=auxLC->next;
                        fprintf(f,"\n");
                    }
                    auxCliente=auxCliente->next;
                }
                fclose(f);
                f= fopen("ficheiroLivros.txt","w");  //Abre o ficheiro
                EscreverNodoABL(f,livros);
                fclose(f);

                //TODO ficheiro para as Filas
                f=fopen("ficheiroEncomendas.txt","w");
                PNodoFilaEncomendas auxEncomendas=encomendas;
                while(auxEncomendas!=NULL){
                    fprintf(f,"%s\n",auxEncomendas->encomenda.codigo);
                    fprintf(f,"%d %d %d\n",auxEncomendas->encomenda.DataDeCompra.dia,auxEncomendas->encomenda.DataDeCompra.mes,auxEncomendas->encomenda.DataDeCompra.ano);
                    fprintf(f,"%d %d %d\n",auxEncomendas->encomenda.DataDeEncomenda.dia,auxEncomendas->encomenda.DataDeEncomenda.mes,auxEncomendas->encomenda.DataDeEncomenda.ano);
                    //fprintf(f,"%d %d %d\n",auxEncomendas->encomenda.DataDeVenda.dia,auxEncomendas->encomenda.DataDeVenda.mes,auxEncomendas->encomenda.DataDeVenda.ano);
                    fprintf(f,"%d\n",auxEncomendas->encomenda.ISBN);
                    fprintf(f,"%d\n",auxEncomendas->encomenda.NIF);
                    fprintf(f,"%d\n",auxEncomendas->encomenda.nmr);
                    fprintf(f,"%f\n",auxEncomendas->encomenda.precoTotal);
                auxEncomendas=auxEncomendas->next;
                }
                fclose(f);
            }
             break;
            case 4: break;
        } //Acaba Switch com variavel x1
        break;

    case 2: //LIVROS
        printf("-------Livros-------\n");
        printf("1.Inserir\n");
        printf("2.Remover\n");
        printf("3.Alterar\n");
        printf("4.Consultar por ISBN\n");
        printf("5.Consultar por Título\n");
        printf("6.Consultar por Autor\n");
        printf("7.Consultar por Editora\n");
        printf("8.Consultar por area Ciêntifica\n");
        printf("9.Consultar por Ano de Publicacao\n");
        printf("10.Voltar\n");
        int x2=0;
        scanf("%d",&x2);
        //getchar();
        switch(x2){  //Switch para escolher o que fazer com livros
            case 1:  //Inserir novo livro na arvore Binaria
                {

                printf("Digite o ISBN do livro que pretende adicionar\n");
                int isbn;
                scanf("%d",&isbn);
                PNodoABL auxiliarli=PesquisarporISBN(isbn,livros);
                if(auxiliarli==NULL){
                LIVRO X=NovoLivro();   //**************FALTA VERIFICAR SE O LIVRO Ja EXISTE************
                X.ISBN=isbn;
                livros=InserirABP(livros,X); //insere novo livro na arvore de Pesquisa
                livros=CriarArvoreEquilibrada(livros); //Equilibra a arvore
                }
                else printf("Ja existe um livro com esse ISBN\n");
                }
                 break;
            case 2:  //Remover dado um ISBN
                printf("Digite o ISBN do livro que pretende remover\n");
                int isbn;
                scanf("%d",&isbn);
                //getchar();
                PNodoABL aux;  //Nodo para guardar o Nodo correspondente ao livro com o ISBN
                aux=PesquisarporISBN(isbn,livros);  //Procurar o livro
                if(aux!=NULL) livros=RemoverABP(livros,aux->livro); //Se existir, remover
                else printf("Nao existe o livro com o dado ISBN\n");//Nao existe

                 break;
            case 3:
                printf("Digite o ISBN do livro que pretende alterar\n");
                //int isbn;
                scanf("%d",&isbn);
                //getchar();
                aux=PesquisarporISBN(isbn,livros);
                if(aux!=NULL){
                    printf("O que pretende alterar no livro?\n");
                    printf("1-Título\n");
                    printf("2-Idioma\n");
                    printf("3-Primeiro Autor\n");
                    printf("4-Segundo Autor\n");
                    printf("5-Editora\n");
                    printf("6-Ano de Publicacao\n");
                    printf("7-area científica\n");
                    printf("8-Preco\n");
                    printf("9-Quantidade em stock\n");
                    int alt;
                    scanf("%d",&alt);
                    //getchar();
                    aux->livro=AlterarLivro(aux->livro,alt);//AlterarLivro(aux->livro,alt);  //Funcao para alterar o parâmetro do livro que foi escolhido anteriormente
                    printf("Alteracao efetuada\n");

                }
                else printf("Nao existe o livro com o dado ISBN\n");

                 break;
            case 4:  //Consultar livro por ISBN
                printf("Digite o ISBN do livro que pretende consultar\n");
                //int isbn;
                scanf("%d",&isbn);
                //getchar();
                aux=PesquisarporISBN(isbn,livros);
                if(aux!=NULL) MostrarLivro(aux->livro);
                else printf("Nao existe o livro com o dado ISBN\n");
                break;
            case 5:  //Consultar livro por título
                printf("Digite o Título do livro que pretende consultar\n");
                char titulo[TAM];
                scanf("%s",titulo);
                printf("Lista de Livros:\n");
                ListarLivroTitulo(titulo,livros);

                break;
            case 6: //Consultar livro por Autor
                printf("Digite o nome completo do autor do livro que pretende consultar\n");
                char autor[TAM];
                scanf("%s",autor);
                printf("Lista de Livros:\n");
                ListarLivroAutor(autor,livros);


                 break;
            case 7:  //Consultar livro por Editora
                printf("Digite o nome da Editora do livro que pretende consultar\n");
                char editora[TAM];
                scanf("%s",editora);
                printf("Lista de Livros:\n");
                ListarLivroEditora(editora,livros);

                 break;
            case 8: //Consultar livro por area Cientifica
                 printf("Digite a area Ciêntifica do livro que pretende consultar\n");
                char ac[TAM];
                scanf("%s",ac);
                printf("Lista de Livros:\n");
                ListarLivroAC(ac,livros);
                break;
            case 9:  //Consultar livro por ano de publicacao
                printf("Digite o Ano de Publicacao do livro que pretende consultar\n");
                int ano;
                scanf("%d",&ano);
                printf("Lista de Livros:\n");
                ListarLivroAno(ano,livros);

                break;
            case 10: break;
        }//Acaba Switch com variavel x2
        break;
    case 3: //CLIENTES
        printf("-------Clientes-------\n");
        printf("1.Inserir\n");
        printf("2.Remover\n");
        printf("3.Alterar\n");
        printf("4.Consultar por NIF\n");
        printf("5.Consultar por Nome\n");
        printf("6.Consultar por Morada\n");
        printf("7.Voltar\n");
        int x3=0;
        scanf("%d",&x3);
        //getchar();
        switch(x3){  //Switch para escolher o que fazer com Clientes
            case 1:{  //Novo cliente
            CLIENTE client;  //**************FALTA VERIFICAR SE O CLIENTE Ja EXISTE COM O NIF************
            printf("Digite o NIF do novo cliente:\n");
            long int nif;
            scanf("%ld",&nif);
            PNodoCliente aux=PesquisarPorNIF(nif,clientes);
            if(aux==NULL){
            client=NovoCliente();
            client.NIF=nif;
            client=adicionarLCaCliente(client,livros);  //Adiciona a lista de compras ao cliente
            clientes=InserirFim(client,clientes); 
            }
            else printf("Ja existe o cliente com esse NIF\n");
            //printf("%s\n",client.compras->compra.codigo); Ele guarda a encomenda
            //Chega aqui
            break;
            }
            case 2: //Remover cliente
            printf("Digite o NIF do cliente que pretende remover\n");
            long int nif;
            scanf("%ld",&nif);        
            //getchar();
            if(PesquisarPorNIF(nif,clientes)!=NULL){  //Se existe um cliente com esse NIF
                CLIENTE client;
                client=PesquisarPorNIF(nif,clientes)->cliente;  //Guardamos o cliente
                client.compras=DestruirListaCompras(client.compras); //Destruir lista de compras para nao ficar na memoria
                PNodoFilaEncomendas feaux=encomendas; //auxiliar para percorrer a fila
                while(feaux!=NULL){
                    if(feaux->encomenda.NIF==nif) encomendas=RemoverEncomendaFila(feaux->encomenda,encomendas);  //Remove encomendas do cliente removido
                    feaux=feaux->next;
                }
            clientes=RemoverCliente(client,clientes);  //Depois de remover lista de compras e encomendas do cliente, remover o cliente
            }
            else printf("Nao existe um cliente com esse NIF\n");
             break;
            case 3: //Alterar Cliente
            printf("Digite o NIF do cliente que pretende alterar\n");
            scanf("%ld",&nif);
            //getchar();
            PNodoCliente auxcliente=clientes;
            if(PesquisarPorNIF(nif,clientes)!=NULL){
                printf("O que pretende alterar no cliente?\n");
                printf("1-Nome\n");
                printf("2-Morada\n");
                printf("3-Telefone\n");
                printf("4-Lista de Compras\n");  //FALTA****
                int alt;
                scanf("%d",&alt);
                //getchar();
                auxcliente->cliente=AlterarCliente(auxcliente->cliente,alt);//AlterarLivro(aux->livro,alt);  //Funcao para alterar o parâmetro do livro que foi escolhido anteriormente
                printf("Alteracao efetuada\n");

                }
                else printf("Nao existe o cliente com o dado NIF\n");
             break;
            case 4:  //Consultar cliente por NIF
                printf("Digite o NIF do cliente que pretende consultar\n");
                scanf("%ld",&nif);
                //getchar();
                if(PesquisarPorNIF(nif,clientes)!=NULL){
                CLIENTE consultaraux=PesquisarPorNIF(nif,clientes)->cliente;
                MostrarCliente(consultaraux);}
                else printf("Nao existe o cliente com o dado NIF\n");
                break;
            case 5:
                printf("Digite o Nome do cliente que pretende consultar\n");
                char nomecliente[TAM];
                scanf("%s",nomecliente);
                ListarClienteNome(nomecliente,clientes);
                break;
            case 6:
                printf("Digite a morada do cliente que pretende consultar\n");
                char moradacliente[TAM];
                scanf("%s",moradacliente);
                ListarClienteMorada(moradacliente,clientes);
            
             break;
            case 7: break;
        }//Acaba Switch com variavel x3
        break;
    case 4: //ENCOMENDAS
        printf("-------Encomendas-------\n");
        printf("1.Inserir\n");
        printf("2.Remover\n");
        printf("3.Voltar\n");
        int x4=0;
        scanf("%d",&x4);
        //getchar();
        switch(x4){  //Switch para escolher o que fazer com Encomendas
            case 1:{
            ENCOMENDA encs;
            printf("Digite o ISBN da encomenda que pretende inserir\n");
            int isbn;
            scanf("%d",&isbn);
            PNodoABL aux=PesquisarporISBN(isbn,livros);
            if(aux==NULL){   //Se livro nao existe
                printf("O livro pedido nao se encontra disponível.\n");
                break;
            } 
            printf("Digite o NIF do cliente da encomenda\n");
            long int nif;
            scanf("%ld",&nif);
            PNodoCliente auxcli=PesquisarPorNIF(nif,auxcli);
            if(auxcli==NULL){  //Se cliente nao existe
                printf("O cliente nao existe na base de dados\n");
                break;
            }
            
             } break;
            case 2: break;
            case 3: break;
        }  //Acaba Switch com variavel x4
        break;
    case 5:  //OPERAcÕES
        printf("-------Operacões-------\n");
        printf("1.Quantos livros foram vendidos num dado período de tempo (mês e ano)?\n");
        printf("2.Determinar a data da ultima compra/venda de um dado livro\n");
        printf("3.Determinar quantos livros um dado cliente ja comprou\n");
        printf("4.Mostrar os K livros mais recentes de uma dada area Científica\n");
        printf("5.Mostrar os K livros mais vendidos num dado período (mês e ano)\n");
        printf("6.Determinar a area Científica com mais livros\n");
        printf("7.Determinar qual o Cliente com mais livros comprados\n");
        printf("8.Mostrar os Clientes por ordem decrescente do numero de compras\n");
        printf("9.Determinar o Ano com mais publicacões\n");
        printf("10.Calcular o cliente que mais gastou num dado período (mês e ano)\n");
        printf("11.Determinar o desperdício de memoria (no caso em que por exemplo numlivro, no campo TITULO tenham char TITULO[100], se os TITULOS forem mais pequeno existe muito desperdício.\n");
        printf("12.Voltar\n");
        int x5=0;
        scanf("%d",&x5);
        //getchar();
        switch(x5){  //Switch para escolher o que fazer com Clientes
            case 1:
                printf("Digite o mes que pretende verificar\n");
                int mes;
                scanf("%d",&mes);
                printf("Digite o ano que pretende verificar\n");
                int ano;
                scanf("%d",&ano);
                int numeroliv=LivrosVendidosNumDadoPeriodoDeTempo(mes,ano,clientes);
                printf("O numero de livros vendidos em %d/%d foi %d\n",mes,ano,numeroliv);
             break;
            case 2: {
                DATA ultimacompraData;
                ultimacompraData=dataDeUltimaCompra(clientes);
                if(ultimacompraData.dia==0) printf("Nao ha compras feitas\n");
                else if (ultimacompraData.dia==99) printf("Nao ha compras ainda terminadas\n");
                else printf("A ultima compra efetuada foi a %d/%d/%d\n",ultimacompraData.dia,ultimacompraData.mes,ultimacompraData.ano);   
            }        
            break;
            case 3:
                printf("Digite o NIF do cliente que pretende verificar o numero de livros ja comprados\n");
                long int nif;
                scanf("%ld",&nif);
                PNodoCliente aux=PesquisarPorNIF(nif,clientes);
                if(aux==NULL){
                    printf("Nao existe um cliente com esse NIF\n");
                    continue;
                }
                int nmrdelivroscliente=QuantidadeDeLivrosCompradosPorCliente(aux->cliente);
                printf("O cliente com o NIF %d comprou %d livros\n",nif,nmrdelivroscliente);       
             break;
            case 4: 
                printf("Digite a area ciêntifica que pretende verificar\n");
                getchar();
                char *area=getCharDinamicamente();
                printf("Digite o numero de livros mais recentes que pretende verificar\n");
                int k;
                scanf("%d",&k);
                MostrarKLivrosMaisRecentes(area,k,livros);
                printf("Lista dos %d livros de %s mais recentes:\n",k,area);
            
            break;
            case 5: break;
            case 6: break;
            case 7: break;
            case 8: break;
            case 9: break;
            case 10: break;
            case 11: break;
            case 12: break;
        }//Acaba Switch com variavel x5

        break;




}//Acaba o Switch principal

}  //Acaba o While do Menu
return 0;
}  //Acaba o Main
