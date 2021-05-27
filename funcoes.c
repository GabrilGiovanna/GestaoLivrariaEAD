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

