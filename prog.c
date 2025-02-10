// Caio de Oliveira Muniz: 20242006337
//Guilherme Malard Frezzolino Pereira 20242006103
//Francisco E. N. Mesquita. matricula: 20242011266
//https://github.com/Caio3108/fila.c/tree/main
#include "fila.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main() {
    int instrucao;
    char arquivo[] = "conteudo";
    Amigo *fila = NULL;
    printf("Bem vindo a Fila!\n--Insira a Instrucao!--\n1: Enfileirar\n2: Desenfileirar\n3: Salva no Arquivo de texto\n4: Sai da fila\n");
    while (1)
    {
        scanf("%d", &instrucao);
        switch (instrucao)
        {
        case 1: // Enfileira
            int num = 0;
            fila = Enfileirar(fila, arquivo, num); /*mudar para nome fixo*/
            printf("Enfileirado com sucesso!\n");
            break;
        case 2: // Desenfileira
            Desenfileirar(&fila);
            break;
        case 3: // Salva no arquivo
            Salvar(fila, arquivo);
            break;
        }
        if (instrucao == 4){
            Esvaziar(fila);
            break;
        }
    }

    return 0;
}