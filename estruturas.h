#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50

typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct livro{
    int ISBN;
    char titulo[TAM];
    char idioma[TAM];
    char primeiroAutor[TAM];
    char segundoAutor[TAM];
    char editora[TAM];
    int ano;
    char areacientifica[TAM];
    float preco;
    int stock;
}LIVRO;

struct NodoABLivro{ //Arvore binaria para manusear livros
    LIVRO livro;
    struct NodoABLivro *Esquerda;
    struct NodoABLivro *Direita;

};
typedef struct NodoABLivro * PNodoABL;

typedef struct Compra{  //Lista Ligada para lista de compras
    int Produto;
    DATA  datadecompra;  //Data em que a compra foi/vai ser efetuada
    int NumeroDeUnidadesCompradas;
    float PrecoTotal;
    char codigo[TAM];
}COMPRA;

struct NodoLC{  //Lista ligada para manusear clientes, cada Nodo contêm um cliente
 COMPRA compra;
 struct NodoLC* next;
};
typedef struct NodoLC *PNodoLC;

typedef struct cliente{
    long int NIF;  //NIF
    char nome[TAM];  //Nome do Cliente
    char morada[TAM];  //Morada do Cliente
    long int telefone; //Numero de Telefone do Cliente
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
    DATA DataDeEncomenda;  //Data em que a encomenda foi efetuada(sera a data atual quando adicionada uma nova encomenda)
    DATA DataDeCompra;  //Data em que a encomenda é realizada(data da compra futura do cliente)
    int nmr;  //Numero de Unidades encomendadas
    float precoTotal;
    char codigo[TAM];
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
CLIENTE adicionarLCaCliente(CLIENTE c,PNodoABL T);
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
//void ListarLCRec (PNodoLC L);
//void MostrarLC (COMPRA X);
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
void ListarClienteNome(char *X,PNodoCliente L);
void MostrarCliente(CLIENTE X);
void ListarClienteMorada(char *X,PNodoCliente L);
void MostrarLC(PNodoLC X);
int LivrosVendidosNumDadoPeriodoDeTempo(int mes,int ano,PNodoCliente L);
DATA dataDeUltimaCompra(PNodoCliente L);
int CompararDatas (DATA d1, DATA d2);
int QuantidadeDeLivrosCompradosPorCliente(CLIENTE X);
void MostrarKLivrosMaisRecentes(char *area,int k,PNodoABL T);
PNodoABL converterABPisbnParaABPano(PNodoABL T,char *area);
PNodoABL InserirABPAnoDePub (PNodoABL T, LIVRO X);
int CompararLivroAnoDePub (LIVRO X, LIVRO Y);
PNodoABL NodoMaiorElementoABP (PNodoABL T);
PNodoABL CriarArvoreEquilibradaAno (PNodoABL T);
void CriarSequenciaEmOrdemAno (PNodoABL T, LIVRO *L, int *N);
PNodoABL EquilibrarArvoreAno (PNodoABL T, LIVRO *L, int inicio, int fim);
PNodoABL RemoverABPAno (PNodoABL T, LIVRO X);
#endif