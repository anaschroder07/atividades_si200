#include <stdio.h>
int main()
{
    int num;
    char *romanos[] = {"I", "IV", "V", "IX", "X", "XL", "L",
                       "XC", "C", "CD", "D", "CM", "M"};
    int normais[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500,
                     900, 1000};
    int indice = (sizeof(normais) / sizeof(normais[0])) - 1; // encontra a quant de elementos no array
    scanf("%d", &num);
    while (num > 0)
    {
        if (num >= normais[indice])
        {
            printf("%s", romanos[indice]); // conversão é impressa
            num -= normais[indice];        // diminui o num pra mais laços até imprimir o num todo
        }
        else
        {
            indice--;
        }
    }
    printf("\n");
}