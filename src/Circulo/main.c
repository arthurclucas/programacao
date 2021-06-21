#include <stdio.h>
#include <stdlib.h>
#include "Circulo.h"
#include "No.h"
#include "ListaCirculo.h"
#include "ListaCirculoOrdenada.h"

Circulo* random_circulo() 
{
    int x = rand() % 100;
    int y = rand() % 100;
    int r = rand() % 100;

    return criar_circulo(x, y, r);
}

ListaCirculo* random_lista_cheia(int capacidade) 
{
    ListaCirculo* lst = criar_lista(capacidade);

    for (int i = 0; i < capacidade; i++)
    {
        Circulo* c = random_circulo();
        inserir_final(lst, c);
    }

    return lst;
}

ListaCirculo* random_lista_cheia_ordenada(int capacidade)
{
    ListaCirculo* lst = criar_lista(capacidade);

    for (int i = 0; i < capacidade; i++)
    {
        Circulo* c = random_circulo();
        inserir_ordenado(lst, c);
    }

    return lst;
}

int random_int() 
{
    int qtd = rand() % 10;

    while (qtd < 5)
        qtd = rand() % 10;

    return qtd;
}

int main() 
{
    int qtd = random_int();

    printf("Criando uma lista cheia com %2d elementos\n", qtd);
    ListaCirculo* lst = random_lista_cheia(qtd);
    exibir_lista(lst);

    printf("Como a lista esta cheia, testando a insercao de um novo elemento");
    Circulo* c = random_circulo();
    printf("\n");
    inserir_inicio(lst, c);
    printf("\n");
    inserir_meio(lst, c, qtd -1);
    printf("\n");
    inserir_final(lst, c);
    printf("\n");

    printf("Removendo o primeiro elemento da lista\n");
    remover_inicio(lst);
    exibir_lista(lst);

    printf("Removendo o ultimo elemento da lista\n");
    remover_final(lst);
    exibir_lista(lst);

    printf("Removendo o elemento da posicao 3 da lista\n");
    remover_meio(lst, 3);
    exibir_lista(lst);

    printf("Inserindo um novo elemento na posicao 2 da lista\n");
    inserir_meio(lst, random_circulo(), 2);
    exibir_lista(lst);

    printf("Inserindo no inicio da lista\n");
    inserir_inicio(lst, random_circulo());
    exibir_lista(lst);

    printf("Inserindo no final da lista\n");
    inserir_final(lst, random_circulo());
    exibir_lista(lst);

    qtd = random_int();

    printf("Criando uma segunda lista com %2d elementos para concatenar\n", qtd);
    ListaCirculo* lst2 = random_lista_cheia(qtd);
    exibir_lista(lst);
    printf("Concatenando\n");
    ListaCirculo* lstConcat = concatenar(lst, lst2);
    exibir_lista(lstConcat);

    qtd = random_int();
    printf("Criando uma terceira lista com %2d elementos para concatenar ordenadamente\n", qtd);
    ListaCirculo* lst3 = random_lista_cheia_ordenada(qtd);
    exibir_lista(lst3);
    printf("\n");

    qtd = random_int();
    printf("Criando uma quarta lista com %2d elementos para concatenar ordenadamente\n", qtd);
    ListaCirculo* lst4 = random_lista_cheia_ordenada(qtd);
    exibir_lista(lst4);
    printf("\n");

    ListaCirculo* lst5 = merge(lst3, lst4);
    
 }