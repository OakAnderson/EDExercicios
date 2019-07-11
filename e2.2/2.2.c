#include <stdlib.h>
#include "e1.5/1.5.c"

/*2. Passagem de parâmetros por referência. Exercício 2.2 */

/*Função que calcula a área e o volume de uma esfera */
void calc_esfera(float r, float* area, float* volume)
{
    *area = 4 * eleve(r, 2);        /*Área = 4r² */
    *volume = (4 * eleve(r, 3))/3;  /*Volume = 4r³/3 */
}

int main (void)
{
    float r, area, volume;

    printf("Digite o raio do círculo: ");   /*Solicita o raio ao usuário */
    scanf(" %f", &r);

    calc_esfera(r, &area, &volume);         /*Chama a função para calcular a área/volume */

    printf("Área: %.2f\nVolume: %.2f\n", area, volume); /*Mostra o resultado na tela */

    return 0;
}