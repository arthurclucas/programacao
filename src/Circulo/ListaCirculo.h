#pragma once
#include "Circulo.h"
#include "No.h"

typedef struct
{
    No* primeiro;
    No* ultimo;
    int capacidade;
    int quantidade;

} ListaCirculo;

ListaCirculo* criar_lista(int capacidadeMaxima);
void* exibir_lista(ListaCirculo* lst);
bool esta_cheia(ListaCirculo* lst);
bool esta_vazia(ListaCirculo* lst);
int tamanho(ListaCirculo* lst);
int capacidade(ListaCirculo* lst);
esvaziar(ListaCirculo* lst);
No* buscar_elemento(ListaCirculo* lst, int pos);
void inserir_inicio(ListaCirculo* lst, Circulo* c);
void inserir_final(ListaCirculo* lst, Circulo* c);
void inserir_meio(ListaCirculo* lst, Circulo* c, int pos);
void remover_inicio(ListaCirculo* lst);
void remover_final(ListaCirculo* lst);
void remover_meio(ListaCirculo* lst, int pos);
ListaCirculo* concatenar(ListaCirculo* lst1, ListaCirculo* lst2);
void liberar_lista(ListaCirculo** lst);