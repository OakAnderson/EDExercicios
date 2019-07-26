#include <stdio.h>
#include <stdlib.h>

/*4. Matrizes. Exercício 4.2 e 4.1*/

struct matriz{
    int m;
    int n;
    float** matriz;
};

/*Função que aloca uma matriz triangular inferior (economizando espaço)*/
float** aloca_ti(int m, int n)
{
    float** matriz;
    
    matriz = (float**) malloc (m*sizeof(float*));

    for (int i = m-1; i >= 0; i--)
        matriz[i] = (float*) malloc ((n-m)*sizeof(float));

    return matriz;
}

/*Função que aloca uma matriz triangular superior (economizando espaço)*/
float** aloca_ts(int m, int n)
{
    float** matriz;
    
    matriz = (float**) malloc (m*sizeof(float*));

    for (int i = 0; i < m; i++)
        matriz[i] = (float*) malloc ((n-i)*sizeof(float));

    return matriz;
}

/*Função que libera uma matriz */
void free_mat(float** matriz, int m, int n)
{
    for (int i = 0; i < m; i++)
        free(matriz[i]);
    
    free(matriz);
}

/*Função que preenche a matriz triangular inferior */
void preenche_ti(float** matriz, int m, int n)
{
    int aux = 1;

    printf("\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < aux; j++){
            printf("Valor da posição[%d][%d]: ", i+1, j+1);
            scanf(" %f", &matriz[i][j]);
        }
        aux++;
    }
}

/*Função que preenche a matriz triangular superior */
void preenche_ts(float** matriz, int m, int n)
{
    int aux = n;

    printf("\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < aux; j++){
            printf("Valor da posição[%d][%d]: ", i+1, i+j+1);
            scanf(" %f", &matriz[i][j]);
        }
        aux--;
    }
}

/*Função que mostra a matriz triangular inferior na tela */
void mostra_ti(float** matriz, int m, int n)
{
    int aux = 1;

    printf("\n\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < aux; j++){
            printf("%.0f ", matriz[i][j]);
        }
        for (int j = aux; j != n; j++){
            printf("0 ");
        }
        aux++;
        printf("\n");
    }
    printf("\n\n");
}

/*Função que mostra a matriz triangular superior na tela */
void mostra_ts(float** matriz, int m, int n)
{
    int aux = n;

    printf("\n\n");
    for (int i = 0; i < m; i++){
        for (int j = aux; j != n; j++){
            printf("0 ");
        }
        for (int j = 0; j < aux; j++){
            printf("%.0f ", matriz[i][j]);
        }
        aux--;
        printf("\n");
    }
    printf("\n\n");
}

/*Função principal */
int main(void)
{
    struct matriz mat;
    int decisao = 0;

    printf("Insira a quantidade de linhas e colunas(matriz quadrada): ");
    scanf(" %d", &mat.m);
    mat.n = mat.m;

    do{
        printf("Escolha entre as duas opções a seguir:\n\nMatriz Triangular Inferior - 1\n\nMatriz Triangular Superior - 2\n\nSua escolha: ");
        scanf(" %d", &decisao);
    } while ((decisao != 1) && (decisao != 2));

    if (decisao == 1){
        mat.matriz = aloca_ti(mat.m, mat.n);
        preenche_ti(mat.matriz, mat.m, mat.n);
        mostra_ti(mat.matriz, mat.m, mat.n);
    }
    else
    {
        mat.matriz = aloca_ts(mat.m, mat.n);
        preenche_ts(mat.matriz, mat.m, mat.n);
        mostra_ts(mat.matriz, mat.m, mat.n);
    }
    
    free_mat(mat.matriz, mat.m, mat.n);
}