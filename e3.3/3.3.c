#include <stdio.h>

/*3. Vetores. Exercícios 3.3 */

/*Função que inverte a ordem dos elementos de um vetor */
void inverte (int n, int* vet)
{
    int i, cont = n-1, aux;         /*cont recebe n-1 para pegar o último elemento do vetor */

    for (i = 0; i < n/2; i++){
        aux = vet[i];               /*variável auxiliar recebe o valor do elemento i para a troca */
        vet[i] = vet[cont];         /*A posição i recebe o valor da posição de cont */
        vet[cont] = aux;            /*E a posição de cont recebe o valor da auxiliar, antigo elemento i */
        cont--;                     /*Decrementa cont */
    }
}

/*Função principal, utiliza um vetor para inverter */
int main (void)
{
    int vetor[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; /*Vetor que será invertido */
    int i;
    inverte(9, vetor);

    for (i = 0; i < 9; i++)         /*Mostra todos os vetores na tela */
        printf("%d ", vetor[i]);
    printf("\n");

    return 0;
}