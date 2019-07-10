#include <stdio.h>

/*1. Função simples. Exercício 1.3 */

/*Função que calcula os valores de fibonacci */
int fibonacci (int n)
{
    int x = 1, y = 1, i = n; /*Inicia com x, y == 1 e i = n (para poder decrementar)*/

    do {        /*Faça enquanto i > 0 */
        printf("%d ", x);       /*Mostra o valor de x */
        x += y;                 /*Soma o valor atual com o anterior (y) */
        i -= 1;                 /*i é decrementado */
        if (i > 0){             /*Se i ainda for maior que 0... */
            printf("%d ", y);   /*Mostra o valor de y */
            y += x;             /*Soma o valor atual com o anterior (x) */
            i -= 1;             /*i é decrementado */
        }
    } while (i > 0);            
    
    printf("\n");       /*Salta uma linha quando estiver concluido */
}

/*Função principal que solicita ao usuário a quantidade de valores que ele deseja ver */
int main (void)
{
    int n;

    printf("Digite um número: ");
    scanf(" %d", &n);               /*n recebe a quantidade de números */
    fibonacci(n);
}