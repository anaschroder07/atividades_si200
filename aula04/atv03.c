#include <stdio.h>
int main()
{
    float km, m = 0;
    printf("Entre com uma velocidade em quilometros por hora: ");
    scanf("%f", &km); // recebe o valor
    m = km / 3.6;     // faz a conversão para metros por segundo
    printf("%.2f quilometros por hora eh o mesmo que %.2f metros por segundo\n", km, m); //imprime os resultados
return 0;
}