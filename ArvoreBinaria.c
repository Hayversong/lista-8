#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h" //inclui os Prot�tipos

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};


ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada n�
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento j� existe
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 � o n� anterior a r na ordem e-r-d
    // no1 � o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}


void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

/*exercicio-1 resolvido em sala*/
int folhas_ArvBin(ArvBin *raiz){
    if(estaVazia_ArvBin((*raiz) -> esq) && estaVazia_ArvBin((*raiz) -> dir)){
        return 1;
    }
    else if(!estaVazia_ArvBin((*raiz) -> esq) && estaVazia_ArvBin((*raiz) -> dir)){
        return folhas_ArvBin(&((*raiz) -> esq));
    }else if(estaVazia_ArvBin((*raiz) -> esq) && !estaVazia_ArvBin((*raiz) -> dir)){
        return folhas_ArvBin(&((*raiz) -> dir));
    }
    return folhas_ArvBin(&((*raiz) -> esq)) + folhas_ArvBin(&((*raiz) -> dir));
}

/*exercicio-3 resolvido em sala*/
int valor_especifico_ArvBin(ArvBin *raiz, int valor){
    if(estaVazia_ArvBin(raiz)){
        return 0;
    }
    else if((*raiz) -> info == valor){
        return 1 + valor_especifico_ArvBin(&((*raiz) -> dir), valor);
    }else if((*raiz) -> info < valor){
        return  valor_especifico_ArvBin(&((*raiz) -> dir), valor);
    }
    return valor_especifico_ArvBin(&((*raiz) -> esq), valor);
}

void imprimir_ArvBin(ArvBin *raiz, int nivel){
    if(raiz == NULL || *raiz == NULL) return;
    for (int i = 0; i < nivel; i++)//recuo que vai ser proporcional ao nivel
        printf("   ");

    if((*raiz) -> esq == NULL && (*raiz) -> dir == NULL){
        printf("folha: ");
    }else{
        printf("no: ");
    }

    printf("%d\n", (*raiz)->info);

    imprimir_ArvBin(&(*raiz)->esq, nivel + 1);
    imprimir_ArvBin(&(*raiz)->dir, nivel + 1);

    /*a ideia é fazer a arvore ser percorrida inteira e imprimir cada nodo com um recuo
    que seja proporcional ao nivel dele na arvore, faz a verificação para saber se é nodo ou folha
    e a impressao segue
    */
}


void imprimir_decrescente_ArvBin(ArvBin *raiz){
    if(raiz == NULL || *raiz == NULL) return;

    imprimir_decrescente_ArvBin(&((*raiz) -> dir)); //anda pelo galho da direita primeiro

    if((*raiz) -> esq == NULL && (*raiz) -> dir == NULL){//faz a verificação pra ver se é folha
        printf("%d ", (*raiz) -> info);
    }

    imprimir_decrescente_ArvBin(&((*raiz) -> esq));

    /*Percorre a arvore de forma contrária, vai primeiro para a direita, depois o nodo atual
    e então a parte da esquerda, assim faz ficar decrescente*/
}

int arvore_igual(ArvBin *raiz, ArvBin *raiz2){
    if(raiz == NULL || raiz2 == NULL) return 0;
    struct NO* no = *raiz;
    struct NO* no2 = *raiz2;
    if(no==NULL && no2==NULL) return 1;
    if(no==NULL || no2==NULL) return 0;
    if(no->info != no2->info) return 0;
    arvore_igual(&((*raiz) -> esq), &((*raiz2) -> esq));
    arvore_igual(&((*raiz) -> dir), &((*raiz2) -> dir));
    /*
    Lógica usada: cria um no para cada arvore, caso os dois sejam null,
    quer dizer que as duas chegaram ao final ao mesmo tempo sem encontrar
    valores diferentes, aí retorna 1 (igual), mas caso alguma chegue ao final
    antes da outra, signfica que tem tamanhos diferentes, retornando 0 (diferente),
    caso não caía em nenhum desses ifs ele compara o valor de cada no, se passar
    chama a funcao novamente passando a esquerda e a direita.
    */
}
int remove_pares(ArvBin *raiz){
    if(raiz == NULL|| *raiz == NULL) return 0;
    remove_pares(&((*raiz) -> esq));
    remove_pares(&((*raiz) -> dir));
    if((*raiz)->info % 2 == 0) remove_ArvBin(raiz, (*raiz)->info);
    return 1;
    /*
    Lógica usada: percorre a arvore conferindo o resto dos valores por 2,
    toda vez que for igual a zero chama a função de remover valor passando
    o valor.
    */
}
int arvore_similar(ArvBin *raiz, ArvBin *raiz2){
    if(raiz == NULL || raiz2 == NULL) return 0;
    if(*raiz == NULL && *raiz2 == NULL) return 1;
    if(*raiz == NULL || *raiz2 == NULL) return 0;
    arvore_similar(&((*raiz)->esq), &((*raiz2)->esq));
    arvore_similar(&((*raiz)->dir), &((*raiz2)->dir));
    /*
    Lógica usada: percorre as duas arvores até chegar ao final,
    caso as duas cheguem ao final ao mesmo tempo, possuem a mesma
    estrutra, caso cheguem uma chegue antes da outra, possuem
    estrutureas diferentes.
    */
}


