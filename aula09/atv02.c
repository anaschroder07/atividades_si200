#include <stdio.h>
int main()
{
    FILE *arquivo;
    char c;
    int i = 0;
    arquivo = fopen("arquivo_base.txt", "r"); // abertura do arq.
    c = getc(arquivo);
    while (!feof(arquivo))
    { // laço para contar as vogais
        if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u')
        {
            i += 1;
        }
        c = getc(arquivo);
    }
    printf("%d\n", i); // exibição da contagem
    fclose(arquivo);   // fechamento do arq.
    return 0;
}
