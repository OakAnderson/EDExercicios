#include <stdio.h>

#define and &&

/*5. Cadeias de Caracteres. Exercício 5.3 */

/*Função que deixa a frase em minusculo */
void minusculo (char* str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] > 64 and str[i] < 91)
            str[i] += 32;
    }
}

/*Função principal */
int main (void)
{
    char frase[256];

    printf("Digite uma frase: ");
    scanf(" %255[^\n]", frase);

    minusculo(frase);

    printf("Sua frase ficou: %s\n", frase);

    return 0;
}