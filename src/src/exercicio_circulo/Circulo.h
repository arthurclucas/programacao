#include <stdbool.h>

typedef struct
{
    float x, y, raio;

} circulo;

circulo* criar_circulo(float x, float y, float raio);
float calcular_perimetro(circulo* c);
float calcular_area(circulo* c);
void exibir_circulo(circulo* c);
void mover_circulo(circulo* c, float x, float y);
bool verificar_dentro_circulo(circulo* c, float x, float y);
void liberar_circulo(circulo** c);