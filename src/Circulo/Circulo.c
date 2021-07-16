#include <stdio.h>
#include <stdlib.h>//malloc
#include "circulo.h"
#include <stdbool.h>
#include <math.h>

Circulo* criar_circulo(float x, float y, float raio)
{
    Circulo* c = malloc(sizeof(Circulo)); // retorna NULL se alocação falhar

    if (c == NULL)
        return NULL;

    c->x = x;
    c->y = y;
    c->raio = raio;
    c->area = calcular_area(c);
    return c;
}

void exibir_circulo(Circulo* c)
{
    printf("Circulo: [x: %2f,y: %2f,raio: %2f, area: %2f]", c->x, c->y, c->raio, c->area);
}

float calcular_perimetro(Circulo* c)
{
    return (2 * 3.14) * c->raio;
}

float calcular_area(Circulo* c)
{
    return (3.14) * pow(c->raio, 2);
}

bool verificar_dentro_circulo(Circulo* c, float x, float y)
{
    float distancia = sqrt(pow(c->x - x, 2) + pow(c->y - y, 2));
    return distancia < c->raio;
}

void mover_circulo(Circulo* c, float x, float y)
{
    c->x = c->x + x;
    c->y = c->y + y;
}

void liberar_circulo(Circulo** c)
{
    free(*c);
    *c = NULL;
}