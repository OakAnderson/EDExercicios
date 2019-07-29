#include <stdio.h>

/*6. Tipos estruturados. Exercício 6.2 */

//Define a estrutura de vetor
typedef struct vetor{
    float x, y, z; 
} Vetor;

/*Função que retorna o produto de dois vetores */
float dot ( Vetor* v1, Vetor* v2 )
{
    float prod;

    prod = ( v1->x * v2->x ) + ( v1->y * v2->y ) + ( v1->z * v2->z );

    return prod;
}

/*Função principal */
int main( void )
{
    Vetor a, b;
    float produto;

    printf( "Dê um vetor a = (x, y, z): " );
    scanf( " %f %f %f", &a.x, &a.y, &a.z );

    printf( "Dê outro vetor b = (x, y, z): " );
    scanf( " %f %f %f", &b.x, &b.y, &b.z );

    produto = dot( &a, &b );

    printf( "O produto de a(%.1f, %.1f, %.1f) x b(%.1f, %.1f, %.1f) = %.1f\n", a.x, a.y, a.z, b.x, b.y, b.z, produto );

    return 0;
}