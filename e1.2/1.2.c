#include <stdio.h>

/*1. Funções simples. Exercício 1.2 */

/*Função que verifica se o número é primo */
int primo (int n)
{
    int i;

    if (n == 2)             /*Se o número for 2, retorna verdadeiro */
        return 1;

    else if (n == 1 || n == 0)  /*Se o número for 1 ou 0, retorna -1 */
        return -1;

    else if (n % 2 == 0)    /*Se o número for par, retorna falso */
        return 0;
    
    else {                  /*Senão, teste se o número é divisível por algum número além dele mesmo */

        for (i = 3; i < n; i += 2)      /*Para os números ímpares menores que o número inserido */
            if ((n % i) == 0)           /*Teste se ele n é divísel pelo número */
                return 0;               /*Se sim, retorne falso (não é primo) */
    }
}

/*Função principal que testa a função primo */
int main (void)
{
    int n;

    printf("Insira um número: ");
    scanf(" %d", &n);       /*Solicita o usuário um número */

    if (primo(n) == -1)         /*Testa se o número é igual a 1 ou 0 */
        printf("%d é um caso especial.\n", n);
    else if (!primo(n))         /*Testa com a função se o número é primo */
        printf("%d não é um número primo.\n", n);
    else                        /*Se não for nenhum caso acima, o número é primo */
        printf("%d é um número primo.\n", n);
}