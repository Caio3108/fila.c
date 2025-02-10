#ifndef _FILA_H
    #define _FILA_H

    typedef struct NO
    {
        char dia[6];
        char horario[4];
        char nome[50], compromisso[100];
        char idade[3];
        struct NO *proximo, *anterior;
    } Amigo;
    
    Amigo *criacao(Amigo *);
    int testVazia(Amigo *);
    Amigo *Enfileirar(Amigo *, char *, int num);
    Amigo *Desenfileirar(Amigo **);
    Amigo *Esvaziar(Amigo *);
    Amigo *Desalocar(Amigo *);
    void Imprimir(Amigo *);
    void Salvar(Amigo *, char *);



#endif