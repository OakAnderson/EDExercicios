#include <stdio.h>

/*5. Cadeias de Caracteres. Exercício 5.5 */

/*Função que troca as letras pela letra oposta no alfabeto */
void string_oposta( char* str )
{
    int condicao;

    for( int i = 0; str[i] != '\0'; i++ )
    {
        condicao = ( str[i] >= 'a' && str[i] <= 'z' ) || ( str[i] >= 'A' && str[i] <= 'Z' );

        if( condicao )
        {
            if( str[i] <= 'm' )
            {
                str[i] += 25 - ( str[i] - 'a' ) * 2;
            }

            else if( str[i] <= 'M' )
            {
                str[i] += 25 - ( str[i] - 'A' ) * 2;
            }

            else if( str[i] >= 'n' )
            {
                str[i] -= ( str[i] - 'a' ) * 2 - 25;
            }

            else if( str[i] >= 'N' )
            {
                str[i] -= ( str[i] - 'A' ) * 2 - 25;
            }
        }
    }
}

int main( void )
{
    char frase[256];

    printf( "Digite algo: " );
    scanf( " %255[^\n]", frase );

    string_oposta( frase );

    printf( "%s\n",frase );

    return 0;
}