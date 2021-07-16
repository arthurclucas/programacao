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

int esvaziar(ListaCirculo* lst)
{
	lst->primeiro = NULL;
	lst->ultimo = NULL;
	lst->quantidade = 0;

	return 3;
}

No* buscar_elemento(ListaCirculo* lst, int pos, int *iteracoes)
{
	iteracoes++;
	if (lst->quantidade < pos)
		return lst->ultimo;
	else
	{
		iteracoes++;
		No* retorno = lst->primeiro;

		for (int i = 1; i < pos; i++)
		{
			retorno = retorno->proximo;
			iteracoes = iteracoes + 3;
		}
			
		return retorno;
	}
}

int inserir_primeiro(ListaCirculo* lst, Circulo* c) 
{
	int iteracoes;
	
	No* unico = criar_no(c);
	iteracoes = 4;

	lst->primeiro = unico;
	iteracoes++;
	lst->ultimo = unico;
	iteracoes++;
	lst->quantidade = lst->quantidade + 1;
	iteracoes++;

	return iteracoes;
}

int inserir_inicio(ListaCirculo* lst, Circulo* c)
{
	int iteracoes = 1;
	if (esta_vazia(lst))
		inserir_primeiro(lst, c);
	else
	{
		iteracoes++;
		if (esta_cheia(lst)) 
			printf("Nao e possivel inserir, pois a lista esta cheia");
		else
		{
			No* primeiro = lst->primeiro;
			iteracoes++;

			No* novoPrimeiro = criar_no(c);
			iteracoes++;
			
			iteracoes = iteracoes + ligar_no(novoPrimeiro, primeiro);
						
			lst->primeiro = novoPrimeiro;
			iteracoes++;

			lst->quantidade = lst->quantidade + 1;
			iteracoes++;
		}
	}

	return iteracoes;
}

int inserir_final(ListaCirculo* lst, Circulo* c)
{
	int iteracoes = 1;
	if (esta_vazia(lst))
		inserir_primeiro(lst, c);
	else
	{
		iteracoes++;
		if (esta_cheia(lst))
			printf("Nao e possivel inserir, pois a lista esta cheia");
		else
			iteracoes = iteracoes + inserir_ultimo(lst, c);
	}

	return iteracoes;
}

int inserir_ultimo(ListaCirculo* lst, Circulo* c)
{
	int iteracoes = 0;

	No* ultimo = lst->ultimo;
	iteracoes++;
	No* novoUltimo = criar_no(c);
	iteracoes++;

	iteracoes = iteracoes + ligar_no(ultimo, novoUltimo);
	
	lst->ultimo = novoUltimo;
	iteracoes++;

	lst->quantidade = lst->quantidade + 1;
	iteracoes++;

	return iteracoes;
}

int inserir_meio(ListaCirculo* lst, Circulo* c, int pos)
{
	int iteracoes = 1;
	if (esta_vazia(lst))
		iteracoes += inserir_primeiro(lst, c);
	else 
	{
		iteracoes++;
		if (lst->quantidade < pos)
			iteracoes += inserir_final(lst, c);
		else
		{
			iteracoes++;
			if (esta_cheia(lst))
				printf("Nao e possivel inserir, pois a lista esta cheia");
			else
			{
				No* depois = buscar_elemento(lst, pos, iteracoes);
				
				No* antes = depois->anterior;
				iteracoes++;

				No* meio = criar_no(c);
				iteracoes = iteracoes + 4;


				iteracoes += ligar_no(antes, meio);
				iteracoes += ligar_no(meio, depois);

				lst->quantidade = lst->quantidade + 1;
				iteracoes++;
			}
		}
	}

	return iteracoes;
}

int remover_inicio(ListaCirculo* lst)
{
	int iteracoes = 1;
	if (!esta_vazia(lst))
	{
		iteracoes++;
		if (lst->quantidade == 1)
			iteracoes += esvaziar(lst);
		else 
		{
			No* novoPrimeiro = lst->primeiro->proximo;
			iteracoes++;

			lst->primeiro = novoPrimeiro;
			iteracoes++;

			novoPrimeiro->anterior = NULL;
			iteracoes++;

			lst->quantidade = lst->quantidade - 1;
			iteracoes++;
		}
	}

	return iteracoes;
}

int remover_final(ListaCirculo* lst)
{
	int iteracoes = 1;
	if (!esta_vazia(lst))
	{
		iteracoes++;
		if (lst->quantidade == 1)
			iteracoes += esvaziar(lst);
		else
		{
			No* novoUltimo = lst->ultimo->anterior;
			iteracoes++;

			lst->ultimo = novoUltimo;
			iteracoes++;

			novoUltimo->proximo = NULL;
			iteracoes++;

			lst->quantidade = lst->quantidade - 1;
			iteracoes++;
		}
	}

	return iteracoes;
}

int remover_meio(ListaCirculo* lst, int pos)
{
	int iteracoes = 1;
	if (!esta_vazia(lst))
	{
		iteracoes++;
		if (lst->quantidade == 1)
			iteracoes += esvaziar(lst);
		else
		{
			if (pos >= lst->quantidade)
				iteracoes += remover_final(lst);
			else
			{
				No* remover = buscar_elemento(lst, pos, iteracoes);
				iteracoes += ligar_no(remover->anterior, remover->proximo);
				
				lst->quantidade = lst->quantidade - 1;
				iteracoes++;
			}
		}
	}

	return iteracoes;
}

ListaCirculo* concatenar(ListaCirculo* lst1, ListaCirculo* lst2, int* iteracoes)
{
	iteracoes++;
	if (esta_vazia(lst1))
		return lst2;
	else
	{
		iteracoes++;
		if (esta_vazia(lst2))
			return lst1;
		else
		{
			iteracoes++;
			if (lst2->quantidade > (lst1->capacidade - lst1->quantidade))
				lst1->capacidade = lst1->quantidade + lst2->quantidade;

			iteracoes += ligar_no(lst1->ultimo, lst2->primeiro);

			lst1->quantidade = lst1->quantidade + lst2->quantidade;
			iteracoes++;

			iteracoes += esvaziar(lst2);
			return lst1;
		}
	}
}

void liberar_lista(ListaCirculo** lst)
{
	free(*lst);
	*lst = NULL;
}