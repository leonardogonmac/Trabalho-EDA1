#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int* v;
    int topo;
    int tam;
}pilha;

void inicia_pilha(pilha* p, int tam){
    p->v = malloc(sizeof(int)*tam);
    if (p->v == NULL) return;
    p->topo = 0;
    p->tam = tam;
}

int topo(pilha *p){
    return p->v[p->topo-1];
}

int pesta_vazia(pilha *p){
    return p->topo == 0;
}
void empilha(pilha *p , int e){
    if (p->tam == p ->topo) return;
    p->v[p->topo++] = e;

}
int desempilha(pilha *p){
    p->topo--;
    return p->v[p->topo];
}
int verifica_trajeto(pilha *p ,  int* v, int qtde){
    int menor = 1;
    int pos = 0;
    while(menor <= qtde){
        while(pos < qtde){
            if(menor > 1 && p->topo > 0){
                if(topo(p) == menor){
                    desempilha(p);
                    break;
                } 
            }
            
            if(v[pos] > menor){
                if(p->topo > 0 && v[pos] > topo(p) ){
                    return 0;
                }
                empilha(p, v[pos]);
                pos++;
            }
            else{
                pos++;
                break;
            }
        }
        menor++;
    
    }

    return 1;
    
}


int main(){
    int numero_de_carros;
    
    pilha p;

    scanf("%d", &numero_de_carros);

    while(numero_de_carros != 0){
        int *carros = malloc(sizeof(int)*numero_de_carros);
        inicia_pilha(&p, numero_de_carros);
    
        for (int i = 0; i < numero_de_carros; i++){
            scanf("%d",&carros[i]);
        }
        if(verifica_trajeto(&p,carros, numero_de_carros)){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
        scanf("%d", &numero_de_carros);
    
    }

    return 0;

}