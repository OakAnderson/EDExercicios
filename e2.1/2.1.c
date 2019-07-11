#include <stdio.h>
#include <math.h>
#include "e1.5/1.5.c"       /*Importa a biblioteca da atividade anterior para elevar os números */

/*2. Passagem de parâmetros por referência. Exercício número 2.1 */

/*Função que calcula a raiz de um a função do segundo grau */
int raizes(float a, float b, float c, float* x1, float* x2)
{
    float delta;
    delta = eleve(b, 2) - 4*a*c;        /*Δ = -b² -4.a.c */
    
    if (delta < 0)      /*Se delta for negativo, não há raiz exata */
        printf("Delta é menor que 0, portanto, a função não tem raiz exata\n");
    
    else if (delta == 0){       /*Se for 0, há apenas uma raiz */
        *x1 = (-b + sqrt(delta))/2;
        *x2 = *x1;
        return 1;
    }
    else            /*Em último caso, delta é maiior que 0 e tem duas raízes distintas */
    {
        *x1 = (-b + sqrt(delta))/2*a;
        *x2 = (-b - sqrt(delta))/2*a;
        return 2;
    }
}

/*Função principal */
int main (void)
{
    int result;
    float a, b, c, x1, x2;      /*Declara a, b, c, x1 e x2 */

    printf("Entre com a, b e c respectivamente: ");
    scanf(" %f %f %f", &a, &b, &c);         /*Solicita os valores de a, b e c */

    result = raizes(a, b, c, &x1, &x2);     /*Result recebe a quantidade de raízes */

    if (result == 1)                        /*Se tiver apenas uma raíz, só mostra um resultado */
        printf("Só tem uma única raiz = %.2f\n", x1);
    else if (result == 2)                   /*Se tiver duas, mostra as duas raízes na tela */
        printf("Tem duas raízes: \nx1 = %.2f\nx2 = %.2f\n", x1, x2);
}