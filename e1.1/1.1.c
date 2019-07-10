#include <stdio.h>

/*1 - Funções Simples. Exercício 1.1. */

/*Função que testa se um ponto está dentro de um retângulo */
int dentro_ret (int x0, int y0, int x1, int y1, int x, int y)
{
    if (x >= x1 || x <= x0)
        return 0;
    else if (y >= y1 || y <= y0)
        return 0;
    else
        return 1;
}

/*Função principal que testa a função dentro_ret */
int main (void)
{
    int x0 = 2, y0 = 3, x1 = 10, y1 = 7, x, y, aux;     /*Declara as varáveis e o retângulo */
    printf("Para um retângulo com o vértice inferior esquerdo = (%d, %d)\nE um vértice superior direito = (%d, %d)\n", x1, y1, x0, y0);
    
    /*Enquanto não for um ponto dentro do retângulo, será solicitado novamente */
    do{
        printf("Digite um ponto dentro do retângulo (x, y): ");
        scanf("%d %d", &x, &y);
        aux = dentro_ret(x0, y0, x1, y1, x, y);
        if (!aux)
            printf("Tente novamente.\n");
    } while (!aux);

    /*Se o usuário acertar, mostre o resultado */
    printf("O ponto (%d, %d) está dentro do retângulo.\n", x, y);
}