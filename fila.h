#ifndef _FILA_H
    #define _FILA_H

    typedef struct NO
    {
        int dia;
        int horario;
        char nome[50], compromisso[100];
        int idade;
        struct NO *proximo, *anterior;
    } Amigo;
    
    Amigo *criacao(Amigo *);
    int testVazia(Amigo *);
    Amigo *Enfileirar(Amigo *, char *);
    Amigo Desenfileirar(Amigo **);
    Amigo *Esvaziar(Amigo *);
    Amigo *Desalocar(Amigo *);
    void Imprimir(Amigo *);
    void Salvar(Amigo *, char *);



#endif