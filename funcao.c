#include "funcao.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define MAX 100

int* lerFicheiro(char *nomeFicheiro, int numeroVertices, int numeroArestas)
{
    FILE *f;
    int col = 2, temp = 0;
    char fl[MAX];
    char line[MAX] = {};
    int (*grafo)[numeroArestas][col];

    f= fopen(nomeFicheiro,"r");
    if(!f)
    {
        printf("Erro no acesso ao ficheiro dos dados\n");
        exit(1);
    }
    printf("checkpoint 1");
    while(fgets(line, sizeof(line), f)){
        sscanf(line, "%s", fl);
        printf("%s ", fl);
     //   if( strcmp(fl, "c") == 0){S
     //       printf("deu c\n");
     //   }
        if( strcmp(fl,"p") == 0){
            
            sscanf(line,"p edge %d %d", &numeroVertices, &numeroArestas);
            printf("%d %d", numeroVertices, numeroArestas);
            int *grafo = malloc(col * numeroArestas * sizeof(int));
            printf("%d", grafo[0]);
        }
        else if( strcmp(fl,"e") == 0){
            
            sscanf(line, "e %d %d", grafo[temp][0], grafo[temp][1]);
          //  printf("%d %d", &grafo[temp][0], &grafo[temp][1]);
      
            temp++;
       
        }
        
      }
      
    printf("checkpoint 2");
    fclose(f);
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