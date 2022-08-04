#include <stdio.h>
int main()
{
    FILE *arquivo;
    char *linhas[30];
    char linha[100];
    int i = 0;
    arquivo = fopen("arquivo_linhas.txt", "r"); // abertura do arq.
    while (!feof(arquivo))
    { // laço para contar o número de linhas
        linhas[i] = fgets(linha, 100, arquivo);
        i++;
    }
    printf("%d\n", i); // imprime o número de linhas
    fclose(arquivo);   // fechamento do arquivo
    return 0;
}