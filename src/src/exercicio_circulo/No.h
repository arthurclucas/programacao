#include "Circulo.h"

typedef struct
{
    Circulo* conteudo;
    struct No* proximo;
    struct No* anterior;

} No;

No* criar_no(Circulo* c, No* anterior);