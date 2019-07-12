#include <stdio.h>

/*3. Vetores. Exercício 3.2 */

/*Função que conta a quantidade de pares em um vetor */
int pares (int n, int* vet)
{
    int i, cont = 0;
    for (i = 0; i < n; i++)
        if (vet[i] % 2 == 0)    /*Se o número for divisível por 2, ele é par. Acrescenta-se 1 ao contador */
            cont++;
    return cont;
}

/*Função principal */
int main (void)
{
    int vet[10] = {1, 2, 15, 16, 28, 19, 23,54, 453, 234};      /*Vetor para teste */
    int result;

    result = pares(10, vet);

    printf("Pares: %d\n", result);

    return 0;
}