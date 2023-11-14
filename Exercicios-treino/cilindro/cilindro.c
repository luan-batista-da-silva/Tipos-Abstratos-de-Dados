#include "cilindro.h"
#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415

struct cilindro {
    float h;
    float r;
};

// Cria o cilindro
Cilindro* cilindro_create(float altura, float raio) {
    Cilindro* cilindro = (Cilindro*) malloc(sizeof(Cilindro*));
    if (cilindro != NULL) {
        cilindro->h = altura;
        cilindro->r = raio;
    }
    return (cilindro);
}

// Desaloca a memória do Cilindro
void cilindro_destroy(Cilindro* cilindro) {
    if (cilindro != NULL) {
        free(cilindro);
    }
}

// Retorna a área da Base do cilindro
float cilindro_areaBase(Cilindro* cilindro) {
    if (cilindro != NULL) {
        return PI*(cilindro->r)*(cilindro->r);
    }
}

// Retirba a área lateral do cilindro
float cilindro_areaFace(Cilindro* cilindro) {
    if (cilindro != NULL) {
        return 2*PI*(cilindro->r)*(cilindro->h);
    }
}

// Retorna o volume total do cilindro
float cilindro_volume(Cilindro* cilindro) {
    if (cilindro != NULL) {
        return PI*(cilindro->r)*(cilindro->r)*(cilindro->h);
    }
}