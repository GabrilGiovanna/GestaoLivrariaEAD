#include "estruturas.h"

time_t s, val = 1;
struct tm* current_time;



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
  c.compras=NULL;
  
  //getchar();  //Como o scanf deixa um newline no buffer, não podemos utilizar o getCharDinamicamente() não vai funcionar por causa do getc(stdin)
  printf("Digite o nome do novo cliente:\n");
  scanf("%s",c.nome);
  printf("Digite a morada do novo cliente:\n");
  scanf("%s",c.morada);
  printf("Digite o número de telefone do novo cliente:\n");
  scanf("%ld",&c.telefone);
  //getchar();
  /*printf("Lista de Compras do novo cliente:\n");
  printf("Número de Compras na Lista:\n");
  int x;
  scanf("%d",&x);
  //getchar();
  for(int i=0;i<x;i++){
    COMPRA cp=NovaCompra();
    c.compras=InserirFimLC(cp,c.compras);
  }*/
  //Ele chega aqui
  //printf("%s\n",c.compras->compra.codigo);
  return c;
}

COMPRA NovaCompra(){

COMPRA comp;


printf("Digite o Código da Compra:\n");
scanf("%s",comp.codigo);
printf("Digite o dia da Compra:\n");
scanf("%d",&comp.datadecompra.dia);
//getchar();
printf("Digite o mês da Compra(1,2,3...etc):\n");
scanf("%d",&comp.datadecompra.mes);
//getchar();
printf("Digite o ano da Compra:\n");
scanf("%d",&comp.datadecompra.ano);
//getchar();
printf("Digite o numero de unidades compradas:\n");
scanf("%d",&comp.NumeroDeUnidadesCompradas);
//getchar();
printf("Digite o preço total:\n");
scanf("%f",&comp.PrecoTotal);
//getchar();
printf("Digite o ISBN do produto:\n");
scanf("%d",&comp.Produto);
//getchar();

return comp;
}

CLIENTE adicionarLCaCliente(CLIENTE c,PNodoABL T){

  printf("Lista de Compras do novo cliente:\n");
  printf("Número de Compras na Lista:\n");
  int x;
  scanf("%d",&x);
  //getchar();
  for(int i=0;i<x;i++){
     COMPRA cp;
     printf("Digite o ISBN do produto:\n");
     scanf("%d",&cp.Produto);
     T=PesquisarporISBN(cp.Produto,T);
    if(T!=NULL){
      printf("Digite o Código da Compra:\n");
      scanf("%s",cp.codigo);
      printf("Digite o dia da Compra:\n");
      scanf("%d",&cp.datadecompra.dia);
      //getchar();
      printf("Digite o mês da Compra(1,2,3...etc):\n");
      scanf("%d",&cp.datadecompra.mes);
      //getchar();
      printf("Digite o ano da Compra:\n");
      scanf("%d",&cp.datadecompra.ano);
      //getchar();
      printf("Digite o numero de unidades compradas:\n");
      scanf("%d",&cp.NumeroDeUnidadesCompradas);
      //getchar();
      cp.PrecoTotal=(T->livro.preco) * (float)(cp.NumeroDeUnidadesCompradas);  //Muda o Stock
      T->livro.stock=(T->livro.stock)-cp.NumeroDeUnidadesCompradas;  //Muda o Stock
      if(T->livro.stock>=0)  c.compras=InserirFimLC(cp,c.compras);  //Inserir na Lista de Compras

    }
    else printf("Não é possível a compra\n");
  }
return c;
}


LIVRO NovoLivro(){
    LIVRO l;
    //getchar();
    printf("Digite o Título do livro que pretende adicionar\n");
    scanf("%s",l.titulo);
    printf("Digite o idioma do livro que pretende adicionar\n");
    scanf("%s",l.idioma);
    printf("Digite o nome do 1º Autor do livro que pretende adicionar\n");
    scanf("%s",l.primeiroAutor);
    printf("Digite o nome do 2º Autor do livro que pretende adicionar(se existir).\n");  //fazer If para se não existir
    scanf("%s",l.segundoAutor);
    printf("Digite o nome da Editora do livro que pretende adicionar\n");
    scanf("%s",l.editora);
    printf("Digite o ano em que o livro que pretende adicionar foi publicado.\n");
    scanf("%d",&l.ano);
    //getchar();
    printf("Digite a Área Científica correspondente ao livro que pretende adicionar\n");
    scanf("%s",l.areacientifica);
    printf("Digite o preço do livro que pretende adicionar\n");
    scanf("%f",&l.preco);
    //getchar();
    printf("Digite o Stock do livro que pretende adicionar\n");
    scanf("%d",&l.stock);
    //getchar();
    return l;

}

LIVRO AlterarLivro(LIVRO L,int x){  //Função para alterar o parâmetro do livro que o utilizador pretende

    switch(x){

    case 1:
        printf("Digite o Título que pretende que o livro tenha\n");
        scanf("%s",L.titulo);
         break;
    case 2:
        printf("Digite o idioma do livro\n");
        scanf("%s",L.idioma);

         break;
    case 3:
        printf("Digite o nome do primeiro autor do livro\n");
        scanf("%s",L.primeiroAutor);
         break;
    case 4:
        printf("Digite o nome do segundo autor do livro\n");
        scanf("%s",L.segundoAutor);
        break;
    case 5:
        printf("Digite o nome da editora do livro\n");
        scanf("%s",L.editora);
        break;
    case 6:
        printf("Digite o ano do livro\n");
        int ano;
        scanf("%d",&ano);
        //getchar();
        L.ano=ano;
         break;
    case 7:
        printf("Digite a área científica do livro\n");
        scanf("%s",L.areacientifica);
        break;
    case 8:
        printf("Digite o preço do livro\n");
        float preco;
        scanf("%f",&preco);
        //getchar();
        L.preco=preco;
        break;
    case 9:
        printf("Digite o stock do livro\n");
        int stock;
        scanf("%d",&stock);
        //getchar();
        L.stock=stock;
        break;


    }
return L;
}

CLIENTE AlterarCliente(CLIENTE L,int x){  //Função para alterar o parâmetro do livro que o utilizador pretende

    switch(x){

    case 1:
        printf("Digite o nome que pretende que o cliente tenha\n");
        scanf("%s",L.nome);
         break;
    case 2:
        printf("Digite a morada do cliente\n");
        scanf("%s",L.morada);
         break;
    case 3:
        printf("Digite o telefone do cliente\n");
        scanf("%ld",&L.telefone);
        //getchar();
        break;
    }
return L;
}


//Funcões para criar uma árvore binária balanceada
PNodoABL CriarArvoreEquilibrada (PNodoABL T) {//Algoritmo dado nas aulas para criar árvore binária equilibrada
    LIVRO *Lista;
    int N = 0, Num;
    Num = NumeroNodosAB(T);
    if (T == NULL)
        return NULL;
    Lista = (LIVRO *) malloc(Num * sizeof(LIVRO));
    if (Lista == NULL)
        return NULL;
    CriarSequenciaEmOrdem(T, Lista, &N);
    PNodoABL aux=NULL;
    aux=EquilibrarArvore(aux, Lista, 0, N-1);
    T=DestruirAB(T);
    return aux;
 }
int NumeroNodosAB (PNodoABL T) {  //Conta número de Nodos em árvore
  int  e, d;
  if (T == NULL)
    return 0;
  e = NumeroNodosAB(T->Esquerda);
  d = NumeroNodosAB(T->Direita);
  return (e + d + 1);
}

void CriarSequenciaEmOrdem (PNodoABL T, LIVRO *L, int *N) {
    if (T != NULL) {
        CriarSequenciaEmOrdem(T->Esquerda,L,N);
        L[*N] = T->livro;
        *N = (*N) + 1;
        CriarSequenciaEmOrdem(T->Direita,L,N);
    }
}

PNodoABL EquilibrarArvore (PNodoABL T, LIVRO *L, int inicio, int fim) {
    int medio;
    if (inicio > fim)
        return T;
    if (inicio == fim) {
        T = InserirABP(T, L[inicio]);
        return T;
    }
    medio = (inicio + fim) / 2;
    T = InserirABP(T, L[medio]);
    T=EquilibrarArvore(T, L, inicio, medio-1);
    T=EquilibrarArvore(T, L, medio+1, fim);
    return T;
}

PNodoABL InserirABP (PNodoABL T, LIVRO X){  //Utilizar esta função para adicionar novos Livros à ABP balanceada, e depois utilizar a função CriarArvoreEquilibrada, para balancear a árvore de novo
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

PNodoABL CriarNodoAB(LIVRO X){
  PNodoABL P = (PNodoABL) malloc(sizeof(struct NodoABLivro));
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

PNodoABL RemoverABP (PNodoABL T, LIVRO X) {
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


PNodoABL RemoverNodoABP (PNodoABL T){
  PNodoABL R;
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

PNodoABL LibertarNodoAB(PNodoABL P){
  P->Esquerda = NULL;
  P->Direita = NULL;
  free(P);
  P = NULL;
  return P;
}

PNodoABL SubstituirNodoDireita (PNodoABL T, LIVRO *X){
  PNodoABL PAux;
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

PNodoABL SubstituirNodoEsquerda (PNodoABL T, LIVRO *X){
  PNodoABL PAux;
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

int PesquisarABP (PNodoABL T, LIVRO X) {  //Pesquisar na árvore binária de Pesquisa por livro ****VERIFICAR SE FUNÇÃO VAI SER USADA/ESTÁ CERTA
 PNodoABL P;
  if (T == NULL)
    return 0;
  if (CompararLivroISBN(X, T->livro) == 0)
    return 1;
  if (CompararLivroISBN(X, T->livro) == -1)   // X.ISB < (T->livro).ISBN)
    return PesquisarABP(T->Esquerda, X);
  else
    return PesquisarABP(T->Direita, X);
}

PNodoABL PesquisarporISBN (int X, PNodoABL T) {  //Pesquisar na árvore binária de Pesquisa por ISBN
 PNodoABL P;  //Porquê?
  if (T == NULL)
    return NULL;
  if (CompararLivroISBN2(X, T->livro.ISBN) == 0)
    return T;
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

void ListarLivroTitulo (char *X, PNodoABL T) {  //Lista Livros que contêm a frase pedida, no título
  if (T != NULL) {
    ListarLivroTitulo(X,T->Esquerda);
    if(contemChar(T->livro.titulo,X)==0) MostrarLivro(T->livro);
    ListarLivroTitulo(X,T->Direita);
  }
}

void ListarLivroAutor (char *X, PNodoABL T) {  //Lista Livros que contêm a frase pedida, no Autor(primeiro ou segundo)
  if (T != NULL) {
    ListarLivroAutor(X,T->Esquerda);
    if((contemChar(T->livro.primeiroAutor,X)==0)||(contemChar(T->livro.segundoAutor,X)==0)) MostrarLivro(T->livro);
    ListarLivroAutor(X,T->Direita);
  }
}

void ListarLivroEditora (char *X, PNodoABL T) {  //Lista Livros que contêm a frase pedida, na Editora
  if (T != NULL) {
    ListarLivroEditora(X,T->Esquerda);
    if(contemChar(T->livro.editora,X)==0) MostrarLivro(T->livro);
    ListarLivroEditora(X,T->Direita);
  }
}

void ListarLivroAC (char *X, PNodoABL T) {  //Lista Livros que contêm a frase pedida, na Área Cientifica
  if (T != NULL) {
    ListarLivroAC(X,T->Esquerda);
    if(contemChar(T->livro.areacientifica,X)==0) MostrarLivro(T->livro);
    ListarLivroAC(X,T->Direita);
  }
}

void ListarLivroAno (int X, PNodoABL T) {  //Lista Livros que foram publicados no ano X
  if (T != NULL) {
    ListarLivroAno(X,T->Esquerda);
    if(verificaAno(T->livro.ano,X)==0) MostrarLivro(T->livro);
    ListarLivroAno(X,T->Direita);
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
    printf("Título - %s |", X.titulo);
    printf("Idioma - %s |", X.idioma);
    printf("Primeiro autor - %s |", X.primeiroAutor);
    printf("Segundo autor - %s |", X.segundoAutor);
    printf("Editora - %s |", X.editora);
    printf("Ano - %d |", X.ano);
    printf("Área científica - %s |", X.areacientifica);
    printf("Preço - %f |", X.preco);
    printf("Stock - %d |", X.stock);
    printf("\n");
}


//Funções Lista Ligada Cliente

PNodoCliente CriarNodoCliente (CLIENTE X){
  PNodoCliente P;
  P = (PNodoCliente) malloc(sizeof(struct NodoCliente));
  if (P == NULL)
    return NULL;
  P->cliente = X;
  P->next = NULL;
  return P;
}

void LibertarNodoCliente (PNodoCliente P){
  free(P);
  P = NULL;
}

int VaziaCliente (PNodoCliente L){
  if (L == NULL)
    return 1;
  else
    return 0;
}


void ListarClienteRec (PNodoCliente L){
  if (L != NULL){
    MostrarElementoCliente(L->cliente);
    ListarClienteRec(L->next);
  }
}

void MostrarElementoCliente (CLIENTE X){  //Alterar parâmetros *****POR FAZER***
  printf("%d - ", X.NIF);
  printf("%d - ", X.morada);
  printf("%d - ", X.nome);
}

int PesquisarClienteRec (CLIENTE X, PNodoCliente L){
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

PNodoCliente RemoverClienteRec (CLIENTE X, PNodoCliente L, PNodoCliente LAux) {
  PNodoCliente P;
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

PNodoCliente InserirFim (CLIENTE X, PNodoCliente L){
  PNodoCliente P, PAux;  
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

PNodoCliente RemoverCliente (CLIENTE X, PNodoCliente L){
  PNodoCliente P, PAnt;
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

PNodoCliente ProcurarAnteriorCliente (CLIENTE X, PNodoCliente L){
  PNodoCliente Ant = NULL;
  while (L != NULL && CompararCliente(L->cliente, X) != 0){
    Ant = L;
    L = L->next;
  }
  return Ant;
}

PNodoCliente PesquisarPorNIF(long int nif,PNodoCliente L){  //Pesquisa Cliente por NIF
while(L!=NULL){
  if(L->cliente.NIF==nif) return L;
  L=L->next;
}
return NULL;
}

//Funções para consultar cliente

void ListarClienteNome(char *X,PNodoCliente L){ //Lista clientes que contêm a frase pedida, no nome
  if (L == NULL) return;
  while(L!=NULL){
    if(contemChar(L->cliente.nome,X)==0) MostrarCliente(L->cliente);
    L=L->next;
  }
}

void ListarClienteMorada(char *X,PNodoCliente L){ //Lista clientes que contêm a frase pedida, no nome
  if (L == NULL) return;
  while(L!=NULL){
    if(contemChar(L->cliente.morada,X)==0) MostrarCliente(L->cliente);
    L=L->next;
  }
}



void MostrarCliente(CLIENTE X){
    printf("NIF - %ld |", X.NIF);
    printf("Nome - %s |", X.nome);
    printf("Telefone - %ld |\n", X.telefone);
    printf("Morada - %s |\n", X.morada);
    printf("Lista de Compras:\n");
    while(X.compras!=NULL) {
      MostrarLC(X.compras);
      X.compras=X.compras->next;
    }
}


//Função para mostrar lista de compras

void MostrarLC(PNodoLC X){
  printf("Codigo de Compra - %s |", X->compra.codigo);
  printf("Dia - %d |", X->compra.datadecompra.dia);
  printf("Mes - %d |", X->compra.datadecompra.mes);
  printf("Ano - %d |", X->compra.datadecompra.ano);
  printf("Preço total - %f |", X->compra.PrecoTotal);
  printf("ISBN - %d |", X->compra.Produto);
  printf("Número de Unidades Compradas - %d |", X->compra.NumeroDeUnidadesCompradas);
}

//Funções Lista Ligada Compras


PNodoLC CriarNodoLC (COMPRA X){
  PNodoLC P;
  P = (PNodoLC) malloc(sizeof(struct NodoLC));
  if (P == NULL)
    return NULL;
  P->compra = X;
  P->next = NULL;
  return P;
}

void LibertarNodoLC (PNodoLC P){
  free(P);
  P = NULL;
}

int VaziaLC (PNodoLC L){
  if (L == NULL)
    return 1;
  else
    return 0;
}


/*void ListarLCRec (PNodoLC L){
  if (L != NULL){
    MostrarLC(L->compra);
    ListarLCRec(L->next);
  }
}

/*void MostrarLC (COMPRA X){  //Alterar parâmetros *****POR FAZER***
  printf("%d - ", X.codigo);
  printf("%d - ", X.NumeroDeUnidadesCompradas);
} */

int PesquisarLCRec (COMPRA X, PNodoLC L){
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

PNodoLC RemoverCompraRec (COMPRA X, PNodoLC L, PNodoLC LAux) {
  PNodoLC P;
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

PNodoLC InserirFimLC (COMPRA X, PNodoLC L){
  PNodoLC P, PAux;
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

PNodoLC RemoverCompra (COMPRA X, PNodoLC L){
  PNodoLC P, PAnt;
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

PNodoLC ProcurarAnteriorLC (COMPRA X, PNodoLC L){
  PNodoLC  Ant = NULL;
  while (L != NULL && CompararCompra(L->compra, X) != 0){
    Ant = L;
    L = L->next;
  }
  return Ant;
}

//Funções Filas

PNodoFilaEncomendas CriarNodoFila (ENCOMENDA X){
  PNodoFilaEncomendas P;
  P = (PNodoFilaEncomendas) malloc(sizeof(struct filaEncomendas));
  if (P == NULL)
    return NULL;
  P->encomenda = X;
  P->next = NULL;
  return P;
}

PNodoFilaEncomendas LibertarNodoFila (PNodoFilaEncomendas P){
  free(P);
  P = NULL;
  return P;
}

int FilaVazia (PNodoFilaEncomendas Fila){
  if (Fila == NULL)
    return 1;
  else
    return 0;
}

PNodoFilaEncomendas Juntar (ENCOMENDA X, PNodoFilaEncomendas Fila){
  PNodoFilaEncomendas Novo, PAnt;
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

PNodoFilaEncomendas RemoverFila (PNodoFilaEncomendas Fila){
  PNodoFilaEncomendas P;
  P = Fila;
  Fila = Fila->next;
  P = LibertarNodoFila(P);
  return Fila;
}

PNodoFilaEncomendas RemoverEncomendaFila (ENCOMENDA X, PNodoFilaEncomendas L){
  PNodoFilaEncomendas P, PAnt;
  PAnt = ProcurarAnteriorEncomenda(X, L);
  if (PAnt == NULL){   // remover elemento do início de L
    P = L;
    L = L->next;
  }
  else{
    P = PAnt->next;
    PAnt->next = P->next; // ou (PAnt->Prox)->Prox
  }
  LibertarNodoEncomenda(P);
  return  L;
}

void LibertarNodoEncomenda (PNodoFilaEncomendas P){
  free(P);
  P = NULL;
}

PNodoFilaEncomendas ProcurarAnteriorEncomenda (ENCOMENDA X, PNodoFilaEncomendas L){
  PNodoFilaEncomendas Ant = NULL;
  while (L != NULL && CompararEncomenda(L->encomenda, X) != 0){
    Ant = L;
    L = L->next;
  }
  return Ant;
}


int CompararEncomenda (ENCOMENDA X, ENCOMENDA Y){  // devolve -1 se X < Y, 0 se X = Y, 1 se X > Y Comparar Clientes
  if (X.codigo > Y.codigo)
    return 1;
  if (X.codigo < Y.codigo)
    return -1;
  return 0;
}
//Funções para destruir Estruturas



PNodoABL DestruirAB(PNodoABL T){
  if (T == NULL)
    return NULL;
  T->Esquerda = DestruirAB(T->Esquerda);
  T->Direita = DestruirAB(T->Direita);
  return LibertarNodoAB(T);
}

PNodoCliente DestruirListaClientes(PNodoCliente L){
    if(L==NULL) return NULL;
    PNodoCliente aux;
    while(L!=NULL){
        aux=L;
        aux->cliente.compras=DestruirListaCompras(aux->cliente.compras);
        aux=RemoverCliente(aux->cliente,aux);
        L=L->next;
    }
    return L;
}

PNodoLC DestruirListaCompras(PNodoLC lcompras){
    if(lcompras==NULL) return NULL;
    PNodoLC aux;
    while(lcompras!=NULL){
        aux=lcompras;
        aux=RemoverCompra(aux->compra,aux);
        lcompras=lcompras->next;
    }
    return lcompras;
}

PNodoFilaEncomendas DestruirFila(PNodoFilaEncomendas L){
    if(L==NULL) return NULL;
    PNodoFilaEncomendas aux;
    while(L!=NULL) {
      aux=L;
      aux=RemoverFila(aux);
      L=L->next;
    }
    return L;
}


//Função para passar uma compra para Encomenda

ENCOMENDA ConverterCOMPRAparaENCOMENDA(CLIENTE c,COMPRA X){
  ENCOMENDA nova;
   strcpy(nova.codigo,X.codigo);
   nova.DataDeCompra.dia=X.datadecompra.dia;
   nova.DataDeCompra.mes=X.datadecompra.mes;
   nova.DataDeCompra.ano=X.datadecompra.ano;
   nova.ISBN=X.Produto;//Produto é ISBN
   nova.NIF=c.NIF;
   nova.nmr=X.NumeroDeUnidadesCompradas;
   nova.precoTotal=X.PrecoTotal;

  return nova;
}

PNodoFilaEncomendas ComprasToEncomendas(PNodoCliente clientes,PNodoFilaEncomendas encomendas){  //Função para tornar as compras futuras em encomendas
time_t s, val = 1;
struct tm* current_time;
    
s = time(NULL);
    
current_time = localtime(&s);
int diaAtual=current_time->tm_mday;
int mesAtual=current_time->tm_mon + 1;
int anoAtual=current_time->tm_year + 1900;
int diaDoAnoAtual=current_time->tm_yday;  //Estas linhas de código são necessárias para saber o tempo atual
if(clientes==NULL) return NULL;

//if(clientes !=NULL) printf("%s\n",clientes->cliente.compras->compra.codigo);

PNodoCliente aux=clientes;
PNodoLC auxlc=aux->cliente.compras;

while(aux!=NULL){  //Vamos guardar as compras que ainda não foram efetuadas nas encomendas 
    while(auxlc!=NULL){
        if((auxlc->compra.datadecompra.ano)>anoAtual){ //Se ano da compra for mais que o Ano Atual
            COMPRA new=auxlc->compra;
            ENCOMENDA nova=ConverterCOMPRAparaENCOMENDA(aux->cliente,new);  //Passar como parametro, o cliente e a compra
            nova.DataDeEncomenda.dia=diaAtual;
            nova.DataDeEncomenda.mes=mesAtual;
            nova.DataDeEncomenda.ano=anoAtual;
            encomendas=Juntar(nova,encomendas); //Adicionar a encomenda à fila de encomendas
        }
        else if(((auxlc->compra.datadecompra.ano)==anoAtual)&&((auxlc->compra.datadecompra.mes)>mesAtual)){ //Se ano for igual e mes de compra for maior
        COMPRA new=auxlc->compra;
        ENCOMENDA nova=ConverterCOMPRAparaENCOMENDA(aux->cliente,new);
        nova.DataDeEncomenda.dia=diaAtual;
        nova.DataDeEncomenda.mes=mesAtual;
        nova.DataDeEncomenda.ano=anoAtual;
        encomendas=Juntar(nova,encomendas); //Adicionar a encomenda à fila de encomendas
        }
        else if(((auxlc->compra.datadecompra.ano)==anoAtual)&&((auxlc->compra.datadecompra.mes)==mesAtual)&&((auxlc->compra.datadecompra.dia)==diaAtual)){ //Se ano e mes de compra for igual e dia maior
        COMPRA new=auxlc->compra;
        ENCOMENDA nova=ConverterCOMPRAparaENCOMENDA(aux->cliente,new);
        nova.DataDeEncomenda.dia=diaAtual;
        nova.DataDeEncomenda.mes=mesAtual;
        nova.DataDeEncomenda.ano=anoAtual;
        encomendas=Juntar(nova,encomendas); //Adicionar a encomenda à fila de encomendas
        }
        else ;
        auxlc=auxlc->next;  //iterar a lista de compras
    }  //Fim do While de Compras
    aux=aux->next; //iterar a lista ligada de clientes


}

//printf("%s\n",clientes->cliente.compras->compra.codigo);

return encomendas;
}

void EscreverNodoABL(FILE *f,PNodoABL T){
  if(T==NULL) return;

  fprintf(f,"%d\n",T->livro.ISBN);
  fprintf(f,"%s\n",T->livro.titulo);
  fprintf(f,"%s\n",T->livro.idioma);
  fprintf(f,"%s\n",T->livro.primeiroAutor);
  fprintf(f,"%s\n",T->livro.segundoAutor);
  fprintf(f,"%s\n",T->livro.editora);
  fprintf(f,"%d\n",T->livro.ano);
  fprintf(f,"%s\n",T->livro.areacientifica);
  fprintf(f,"%f\n",T->livro.preco);
  fprintf(f,"%d\n",T->livro.stock);
  // ***TODO Resto dos fprintfs

  EscreverNodoABL(f,T->Esquerda);
  EscreverNodoABL(f,T->Direita);

}

PNodoABL LerNodoABL(FILE *f,PNodoABL T){
  LIVRO l;
  if(fscanf(f," %d\n %s\n %s\n %s\n %s\n %s\n %d\n %s\n %f\n %d\n",&l.ISBN,l.titulo,l.idioma,l.primeiroAutor,l.segundoAutor,l.editora,&l.ano,l.areacientifica,&l.preco,&l.stock) == 10) {  //Não esquecer mudar o 2
    T=InserirABP(T,l);
    T->Esquerda=LerNodoABL(f,T->Esquerda);
    T->Direita=LerNodoABL(f,T->Direita);
  }
  return T;

//TODO COMPLETAR
}


int LivrosVendidosNumDadoPeriodoDeTempo(int mes,int ano,PNodoCliente L){
  int c=0;
  if (L==NULL) return c;
  while(L!=NULL){  //Percorrer a lista de clientes
    if(L->cliente.compras==NULL){  //Se o cliente não tem uma lista de compras
      L=L->next;  //Passa ao próximo cliente
      continue;
    }
    while(L->cliente.compras!=NULL){ //Percorrer a lista de compras de um cliente
      if((L->cliente.compras->compra.datadecompra.mes==mes) && (L->cliente.compras->compra.datadecompra.ano==ano)) c= c+ L->cliente.compras->compra.NumeroDeUnidadesCompradas;  //Se o ano e o mes coincidem, guardar numero de unidades compradas
      L->cliente.compras=L->cliente.compras->next;
    }
  L=L->next;
  }

return c;
}

DATA dataDeUltimaCompra(PNodoCliente L){
  time_t s, val = 1;
  struct tm* current_time;
    
  s = time(NULL);
    
  current_time = localtime(&s);
  int diaAtual=current_time->tm_mday;
  int mesAtual=current_time->tm_mon + 1;
  int anoAtual=current_time->tm_year + 1900;
  DATA d;
  d.dia=99;  //valores arbitrários 
  d.mes=99;
  d.ano=99999;
  DATA atual;
  atual.dia=diaAtual;
  atual.mes=mesAtual;
  atual.ano=anoAtual;
  if(L==NULL) {
    d.dia=0;
    return d;
  }
  while(L!=NULL){  //Percorrer a lista de clientes
    if(L->cliente.compras==NULL){  //Se o cliente não tem uma lista de compras
      L=L->next;  //Passa ao próximo cliente
      continue;
    }
    while(L->cliente.compras!=NULL){
      if((CompararDatas(L->cliente.compras->compra.datadecompra,atual)==-1) &&(CompararDatas(L->cliente.compras->compra.datadecompra,d))==-1)  {  // Se data da compra for menor que a data atual e for menor do que a data guardada (d)
      d.dia=L->cliente.compras->compra.datadecompra.dia;
      d.mes=L->cliente.compras->compra.datadecompra.mes;
      d.ano=L->cliente.compras->compra.datadecompra.ano;
      }

    L->cliente.compras=L->cliente.compras->next;
    }

  L=L->next;
  }
  return d;
}

int CompararDatas (DATA d1, DATA d2){  //Devolve -1 se d1 for menor que d2, devolve 1 se d2 for maior que d1, devolve 0 se forem iguais

  if (d1.ano < d2.ano) return -1;
  else if (d1.ano > d2.ano) return 1;
  if (d1.ano == d2.ano){
    if (d1.mes<d2.mes) return -1;
    else if (d1.mes>d2.mes) return 1;     
    else if (d1.mes<d2.mes) return -1;
    else if(d1.mes>d2.mes) return 1;
    else return 0;
  }
}