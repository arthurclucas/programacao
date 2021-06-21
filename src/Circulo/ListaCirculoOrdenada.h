#pragma once

#include "ListaCirculo.h"
#include "Circulo.h"
#include "No.h"

void inserir_ordenado(ListaCirculo* lst, Circulo* c);
No* busca_sequencial(ListaCirculo* lst, int raio);
void remover_elemento(ListaCirculo* lst, Circulo* c);
ListaCirculo* merge(ListaCirculo* lst1, ListaCirculo* lst2);