#include <stdio.h>
int main()
{
    float C, F;                                                             // declaração das variáveis que receberão as temperaturas
    printf("Entre com uma temperatura em graus Celsius: ");                 // escreve na tela o comando ao usuário
    scanf("%f", &C);                                                        // recebe e armazena o valor inserido pelo usuário
    F = ((9 * C) / 5) + 32;                                                 // converte o valor inserido de graus Celsius para Farenheit
    printf("%.2f graus Celsius equivalem a %.2f graus Farenheit.\n", C, F); // escreve na tela o resultado da conversão
    return 0;
}