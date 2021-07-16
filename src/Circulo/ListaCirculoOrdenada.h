#pragma once

#include "ListaCirculo.h"
#include "Circulo.h"
#include "No.h"

int inserir_ordenado(ListaCirculo* lst, Circulo* c);
No* busca_sequencial(ListaCirculo* lst, int raio);
void remover_elemento(ListaCirculo* lst, Circulo* c);
ListaCirculo* concatenar_ordenado(ListaCirculo* lst1, ListaCirculo* lst2);