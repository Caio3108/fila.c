#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Amigo *criacao(Amigo *inicio){
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
    Amigo *nFinal = NULL;
    if (final == NULL)
    {
        final = criacao(final);
    }
    if (testVazia(final) == 0)
    {
        
        nFinal = malloc(sizeof(Amigo)); 
        FILE *fs = NULL;
        fs = fopen(entrada, "r");
        if (fs == NULL)
        {
            printf("erro\n");
            return final;
        }
        

        fscanf(fs , "%s ,%d ,%s", nFinal->nome, &nFinal->idade, nFinal->compromisso); // add campos
        fclose(fs);
        final->proximo = nFinal;
        nFinal->anterior = final;
        final = nFinal;
        return final;
    }
    else
    {
        FILE *fs = NULL;
        fs = fopen(entrada, "r");
        if (fs == NULL)
        {
            printf("erro\n");
            return final;
        }
        

        fscanf(fs , "%s,%d,%s", final->nome, &final->idade, final->compromisso); // add campos
        fclose(fs);
        return final;
    }
    
    
}

Amigo Desenfileirar(Amigo **final)
{
    if (testVazia(*final) == 0)
    {
        Amigo copia, *anterior = ((*final)->proximo)->anterior;
        anterior = NULL;
        strcpy(copia.compromisso, (*final)->compromisso);
        copia.idade = (*final)->idade;
        strcpy(copia.nome, (*final)->nome);

        free(*final);
        *final = anterior;
        return copia;
    }
    else
    {
        printf("Fila Vazia\n");
        return **final;
    }
    
}

Amigo *Esvaziar(Amigo **final)
{
    while (*final != NULL)
    {
        Amigo *temp = *final;
        *final = (*final)->anterior;
        free(temp);
    }
    return NULL;
}

Amigo *Desalocar(Amigo **final)
{
    return Esvaziar(final);
}
