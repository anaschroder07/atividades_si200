#include <stdio.h>
int main()
{
    char caracter;                                            // declaração do caracter
    int num = 0;                                              // declaração da variável que receberá o valor numérico do caracter
    printf("Digite um caracter: ");                           // escreve na tela o comando ao usuário
    scanf("%c", &caracter);                                   // recebe e armazena o valor inserido pelo usuário
    num = caracter;                                           // a variável num recebe o valor numérico do caracter que foi inserido
    printf("O valor numerico de %c eh: %d\n", caracter, num); // escreve na tela o valor numérico do caracter inserido inicialmente
    return 0;
}
