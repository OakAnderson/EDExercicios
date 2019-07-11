#include <stdio.h>

/*1. Função simples. Exercício 5 */

/*Função que retorna o inteiro de uma divisão */
int div_int (float p, float m)
{
    int n = 0;
    if (p - m < 0)      /*Se o primeiro nº - segundo nº for menor que 0, retorna a soma da quantidade de divisões  */
        return n;
    else
        return 1 + div_int(p - m, m);   /*Senão, conta +1 e chama a função para p - m / m */
}

/*Função exclusiva para expoentes negativos */
float eleve_n (float n, int expoente)
{
    if (expoente == 0)      /*Se o expoente for igual a 0, retorna o número dividido por ele mesmo (1)*/
            return n / n;
    else
        return eleve_n (n, expoente + 1) / n;   /*Senão, retorna n^expoente+1 / n */
}

/*Função que eleva um número a um expoente */
float eleve (float n, int expoente)
{
    if (expoente == 0)          /*Se o expoente for igual a 0, é retornado o número 1 */
        return 1;
    else if (expoente == 1)     /*se o expoente for igual a 1, retorna o resultado */
        return n;
    else if (expoente > 1)      /*Se o expoente for maior que 1, retorna n x n ^expoente -1 */
        return n * eleve(n, expoente - 1);
    else if (expoente < 0)      /*Se o expoente for negativo, retorna a função para expoente negativo */
        return eleve_n (n, expoente);
}

/*Função que mostra na tela um número com n casas decimais */
void mostra_float (float n, int p)
{
    float i = 0, j, soma = 0, aux = n, cont = 0;

    while (j < n)               /*Encontra a maior potência do número para o cálculo do polinômio */
    {
        j = eleve(10, i);       /*j = 10^i */
        ++i;                    /*i + 1 */
    }

    j = i-2;                    /*j recebe o expoente equivalente à potência do número */

    for (i = 0; i <= p; i++){
        if (j == 0)                                         /*Se for o último número na frente da vírgula, mostra a vírgula */
            printf("%d,", div_int(aux, eleve(10, j)));
        else                                                /*Senão, só mostra o próximo número */
            printf("%d", div_int(aux, eleve(10, j)));
        aux -= div_int(aux, eleve(10, j)) * eleve(10, j);   /*variável é igual ao número passado menos uma potência */
        j -= 1;
    }
    printf("\n");       /*Salta uma linha */
}

/*Função que calcula um número aproximado de pi */
double pi (int n)
{
    int faixa = eleve(10, n+2);     /*Faixa é igual a 10^(casa de números para mostrar)+2 */
    float pi = 1, i;                /*pi já inicia com 1 */

    for (i = 3; i < faixa; i += 8){
        pi -= 1/i;                  /*pi = 4 x 1/1 - 1/3 + 1/5 - 1/7...  */
        pi += 1/(i+2);
        pi -= 1/(i+4);
        pi += 1/(i+6);
    }

    return pi * 4;          /*Retorna o resultado da soma e subtração x 4 */
}

/*Função principal */
int main ()
{
    float n, result;
    int p;

    do {
        printf("Quantidade de casas: ");            /*Solicita a quantidade de casas decimais para mostrar (de 1 a 5) */
        scanf(" %d", &p);
        if (p > 5 || p <= 0)
            printf("Número de casas inválido. Tente um número entre 1 e 5\n");
    } while (p > 5 || p <= 0);

    result = pi(p);     /*Result recebe o valor de pi */

    mostra_float(result, p);        /*Mostra pi na tela com a quantidade de casas solicitadas */

    return 0;
}