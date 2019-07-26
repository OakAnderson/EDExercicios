#include <stdio.h>

/*5. Cadeias de caracteres. Exercício 5.2 */

/*Função que conta a quantidade de um determinado caractere em uma string */
int conta_char (char* str, char c)
{
    int cont = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c)
            cont++;
    }

    return cont;
}

/*Função principal */
int main (void)
{
    char frase[256];
    char c;

    printf("Digite uma frase: ");
    scanf(" %255[^\n]", frase);

    printf("Caractere a contar: ");
    scanf(" %c", &c);

    printf("A frase \"%s\" tem %d ocorrências do caractere \"%c\"\n", frase, conta_char(frase, c), c);

    return 0;
}