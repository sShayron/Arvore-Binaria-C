#ifndef _ARVOREBINARIA_H
#define _ARVOREBINARIA_H

/**
 * Tipo da informação da arvore
**/
typedef char tipoInfo;

/**
 * Estrutura da arvore binaria
 * Info do tipo char
 * Ponteiros para as sub-árvores à esquerda, e à direita
**/
struct arbin {
    tipoInfo info;
    struct arbin* esq;
    struct arbin* dir;
};

typedef struct arbin Arbin;

void criaArbinVazia();
Arbin* criaArbin(tipoInfo info, Arbin* sae, Arbin* sad);
Arbin* liberaArbin(Arbin* a);
tipoInfo raizArbin(Arbin* a);
Arbin* esqArbin(Arbin* a);
Arbin* dirArbin(Arbin* a);
int vaziaArbin(Arbin* a);
int estaArbin(Arbin* a, tipoInfo info);
void imprimeArbin(Arbin* a);
int pesoArbin(Arbin* a);
int numFolhas(Arbin* a);
int numOcorrencias(Arbin* a, tipoInfo elem);




#endif // _ARVOREBINARIA_H_
