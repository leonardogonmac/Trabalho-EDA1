#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    int topo;
    char* cadeia;
    int tam;
}pilha;

int empilha(pilha*p, char e){
    if(p->tam == p->topo) return 0;
    p->cadeia[p->topo++] = e;
    return 1;
}
int inicia_pilha(pilha *p, int tam){
    p->cadeia = malloc(sizeof(char)*tam);
    if(p->cadeia == NULL)return 0;
    p->topo = 0;
    p->tam = tam;
    return 1;
}

int pesta_vazia(pilha *p){
    return p->topo == 0;
}
char topo(pilha *p){
    return p->cadeia[p->topo-1];
}

char desempilha(pilha *p){
    p->topo--;
    return p->cadeia[p->topo];
}

int identifica_expressao(char** linhas, int qtde_linhas){
    
    pilha* p = malloc(sizeof(pilha));
    inicia_pilha(p,100*100000);    
    
    for(int i = 0; i < qtde_linhas; i++){
        char* c = linhas[i];
        while (*c != '\0'){
            if (*c == '*' || *c == '_' || *c == '/'){
                if(p->cadeia[p->topo - 1] == *c && p->topo != 0){
                    desempilha(p);
                }
                else {
                    empilha(p, *c);
                }
            }
            c += 1; 
        }
    }
    
    return p->topo;
}


int main(void){
    int n;
    scanf("%d%*c", &n);
    char* linhas[n];

    for(int i = 0; i < n; i++){
        char* frase = malloc(sizeof(char)*1000000);
        fgets(frase, 1000000, stdin);
        frase[strlen(frase)] = '\0';
        linhas[i] = frase;        
    }

    if (identifica_expressao(linhas, n) == 0){
        printf("C\n");
    }
    else{
        printf("E\n");
    }
    
    
    return 0;
}