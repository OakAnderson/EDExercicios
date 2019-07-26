#include <stdio.h>

#define True 1
#define False 0

/*5. Cadeias de Caracteres. Exercício 5.1 */

/*FUnção que testa se o caractere é uma vogal */
int verifica_vogal (char letra)
{
    if (letra == 'a' || letra == 'A')
        return True;
    else if (letra == 'e' || letra == 'E')
        return True;
    else if (letra == 'i' || letra == 'I')
        return True;
    else if (letra == 'o' || letra == 'O')
        return True;
    else if (letra == 'u' || letra == 'U')
        return True;
    else
        return False;
}

/*Função que conta as vogais em uma determinada frase */
int conta_vogais (char* str)
{
    int cont = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (verifica_vogal(str[i]))
            cont++;
    }

    return cont;
}

/*Função principal */
int main (void)
{
    char frase[256];

    printf("Digite uma frase: ");
    scanf(" %255[^\n]", frase);

    printf("A frase \"%s\" tem %d vogais\n", frase, conta_vogais(frase));

    return 0;
}