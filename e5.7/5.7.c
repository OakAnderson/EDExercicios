#include <stdio.h>
#include <string.h>
#include "myLib.c"

/*5. Cadeias de Caracteres. Exercício 5.7 */

char* free_save( char* str )
{
    char aux[ strlen( str ) ];

    strcpy(aux, str);

    free( str );

    strcpy(str, aux);
}

/*Função principal */
int main( void )
{
    char frase[256];    //Recebe a entrada do usuário
    char* destino;      //Destino das alterações

    printf( "Digite algo: " );
    scanf( " %255[^\n]", frase );

    destino = minusculo( frase );       //Deixa tudo minúsculo
    free_save( destino );
    printf( "passo 1: %s\n", destino );

    destino = shift_string( destino );  //As letras serão as letras seguintes
    free_save( destino );
    printf( "passo 2: %s\n", destino );

    destino = string_oposta( destino ); //Letras serão suas opostas no alfabeto
    free_save( destino );
    printf( "passo 3: %s\n", destino );

    destino = roda_string( destino );   //As letras vão para uma casa a diereita
    free_save( destino );
    printf( "passo 4: %s\n", destino );

    free( destino );

    return 0;
}

