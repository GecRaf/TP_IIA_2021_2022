#include "funcao.h"
#include "stdlib.h"
#include "stdio.h"

#define MAX 100

int* lerFicheiro(char *nomeFicheiro)
{
    FILE *f;
 //   int *p, q;
    int currentLine;
    char fl;
    char line[MAX] = {};


    f= fopen(nomeFicheiro,"r");
    if(!f)
    {
        printf("Erro no acesso ao ficheiro dos dados\n");
        exit(1);
    }
    printf("checkpoint 1");
    while( fgets(line, MAX, f))
    {
        sscanf(line, "%c", fl);
        printf("%c",fl);
    }
    printf("checkpoint 2");
   // if(fl == "")
   return 0;
  //  p=malloc(sizeof(int)m*)
}

// Calcular custo de uma solução
int calcular_custo(int s[], int *mat, int v){
    int total=0,contador=0;

    for(int i=0;i<v;i++) {
        if (s[i] == 1) {
            for (int j = 0; j < v; j++) {
                if (s[j] == 1 && *(mat + i * v + j) == 1) {
                    total++;
                }
            }
        }
    }

    if(total == 0){
        for(int j=0;j<v;j++){
            if(s[j] == 1){
                contador++;
            }
        }
        return contador;
    }
    else
        return total;
}