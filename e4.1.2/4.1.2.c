#include <stdio.h>
#include <stdlib.h>

#define False 0
#define True 1

/*4. Matrizes. Exercício 4.1 (matriz de ponteiros) */

/*Função que verifica se uma matriz é simétrica quadrada */
int verifica_s (float** mat, int m, int n)
{
    if (n != m)         /*Verifica se é quadrada */
        return False;
    else                /*Verifica se é simétrica (se é igual a transposta) */
    {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mat[i][j] != mat[j][i])
                    return False; 
            }
        }
    }
    
    return True;    /*Se não ocorrer nenhum caso, retorna verdadeiro */
}

/*Função que aloca uma matriz */
float** aloca_mat(int m, int n)
{
    float** matriz;
    
    matriz = (float**) malloc (m*sizeof(float*));

    for (int i = 0; i < m; i++)
        matriz[i] = (float*) malloc (n*sizeof(float));

    return matriz;
}

/*Função que libera uma matriz */
void free_mat(float** matriz, int m, int n)
{
    for (int i = 0; i < m; i++)
        free(matriz[i]);
    
    free(matriz);
}

/*Função que preenche a matriz */
void preenche_mat(float** matriz, int m, int n)
{
    printf("\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("Valor da posição[%d][%d]: ", i+1, j+1);
            scanf(" %f", &matriz[i][j]);
        }
    }
}

/*Função que mostra a matriz na tela */
void mostra_mat(float** matriz, int m, int n)
{
    printf("\n\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%.1f ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

/*Função principal */
int main(void)
{
    float** matriz;
    int linha, coluna;

    printf("Para o tamanho da matriz, digite o tamanho de linhas e de colunas: ");
    scanf(" %d %d", &linha, &coluna);

    matriz = aloca_mat(linha, coluna);
    preenche_mat(matriz, linha, coluna);
    mostra_mat(matriz, linha, coluna);

    switch (verifica_s(matriz, linha, coluna))
    {
        case True:
            printf("A matriz é quadrada e simétrica.\n");
            break;
        case False:
            printf("A matriz não é quadrada ou simétrica.\n");
            break;
    }

    free_mat(matriz, linha, coluna);

    return 0;
}