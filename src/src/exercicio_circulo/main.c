#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "Circulo.h"
#include "No.h"
#include "ListaCirculo.h"
#include <stdbool.h>

int main2()
{
    float x, y, raio;

    printf("informe os valores do circulo (x e y do centro e a medida do raio) no formato 'x y r':\n");
    //Criar e exibir o círculo
    scanf("%f %f %f", &x, &y, &raio);
    Circulo* c = criar_circulo(x, y, raio);
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

int main()
{
    Circulo* c1 = criar_circulo(2, 5, 3);
    Circulo* c2 = criar_circulo(2, 6, 4);

    Circulo* circulos[2] = { c1, c2 };

    criar_lista(2, circulos);
}