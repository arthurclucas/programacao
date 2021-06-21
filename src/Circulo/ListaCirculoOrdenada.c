#include "ListaCirculo.h"
#include "No.h"
#include "Circulo.h"
#include <stdio.h>
#include <stdlib.h>//malloc
#include "circulo.h"
#include <stdbool.h>
#include <math.h>

void inserir_ordenado(ListaCirculo* lst, Circulo* c)
{
	if (esta_cheia(lst))
	{
		printf("Nao e possivel inserir, pois a lista ja esta cheia");
	}
	else
	{
		if (esta_vazia(lst))
			inserir_inicio(lst, c);
		else
		{
			if (lst->primeiro->conteudo->area > c->area)
				inserir_inicio(lst, c);
			else
			{
				No* no = lst->primeiro;

				while (no->conteudo->area < c->area && no->proximo != NULL)
					no = no->proximo;

				if (no->proximo == NULL)
					inserir_final(lst, c);
				else
				{
					No* novoNo = criar_no(c);
					
					if (no->proximo != NULL)
						ligar_no(novoNo, no->proximo);

					ligar_no(no, novoNo);

					lst->quantidade = lst->quantidade + 1;
				}
			}
		}
	}
}

No* busca_sequencial(ListaCirculo* lst, int area)
{
	if (esta_vazia(lst))
		return NULL;
	else
	{
		No* no = lst->primeiro;

		while (no->conteudo->area < area && no->proximo != NULL)
			no = no->proximo;

		if (no->conteudo->area != area)
			return NULL;
		else
			return no;
	}
}

void remover_elemento(ListaCirculo* lst, Circulo* c)
{
	No* no = busca_sequencial(lst, c->area);

	if (no == NULL)
		printf("Elemento nao encontrado");
	else
	{
		if (no->proximo == NULL)
			remover_final(lst);
		else
		{
			if (no->anterior == NULL)
				remover_inicio(lst);
			else
			{
				ligar_no(no->anterior, no->proximo);
				lst->quantidade = lst->quantidade - 1;
			}
		}
	}
}

ListaCirculo* merge(ListaCirculo* lst1, ListaCirculo* lst2) 
{
	if (esta_vazia(lst1))
		return lst2;
	else
	{
		if (esta_vazia(lst2))
			return lst1;
		else
		{
			ListaCirculo* lst3 = criar_lista(lst1->quantidade + lst2->quantidade);

			No* noLst1 = lst1->primeiro;
			No* noLst2 = lst2->primeiro;

			while (noLst1 != NULL && noLst2 == NULL)
			{				
				int noInserir = 0;

				if (noLst1 == NULL)
					noInserir = 2;
				else
				{
					if (noLst2 == NULL)
						noInserir = 1;
					else
					{
						if (noLst1->conteudo->area < noLst2->conteudo->area)
							noInserir = 1;
						else
							noInserir = 2;
					}
				}

				if (noInserir == 1)
				{
					inserir_final(lst3, noLst1->conteudo);
					noLst1 = noLst1->proximo;
				}
				else
				{
					inserir_final(lst3, noLst2->conteudo);
					noLst2 = noLst2->proximo;
				}
			}

			return lst3;
		}
	}
}