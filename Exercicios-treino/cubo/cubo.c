#include "cubo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declara o Cubo
struct cubo
{
    float a;
};

// Cria o cubo
Cubo* cubo_create(float aresta) {
    Cubo* cubo = (Cubo*) malloc(sizeof(Cubo));
    if (cubo != NULL) {
        cubo->a = aresta;
    }
    return (cubo);
}

// Destroi o cubo ja criado
void cubo_destroy(Cubo *cubo) {
    if (cubo != NULL) {
        free(cubo);
    }
}

// Retorna o comprimento da Aresta
float cubo_compAresta(Cubo *cubo) {
    return (cubo->a);
}

// Atribui um novo valor a aresta do cubo
void cubo_atribui(Cubo* cubo, float aresta) {
    if (cubo != NULL) {
        cubo->a = aresta;
    }
}

// Calcula o perímetro do cubo
float cubo_perimetro(Cubo *cubo) {
    if (cubo != NULL) {
        return 12*(cubo->a); 
    }
}

// Calcula a área da face do cubo
float cubo_areaFace(Cubo *cubo) {
    if (cubo != NULL) {
        return (cubo->a * cubo->a);
    }
}

// Calcula a área total das faces externas
float cubo_areaTotal(Cubo *cubo) {
    if (cubo != NULL) {
        return 6*(cubo->a * cubo->a);
    }
}

// Calcula o volume do cubo
float cubo_volume(Cubo *cubo) {
    if (cubo != NULL) {
        return pow(cubo->a, 3);
    }
}

// Calcula a Diagonal do Cubo
float cubo_diagonal(Cubo *cubo) {
    if (cubo != NULL) {
        return sqrt(3)*cubo->a;
    }
}



