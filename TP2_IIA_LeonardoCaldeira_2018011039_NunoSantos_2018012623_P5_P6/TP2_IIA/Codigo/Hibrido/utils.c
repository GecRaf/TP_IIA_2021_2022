#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmo.h"
#include "utils.h"

#include "trepa_colinas.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TC_POP_INIT 0
#define TC_SOL_FINAL 1
#define AMBOS 2

// Inicializa��o do gerador de n�meros aleat�rios
void init_rand()
{
	srand((unsigned)time(NULL));
}

// Leitura dos par�metros e dos dados do problema
// Par�metros de entrada: Nome do ficheiro e matriz
// Par�metros de sa�da: Devolve a estrutura com os par�metros
int * init_data(char *filename, struct info * x)
{

	FILE    *f;
	int lixo;
        int pop[3] = {10,50,100};
        int tsize[1] = {2};
        int max_gen[2] = {2500,5000};
        float pm[4] = {0.0,0.001,0.01,0.05};
        float pr[3]={0.3,0.5,0.7};
        
	int *p, *k, *q;
	int i, j;
	char z[] = "0"; //lel
	char y[] = "1"; //lel
        
 
        f=fopen(filename, "r");
	if(!f)
	{
		printf("Erro no acesso ao ficheiro dos dados\n");
		exit(1);
	}
	
	fscanf(f, " %d", &x->numGenes);
	
	fscanf(f, " %d", &lixo);
        
	// Alocacao dinamica da matriz
	p = malloc(sizeof(int) * x->numGenes * x->numGenes);
	if(!p)
	{
	    printf("Erro na alocacao de memoria\n");
	    exit(1);
	}
	
        q=p;
	// Preenchimento da matriz com zeros
	for (i = 0; i < x->numGenes; i++)
		for (j = 0; j < x->numGenes; j++)
			sscanf(z, "%d", q++);
	k = p;
        
	//preenchendo de acordo com o ficheiro
	while (fscanf(f, "%d %d", &i, &j) == 2){
            
            sscanf(y, "%d", k + offset(i-1, j-1, x->numGenes));   
	}
        
	fclose(f);
	
        x->popsize = 100;
        x->pm = 0.05;
        x->pr = 0.3;
        x->tsize = 2;
        x->numGenerations = 2500;
	x->ro = 0.0;
	
	return p;
}


// Criacao da populacao inicial. O vector e alocado dinamicamente
// Par�metro de entrada: Estrutura com par�metros do problema
// Par�metro de sa�da: Preenche da estrutura da popula��o apenas o vector bin�rio com os elementos que est�o dentro ou fora da mochila
pchrom init_pop(struct info d, int aplicaTrepaColinas, int * grafo)
{
	int     i, j;
	pchrom  indiv;
        
 
	indiv = malloc(sizeof(chrom)*d.popsize);
	if (indiv==NULL)
	{
		printf("Erro na alocacao de memoria\n");
		exit(1);
	}
	for (i=0; i<d.popsize; i++){
            gera_sol_inicial(indiv[i].p , d.numGenes);
            
        }
        
       // printf("chego");
        
        if(aplicaTrepaColinas == TC_POP_INIT || aplicaTrepaColinas == AMBOS)
        {
          
            for (i=0; i<d.popsize; i++){
                 // for(int k=0; k< d.numGenes; k++)printf("%d ",indiv[i].p[k] );printf("\n\n");
                TrepaColinasAutomatico(d.numGenes, 200, grafo, indiv[i].p);
                  //   for(int k=0; k< d.numGenes; k++)printf("%d ",indiv[i].p[k] );printf("\n\n");
        }
        }
        
return indiv;	
}

// Actualiza a melhor solu��o encontrada
// Par�metro de entrada: populacao actual (pop), estrutura com par�metros (d) e a melhor solucao encontrada at� a gera��oo imediatamente anterior (best)
// Par�metro de sa�da: a melhor solucao encontrada at� a gera��o actual
chrom get_best(pchrom pop, struct info d, chrom best)
{
	int i;

	for (i=0; i<d.popsize; i++)
	{
		if (best.fitness > pop[i].fitness)
			best=pop[i];
          //printf("bestFit: %f\n", best.fitness); 
	}
	return best;
}

// Devolve um valor inteiro distribuido uniformemente entre min e max
int random_l_h(int min, int max)
{
	return min + rand() % (max-min+1);
}

// Devolve um valor real distribuido uniformemente entre 0 e 1
float rand_01()
{
	return ((float)rand())/RAND_MAX;
}

// Escreve uma solu��o na consola
// Par�metro de entrada: populacao actual (pop) e estrutura com par�metros (d)
void write_best(chrom x, struct info d)
{
	int i;

	printf("\nBest individual: %4.1f\n", x.fitness);
	for (i=0; i<d.numGenes; i++)
		printf("%d ", x.p[i]);
	putchar('\n');
}




int probEvento(float prob){
    return prob > ((float)rand()/RAND_MAX);
}
/*offset da matriz de adjacencia*/
int offset(int i, int j, int cols) {
	return i * cols + j;
}

// Gera a solucao inicial
// Parametros: solucao, numero de vertices
//na soluçao inicial temos de atribuir numeros de 0 a n_vert, nao repetidos
void gera_sol_inicial(int *sol, int vert)
{
int i;
    int * arrayAleatorio,* p;
    int numTrocas= 2*vert;
    int aux1=0, aux2=0, temp;
    
    arrayAleatorio = malloc(vert * sizeof(vert));
  
    //coloca os rotulos ordenados para cada vertice
    for(int i = 0; i<vert; i++){
        arrayAleatorio[i] = i+1;
    }

    //troca os rotulos
    for(int i =0;i<numTrocas; i++){
        aux1= random_l_h(0,vert-1);
        aux2= random_l_h(0,vert-1);
        
        if(aux1 != aux2)
        {
            temp = arrayAleatorio[aux1];
            arrayAleatorio[aux1]=arrayAleatorio[aux2];
            arrayAleatorio[aux2] = temp;
        }
    }

        //atribui os rotulos aleatorios à soluçao
        for(i=0; i<vert; i++)
            sol[i]=arrayAleatorio[i];
    
    

      free(arrayAleatorio);
}
