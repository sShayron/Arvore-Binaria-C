#include "arvorebinaria.h"

/**
 * sae = sub-arvore da esquerda
 * sad = sub-arvore da direita
**/

/****************************************/
/********** Functions Arbin ************/
/**************************************/

/**
 * @brief Cria uma árvore vazia
 * @params
 * @return NULL
**/
Arbin* criaArbinVazia()
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
    Arbin* a  = (Arbin*)malloc(sizeof(Arbin));
    a->info = info;
    a-> esq = sae;
    a-> dir  = sad;
    return a;
}

/**
 * @brief Insere um nó na arvore
 * @parms tipoInfo, Arbin esq, Arbin dir
 * @return Arbin
**/
Arbin* insArbin(Arbin* a, tipoInfo info)
{
    printf("\nInserindo...\n");
    if(vaziaArbin(a)) {
        a = criaArbin(info, NULL, NULL);
    }
    else if (vaziaArbin(esqArbin(a)))
        a = insArbin(esqArbin(a), info);
    else if ((vaziaArbin(dirArbin(a))))
        a = insArbin(dirArbin(a), info);
    else
        printf("WTF I DO");

    return a;
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
 * @return 1 - se vazia
           0 - se não vazia
**/
int vaziaArbin(Arbin* a)
{
    return a==NULL;
}

/**     2)
 * @brief Verifica a ocorrencia de uma info na arvore
 * @params Arbin, tipoInfo
 * @return  1 - se encontrar
            0 - se nao encontrar
**/
int estaArbin(Arbin* a, tipoInfo info)
{
    if(vaziaArbin(a))
        return 0;
    else
            return (raizArbin(a)==info ||
                estaArbin(esqArbin(a), info) ||
                estaArbin(dirArbin(a), info));
}

/**
 * @brief Imprime as infos da arvore
 * @params Arbin
 * @return void
**/
void imprimeArbin(Arbin* a)
{
    printf("\n\n...Imprimindo Arvore Binaria...\n\n");
    if(!vaziaArbin(a)){
        printf("%i", raizArbin(a));
        imprimeArbin(esqArbin(a));
        imprimeArbin(dirArbin(a));
    } else {
        printf("Arvore vazia\n\n");
    }
}

/**     1)
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

/**     3)
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

/**     4)
 * @brief Calcula e retorna numero de vezes que um elemento aparece na arvore
 * @params Arbin
 * @return int
**/
int numOcorrencias(Arbin* a, tipoInfo elem){
    if(vaziaArbin(a))
        return 0;
    else if(raizArbin(a) == elem)
        return 1 + numOcorrencias(esqArbin(a),elem) + numOcorrencias(dirArbin(a),elem);
    else
        return numOcorrencias(esqArbin(a),elem) + numOcorrencias(dirArbin(a),elem);
}

/**     5)
 * @brief Verifica se existe caminho entre 2 elementos na arvore
 * @params Arbin, tipoInfo, tipoInfo
 * @return int
**/
int existeCaminho(Arbin* a, tipoInfo elemA, tipoInfo elemB) {
    Arbin *aux;
    if (vaziaArbin(a) || !(estaArbin(a, elemA), estaArbin(a, elemB))) {
        return 0;
    } else {
        if(raizArbin(a) == elemA) {
            aux = a;
            if(estaArbin(aux, elemB))
                return 1;
        } else {
            existeCaminho(esqArbin(a), elemA, elemB);
            existeCaminho(dirArbin(a), elemA, elemB);
        }
    }
    return 0;
}

/*********************************************/
/********** Functions ArbinBusca ************/
/*******************************************/

/**
 * @brief Cria uma árvore de busca vazia
 * @params
 * @return NULL
**/
ArbinBusca* criaArbinBuscaVazia()
{
    return NULL;
}

/**
 * @brief Retorna raiz da arvore de busca
 * @params ArbinBusca
 * @return tipoInfo
**/
tipoInfo raizArbinBusca(ArbinBusca* a)
{
    return a->info;
}

/**
 * @brief Retorna sub arvore de busca da esquerda
 * @params ArbinBusca
 * @return ArbinBusca
**/
ArbinBusca* esqArbinBusca(ArbinBusca* a)
{
    return a->esq;
}

/**
 * @brief Retorna sub arvore de busca da direita
 * @params ArbinBusca
 * @return ArbinBusca
**/
ArbinBusca* dirArbinBusca(ArbinBusca* a)
{
    return a->dir;
}

/**
 * @brief Indica se a arvore de busca esta vazia
 * @params ArbinBusca
 * @return  1 - se vazia
            0 - se nao vazia
**/
int vaziaArbinBusca(ArbinBusca* a)
{
    return a==NULL;
}

/**     2.1)
 * @brief Verifica a ocorrencia de uma info na arvore de busca
 * @params ArbinBusca, tipoInfo
 * @return  1 - se encontrar
            0 - se nao encontrar
**/
int estaArbinBusca(ArbinBusca* a, tipoInfo info)
{
	if (vaziaArbinBusca(a))
		return 0;
	else
		if (raizArbinBusca(a) > info)
			return estaArbinBusca(esqArbinBusca(a), info);
		else
			if (raizArbinBusca(a) < info)
				return estaArbinBusca(dirArbinBusca(a), info);
			else
				return 1;
}

/**     2.2)
 * @brief Insere um elemento na arvore de busca
 * @params ArbinBusca, tipoInfo
 * @return  AbinBusca
**/
ArbinBusca* insArbinBusca(ArbinBusca* a, tipoInfo info)
{
    if(vaziaArbinBusca(a)) {
        a = (ArbinBusca*)malloc(sizeof(ArbinBusca));
        a->info = info;
        a->esq = a->dir = NULL;
    }
    else if (info < raizArbinBusca(a))
        a->esq = insArbinBusca(esqArbinBusca(a), info);
    else
        a->dir = insArbinBusca(dirArbinBusca(a), info);
    return a;
}

/**     2.3)
 * @brief Elimina um elemento na arvore de busca
 * @params ArbinBusca, tipoInfo
 * @return  AbinBusca
**/
ArbinBusca* elimArbinBusca(ArbinBusca* a, tipoInfo info)
{
    if(vaziaArbinBusca(a))
        return NULL;
    else if (raizArbinBusca(a) > info)
            a->esq = elimArbinBusca(esqArbinBusca(a), info);
    else if (raizArbinBusca(a) < info)
            a->dir = elimArbinBusca(dirArbinBusca(a), info);
    else {
        if(a->esq == NULL && a->dir == NULL) {
            free(a);
            a = NULL;
        }
        else if(a->esq == NULL) {
            ArbinBusca* temp = a;
            a = a->dir;
            free(temp);
        }
        else if(a->dir == NULL) {
            ArbinBusca* temp = a;
            a = a->esq;
            free(temp);
        }
        else {
            ArbinBusca* pai = a;
            ArbinBusca* filho = a->esq;
            while(filho->dir != NULL) {
                pai = filho;
                filho = filho->dir;
            }
            a->info = filho->info;
            filho->info = info;
            a->esq = elimArbinBusca(esqArbinBusca(a), info);
        }
    }
    return a;
}



