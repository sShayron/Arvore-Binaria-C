#include "arvorebinaria.h"

/**
 * sae = sub-arvore da esquerda
 * sad = sub-arvore da direita
**/

/**
 * @brief Cria uma árvore vazia
 * @params
 * @return NULL
**/
void criaArbinVazia()
{
    return NULL;
}

/**
 * @brief Cria e retorna posição do nó raiz
 * @parms tipoInfo, Arbin esq, Arbin dir
 * @return Arbin
**/
Arbin* criaArbin(tipoInfo info, Arbin* sae, Arbin* sad)
{
    Arbin* p  = (Arbin*)malloc(sizeof(Arbin));
    p->info = info;
    p-> esq = sae;
    p-> dir  = sad;
    return p;
}

/**
 * @brief Libera memoria alocada pela estrutura da arvore
 * @params Arbin
 * @return NULL
**/
Arbin* liberaArbin(Arbin* a)
{
    if(!vaziaArbin(a)){
        liberaArbin(esqArbin(a));
        liberaArbin(dirArbin(a));
        free(a);
    }
    return NULL;
}

/**
 * @brief Retorna raiz da arvore
 * @params Arbin
 * @return tipoInfo
**/
tipoInfo raizArbin(Arbin* a)
{
    return a->info;
}

/**
 * @brief Retorna sub arvore da esquerda
 * @params Arbin
 * @return Arbin
**/
Arbin* esqArbin(Arbin* a)
{
    return a->esq;
}

/**
 * @brief Retorna sub arvore da dir
 * @params Arbin
 * @return Arbin
**/
Arbin* dirArbin(Arbin* a)
{
    return a->dir;
}

/**
 * @brief Indica se a arvore esta vazia
 * @params Arbin
 * @return true/false
**/
int vaziaArbin(Arbin* a)
{
    return a==NULL;
}

/**
 * @brief Verifica a ocorrencia de uma info na arvore
 * @params Arbin, tipoInfo
 * @return true/false
**/
int estaArbin(Arbin* a, tipoInfo info)
{
    if(vaziaArbin(a))
        return 0; // Não encontrou
    else
            return raizArbin(a)==info ||
                estaArbin(esqArbin(a), info) ||
                estaArbin(dirArbin(a), info);
}

/**
 * @brief Imprime as infos da arvore
 * @params Arbin
 * @return void
**/
void imprimeArbin(Arbin* a)
{
    if(!vaziaArbin(a)){
        printf("%i", raizArbin(a));
        imprimeArbin(esqArbin(a));
        imprimeArbin(dirArbin(a));
    }
}

/**
 * @brief Calcula e retorna peso da arvore (número de elementos da árvore)
 * @params Arbin
 * @return int
**/
int pesoArbin( Arbin* a){
    if(vaziaArbin(a))
        return 0;
    else{
        return 1 + pesoArbin(esqArbin(a)) + pesoArbin(dirArbin(a));
    }
}

/**
 * @brief Calcula e retorna numero de folhas da arvore
 * @params Arbin
 * @return int
**/
int numFolhas(Arbin* a){
    if(vaziaArbin(a))
        return 0;
    else if(vaziaArbin(esqArbin(a)) && vaziaArbin(dirArbin(a)))
        return 1;
    else return numFolhas(esqArbin(a)) + numFolhas(dirArbin(a));

}

/**
 * @brief Calcula e retorna numero de vezes que um elemento aparece na arvore
 * @params Arbin
 * @return int
**/
int numOcorrencias(Arbin* a, elem){
    if(vaziaArbin(a))
        return 0;
    else if(raizArbin(a) == elem)
        return 1 + numOcorrencias(esqArbin(a),elem) + numOcorrencias(dirArbin(a),elem);
    else
        return numOcorrencias(esqArbin(a),elem) + numOcorrencias(dirArbin(a),elem);
}

