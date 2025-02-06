#ifndef _FILA_H
    #define _FILA_H

    typedef struct NO
    {
        //mais 3 campos
        char nome[50], compromisso[100];
        int idade;
        NO *proximo, *anterior;
    } Amigo;
    
    Amigo *criação(Amigo **);
    int testVazia(Amigo **);
    Amigo *Enfileirar(Amigo **);
    Amigo *Desenfileirar(Amigo **);
    Amigo *Esvaziar(Amigo **);
    Amigo *Desalocar(Amigo **);
    Amigo *Imprimir(Amigo **);



#endif