#include <stdio.h>
int main()
{
    int num;
    printf("Entre com o valor a ser sacado: \n");
    scanf("%d", &num);                                  // recebe o valor
    printf("%d nota(s) de R$ 100,00\n", num / 100);     // realiza as divisões e imprime os inteiros para contabilizar as notas
    num = num - num / 100 * 100;                        // subtrai para encontrar a quant de notas com valor menor
    printf("%d nota(s) de R$ 50,00\n", num / 50);
    num = num % 50;                                     // guarda o resto p/ contar as notas menores
    printf("%d nota(s) de R$ 10,00\n", num / 10);
    num = num % 10;                                     // guarda o resto p/ contar as notas menores
    printf("%d nota(s) de R$ 5,00\n", num / 5);
    num = num % 5;                                      // guarda o resto p/ contar as notas menores
    printf("%d nota(s) de R$ 1,00\n", num / 1);
    return 0;
}