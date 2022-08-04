#include <stdio.h>
int main()
{
    float raio, area;
    
    printf("Entre com o raio de uma circunferencia: ");
    scanf("%f", &raio);                                        // recebe os valores
    area = 3.14 * (raio * raio);                               // faz o cálculo
    printf("A area desta circunferÊncia eh de: %.2f\n", area); // imprime a area
    
    return 0;
}