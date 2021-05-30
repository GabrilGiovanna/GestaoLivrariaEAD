#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
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

struct NodoABLivro{ //Arvore binária para manusear livros
    LIVRO livro;
    struct NodoABLivro *Esquerda;
    struct NodoABLivro *Direita;

};
typedef struct NodoABLivro * PNodoABL;

typedef struct Compra{  //Lista Ligada para lista de compras
    int Produto;
    DATA  datadecompra;
    int NumeroDeUnidadesCompradas;
    float PrecoTotal;
    char *codigo;
}COMPRA;

struct NodoLC{  //Lista ligada para manusear clientes, cada Nodo contêm um cliente
 COMPRA compra;
 struct NodoLC* next;
};
typedef struct NodoLC *PNodoLC;

typedef struct cliente{
    long int NIF;  //NIF
    char *nome;  //Nome do Cliente
    char *morada;  //Morada do Cliente
    long int telefone; //Número de Telefone do Cliente
    PNodoLC compras;

}CLIENTE;  // estrutura para Clientes


struct NodoCliente{  //Lista ligada para manusear clientes, cada Nodo contêm um cliente
 CLIENTE cliente;
 struct NodoCliente* next;
};
typedef struct NodoCliente *PNodoCliente;

typedef struct encomendas{
    int ISBN;  //código do livro
    int NIF;
    DATA DataDeEncomenda;
    DATA DataDeCompra;
    DATA DataDeVenda;
    int nmr;  //Numero de Unidades encomendadas
    float precoTotal;
    char *codigo;
}ENCOMENDA;

struct filaEncomendas{  //Fila para manusear encomendas
    ENCOMENDA encomenda;
    struct filaEncomendas *next;
};
typedef struct filaEncomendas *PNodoFilaEncomendas;


//Protótipo das Funções utilizadas no programa inteiro
char *getCharDinamicamente();
CLIENTE NovoCliente();
COMPRA NovaCompra();
LIVRO NovoLivro();
LIVRO AlterarLivro(LIVRO L,int x);
PNodoABL CriarArvoreEquilibrada (PNodoABL T);
int NumeroNodosAB (PNodoABL T);
void CriarSequenciaEmOrdem (PNodoABL T, LIVRO *L, int *N);
PNodoABL EquilibrarArvore (PNodoABL T, LIVRO *L, int inicio, int fim);
PNodoABL InserirABP (PNodoABL T, LIVRO X);
PNodoABL CriarNodoAB(LIVRO X);
int CompararLivroISBN (LIVRO X, LIVRO Y);
PNodoABL RemoverABP (PNodoABL T, LIVRO X);
PNodoABL RemoverNodoABP (PNodoABL T);
PNodoABL LibertarNodoAB(PNodoABL P);
PNodoABL SubstituirNodoDireita (PNodoABL T, LIVRO *X);
PNodoABL SubstituirNodoEsquerda (PNodoABL T, LIVRO *X);
int PesquisarABP (PNodoABL T, LIVRO X);
PNodoABL PesquisarporISBN (int X, PNodoABL T);
int CompararLivroISBN2 (int x, int y);
void ListarLivroTitulo (char *X, PNodoABL T);
void ListarLivroAutor (char *X, PNodoABL T);
void ListarLivroEditora (char *X, PNodoABL T);
void ListarLivroAC (char *X, PNodoABL T);
void ListarLivroAno (int X, PNodoABL T);
int verificaAno (int x, int y);
int contemChar (char *X, char *Y);
void MostrarLivro(LIVRO X);
PNodoCliente CriarNodoCliente (CLIENTE X);
void LibertarNodoCliente (PNodoCliente P);
int VaziaCliente (PNodoCliente L);
void ListarClienteRec (PNodoCliente L);
void MostrarElementoCliente (CLIENTE X);
int PesquisarClienteRec (CLIENTE X, PNodoCliente L);
int CompararCliente (CLIENTE X, CLIENTE Y);
PNodoCliente RemoverClienteRec (CLIENTE X, PNodoCliente L, PNodoCliente LAux);
PNodoCliente InserirFim (CLIENTE X, PNodoCliente L);
PNodoCliente RemoverCliente (CLIENTE X, PNodoCliente L);
PNodoCliente ProcurarAnteriorCliente (CLIENTE X, PNodoCliente L);
PNodoCliente PesquisarPorNIF(long int NIF,PNodoCliente L);
PNodoLC CriarNodoLC (COMPRA X);
void LibertarNodoLC (PNodoLC P);
int VaziaLC (PNodoLC L);
void ListarLCRec (PNodoLC L);
void MostrarLC (COMPRA X);
int PesquisarLCRec (COMPRA X, PNodoLC L);
int CompararCompra (COMPRA X, COMPRA Y);
PNodoLC RemoverCompraRec (COMPRA X, PNodoLC L, PNodoLC LAux);
PNodoLC InserirFimLC (COMPRA X, PNodoLC L);
PNodoLC RemoverCompra (COMPRA X, PNodoLC L);
PNodoLC ProcurarAnteriorLC (COMPRA X, PNodoLC L);
PNodoFilaEncomendas CriarNodoFila (ENCOMENDA X);
PNodoFilaEncomendas LibertarNodoFila (PNodoFilaEncomendas P);
int FilaVazia (PNodoFilaEncomendas Fila);
PNodoFilaEncomendas Juntar (ENCOMENDA X, PNodoFilaEncomendas Fila);
PNodoFilaEncomendas RemoverFila (PNodoFilaEncomendas Fila);
PNodoFilaEncomendas RemoverEncomendaFila(ENCOMENDA X, PNodoFilaEncomendas L);
void LibertarNodoEncomenda (PNodoFilaEncomendas P);
PNodoFilaEncomendas ProcurarAnteriorEncomenda (ENCOMENDA X, PNodoFilaEncomendas L);
int CompararEncomenda (ENCOMENDA X, ENCOMENDA Y);
PNodoABL DestruirAB(PNodoABL T);
PNodoCliente DestruirListaClientes(PNodoCliente L);
PNodoLC DestruirListaCompras(PNodoLC L);
PNodoFilaEncomendas DestruirFila(PNodoFilaEncomendas L);
ENCOMENDA ConverterCOMPRAparaENCOMENDA(CLIENTE c,COMPRA X);
PNodoFilaEncomendas ComprasToEncomendas(PNodoCliente clientes,PNodoFilaEncomendas encomendas);
#endif