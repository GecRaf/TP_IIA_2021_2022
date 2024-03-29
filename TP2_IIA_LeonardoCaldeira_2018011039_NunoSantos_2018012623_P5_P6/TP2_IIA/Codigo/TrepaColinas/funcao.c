#include "funcao.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>



// Calcula a qualidade de uma solu��o
// Recebe:  A solu��o, a, a matriz de adjac�ncias, mat, e o n�mero de v�rtices, vert
// Devolve: O custo da ligaçao, (custo = v(a)- v(b))
int calcula_fit(int a[], int *mat, int vert)
{
	int custo=0;
        int aux=0;
        int offsetv=0;
	int i, j;
        //o custo da solucao equivale a diferenca entre duas ligacoes
	for(i=0; i<vert; i++)
	{
            for(int j= 0 ; j < vert ; j++)
            {
                offsetv = offset(i,j,vert);
                if(mat[offsetv] == 1)
                {
                    aux = abs(a[i]-a[j]);
                    if(aux > custo)
                        custo=aux;
                }  
            }
        }
     
	return custo;
}



