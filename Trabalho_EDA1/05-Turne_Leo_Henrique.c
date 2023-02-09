#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define copy(A, B)  for(int i = 0; i <= strlen(B); i++) A[i] = B[i];

typedef struct cidade{
    char nome[27];
}cidade;

typedef struct no{
    cidade c;
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

void insere_primeiro(cabeca* h, cidade c){
    no* primeiro = malloc(sizeof(no));
    primeiro->c = c;
    h->inicio = primeiro;
    h->fim = primeiro;
    primeiro->prox = NULL;

}

void insere_prox(cabeca* h, cidade c, char* ant){
    no* aux = h->inicio;
    while(strcmp(aux->c.nome, ant) != 0){
        aux = aux->prox;
    }
    no* novo = malloc(sizeof(no));
    novo->c = c;
    novo->prox = aux->prox;
    aux->prox = novo;

    if(strcmp(h->fim->c.nome, ant) == 0){
        h->fim = novo;
    }

}

void insere_fim(cabeca* h, cidade c){
    if(h->fim == NULL){ 
        insere_primeiro(h, c); 
        return;
    }
    
    no* novo = malloc(sizeof(no));
    novo->c = c;
    h->fim->prox = novo;
    h->fim = novo;
    novo->prox = NULL;
    
}

void printa_lista(cabeca* h){
    no* aux = h->inicio;
    printf("DEPOIS:\n");
    while(aux != NULL){
        printf("%s\n", aux->c.nome);
        aux = aux->prox;
    }
}

int main(){
    char string[27];
    int primeiro = 1;
    cabeca h;
    inicia_cabeca(&h);
    char ultimo;
    char string_ant[27];

    while(scanf(" %s", string )!= EOF){
        cidade c;
        copy(c.nome, string);
        
        if(primeiro == 1){
            insere_primeiro(&h, c);
            primeiro = 0;
            ultimo = string[strlen(string) - 1];
            copy(string_ant, string);
            continue;
        }

        if(string[0] == ultimo - 32){
            insere_fim(&h, c);

            if(scanf(" %s", string) == EOF) break;
            cidade c2;
            
            copy(c2.nome, string);
            
            insere_prox(&h, c2, string_ant);
            ultimo = string[strlen(string) - 1];
            copy(string_ant, c2.nome);
            continue;
        }

        insere_prox(&h, c, string_ant);
        copy(string_ant, c.nome);
        ultimo = string[strlen(string) - 1];

    }

    printa_lista(&h);

    return 0;

}