#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Função que deixa a frase em minusculo */
char* minusculo (char* str)
{
    char* destStr;      //Variavel de destino com mesmo tamanho

    destStr = (char*) malloc (strlen(str)*sizeof(char));

    strcpy(destStr, str);           //Recebe a cópia da string

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] > 64 && str[i] < 91)
            destStr[i] += 32;   //A nova string é igual a anterior, altera-se igualmente
    }

    return destStr;     //Retorna a string alterada
}

/*Todas as letras de uma frase serão a letra seguinte */
char* shift_string( char* str )
{
    char* destStr;      //Destino de mesmo tamanho

    destStr = (char*) malloc (strlen(str)*sizeof(char));

    strcpy(destStr, str);           //Cria uma cópia no destino

    for( int i = 0; str[i] != '\0'; i++ )
    {
        if( str[i] == 'Z' )
        {
            destStr[i] = 'a';
        }

        else if( str[i] == 'Z' )
        {
            destStr[i] = 'A';
        }

        else if( ( str[i] >= 'a' && str[i] < 'z' ) || ( str[i] >= 'A' && str[i] < 'Z' ) )
        {
            destStr[i]++;
        }
    }

    return ( "%s", destStr );     //Retorna o resultado
}

/*Função que troca as letras pela letra oposta no alfabeto */
char* string_oposta( char* str )
{
    char* destStr;      //Variável destino

    destStr = ( char* ) malloc ( strlen( str ) * sizeof( char ) );

    strcpy( destStr, str );             //Cria a cópia
    
    int condicao;       //declara a variável da condição

    for( int i = 0; str[i] != '\0'; i++ )
    {
        condicao = ( str[i] >= 'a' && str[i] <= 'z' ) || ( str[i] >= 'A' && str[i] <= 'Z' );

        if( condicao )      //Se for uma letra
        {
            if( str[i] <= 'm' )     //Se for preciso acrescentar (Minúsculo)
            {
                destStr[i] += 25 - ( str[i] - 'a' ) * 2;
            }

            else if( str[i] <= 'M' )    //Se for preciso acrescentar (Maiusculo)
            {
                destStr[i] += 25 - ( str[i] - 'A' ) * 2;
            }

            else if( str[i] >= 'n' )    //Se for preciso decrementar (min)
            {
                destStr[i] -= ( str[i] - 'a' ) * 2 - 25;
            }

            else if( str[i] >= 'N' )    //Se for preciso decrementar (mai)
            {
                destStr[i] -= ( str[i] - 'A' ) * 2 - 25;
            }
        }
    }

    return ( "%s", destStr );     //Retorna a string resultado
}

/*Função que desloca os caracteres de uma string para a direita */
char* roda_string( char* str )
{
    char* destStr;      //Variável destino

    destStr = ( char* ) malloc ( strlen( str ) * sizeof( char ) );

    strcpy(destStr, str);           //Cria uma cópia

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
            destStr[i] = aux;   //Atribui o valor anterior a posição atual
            aux = l;        //Guarda o valor anterior em aux
        }

        if( str[i+1] == '\0' )  //Se o próximo caractere for o nulo
        {
            destStr[0] = aux;       //A primeira posição é igual ao último valor de aux
        }
    }

    return ( "%s", destStr );     //Retorna a string resultado
}
