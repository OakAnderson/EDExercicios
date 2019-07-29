#include <stdio.h>

#define True 1
#define False 0

/*6. Tipos estruturados. Exercício 6.1 */

typedef struct ponto
{
    float x, y;
}Ponto;

/*Função que verifica se um ponto p está dentro de um retângulo v */
int dentroRet( Ponto* v1, Ponto* v2, Ponto* p )
{
    if( p->x <= v1->x || p->x >= v2->x )
    {
        return False;
    }

    else if( p->y >= v1->y || p->y <= v2->y )
    {
        return False;
    }

    else
    {
        return True;
    }
}

/*Função principal */
int main( void )
{
    Ponto p, v1, v2;

    printf( "Para um retângulo, insira a coordenada do vértice superior esquerdo: " );
    scanf( " %f %f", &v1.x, &v1.y );

    printf( "Insira as coordenadas do vértice inferior direito: " );
    scanf( " %f %f", &v2.x, &v2.y );

    printf( "Insira um ponto para verificar se está dentro do retângulo(x, y): " );
    scanf( " %f %f", &p.x, &p.y );

    if( dentroRet( &v1, &v2, &p ) )
    {
        printf( "Está dentro do retângulo\n" );
    }

    else
    {
        printf( "Não está dentro do retângulo\n" );
    }
    
    return 0;
}