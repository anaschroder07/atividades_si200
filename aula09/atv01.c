#include <stdio.h>
int main()
{
    FILE *arquivo;
    char c;
    int i = 0;
    arquivo = fopen("arquivo_base.txt", "r+"); // abertura do arq.
    c = getc(arquivo);
    while (!feof(arquivo)) { // laço para contar os caracteres
        if (c != ' ')
        {
            i += 1;
        }
        c = getc(arquivo);
    }
    fprintf(arquivo, " %d \n", i); // exibição da contagem
    fclose(arquivo);               // fechamento do arq.
    return 0;
}
