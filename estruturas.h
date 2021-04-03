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
    char titulo[50];
    char idioma[15];
    char primeiroAutor[50];
    char segundoAutor[50];
    char editora[50];
    int ano;
    char areacientifica[100];
    float preco;
    int stock;
}LIVRO;

typedef struct cliente{
 long int NIF;  //NIF
 char nome[50];  //Nome do Cliente
 char morada[100];  //Morada do Cliente
 long int telefone; //Número de Telefone do Cliente

}CLIENTE;  // estrutura para Clientes

typedef struct NodoCliente{
 CLIENTE cliente;
 NODOCLIENTE *next;
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
    FILAENCOMENDAS *next;
}FILAENCOMENDAS;



CLIENTE NovoCliente(){
  CLIENTE c;
  c.NIF = scanf("%d",c.NIF);
  c.telefone = scanf("%ld",c.telefone);
  c.nome[50]= scanf("%c",c.nome);
  c.morada[100] = scanf("%c",c.morada);
 
  return c;
}
