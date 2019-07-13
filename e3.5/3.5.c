#include <stdio.h>
#include "e1.5/1.5.c"


/*3. Vetores. Exercício 3.5 */

/*Função que calcula a derivada de um polinômio */
void deriva(double* poli, int grau, double* out)
{
    int i, exp = grau;
    for (i = 0; i < grau; i++){
        out[i] = exp * eleve(1, exp - 1);
        exp--;
    }
}

/*Função que avalia um polinômio */
double avalia (double* poli, int grau, double x)
{
    int i;
    double result = 0;

    for (i = 0; i < grau; i++)
        result += poli[i] * eleve(x, i);        /* n*a^i + n*a^i-1 + n*a^i-2...n*a^1 + a  */

    return result;
}

void print_poli (double* vet, int grau)
{
    int i, exp = grau;
    for (i = 0; i <= grau; i++){
        if (vet[i] > 0)
            printf("+ %.1f.X^%d ", vet[i], exp);
        else if (vet[i] < 0)
            printf("- %.1f.X^%d ", vet[i] * -1, exp);
        exp--;
    }
    printf("\n");
}

int main(void)
{
    double vetor[] = {4, 6, 0, -3, -8, 5}, saida[6];
    double saida2;
    int i;

    print_poli(vetor, 5);

    deriva(vetor, 5, saida);

    saida2 = avalia(saida, 5-1, 1);

    print_poli(saida, 4);

    printf("%.1lf\n", saida2);

    return 0;
}