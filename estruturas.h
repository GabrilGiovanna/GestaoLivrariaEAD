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

typedef struct cliente{
 long int NIF;  //NIF
 char *nome;  //Nome do Cliente
 char *morada;  //Morada do Cliente
 long int telefone; //Número de Telefone do Cliente

}CLIENTE;  // estrutura para Clientes

typedef struct NodoCliente{
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

typedef struct filaEncomendas{
    ENCOMENDA encomenda;
    struct filaEncomendas *next;
}FILAENCOMENDAS;


//Funções utilizadas 
char *getCharDinamicamente();
CLIENTE NovoCliente();
