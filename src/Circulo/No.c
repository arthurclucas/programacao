#include "No.h"
#include <stdlib.h>//malloc

No* criar_no(Circulo* c) 
{
	No* no = malloc(sizeof(No));
	no->conteudo = c;	
	no->proximo = NULL;
	no->anterior = NULL;

	return no;
}

int ligar_no(No* anterior, No* proximo)
{
	anterior->proximo = proximo;
	proximo->anterior = anterior;

	return 2;
}