
typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, int valor);
int remove_ArvBin(ArvBin *raiz, int valor);
struct NO* remove_atual(struct NO* atual);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, int valor);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);
int folhas_ArvBin(ArvBin *raiz);
int valor_especifico_ArvBin(ArvBin *raiz, int valor);
void imprimir_ArvBin(ArvBin *raiz, int nivel);
void imprimir_decrescente_ArvBin(ArvBin *raiz);
int arvore_igual(ArvBin *raiz, ArvBin *raiz2);
int remove_pares(ArvBin *raiz);
int arvore_similar(ArvBin *raiz, ArvBin *raiz2)
