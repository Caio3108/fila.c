// Caio de Oliveira Muniz

#include "fila.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main() {
    int instrucao;
    char arquivo[10] = "conteudo";
    Amigo *fila = NULL;
    while (1)
    {
        scanf("%d", &instrucao);
        if (instrucao == 4)
            break;
        switch (instrucao)
        {
        case 1: // Enfileira
            Enfileirar(fila, arquivo); /*mudar para nome fixo*/
            break;
        case 2: // Desenfileira
            Desenfileirar(&fila);
            break;
        case 3: // Salva no arquivo
            /* code */
            break;
        }
    }
    
    
    
    
    
}