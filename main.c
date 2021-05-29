#include "estruturas.c"


int main(){

/*LIVRO livro;

livro=NovoLivro(); */

PNodoABL livros;
PNodoCliente clientes;
PNodoLC listadecompras;
PNodoFilaEncomendas encomendas;


int x=0;

while(x!=6){



printf("-------Gestão de uma Livraria-------\n");

printf("Pretende ir para que secção?\n");
printf("1.Ficheiro\n");
printf("2.Livros\n");
printf("3.Clientes\n");
printf("4.Encomendas\n");
printf("5.Operações\n");
printf("6.Sair\n");



scanf("%d",&x);

switch(x){  //Primeiro Switch para escolher a secção
    case 1: //FICHEIROS
        printf("-------Ficheiros-------\n");
        printf("1.Novo\n");
        printf("2.Abrir\n");
        printf("3.Guardar\n");
        printf("4.Sair\n");
        int x1=0;
        scanf("%d",&x1);
        getchar();
        switch(x1){  //Switch para escolher o que fazer com ficheiros
            case 1:  //Nova ED. Destrói as ED's de momento, e tornam-se nulas
                livros=DestruirAB(livros);
                clientes=DestruirListaClientes(clientes);
                listadecompras=DestruirListaCompras(listadecompras);
                encomendas=DestruirFila(encomendas);
                break;
            case 2: break;
            case 3: break;
            case 4: break;
        } //Acaba Switch com variável x1
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
        printf("8.Consultar por Área Ciêntifica\n");
        printf("9.Consultar por Ano de Publicação\n");
        int x2=0;
        scanf("%d",&x2);
        getchar();
        switch(x2){  //Switch para escolher o que fazer com livros
            case 1:  //Inserir novo livro na Árvore Binária
                {


                LIVRO X=NovoLivro();
                livros=InserirABP(livros,X); //insere novo livro na Árvore de Pesquisa
                livros=CriarArvoreEquilibrada(livros); //Equilibra a árvore
                }
                 break;
            case 2:  //Remover dado um ISBN
                printf("Digite o ISBN do livro que pretende remover\n");
                int isbn;
                scanf("%d",&isbn);
                getchar();
                PNodoABL aux;  //Nodo para guardar o Nodo correspondente ao livro com o ISBN
                aux=PesquisarporISBN(isbn,livros);  //Procurar o livro
                if(aux!=NULL) livros=RemoverABP(livros,aux->livro); //Se existir, remover
                else printf("Não existe o livro com o dado ISBN\n");//Não existe

                 break;
            case 3:
                printf("Digite o ISBN do livro que pretende alterar\n");
                //int isbn;
                scanf("%d",&isbn);
                getchar();
                aux=PesquisarporISBN(isbn,livros);
                if(aux!=NULL){
                    printf("O que pretende alterar no livro?\n");
                    printf("1-Título\n");
                    printf("2-Idioma\n");
                    printf("3-Primeiro Autor\n");
                    printf("4-Segundo Autor\n");
                    printf("5-Editora\n");
                    printf("6-Ano de Publicação\n");
                    printf("7-Área científica\n");
                    printf("8-Preço\n");
                    printf("9-Quantidade em stock\n");
                    int alt;
                    scanf("%d",&alt);
                    getchar();
                    aux->livro=AlterarLivro(aux->livro,alt);//AlterarLivro(aux->livro,alt);  //Função para alterar o parâmetro do livro que foi escolhido anteriormente
                    printf("Alteração efetuada\n");

                }
                else printf("Não existe o livro com o dado ISBN\n");

                 break;
            case 4:  //Consultar livro por ISBN
                printf("Digite o ISBN do livro que pretende consultar\n");
                //int isbn;
                scanf("%d",&isbn);
                getchar();
                aux=PesquisarporISBN(isbn,livros);
                if(aux!=NULL) MostrarLivro(aux->livro);
                else printf("Não existe o livro com o dado ISBN\n");
                break;
            case 5:  //Consultar livro por título
                printf("Digite o Título do livro que pretende consultar\n");
                char *titulo=getCharDinamicamente();
                printf("Lista de Livros:\n");
                ListarLivroTitulo(titulo,livros);

                break;
            case 6: //Consultar livro por Autor
                printf("Digite o nome completo do autor do livro que pretende consultar\n");
                char *autor=getCharDinamicamente();
                printf("Lista de Livros:\n");
                ListarLivroAutor(autor,livros);


                 break;
            case 7:  //Consultar livro por Editora
                printf("Digite o nome da Editora do livro que pretende consultar\n");
                char *editora=getCharDinamicamente();
                printf("Lista de Livros:\n");
                ListarLivroEditora(editora,livros);

                 break;
            case 8: //Consultar livro por Área Cientifica
                 printf("Digite a Área Ciêntifica do livro que pretende consultar\n");
                char *ac=getCharDinamicamente();
                printf("Lista de Livros:\n");
                ListarLivroAC(ac,livros);
                break;
            case 9:  //Consultar livro por ano de publicação
                printf("Digite o Ano de Publicação do livro que pretende consultar\n");
                int ano;
                scanf("%d",&ano);
                printf("Lista de Livros:\n");
                ListarLivroAno(ano,livros);

                break;
        }//Acaba Switch com variável x2
        break;
    case 3: //CLIENTES
        printf("-------Clientes-------\n");
        printf("1.Inserir\n");
        printf("2.Remover\n");
        printf("3.Alterar\n");
        printf("4.Consultar por NIF\n");
        printf("5.Consultar por Nome\n");
        printf("6.Consultar por Morada\n");
        int x3=0;
        scanf("%d",&x3);
        getchar();
        switch(x3){  //Switch para escolher o que fazer com Clientes
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 7: break;
            case 8: break;
        }//Acaba Switch com variável x3
        break;
    case 4: //ENCOMENDAS
        printf("-------Encomendas-------\n");
        printf("1.Inserir\n");
        printf("2.Remover\n");
        int x4=0;
        scanf("%d",&x4);
        getchar();
        switch(x4){  //Switch para escolher o que fazer com Encomendas
            case 1: break;
            case 2: break;
        }  //Acaba Switch com variável x4
        break;
    case 5:  //OPERAÇÕES
        printf("-------Operações-------\n");
        printf("1.Quantos livros foram vendidos num dado período de tempo (mês e ano)?\n");
        printf("2.Determinar a data da última compra/venda de um dado livro\n");
        printf("3.Determinar quantos livros um dado cliente já comprou\n");
        printf("4.Mostrar os K livros mais recentes de uma dada Área Científica\n");
        printf("5.Mostrar os K livros mais vendidos num dado período (mês e ano)\n");
        printf("6.Determinar a Área Científica com mais livros\n");
        printf("7.Determinar qual o Cliente com mais livros comprados\n");
        printf("8.Mostrar os Clientes por ordem decrescente do número de compras\n");
        printf("9.Determinar o Ano com mais publicações\n");
        printf("10.Calcular o cliente que mais gastou num dado período (mês e ano)\n");
        printf("11.Determinar o desperdício de memória (no caso em que por exemplo numlivro, no campo TITULO tenham char TITULO[100], se os TITULOS forem mais pequeno existe muito desperdício.\n");
        int x5=0;
        scanf("%d",&x5);
        getchar();
        switch(x5){  //Switch para escolher o que fazer com Clientes
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 7: break;
            case 8: break;
            case 9: break;
            case 10: break;
            case 11: break;
        }//Acaba Switch com variável x5

        break;




}//Acaba o Switch principal

}  //Acaba o While do Menu
return 0;
}  //Acaba o Main
