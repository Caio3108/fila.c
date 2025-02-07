#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Amigo *criação(Amigo *inicio){
    inicio = malloc(sizeof(Amigo));
    inicio->proximo = NULL;
    inicio->anterior = NULL;
    return inicio;
}

int testVazia(Amigo *final) {
    int r = 0;
    if (final == NULL)
    {
        r = 1;
    }
    return r;
}

Amigo *Enfileirar(Amigo *final, char *entrada){
    if (final == NULL)
    {
        final = criação(final);
    }
    
    Amigo *nFinal = NULL;
    nFinal = malloc(sizeof(Amigo)); 
    FILE *fs = NULL;
    fs = fopen(entrada, "r");
    if (fs == NULL)
    {
        printf("erro\n");
        return;
    }
    

    fscanf(fs , "%s %d %s", nFinal->nome, &nFinal->idade, nFinal->compromisso); // add campos
    fclose(fs);
    final->proximo = nFinal;
    nFinal->anterior = final;
    final = nFinal;
    return final;
}

Amigo Desenfileirar(Amigo **final)
{
    if (testVazia(*final == 0))
    {
        Amigo copia, *anterior = ((*final)->proximo)->anterior;
        anterior = NULL;
        strcpy(copia.compromisso, (*final)->compromisso);
        copia.idade = (*final)->idade;
        strcpy(copia.nome, (*final)->nome);

        free(*final);
        *final = ((*final)->proximo)->anterior;
        return copia;
    }
    
    
}