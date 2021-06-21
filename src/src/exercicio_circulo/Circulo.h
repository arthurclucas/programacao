#include <stdbool.h>

typedef struct
{
    float x, y, raio;

} Circulo;

Circulo* criar_circulo(float x, float y, float raio);
float calcular_perimetro(Circulo* c);
float calcular_area(Circulo* c);
void exibir_circulo(Circulo* c);
void mover_circulo(Circulo* c, float x, float y);
bool verificar_dentro_circulo(Circulo* c, float x, float y);
void liberar_circulo(Circulo** c);