#include "estruturas.h"

char *getCharDinamicamente()  // 
{
    char *line = NULL, *aux = NULL;
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
                free(line);
                line = NULL;
                break;
            }
            line = aux;
        }

        /* Guarda o caractér. */
        line[i++] = ch;
    }

    return line;
}

CLIENTE NovoCliente(){   //criar novo cliente
  CLIENTE c;
  printf("Digite o NIF do novo cliente:\n");
  c.NIF = scanf("%d",c.NIF);
  printf("Digite o nome do novo cliente:\n");
  c.nome=getCharDinamicamente();
  printf("Digite a morada do novo cliente:\n");
  c.morada = getCharDinamicamente();
  printf("Digite o número de telefone do novo cliente:\n");
  c.telefone = scanf("%ld",c.telefone);
  return c;
}

void main(){
    CLIENTE c = NovoCliente();

    printf("%s",c.nome);
    

}