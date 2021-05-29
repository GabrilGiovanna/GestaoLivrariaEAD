#include <stdio.h>
#include <string.h>
#include "estruturas.h"

char *getCharDinamicamente()  //Para não haver desperdícios de memória, utilizamos esta função para alocar apenas a memória necessária em cada array de chars
{
    char *string = NULL, *aux = NULL;
    size_t size = 0, i = 0;
    int ch = EOF;

    while (ch) {
        ch = getc(stdin);

        /* Verifica se é necessário parar */
        if (ch == EOF || ch == '\n')
            ch = 0;

        /* Verifica se é necessário realocar. */
        if (size <= i) {

            aux =(char*)realloc(aux,i*sizeof(char*));
            if (!aux) {
                free(string);
                string = NULL;
                break;
            }
            string = aux;
        }

        /* Guarda o caractér. */
        string[i++] = ch;
    }

    return string;
}

//Funcões para inserir novos dados

CLIENTE NovoCliente(){   //criar novo cliente
  CLIENTE c;
  printf("Digite o NIF do novo cliente:\n");
  scanf("%d",&c.telefone);
  getchar();  //Como o scanf deixa um newline no buffer, não podemos utilizar o getCharDinamicamente() não vai funcionar por causa do getc(stdin)
  printf("Digite o nome do novo cliente:\n");
  c.nome = getCharDinamicamente();
  printf("Digite a morada do novo cliente:\n");
  c.morada = getCharDinamicamente();
  printf("Digite o número de telefone do novo cliente:\n");
  scanf("%ld",&c.telefone);
  return c;
}

LIVRO NovoLivro(){
    LIVRO l;
    printf("Digite o ISBN do livro que pretende adicionar\n");
    scanf("%d",&l.ISBN);
    getchar();
    printf("Digite o Título do livro que pretende adicionar\n");
    l.titulo=getCharDinamicamente();
    printf("Digite o idioma do livro que pretende adicionar\n");
    l.idioma=getCharDinamicamente();
    printf("Digite o nome do 1º Autor do livro que pretende adicionar\n");
    l.primeiroAutor=getCharDinamicamente();
    printf("Digite o nome do 2º Autor do livro que pretende adicionar(se existir).\n");  //fazer If para se não existir
    l.segundoAutor=getCharDinamicamente();
    printf("Digite o nome da Editora do livro que pretende adicionar\n");
    l.editora=getCharDinamicamente();
    printf("Digite o ano em que o livro que pretende adicionar foi publicado.\n");
    scanf("%d",&l.ano);
    getchar();
    printf("Digite a Área Científica correspondente ao livro que pretende adicionar\n");
    l.areacientifica=getCharDinamicamente();
    printf("Digite o preço do livro que pretende adicionar\n");
    scanf("%f",l.preco);
    printf("Digite o Stock do livro que pretende adicionar\n");
    scanf("%d",l.stock);

    return l;

}

LIVRO AlterarLivro(LIVRO X,int x){  //Função para alterar o parâmetro do livro que o utilizador pretende

    switch(x){

    case 1:
        printf("Digite o Título que pretende que o livro tenha\n");
        X.titulo=getCharDinamicamente();
         break;
    case 2:
        printf("Digite o idioma do livro\n");
        X.idioma=getCharDinamicamente();

         break;
    case 3:
        printf("Digite o nome do primeiro autor do livro\n");
        X.primeiroAutor=getCharDinamicamente();
         break;
    case 4:
        printf("Digite o nome do segundo autor do livro\n");
        X.segundoAutor=getCharDinamicamente();
        break;
    case 5:
        printf("Digite o nome da editora do livro\n");
        X.editora=getCharDinamicamente();
        break;
    case 6:
        printf("Digite o ano do livro\n");
        int ano;
        scanf("%d",&ano);
        getchar();
        X.ano=ano;
         break;
    case 7:
        printf("Digite a área científica do livro\n");
        X.areacientifica=getCharDinamicamente();
        break;
    case 8:
        printf("Digite o preço do livro\n");
        float preco;
        scanf("%f",&preco);
        getchar();
        X.preco=preco;
        break;
    case 9:
        printf("Digite o stock do livro\n");
        int stock;
        scanf("%d",&stock);
        getchar();
        X.stock=stock;
        break;


    }

}


//Funcões para criar uma árvore binária balanceada
NODOABL* CriarArvoreEquilibrada (NODOABL *T) {//Algoritmo dado nas aulas para criar árvore binária equilibrada
    LIVRO *Lista;
    int N = 0, Num;
    Num = NumeroNodosAB(T);
    if (T == NULL)
        return NULL;
    Lista = (LIVRO *) malloc(Num * sizeof(LIVRO));
    if (Lista == NULL)
        return NULL;
    CriarSequenciaEmOrdem(T, Lista, &N);
    EquilibrarArvore(&T, Lista, 0, N-1);
    return T;
 }
int NumeroNodosAB (NODOABL *T) {  //Conta número de Nodos em árvore
  int  e, d;
  if (T == NULL)
    return 0;
  e = NumeroNodosAB(T->Esquerda);
  d = NumeroNodosAB(T->Direita);
  return (e + d + 1);
}

void CriarSequenciaEmOrdem (NODOABL *T, LIVRO *L, int *N) {
    if (T != NULL) {
        CriarSequenciaEmOrdem(T->Esquerda,L,N);
        L[*N] = T->livro;
        *N = (*N) + 1;
        CriarSequenciaEmOrdem(T->Direita,L,N);
    }
}

void EquilibrarArvore (NODOABL **T, LIVRO *L, int inicio, int fim) {
    int medio;
    if (inicio > fim)
        return;
    if (inicio == fim) {
        *T = InserirABP(*T, L[inicio]);
        return;
    }
    medio = (inicio + fim) / 2;
    *T = InserirABP(*T, L[medio]);
    EquilibrarArvore(T, L, inicio, medio-1);
    EquilibrarArvore(T, L, medio+1, fim);
}

NODOABL* InserirABP (NODOABL *T, LIVRO X){  //Utilizar esta função para adicionar novos Livros à ABP balanceada, e depois utilizar a função CriarArvoreEquilibrada, para balancear a árvore de novo
  if (T == NULL) {
    T = CriarNodoAB(X);
    return T;
  }
  if (CompararLivroISBN(X, T->livro) == -1)
    T->Esquerda = InserirABP(T->Esquerda, X);
  else
    T->Direita = InserirABP(T->Direita, X);
  return T;
}

NODOABL* CriarNodoAB(LIVRO X){
  NODOABL *P = (NODOABL*) malloc(sizeof(NODOABL));
  if (P == NULL)
    return  NULL;
  P->livro = X;
  P->Esquerda = NULL;
  P->Direita = NULL;
  return P;
}


int CompararLivroISBN (LIVRO X, LIVRO Y){  // devolve -1 se X < Y, 0 se X = Y, 1 se X > Y ***COMPARAR LIVRO COM ISBN***
  if (X.ISBN > Y.ISBN)
    return 1;
  if (X.ISBN < Y.ISBN)
    return -1;
  return 0;
}


//Funçoes para remover um elemento da árvore(Não esquecer de equilibrar com a funçao CriarArvoreEquilibrada no fim de cada remoção)

NODOABL* RemoverABP (NODOABL *T, LIVRO X) {
  if (CompararLivroISBN(X, T->livro) == 0) {
    T = RemoverNodoABP(T);
    return T;
  }
  if (CompararLivroISBN(X, T->livro) == -1)
    T->Esquerda = RemoverABP(T->Esquerda, X);
  else
    T->Direita = RemoverABP(T->Direita, X);
  return T;
}


NODOABL* RemoverNodoABP (NODOABL* T){
  NODOABL *R;
  LIVRO X;
  if (T->Esquerda == NULL && T->Direita == NULL) {   // T é uma folha
    T = LibertarNodoAB(T);
    return T;
  }
  if (T->Esquerda == NULL) {   //  só um filho direito
    R = T;
    T = T->Direita;
    R = LibertarNodoAB(R);
    return T;
  }
  if (T->Direita == NULL) {     // só um filho esquerdo
    R = T;
    T = T->Esquerda;
    R = LibertarNodoAB(R);
    return T;
  }
  // 2 filhos (1º caso): remover o nodo sucessor (nodo mais à esquerda da subárvore direita) e copiar a sua informação
  T->Direita = SubstituirNodoDireita(T->Direita, &X);
  // 2 filhos (2º caso): remover o nodo antecessor (nodo mais à direita da subárvore esquerda) e copiar a sua informação
  //  T->Esquerda = SubstituirNodoEsquerda(T->Esquerda, &X);  // 2º caso
  T->livro = X;
  return T;
}

NODOABL* LibertarNodoAB(NODOABL *P){
  P->Esquerda = NULL;
  P->Direita = NULL;
  free(P);
  P = NULL;
  return P;
}

NODOABL* SubstituirNodoDireita (NODOABL *T, LIVRO *X){
  NODOABL  *PAux;
  if (T->Esquerda == NULL) {
    *X = T->livro;
    PAux = T;
    T = T->Direita;
    PAux = LibertarNodoAB(PAux);
    return T;
  }
  T->Esquerda = SubstituirNodoDireita(T->Esquerda, X);
  return T;
}

NODOABL* SubstituirNodoEsquerda (NODOABL *T, INFO *X){
  NODOABL  *PAux;
  if (T->Direita == NULL) {
    *X = T->livro;
    PAux = T;
    T = T->Esquerda;
    PAux = LibertarNodoAB(PAux);
    return  T;
  }
  T->Direita = SubstituirNodoEsquerda(T->Direita, X);
  return T;
}

//Funções para pesquisar e listar elementos específicos na árvore

NODOABL* PesquisarABP (NODOABL *T, LIVRO X) {  //Pesquisar na árvore binária de Pesquisa por livro ****VERIFICAR SE FUNÇÃO VAI SER USADA/ESTÁ CERTA
 NODOABL *P;
  if (T == NULL)
    return 0;
  if (CompararLivroISBN(X, T->livro) == 0)
    return 1;
  if (CompararLivroISBN(X, T->livro) == -1)   // X.ISB < (T->livro).ISBN)
    return PesquisarABP(T->Esquerda, X);
  else
    return PesquisarABP(T->Direita, X);
}

LIVRO PesquisarporISBN (int X, NODOABL *T) {  //Pesquisar na árvore binária de Pesquisa por ISBN
 NODOABL *P;  //Porquê?
  if (T == NULL)
    return NULL;
  if (CompararLivroISBN2(X, T->livro.ISBN) == 0)
    return T->livro;
  if (CompararLivroISBN2(X, T->livro.ISBN) == -1)   // X.ISB < (T->livro).ISBN)
    return PesquisarporISBN(X, T->Esquerda);
  else
    return PesquisarporISBN(X, T->Direita);
}

int CompararLivroISBN2 (int x, int y){  // devolve -1 se X < Y, 0 se X = Y, 1 se X > Y ***USAR NA FUNÇAO PESQUISAR POR ISBN ***
  if (x> y)
    return 1;
  if (x < y)
    return -1;
  return 0;
}

void ListarLivroTitulo (char *X, NODOABL *T) {  //Lista Livros que contêm a frase pedida, no título
  if (T != NULL) {
    ListarLivroTitulo(X,T->Esquerda);
    if(contemChar(T->livro.titulo,X)==0) MostrarLivro(T->livro);
    ListarLivroTitulo(X,T->Direita);
  }
}

void ListarLivroAutor (char *X, NODOABL *T) {  //Lista Livros que contêm a frase pedida, no Autor
  if (T != NULL) {
    ListarLivroAutor(X,T->Esquerda);
    if(contemChar(T->livro.primeiroAutor,X)==0) MostrarLivro(T->livro);
    ListarLivroAutor(X,T->Direita);
  }
}

void ListarLivroEditora (char *X, NODOABL *T) {  //Lista Livros que contêm a frase pedida, na Editora
  if (T != NULL) {
    ListarLivroEditora(X,T->Esquerda);
    if(contemChar(T->livro.editora,X)==0) MostrarLivro(T->livro);
    ListarLivroEditora(X,T->Direita);
  }
}

void ListarLivroAC (char *X, NODOABL *T) {  //Lista Livros que contêm a frase pedida, na Área Cientifica
  if (T != NULL) {
    ListarLivroAC(X,T->Esquerda);
    if(contemChar(T->livro.areacientifica,X)==0) MostrarLivro(T->livro);
    ListarLivroAC(X,T->Direita);
  }
}

void ListarLivroAno (int X, NODOABL *T) {  //Lista Livros que foram publicados no ano X
  if (T != NULL) {
    ListarLivroAno(X,T->Esquerda);
    if(verificaAno(T->livro.ano,X)==0) MostrarLivro(T->livro);
    ListarLivroChar(X,T->Direita);
  }
}


int verificaAno (int x, int y){  // devolve 0 se string Y está contida algures na string X. Verifica se string contêm substring
    if(x==y) return 0;
    return 1;
}

int contemChar (char *X, char *Y){  // devolve 0 se string Y está contida algures na string X. Verifica se string contêm substring
    char *c = strstr(X, Y);
    if(c!=NULL) return 0;
    return 1;

}


void MostrarLivro(LIVRO X){
    printf("ISBN - %d |", X.ISBN);
    printf("Título - %d |", X.titulo);
    printf("Idioma - %d |", X.idioma);
    printf("Primeiro autor - %d |", X.primeiroAutor);
    printf("Segundo autor - %d |", X.segundoAutor);
    printf("Editora - %d |", X.editora);
    printf("Ano - %d |", X.ano);
    printf("Área científica - %d |", X.areacientifica);
    printf("Preço - %d |", X.preco);
    printf("Stock - %d |", X.stock);
    return X;
}


//Funções Lista Ligada Cliente

NODOCLIENTE* CriarNodoCliente (CLIENTE X){
  NODOCLIENTE *P;
  P = (NODOCLIENTE*) malloc(sizeof(NODOCLIENTE));
  if (P == NULL)
    return NULL;
  P->cliente = X;
  P->next = NULL;
  return P;
}

void LibertarNodoCliente (NODOCLIENTE* P){
  free(P);
  P = NULL;
}

int VaziaCliente (NODOCLIENTE* L){
  if (L == NULL)
    return 1;
  else
    return 0;
}


void ListarClienteRec (NODOCLIENTE* L){
  if (L != NULL){
    MostrarElementoCliente(L->cliente);
    ListarClienteRec(L->Prox);
  }
}

void MostrarElementoCliente (CLIENTE X){  //Alterar parâmetros *****POR FAZER***
  printf("%d - ", X.NIF);
  printf("%d - ", X.Telefone);
  printf("%d - ", X.NFatura);
  printf("%f\n",  X.Pagamento);
}

int PesquisarClienteRec (CLIENTE X, NODOCLIENTE* L){
  if (L == NULL)
    return  0;
  if (CompararCliente(L->cliente, X) == 0)
    return  1;
  else
    return PesquisarClienteRec(X, L->next);
}

int CompararCliente (CLIENTE X, CLIENTE Y){  // devolve -1 se X < Y, 0 se X = Y, 1 se X > Y Comparar Clientes
  if (X.NIF > Y.NIF)
    return 1;
  if (X.NIF < Y.NIF)
    return -1;
  return 0;
}

NODOCLIENTE* RemoverClienteRec (CLIENTE X, NODOCLIENTE *L, NODOCLIENTE *LAux) {
  NODOCLIENTE *P;
  if (CompararCliente(L->cliente, X) == 0){   // X está no início da Lista L
    P = L;
    L = L->next;
    free(P);
    return  L;
  }
  if (CompararCliente(LAux->next->cliente, X) == 0){
    // X está na lista L, mas não no inicio
    P = LAux->next;
    LAux->next = P->next;    // ou LAux->next->next;
    free(P);
    return L;
  }
  return RemoverClienteRec(X, L, LAux->next);
}

NODOCLIENTE* InserirFim (CLIENTE X, NODOCLIENTE *L){
  NODOCLIENTE *P, *PAux;
  P = CriarNodoCliente(X);
  if (P == NULL)
    return L;
  if (L == NULL)
    return P;
  PAux = L;
  while (PAux->next != NULL)    // marcar o cliente do fim de L
    PAux = PAux->next;
  PAux->next = P;
  return  L;
}

NODOCLIENTE* RemoverCliente (CLIENTE X, NODOCLIENTE* L){
  NODOCLIENTE *P, *PAnt;
  PAnt = ProcurarAnteriorCliente(X, L);
  if (PAnt == NULL){   // remover elemento do início de L
    P = L;
    L = L->next;
  }
  else{
    P = PAnt->next;
    PAnt->next = P->next; // ou (PAnt->Prox)->Prox
  }
  LibertarNodoCliente(P);
  return  L;
}

NODOCLIENTE* ProcurarAnteriorCliente (CLIENTE X, NODOCLIENTE* L){
  NODOCLIENTE  *Ant = NULL;
  while (L != NULL && CompararCliente(L->cliente, X) != 0){
    Ant = L;
    L = L->next;
  }
  return Ant;
}



//Funções Lista Ligada Compras


NODOLC* CriarNodoLC (COMPRA X){
  NODOLC *P;
  P = (NODOLC*) malloc(sizeof(NODOLC));
  if (P == NULL)
    return NULL;
  P->compra = X;
  P->next = NULL;
  return P;
}

void LibertarNodoLC (NODOLC *P){
  free(P);
  P = NULL;
}

int VaziaLC (NODOLC *L){
  if (L == NULL)
    return 1;
  else
    return 0;
}


void ListarLCRec (NODOLC *L){
  if (L != NULL){
    MostrarLC(L->compra);
    ListarLCRec(L->next);
  }
}

void MostrarLC (COMPRA X){  //Alterar parâmetros *****POR FAZER***
  printf("%d - ", X.NIF);
  printf("%d - ", X.Telefone);
  printf("%d - ", X.NFatura);
  printf("%f\n",  X.Pagamento);
}

int PesquisarLCRec (COMPRA X, NODOLC *L){
  if (L == NULL)
    return  0;
  if (CompararCompra(L->compra, X) == 0)
    return  1;
  else
    return PesquisarLCRec(X, L->next);
}

int CompararCompra (COMPRA X, COMPRA Y){  // devolve -1 se X < Y, 0 se X = Y, 1 se X > Y Comparar compras de cliente
  if (X.codigo > Y.codigo)
    return 1;
  if (X.codigo < Y.codigo)
    return -1;
  return 0;
}

NODOLC* RemoverCompraRec (COMPRA X, NODOLC *L, NODOLC *LAux) {
  NODOLC *P;
  if (CompararCompra(L->compra, X) == 0){   // X está no início da Lista L
    P = L;
    L = L->next;
    free(P);
    return  L;
  }
  if (CompararCompra(LAux->next->compra, X) == 0){
    // X está na lista L, mas não no inicio
    P = LAux->next;
    LAux->next = P->next;    // ou LAux->next->next;
    free(P);
    return L;
  }
  return RemoverCompraRec(X, L, LAux->next);
}

NODOLC* InserirFimLC (COMPRA X, NODOLC *L){
  NODOLC *P, *PAux;
  P = CriarNodoLC(X);
  if (P == NULL)
    return L;
  if (L == NULL)
    return P;
  PAux = L;
  while (PAux->next != NULL)    // marcar a compra do fim de L
    PAux = PAux->next;
  PAux->next = P;
  return  L;
}

NODOCLC* RemoverCompra (COMPRA X, NODOLC* L){
  NODOLC *P, *PAnt;
  PAnt = ProcurarAnteriorLC(X, L);
  if (PAnt == NULL){   // remover elemento do início de L
    P = L;
    L = L->next;
  }
  else{
    P = PAnt->next;
    PAnt->next = P->next; // ou (PAnt->Prox)->Prox
  }
  LibertarNodoLC(P);
  return  L;
}

NODOLC* ProcurarAnteriorLC (COMPRA X, NODOLC* L){
  NODOLC  *Ant = NULL;
  while (L != NULL && CompararCompra(L->compra, X) != 0){
    Ant = L;
    L = L->next;
  }
  return Ant;
}

//Funções Filas

FILAENCOMENDAS* CriarNodoFila (ENCOMENDA X){
  FILAENCOMENDAS *P;
  P = (FILAENCOMENDAS*) malloc(sizeof(FILAENCOMENDAS));
  if (P == NULL)
    return NULL;
  P->encomenda = X;
  P->next = NULL;
  return P;
}

FILAENCOMENDAS* LibertarNodoFila (FILAENCOMENDAS *P){
  free(P);
  P = NULL;
  return P;
}

int FilaVazia (FILAENCOMENDAS *Fila){
  if (Fila == NULL)
    return 1;
  else
    return 0;
}

FILAENCOMENDAS* Juntar (ENCOMENDA X, FILAENCOMENDAS *Fila){
  FILAENCOMENDAS *Novo, *PAnt;
  Novo = CriarNodoFila(X);
  if (Novo == NULL)
    return Fila;
  if (FilaVazia(Fila)){
    Fila = Novo;
    return Fila;
  }
  PAnt = Fila;
  while(PAnt->next != NULL)
    PAnt = PAnt->next;
  PAnt->next = Novo;
  return Fila;
}

FILAENCOMENDAS* RemoverFila (FILAENCOMENDAS *Fila){
  FILAENCOMENDAS *P;
  P = Fila;
  Fila = Fila->next;
  P = LibertarNodoFila(P);
  return Fila;
}

//Funções para destruir Estruturas



NODOABL* DestruirAB(NODOABL *T){
  if (T == NULL)
    return NULL;
  T->Esquerda = DestruirAB(T->Esquerda);
  T->Direita = DestruirAB(T->Direita);
  return LibertarNodoAB(T);
}

NODOCLIENTE* DestruirListaClientes(NODOCLIENTE *L){
    if(L==NULL) return NULL;
    while(L!=NULL){
        L=RemoverCliente(L->cliente,L);
        L=L->next;
    }
    return L;
}

NODOLC* DestruirListaCompras(NODOLC *L){
    if(L==NULL) return NULL;
    while(L!=NULL){
        L=RemoverCompra(L->compra,L);
        L=L->next;
    }
    return L;
}

FILAENCOMENDAS* DestruirFila(FILAENCOMENDAS *L){
    if(L==NULL) return NULL;
    while(L!=NULL){
        L=RemoverFila(L->encomenda,L);
        L=L->next;
    }
    return L;
}
