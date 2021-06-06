#include <stdio.h>
#include <stdlib.h>//malloc
#include "circulo.h"
#include <stdbool.h>
#include <math.h>

circulo* criar_circulo(float x, float y, float raio)
{
    circulo* c = malloc(sizeof(circulo)); // retorna NULL se alocação falhar	

    if (c == NULL)
        return NULL;

    c->x = x;
    c->y = y;
    c->raio = raio;
    return c;
}

void exibir_circulo(circulo* c)
{
    printf("Circulo: [%2f,%2f,%2f]", c->x, c->y, c->raio);
}

float calcular_perimetro(circulo* c)
{
    return (2 * 3.14) * c->raio;
}

float calcular_area(circulo* c)
{
    return (3.14) * pow(c->raio, 2);
}

bool verificar_dentro_circulo(circulo* c, float x, float y)
{
    float distancia = sqrt(pow(c->x - x, 2) + pow(c->y - y, 2));
    return distancia < c->raio;
}

void mover_circulo(circulo* c, float x, float y)
{
    c->x = c->x + x;
    c->y = c->y + y;
}

void liberar_circulo(circulo** c)
{
    free(*c);
    *c = NULL;
}