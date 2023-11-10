#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cubo.h"

int main() {
    float aresta;
    Cubo* varCubo;

    printf("Insira o valor da aresta do cubo: ");
    scanf("%f", &aresta);

    varCubo = cubo_create(aresta);

    printf("Aresta = %.2f\n", cubo_compAresta(varCubo));
    printf("Perimetro = %.2f\n", cubo_perimetro(varCubo));
    printf("Diagonal = %.2f\n", cubo_diagonal(varCubo));
    printf("Area da Face = %.2f\n", cubo_areaFace(varCubo));
    printf("Area Total = %.2f\n", cubo_areaTotal(varCubo));
    printf("Volume = %.2f\n", cubo_volume(varCubo));

    cubo_destroy(varCubo);
    
    return 0;
}