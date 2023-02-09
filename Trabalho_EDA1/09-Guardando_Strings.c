#include <stdio.h>
#include <stdio.h>
#include <string.h>

#define tamanho_de_caracteres 1000005

char string[tamanho_de_caracteres][100000];
char ultima_string[100000];

int main(){
    int  contador_de_substring, contador = 0;

    while (scanf("%s", string[contador]) != EOF) {
        contador++;
    }

    contador--;

    strcpy(ultima_string, string[contador]);
    int i = 0, j = 0,k = 0;
    //percorrer todas as strings digitadas, exceto a última.
    for ( i = 0; i < contador; i++) {
        contador_de_substring = 0;
        // percorrer a string atual, verificando se a última string cabe na string atual.
        for ( j = 0; j < strlen(string[i]) - strlen(ultima_string) + 1; j++) {
          // comparar caractere a caractere da última string com a substring da string atual
            for ( k = 0; k < strlen(ultima_string); k++) {
                if (string[i][j + k] != ultima_string[k]) {

                    break;
                }
            }
            if (k == strlen(ultima_string)) {

                contador_de_substring++;
            }
        }
        
        printf("%d\n", contador_de_substring);
    }

    return 0;
}


