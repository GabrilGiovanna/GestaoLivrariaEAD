#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


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

};
typedef struct NodoABLivro *PNodoABL;

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
};
typedef struct Nodo *PNodoLC;

typedef struct cliente{
    long int NIF;  //NIF
    char *nome;  //Nome do Cliente
    char *morada;  //Morada do Cliente
    long int telefone; //Número de Telefone do Cliente
    PNodoLC compras;

}CLIENTE;  // estrutura para Clientes


typedef struct NodoCliente{  //Lista ligada para manusear clientes, cada Nodo contêm um cliente
 CLIENTE cliente;
 struct NodoCliente* next;
};
typedef struct Nodo *PNodoCliente;

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
};
typedef struct NodoFila *PNodoFilaEncomendas;


//Protótipo das Funções utilizadas no programa inteiro
char *getCharDinamicamente();
CLIENTE NovoCliente();
LIVRO NovoLivro();
PNodoABL CriarArvoreEquilibrada (PNodoABL T);
int NumeroNodosAB (PNodoABL T);
void CriarSequenciaEmOrdem (PNodoABL T, LIVRO *L, int *N);
void EquilibrarArvore (PNodoABL *T, LIVRO *L, int inicio, int fim);
PNodoABL InserirABP (PNodoABL T, LIVRO X);
PNodoABL CriarNodoAB(LIVRO X);
int CompararElementosLivro (LIVRO X, LIVRO Y);
