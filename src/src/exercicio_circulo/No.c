#include "No.h"
#include <stdlib.h>//malloc

No* criar_no(Circulo* c, No* anterior) {
	
	No* no = malloc(sizeof(No));
	no->conteudo = c;
	anterior->proximo = no;
	no->anterior = anterior;
}
