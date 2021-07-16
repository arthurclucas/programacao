#pragma once

#include "Circulo.h"
#include "No.h"

#define MAX 50

typedef struct 
{
	Circulo* vetor[MAX];
	int qtd;	

} ListaSequencial;

void exibir_lista(ListaSequencial* lst);
void inserir_inicio(ListaSequencial* lst, Circulo* c);
void inserir_final(ListaSequencial* lst, Circulo* c);
void inserir_meio(ListaSequencial* lst, Circulo* c, int pos);
void remover_inicio(ListaSequencial* lst);
void remover_final(ListaSequencial* lst);
void remover_meio(ListaSequencial* lst, int pos);
void buscar_elemento(ListaSequencial* lst, int pos);
ListaSequencial* concatenar(ListaSequencial* lst1, ListaSequencial* lst2);
void esvaziar(ListaSequencial* lst);
void liberar(ListaSequencial** lst);