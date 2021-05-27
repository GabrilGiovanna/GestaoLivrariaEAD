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


//Funcões para criar uma árvore binária balanceada
NODOABL CriarArvoreEquilibrada (NODOABL *T) {//Algoritmo dado nas aulas para criar árvore binária equilibrada
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

NODOABL InserirABP (NODOABL *T, LIVRO X){
  if (T == NULL) {
    T = CriarNodoAB(X);
    return T;
  }
  if (CompararElementosLivro(X, T->livro) == -1)
    T->Esquerda = InserirABP(T->Esquerda, X);
  else
    T->Direita = InserirABP(T->Direita, X);
  return T;
}

NODOABL CriarNodoAB(LIVRO X){
  NODOABL *P = (NODOABL*) malloc(sizeof(NODOABL));
  if (P == NULL)
    return  NULL;
  P->livro = X;
  P->Esquerda = NULL;
  P->Direita = NULL;
  return P;
}


int CompararElementosLivro (LIVRO X, LIVRO Y){  // devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
  if (X.ISBN > Y.ISBN)
    return 1;
  if (X.NIF < Y.NIF)
    return -1;
  return 0;
}
