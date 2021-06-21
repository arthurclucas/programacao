#include "ListaCirculo.h"
#include "No.h"
#include "Circulo.h"
#include <stdio.h>
#include <stdlib.h>//malloc
#include "circulo.h"
#include <stdbool.h>
#include <math.h>

ListaCirculo* criar_lista(int qtdElementos, Circulo* vetor[])
{
	ListaCirculo* lst = malloc(sizeof(ListaCirculo));

	for (int i = 0; i < qtdElementos; i++)
	{
		Circulo* c = vetor[i];			

		if (lst->quantidade == 0) {
			lst->primeiro = criar_no(c, NULL);			
		}
		else {
			lst->ultimo = criar_no(c, lst->ultimo);
		}

		lst->quantidade = lst->quantidade + 1;		
	}

	return lst;
}

void* exibir_lista(ListaCirculo* lst) 
{
	No* no = lst->primeiro;

	while (no != NULL)
	{
		exibir_circulo(no->conteudo);
		no = no->proximo;
	}
}