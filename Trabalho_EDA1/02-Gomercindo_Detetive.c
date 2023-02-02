#include <stdio.h>
#include <stdlib.h>

typedef struct pista{
    int id;
    int valor;
    int idprox;
}pista;

typedef struct no{
    pista p;
    struct no* prox;

}no;

typedef struct cabeca{
    no* inicio;
    no* fim;
    
}cabeca;

void inicia_cabeca(cabeca* h){
    h->inicio = NULL;
    h->fim = NULL;
}

void insere_primeiro(cabeca* h, pista p){
    no* primeiro = malloc(sizeof(no));
    primeiro->p = p;
    h->inicio = primeiro;
    h->fim = primeiro;
    primeiro->prox = NULL;

}

void insere_fim(cabeca* h, pista p){
    if(h->fim == NULL){ 
        insere_primeiro(h, p); 
        return;
    }
    
    no* novo = malloc(sizeof(no));
    novo->p = p;
    h->fim->prox = novo;
    h->fim = novo;
    novo->prox = NULL;
    
}

no* busca(cabeca* h, int idprox){
    no* aux = h->inicio;
    while (aux->p.id != idprox){
        aux = aux->prox;
    }
    return aux;
}



int main(void){
    int numero_de_pistas;
    cabeca h;
    inicia_cabeca(&h);
    pista p;
    
    scanf("%d",&numero_de_pistas);
    for (int i = 0; i < numero_de_pistas; i++){
        scanf("%d %d %d",&p.id, &p.valor, &p.idprox);
        insere_fim(&h, p);

    }

    no* atual = h.inicio;
    printf("%d\n", atual->p.valor);
    
    while(atual->p.idprox != -1){
        atual = busca(&h, atual->p.idprox);
        printf("%d\n", atual->p.valor);
    }

    return 0;
}