#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
int main(){
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    ArvBin* raiz = cria_ArvBin();
    ArvBin* raiz2 = cria_ArvBin();
    ArvBin* raiz3 = cria_ArvBin();
    insere_ArvBin(raiz3, 9);
    for(int i=0; i < N; i++){
        insere_ArvBin(raiz,dados[i]);
        insere_ArvBin(raiz2,dados[i]);
    }
    preOrdem_ArvBin(raiz);
    //emOrdem_ArvBin(raiz);
    //posOrdem_ArvBin(raiz);
    if(arvore_similar(raiz, raiz2)==1){
        printf("As arvores sao similares\n");
    } else {
        printf("As arvores nao sao similares\n");
    }
    if(arvore_igual(raiz, raiz2)==1){
        printf("As arvores sao igauis\n");
    } else {
        printf("As arvores sao diferentes\n");
    }
    if(arvore_similar(raiz, raiz3)==1){
        printf("As arvores sao similares\n");
    } else {
        printf("As arvores nao sao similares\n");
    }
    if(arvore_igual(raiz, raiz3)==1){
        printf("As arvores sao igauis\n");
    } else {
        printf("As arvores sao diferentes\n");
    }
    if(remove_ArvBin(raiz,50)){
        printf("removido\n");
        preOrdem_ArvBin(raiz);
    }else
        printf("NAO removido\n");

    printf("\nPares removidos:\n");
    remove_pares(raiz);
    preOrdem_ArvBin(raiz);
//    printf("altura: %d\n",altura_ArvBin(raiz));
//    printf("total NOs: %d\n",totalNO_ArvBin(raiz));
//
//    if (consulta_ArvBin(raiz, 4, &al))
//        printf("\n%d %s\n",al.mat,al.nome);

    libera_ArvBin(raiz);
    printf("\nFim!\n");
    return 0;
}
