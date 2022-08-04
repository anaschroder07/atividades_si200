#include <stdio.h>
int main()
{
    char num[20], inverso[20];
    int i, x = 0;
    ;
    printf("Entre com um numero: \n");
    scanf("%s", num); // recebe o valor
    for (i = strlen(num) - 1; i >= 0; i--)
    {
        inverso[x] = num[i]; // faz a inversão
        x++;
    }
    inverso[x] = '\0';                                                // coloca um zero na posição final para guardar só as posições utilizadas
    printf("O numero %s em sua ordem inversa eh %s\n", num, inverso); // imprime o valor inverso
    return 0;
}