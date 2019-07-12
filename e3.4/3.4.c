#include <stdio.h>
#include "e1.5/1.5.c"

/*3. Vetores. Exercício 3.4 */

/*Função que avalia um polinômio */
double avalia (double* poli, int grau, double x)
{
    int i;
    double result = 0;

    for (i = 0; i < grau; i++)
        result += poli[i] * eleve(x, i);        /* n*a^i + n*a^i-1 + n*a^i-2...n*a^1 + a  */

    return result;
}

/*Função principal */
int main (void)
{
    double vetor[81], x, result;        /*Cria um vetor com o limite de 81 elementos */
    int n, i;

    printf("Digite o grau do polinômio: "); /*Solicita o grau do polinômio */
    scanf(" %d", &n);

    n++;        /*Para um polinômio de grau n, tem-se n+1 elementos */

    for (i = 0; i < n; i++) {
        printf("Para n x a^%d, insira a: ", i);     /*Solicita os valores do polinômio */
        scanf(" %lf", &vetor[i]);
    }

    printf("Digite um número para avaliar o polinômio: ");      /*Recebe x para substituir no polinômio */
    scanf(" %lf", &x);      

    result = avalia(vetor, n, x);       /*Resultado do polinômio de grau n com base x */

    printf("Para x = %.2f, o polinômio é igual a: %.2f\n", x, result);  /*Mostra na tela */

    return 0;
}