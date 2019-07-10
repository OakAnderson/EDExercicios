#include <stdio.h>

/*1. Função simples. Exercício 1.4 */

/*Função que retorna a soma os primeiros n números ímpares*/
int soma_impares (int n)
{
    int i, soma = 0;        /*Contador; somatório */
    for (i = 1; i <= (n*2); i += 2)     /*Para todos os valores ímpares menores que nx2 */
        soma += i;                      /*Some i a soma */
    
    return soma;        /*Retorna o resultado */
}

/*Função principal que pede o usuário o número de ímpares para somar */
int main (void)
{
    int n, impares;

    printf("Digite um número: ");
    scanf(" %d", &n);               /*Solicita a quantidade de ímpares */

    impares = soma_impares(n);      /*impares recebe o somatório */

    printf("A soma dos %d primeiros números é = %d\n", n, impares);     /*Mostra o resultado na tela */
}