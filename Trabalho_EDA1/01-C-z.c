#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char* str;
    struct no* prox;
}no;

typedef struct cabeca{
    no* inicio;

}cabeca;

void inicia_cabeca(cabeca* h){
    h->inicio = NULL;
}

void insere_inicio(cabeca* h, char* str){
    no* novo = malloc(sizeof(no));
    novo->str = str;
    novo->prox = h->inicio;
    h->inicio = novo;

}

no* remove_inicio(cabeca* h){
    if(h->inicio == NULL) return NULL;
    no* aux = h->inicio;
    h->inicio = aux->prox;
    return aux;

}

int main(void){
    char comando[10];
    cabeca h;
    inicia_cabeca(&h);

    while(scanf(" %s", comando) != EOF){
        char* str = malloc(sizeof(char)*101);
        no* desfeito;
        if(strcmp(comando, "inserir") == 0){
            scanf(" %[^\n]%*c", str);
            insere_inicio(&h, str);

        }
        else {
            desfeito = remove_inicio(&h);
            if(desfeito == NULL) printf("NULL\n");
            else printf("%s\n", desfeito->str);
        }
    
    }

    return 0;
}