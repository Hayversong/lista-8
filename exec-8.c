#include <stdio.h>
#include <stdlib.h>

struct NO {
    char info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin() {
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no) {
    if (no == NULL) return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
}

void libera_ArvBin(ArvBin* raiz) {
    if (raiz == NULL) return;
    libera_NO(*raiz);
    free(raiz);
}

int insere_ArvBin(ArvBin* raiz, char valor) {
    if (raiz == NULL) return 0;
    struct NO* novo = (struct NO*) malloc(sizeof(struct NO));
    if (novo == NULL) return 0;
    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    if (*raiz == NULL) {
        *raiz = novo;
    } else {
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while (atual != NULL) {
            ant = atual;
            if (valor == atual->info) {
                free(novo);
                return 0; // já existe
            }
            if (valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if (valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
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

    printf("%c\n", (*raiz)->info);

    imprimir_ArvBin(&(*raiz)->esq, nivel + 1);
    imprimir_ArvBin(&(*raiz)->dir, nivel + 1);
}

int main() {
    char elementos[] = {'M', 'F', 'S', 'D', 'J', 'P', 'U', 'A', 'E', 'H', 'Q', 'T', 'W', 'K'};
    int N = sizeof(elementos) / sizeof(elementos[0]);

    ArvBin *raiz = cria_ArvBin();

    for (int i = 0; i < N; i++) {
        insere_ArvBin(raiz, elementos[i]);
    }

    printf("\nestrutura:\n");
    imprimir_ArvBin(raiz, 0);

    libera_ArvBin(raiz);
    return 0;
}

/*pra não ter que mudar as informações das variáveis eu resolvi fazer esse outro arquivo com as funções alteradas para receberem caracteres
os caracteres são colocados um por um respeitando a régra de árvore, a função de imprimir percorre a árvore e imprime cada um dos nodos com recuos que são os niveis deles na hierarquia
*/