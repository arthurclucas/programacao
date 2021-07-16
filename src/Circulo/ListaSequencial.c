#include "ListaSequencial.h"
#include "No.h"
#include "Circulo.h"

#include <stdio.h>
#include <stdlib.h>//malloc
#include "circulo.h"
#include <stdbool.h>
#include <math.h>

ListaSequencial* criar_lista()
{
	ListaSequencial* lista = malloc(sizeof(ListaSequencial));

	if (lista == NULL)
		return NULL;

	lista->qtd = 0;
	lista->vetor[0] = NULL;
	return lista;
}

bool esta_cheia(ListaSequencial* lst)
{
	return lst->qtd == MAX;
}

bool esta_vazia(ListaSequencial* lst)
{
	return lst->qtd == 0;
}

int tamanho(ListaSequencial* lst)
{
	return lst->qtd;
}

void inserir_primeiro(ListaSequencial* lst, Circulo* c)
{
	lst->vetor[0] = c;
	lst->qtd++;
}

void inserir_inicio(ListaSequencial* lst, Circulo* c)
{
	if (esta_vazia(lst))
		inserir_primeiro(lst, c);
	else
	{
		if (esta_cheia(lst))
			printf("Nao e possivel inserir, pois a lista esta cheia");
		else
		{
			for (int i = lst->qtd - 1; i <= 0; i--)
				lst->vetor[i + 1] = lst->vetor[i];

			inserir_primeiro(lst, c);
		}
	}
}

void inserir_final(ListaSequencial* lst, Circulo* c)
{
	if (esta_cheia(lst))
		printf("Não é possível inserir pois a lista está cheia");
	else
		lst->vetor[lst->qtd] = c;
}

void inserir_meio(ListaSequencial* lst, Circulo* c, int pos)
{	
	if (pos > lst->qtd)
		printf("A lista possui menos elementos que a posição em que se está querendo inserir o elemento");

	pos = pos - 1;//o array começa de zero

	for (int i = pos; i < lst->qtd - 1; i++)
		lst->vetor[i + 1] = lst->vetor[i];

	lst->vetor[pos] = c;
}

void inserir_ordenado(ListaSequencial* lst, Circulo* c)
{
	if (esta_cheia(lst))
		printf("A lista esta cheia e não é mais possível inserir elementos");
	else
	{
		if (esta_vazia(lst))
			inserir_primeiro(lst, c);
		else
		{			
			if (lst->vetor[lst->qtd - 1]->raio < c->raio)
				inserir_final(lst, c);

			int pos = 0;

			while (lst->vetor[pos]->raio < c->raio)
				pos++;

			inserir_meio(lst, c, pos);
		}
	}
}

void remover_inicio(ListaSequencial* lst)
{
	if (esta_vazia)
		printf("A lista esta vazia, não é possível remover o elemento");
	else
	{
		if (lst->qtd == 1)
			esvaziar(lst);
		else
		{
			liberar_circulo(lst->vetor[0]);

			for (int i = 0; i < lst->qtd - 2; i++)
				lst->vetor[i] = lst->vetor[i + 1];
		}
	}
}

void remover_final(ListaSequencial* lst)
{
	if (esta_vazia)
		printf("A lista esta vazia, não é possível remover o elemento");
	else
	{
		liberar_circulo(lst->vetor[lst->qtd -1]);
		lst->qtd--;
	}
		
}

void remover_meio(ListaSequencial* lst, int pos)
{	
	if (pos > lst->qtd)
		printf("A lista possui menos elementos que a posição em que se está querendo remover o elemento");

	pos = pos - 1;//o array começa de zero

	liberar_circulo(lst->vetor[pos]);

	for (int i = pos; i < lst->qtd - 1; i++)
		lst->vetor[i] = lst->vetor[i + 1];
}

ListaSequencial* concatenar(ListaSequencial* lst1, ListaSequencial* lst2)
{
	ListaSequencial* lst = criar_lista();

	for (int i = 0; i < lst1->qtd-1; i++)
		inserir_final(lst, lst1->vetor[i]);

	for (int i = 0; i < lst1->qtd - 1; i++)
		inserir_final(lst, lst2->vetor[i]);

	return lst;
}

void esvaziar(ListaSequencial* lst)
{
	for (int i = 0; i < lst->qtd - 1; i++)
		liberar_circulo(lst->vetor[i]);

	lst->qtd = 0;
}

void liberar(ListaSequencial** lst) 
{
	free(*lst);
	*lst = NULL;
}

void exibir_lista(ListaSequencial* lst)
{
	if (esta_vazia(lst))
		printf("A lista esta vazia");
	else
	{
		for (int i = 0; i < lst->qtd - 1; i++)
		{
			printf("Posicao %2d \n", i + 1);
			exibir_circulo(lst->vetor[i]);
			printf("\n");
		}
	}
}

int busca_sequencial(ListaSequencial* lst, int raio)
{
	if (esta_vazia(lst)) 
	{
		printf("A lista esta vazia");
		return -1;
	}
	else 
	{
		int pos = 0;

		while (lst->vetor[pos]->raio < raio && pos <= lst->qtd - 1)
			pos++;

		if (pos > lst->qtd - 1)
			return -1;

		return lst->vetor[pos];
	}
}

int busca_binaria(ListaSequencial* lst, int raio) 
{
	if (esta_vazia(lst))
	{
		printf("A lista esta vazia");
		return -1;
	}
	else
	{
		int posI = 0;
		int posF = lst->qtd - 1;

		while (posI != posF)
		{
			int pos = (posI + posF) / 2;

			int raioPos = lst->vetor[pos]->raio;

			if (raioPos == raio)
				return pos;

			else
			{
				if (raioPos < raio)
					posF = pos - 1;
				else
					posI = pos + 1;
			}
		}

		return -1;
	}
}

ListaSequencial* merge(ListaSequencial* lst1, ListaSequencial* lst2) 
{
	ListaSequencial* lst = criar_lista();

	int pos1 = 0;
	int pos2 = 0;

	while (pos1 <= lst1->qtd -1 && pos2 <= lst2->qtd -1)
	{
		if (pos1 > lst1->qtd - 1)
			inserir_final(lst, lst2->vetor[pos2]);
		else
		{
			if (pos2 > lst2->qtd - 1)
				inserir_final(lst, lst1->vetor[pos1]);
			else
			{
				if (lst1->vetor[pos1] < lst2->vetor[pos2])
				{
					inserir_final(lst, lst1->vetor[pos1]);
					pos1++;
				}
				else
				{
					inserir_final(lst, lst2->vetor[pos2]);
					pos2++;
				}
			}
		}
	}
}