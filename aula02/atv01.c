#include <stdio.h>
int main()
{
    int inteiro;                                                                                            // declaração do número inteiro
    float real;                                                                                             // declaração do número real
    char caracter;                                                                                          // declaração do caracter
    char string[50];                     
                                                                                                            // declaração da string
    printf("Digite um numero inteiro, um numero real, um caracter e uma string (separados por espaco):\n"); // escreve o comando ao usuário
    scanf("%d %f %c %s", &inteiro, &real, &caracter, string);                                               // recebe e armazena os valores inseridos pelo usuário
    
    printf("Inteiro: %d\t Real: %.2f\t Caracter: %c\t String: %s\n", inteiro, real, caracter, string);      // escreve na tela os valores inseridos
   
    return 0;
}
