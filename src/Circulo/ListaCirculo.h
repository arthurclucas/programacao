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
int esvaziar(ListaCirculo* lst);
No* buscar_elemento(ListaCirculo* lst, int pos, int* iteracoes);
int inserir_inicio(ListaCirculo* lst, Circulo* c);
int inserir_final(ListaCirculo* lst, Circulo* c);
int inserir_meio(ListaCirculo* lst, Circulo* c, int pos);
int inserir_ultimo(ListaCirculo* lst, Circulo* c);
int remover_inicio(ListaCirculo* lst);
int remover_final(ListaCirculo* lst);
int remover_meio(ListaCirculo* lst, int pos);
ListaCirculo* concatenar(ListaCirculo* lst1, ListaCirculo* lst2, int* iteracoes);
void liberar_lista(ListaCirculo** lst);
int inserir_primeiro(ListaCirculo* lst, Circulo* c);