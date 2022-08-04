#include <stdio.h>
int main()
{

    float celsius, fahren, c, f;
    printf("Entre com uma temp em Celsius: ");
    scanf("%f", &celsius); // recebe a temp em C
    printf("Entre com uma temp em Fahrenheit: ");
    scanf("%f", &fahren);                                                                                                                        // recebe a temp em F
    f = (celsius * 1.8) + 32;                                                                                                                    // faz a conversão de C para F
    c = (fahren - 32) * 0.56;                                                                                                                    // faz a conversão de F para C
    printf("%.1f graus Celsius equivalem a %.1f graus Farenheit\n%.1f graus Farenheit equivalem a %.1f graus Celsius\n", celsius, f, fahren, c); // imprime os valores

    return 0;
}