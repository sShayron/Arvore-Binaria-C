#ifndef _ARVOREBINARIA_H
#define _ARVOREBINARIA_H

/**
 * Tipo da informação da arvore
**/
typedef int tipoInfo;

/**
 * Estrutura da arvore binaria
 * Info do tipo int
 * Ponteiros para as sub-árvores à esquerda, e à direita
**/
typedef struct arbin {
    tipoInfo info;
    struct arbin* esq;
    struct arbin* dir;
} Arbin;

typedef struct arbinbusca {
    tipoInfo info;
    struct arbinbusca* esq;
    struct arbinbusca* dir;
} ArbinBusca;

// Functions Arbin
Arbin* criaArbinVazia();
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

// Functions ArbinBusca
ArbinBusca* criaArbinBuscaVazia();
ArbinBusca* esqArbinBusca(ArbinBusca* a);
ArbinBusca* dirArbinBusca(ArbinBusca* a);
int vaziaArbinBusca(ArbinBusca* a);
int estaArbinBusca(ArbinBusca* a, tipoInfo info) ;






#endif // _ARVOREBINARIA_H_
