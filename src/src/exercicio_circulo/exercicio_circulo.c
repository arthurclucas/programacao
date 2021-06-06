#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "circulo.h"
#include <stdbool.h>

int main()
{
    float x, y, raio;

    printf("informe os valores do circulo (x e y do centro e a medida do raio) no formato 'x y r':\n");
    //Criar e exibir o círculo
    scanf("%f %f %f", &x, &y, &raio);
    circulo* c = criar_circulo(x, y, raio);
    printf("dados do circulo\n");
    exibir_circulo(c);

    //Mover o círculo
    float deltaX, deltaY;
    printf("informe os valores de deslocamento do circulo (delta x e delta y):\n");
    scanf("%f %f", &deltaX, &deltaY);
    mover_circulo(c, deltaX, deltaY);
    printf("dados do circulo movido\n");
    exibir_circulo(c);

    //Calcular o perímetro do cículo
    printf("\n");
    float perimetro = calcular_perimetro(c);
    printf("O perimetro e: %.2f\n", perimetro);

    //Calcular a área
    float area = calcular_area(c);
    printf("A area e: %.2f\n", area);

    //Verificar se um ponto informado está dentro do círculo
    printf("informe os valores de um ponto para verificar se o mesmo está dentro do circulo:\n");
    scanf("%f %f", &x, &y);
    bool dentro = verificar_dentro_circulo(c, x, y);

    if (dentro)
        printf("O ponto esta dentro do circulo!\n");

    else
        printf("O ponto esta fora do circulo!\n");

    //liberar_circulo(c);

    return 0;
}