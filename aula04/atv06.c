#include <stdio.h>
int main()
{
    float n1, n2, n3, n4, n5, media = 0;
    printf("Entre com 5 numeros reais:\n");
    scanf("%f", &n1); // recebe os valores
    scanf("%f", &n2);
    scanf("%f", &n3);
    scanf("%f", &n4);
    scanf("%f", &n5);
    media = (n1 + n2 + n3 + n4 + n5) / 5;                            // realiza a média
    printf("A media aritmetica destes 5 numeros eh: %.2f\n", media); // imprime a média
    return 0;
}