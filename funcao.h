#ifndef TPV2_FUNCAO_H
#define TPV2_FUNCAO_H

int* lerFicheiro(char *nomeFicheiro, int numeroVertices, int numeroArestas);
int validarSol(int *solucao,int *matriz, int vertices);
int calcular_custo(int s[], int *mat, int v);

#endif //TPV2_FUNCAO_H
