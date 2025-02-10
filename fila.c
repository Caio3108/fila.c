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

Amigo *Desenfileirar(Amigo **final) {
    if (testVazia(*final) == 0) {
        Amigo *removido = *final;
        Amigo *anterior = (*final)->anterior; 
        
        if (anterior != NULL) {
            anterior->proximo = NULL;
        }
        *final = anterior;
        return removido;
    } else {
        printf("Fila Vazia\n");
        return NULL;
    }
}

Amigo *Enfileirar(Amigo *final, char *entrada, int num) {
    Amigo *nFinal = malloc(sizeof(Amigo));
    if (nFinal == NULL) {
        printf("Erro ao alocar memória.\n");
        return final;
    }

    printf("Escreva 1 caso queira ler do txt, Escreva 0 caso queira adicionar um novo!\n");
    scanf("%d", &num);

    if (num == 0) {
        printf("Coloque o nome, idade, compromisso, dia e hora:\n");
        scanf("%s %s %s %s %s", nFinal->nome, nFinal->idade, nFinal->compromisso, nFinal->dia, nFinal->horario);
    } else {
        FILE *fs = fopen(entrada, "r");
        if (fs == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            free(nFinal);
            return final;
        }
        fscanf(fs, "%[^,], %[^,], %[^,], %[^,], %[^,]", nFinal->nome, nFinal->idade, nFinal->compromisso, nFinal->dia, nFinal->horario);
        fclose(fs);
    }

    nFinal->anterior = final;
    nFinal->proximo = NULL;

    if (final != NULL) {
        final->proximo = nFinal;
    }

    return nFinal;
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
        printf("Nome: %s, Idade: %s, Compromisso: %s\n, Dia: %s\n, Horario: %s\n", atual->nome, atual->idade, atual->compromisso, atual->dia, atual->horario);
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
        fprintf(fs,"%s, %s, %s, %s, %s\n", atual->nome,  atual->idade, atual->compromisso, atual->dia, atual->horario);
        atual = atual->proximo;
    }

    fclose(fs);
    printf("Conteudo da fila salvo no txt\n");
}