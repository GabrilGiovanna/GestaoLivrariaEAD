#include <stdio.h>
#include <time.h>
#include <stdlib.h>


typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct livro{
    int ISBN;
    char *titulo;
    char *idioma;
    char *primeiroAutor;
    char *segundoAutor;
    char *editora;
    int ano;
    char *areacientifica;
    float preco;
    int stock;
}LIVRO;

typedef struct NodoABLivro{ //Arvore binária para manusear livros
    LIVRO livro;
    struct NodoABLivro *esquerda;
    struct NodoABLivro *direita;

}NODOAPB;

typedef struct cliente{
    long int NIF;  //NIF
    char *nome;  //Nome do Cliente
    char *morada;  //Morada do Cliente
    long int telefone; //Número de Telefone do Cliente
    LC compras;

}CLIENTE;  // estrutura para Clientes

typedef struct ListaDeCompras{
    char *Produto;
    DATA  datadecompra;
    int NumeroDeUnidadesCompradas;
    float PrecoTotal;
}LC;

typedef struct NodoCliente{  //Lista ligada para manusear clientes, cada Nodo contêm um cliente
 CLIENTE cliente;
 struct NodoCliente* next;
}NODOCLIENTE;

typedef struct encomendas{
    int ISBN;  //código do livro
    int NIF;
    DATA data;
    int nmr;  //Numero de Unidades encomendadas
    float precoTotal;
}ENCOMENDA;

typedef struct filaEncomendas{  //Fila para manusear encomendas
    ENCOMENDA encomenda;
    struct filaEncomendas *next;
}FILAENCOMENDAS;


//Funções utilizadas 
char *getCharDinamicamente();
CLIENTE NovoCliente();
