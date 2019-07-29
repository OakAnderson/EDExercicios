#include <stdio.h>

/*5. Cadeias de Caracteres. Exercício 5.6 */

/*Função que desloca os caracteres de uma string para a direita */
void roda_string( char* str )
{
    char l, aux;

    for( int i = 0; str[i] != '\0'; i++ )
    {
        if( i == 0 )        //Se for o primeiro caractere, só guarda o valor
        {
            aux = str[i];
        }

        else                //Se não
        {
            l = str[i];     //Guarda o valor atual
            str[i] = aux;   //Atribui o valor anterior a posição atual
            aux = l;        //Guarda o valor anterior em aux
        }

        if( str[i+1] == '\0' )  //Se o próximo caractere for o nulo
        {
            str[0] = aux;       //A primeira posição é igual ao último valor de aux
        }
    }
}

/*Função principal */
int main( void )
{
    char frase[256];

    printf( "Digite algo: " );
    scanf( " %255[^\n]", frase );

    roda_string( frase );
    printf( "Rodada 1: %s\n", frase );

    roda_string( frase );
    printf( "Rodada 2: %s\n", frase );

    roda_string( frase );
    printf( "Rodada 3: %s\n", frase );

    return 0;
}