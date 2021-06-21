#include "Circulo.h"
#include "No.h"

typedef struct
{
    No* primeiro;
    No* ultimo;
    int quantidade;

} ListaCirculo;

ListaCirculo* criar_lista(int qtdElementos, Circulo* vetor[]);
void* exibir_lista(ListaCirculo* lst);