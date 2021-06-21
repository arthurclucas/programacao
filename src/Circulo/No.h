#pragma once
#include "Circulo.h"

typedef struct TNo No;

struct TNo
{
    Circulo* conteudo;
    No *proximo;
    No *anterior;
};

No* criar_no(Circulo* c);
void ligar_no(No* anterior, No* proximo);