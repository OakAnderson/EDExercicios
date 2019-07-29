#include <stdio.h>

/*5. Cadeias de Caracteres. Exercício 5.4 */

/*Todas as letras de uma frase serão a letra seguinte */
void shift_string( char* str )
{
    for( int i = 0; str[i] != '\0'; i++ )
    {
        if( str[i] == 'Z' )
        {
            str[i] = 'a';
        }

        else if( str[i] == 'Z' )
        {
            str[i] = 'A';
        }

        else if( ( str[i] >= 'a' && str[i] < 'z' ) || ( str[i] >= 'A' && str[i] < 'Z' ) )
        {
            str[i]++;
        }
    }
}

/*Função principal */
int main( void )
{
    char frase[256];

    printf("Digite uma frase: ");
    scanf(" %255[^\n]", frase);

    shift_string( frase );

    printf("Sua frase ficou:\n\n%s\n\n", frase);

    return 0;
}