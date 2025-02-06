#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Amigo *criação(Amigo **inicio){
    (*inicio)->proximo = NULL;
    (*inicio)->anterior = NULL;
}

int testVazia(Amigo **final) {
    int r = 0;
    if (*final == NULL)
    {
        r = 1;
    }
    return r;
}

Amigo *Enfileirar(Amigo **final){
    Amigo *nFinal = NULL;
    nFinal = malloc(sizeof(Amigo));
    fprintf( , "Nome Idade Compromisso\n");  // concertar
    fscanf( , "%s %d %s", nFinal->nome, nFinal->idade, nFinal->compromisso);
    
    
}