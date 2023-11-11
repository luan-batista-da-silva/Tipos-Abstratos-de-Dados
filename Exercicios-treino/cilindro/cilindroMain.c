#include "cilindro.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    float altura, raio;
    Cilindro* varCilindro;

    printf("Digite a altura do cilindro: ");
    scanf("%f", &altura);
    printf("Digite o raio do cilindro: ");
    scanf("%f", &raio);

    varCilindro = cilindro_create(altura, raio);

    printf("Area da Base: %.2f\n", cilindro_areaBase(varCilindro));
    printf("Area da Face: %.2f\n", cilindro_areaFace(varCilindro));
    printf("Volume: %.2f", cilindro_volume(varCilindro));

    cilindro_destroy(varCilindro);

    return 0;
}