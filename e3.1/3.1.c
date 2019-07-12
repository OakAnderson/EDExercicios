#include <stdio.h>

/*3. Vetores. Exercício 3.1 */

/*Função que conta os números negativos em um vetor */
int negativos (int n, float* vet)
{
    int i, cont = 0;

    for (i = 0; i < n; i++)     /*Conta de 0 até n, se o vet[i] for menor que zero, cont é incrementado */
        if (vet[i] < 0)
            cont++;
    
    return cont;
}

/*Função principal */
int main (void)
{
    float vet[10] = {1, -2, -6, 5, -10, 0, 18, -32, -5, -3};        /*Vetor para teste */
    int n = 10, result;

    result = negativos(n, vet);         /*Usa a função */
    printf("O vetor tem %d\n", result); /*Mostra na tela */
}