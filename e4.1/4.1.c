#include <stdio.h>
#include <stdlib.h>

/*4.Matrizes. Exercício 4.1 */

/*Função que verifica se uma matriz é simétrica quadrada - Vetor simples */
int verifica_s (float mat[], int n, int m)
{
    int i, j;

    if (n != m)     /*Verifica se é quadrada, se não for, retorna falso */
        return 0;
    else{           /*Verifica se é simétrica */
        for (i = 1; i < n; i++)
            for (j = 0; j < m; j++)
                if (mat[j*m+i] != mat[i*n+j])
                    return 0;
    }

    return 1;   /*Caso não tenha encontrado nenhum caso anterior, retorna verdadeiro */
}

int main (void)
{
    float vet[6] = {
        3,5,6,
        5,2,4
    };

    if (verifica_s(vet, 2, 3))
        printf("É quadrada e simétrica\n");
    else
        printf("Não é quadrada ou simétrica\n");

    return 0;
}