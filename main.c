#include <stdio.h>
#include "estruturas.h"


main(){

/*LIVRO livro;

livro=NovoLivro(); */

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
        switch(x1){  //Switch para escolher o que fazer com ficheiros
            case 1: break;
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
        int x2=0;
        scanf("%d",&x2);
        switch(x2){  //Switch para escolher o que fazer com livros
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 7: break;
            case 8: break;
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
}  //Acaba o Main
