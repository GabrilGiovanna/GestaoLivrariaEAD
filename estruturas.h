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
    struct NodoABLivro *Esquerda;
    struct NodoABLivro *Direita;

}NODOABL;

typedef struct Compra{  //Lista Ligada para lista de compras
    char *Produto;
    DATA  datadecompra;
    int NumeroDeUnidadesCompradas;
    float PrecoTotal;
    int codigo;
}COMPRA;

typedef struct NodoLC{  //Lista ligada para manusear clientes, cada Nodo contêm um cliente
 COMPRA compra;
 struct NodoLC* next;
}NODOLC;

typedef struct cliente{
    long int NIF;  //NIF
    char *nome;  //Nome do Cliente
    char *morada;  //Morada do Cliente
    long int telefone; //Número de Telefone do Cliente
    NODOLC compras;

}CLIENTE;  // estrutura para Clientes


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


//Protótipo das Funções utilizadas no programa inteiro
char *getCharDinamicamente();
CLIENTE NovoCliente();
LIVRO NovoLivro();
NODOABL CriarArvoreEquilibrada (NODOABL *T);
int NumeroNodosAB (NODOABL *T);
void CriarSequenciaEmOrdem (NODOABL *T, LIVRO *L, int *N);
void EquilibrarArvore (NODOABL **T, LIVRO *L, int inicio, int fim);
NODOABL InserirABP (NODOABL *T, LIVRO X);
NODOABL CriarNodoAB(LIVRO X);
int CompararElementosLivro (LIVRO X, LIVRO Y);
