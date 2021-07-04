#include "ListaCirculo.h"
#include "No.h"
#include "Circulo.h"
#include <stdio.h>
#include <stdlib.h>//malloc
#include "circulo.h"
#include <stdbool.h>
#include <math.h>

ListaCirculo* criar_lista(int capacidadeMaxima)
{
	ListaCirculo* lst = malloc(sizeof(ListaCirculo));
	lst->capacidade = 0;
	lst->quantidade = 0;

	lst->capacidade = capacidadeMaxima;

	return lst;
}

void* exibir_lista(ListaCirculo* lst)
{
	if (lst->quantidade == 0)
		printf("A lista esta vazia.");
	else
	{
		No* no = lst->primeiro;

		for (int i = 1; i <= lst->quantidade; i++)
		{
			printf("Posicao %2d \n", i);
			exibir_circulo(no->conteudo);
			printf("\n");
			no = no->proximo;
		}
	}

	return 0;
}

bool esta_cheia(ListaCirculo* lst) 
{
	return lst->quantidade == lst->capacidade;
}

bool esta_vazia(ListaCirculo* lst)
{
	return lst->quantidade == 0;
}

int tamanho(ListaCirculo* lst)
{
	return lst->quantidade;
}

int capacidade(ListaCirculo* lst)
{
	return lst->capacidade;
}

esvaziar(ListaCirculo* lst)
{
	lst->primeiro = NULL;
	lst->ultimo = NULL;
	lst->quantidade = 0;
}

No* buscar_elemento(ListaCirculo* lst, int pos)
{
	if (lst->quantidade < pos)
		return lst->ultimo;
	else
	{
		No* retorno = lst->primeiro;

		for (int i = 1; i < pos; i++)
			retorno = retorno->proximo;

		return retorno;
	}
}

void inserir_primeiro(ListaCirculo* lst, Circulo* c) 
{
	No* unico = criar_no(c);

	lst->primeiro = unico;
	lst->ultimo = unico;
	lst->quantidade = lst->quantidade + 1;
}

void inserir_inicio(ListaCirculo* lst, Circulo* c)
{
	if (esta_vazia(lst))
		inserir_primeiro(lst, c);
	else
	{
		if (esta_cheia(lst)) 
			printf("Nao e possivel inserir, pois a lista esta cheia");
		else
		{
			No* primeiro = lst->primeiro;
			No* novoPrimeiro = criar_no(c);
			primeiro->anterior = novoPrimeiro;
			novoPrimeiro->proximo = primeiro;
			lst->primeiro = novoPrimeiro;
			lst->quantidade = lst->quantidade + 1;
		}
	}
}

void inserir_final(ListaCirculo* lst, Circulo* c)
{
	if (esta_vazia(lst))
		inserir_primeiro(lst, c);
	else
	{
		if (esta_cheia(lst))
			printf("Nao e possivel inserir, pois a lista esta cheia");
		else
		{
			No* ultimo = lst->ultimo;
			No* novoUltimo = criar_no(c);
			ultimo->proximo = novoUltimo;
			novoUltimo->anterior = ultimo;
			lst->ultimo = novoUltimo;
			lst->quantidade = lst->quantidade + 1;
		}
	}
}

void inserir_meio(ListaCirculo* lst, Circulo* c, int pos)
{
	if (esta_vazia(lst))
		inserir_primeiro(lst, c);
	else 
	{
		if (lst->quantidade < pos)
			inserir_final(lst, c);
		else
		{
			if (esta_cheia(lst))
				printf("Nao e possivel inserir, pois a lista esta cheia");
			else
			{
				No* depois = buscar_elemento(lst, pos);
				No* antes = depois->anterior;
				No* meio = criar_no(c);

				ligar_no(antes, meio);
				ligar_no(meio, depois);
				lst->quantidade = lst->quantidade + 1;
			}
		}
	}					
}

void remover_inicio(ListaCirculo* lst)
{
	if (!esta_vazia(lst))
	{
		if (lst->quantidade == 1)
			esvaziar(lst);
		else 
		{
			No* novoPrimeiro = lst->primeiro->proximo;
			lst->primeiro = novoPrimeiro;
			novoPrimeiro->anterior = NULL;
			lst->quantidade = lst->quantidade - 1;
		}
	}
}

void remover_final(ListaCirculo* lst)
{
	if (!esta_vazia(lst))
	{
		if (lst->quantidade == 1)
			esvaziar(lst);
		else
		{
			No* novoUltimo = lst->ultimo->anterior;
			lst->ultimo = novoUltimo;
			novoUltimo->proximo = NULL;
			lst->quantidade = lst->quantidade - 1;
		}
	}
}

void remover_meio(ListaCirculo* lst, int pos)
{
	if (!esta_vazia(lst))
	{
		if (lst->quantidade == 1)
			esvaziar(lst);
		else
		{
			if (pos >= lst->quantidade)
				remover_final(lst);
			else
			{
				No* remover = buscar_elemento(lst, pos);
				ligar_no(remover->anterior, remover->proximo);
				lst->quantidade = lst->quantidade - 1;
			}
		}
	}
}

ListaCirculo* concatenar(ListaCirculo* lst1, ListaCirculo* lst2)
{
	if (esta_vazia(lst1))
		return lst2;
	else
	{
		if (esta_vazia(lst2))
			return lst1;
		else
		{
			if (lst2->quantidade > (lst1->capacidade - lst1->quantidade))
				lst1->capacidade = lst1->quantidade + lst2->quantidade;

			ligar_no(lst1->ultimo, lst2->primeiro);
			lst1->quantidade = lst1->quantidade + lst2->quantidade;
			esvaziar(lst2);
			return lst1;
		}
	}
}

void liberar_lista(ListaCirculo** lst)
{
	free(*lst);
	*lst = NULL;
}