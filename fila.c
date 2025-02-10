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
        

        fscanf(fs , "%s, %d, %s, %d, %d", nFinal->nome, &nFinal->idade, nFinal->compromisso, &nFinal->dia, &nFinal->horario); // add campos
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
        

        fscanf(fs , "%s, %d, %s, %d, %d", final->nome, &final->idade, final->compromisso, &final->dia, &final->horario); // add campos
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
        copia.idade = (*final)->dia;
        copia.idade = (*final)->horario;

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

Amigo *Esvaziar(Amigo *final)
{
    if (final == NULL)
    {
        return NULL;
    }
    Amigo *anterior = final->anterior;
    free(final);

    return Esvaziar(anterior);
}

Amigo *Desalocar(Amigo *final)
{
    return Esvaziar(final);
}

void Imprimir(Amigo *final)
{
    Amigo *atual = final;
    while (atual != NULL)
    {
        printf("Nome: %s, Idade: %d, Compromisso: %s\n, Dia: %d\n, Horario: %d\n", atual->nome, atual->idade, atual->compromisso, atual->dia, atual->horario);
        atual = atual->anterior;
    }
}

void Salvar(Amigo *inicio, char *entrada) {
    FILE *fs = NULL;
    fs = fopen(entrada, "a");
    if (fs == NULL)
    {
        printf("erro\n");
        return;
    }

    Amigo *atual = inicio;
    while (atual != NULL) {
        fprintf(fs,"Nome : %s, Idade: %d, Compromisso: %s, Dia: %d, Horario: %d\n", atual->nome,  atual->idade, atual->compromisso, atual->dia, atual->horario);
        atual = atual->proximo;
    }

    fclose(fs);
    printf("Conteudo da fila salvo no txt\n");
}