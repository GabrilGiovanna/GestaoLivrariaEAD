#include "estruturas.h"

char *getCharDinamicamente()  // 
{
    char *line = NULL, *aux = NULL;
    size_t size = 0, i = 0;
    int ch = EOF;

    while (ch) {
        ch = getc(stdin);

        /* Check if we need to stop. */
        if (ch == EOF || ch == '\n')
            ch = 0;

        /* Check if we need to expand. */
        if (size <= i) {
    
            aux =(char*)realloc(aux,i*sizeof(char*));
            if (!aux) {
                free(line);
                line = NULL;
                break;
            }
            line = aux;
        }

        /* Actually store the thing. */
        line[i++] = ch;
    }

    return line;
}
