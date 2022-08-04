#include <stdio.h>
int main()
{
    char titulo[50];
    char txt[100];
    FILE *arquivo;
    scanf("%s", titulo);          // lê o título do arq.
    arquivo = fopen(titulo, "r"); // abertura do arq.
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%s", txt); // le o conteudo do arq.
    }
    printf("%s", txt); // imprime o conteudo do arq.
    fclose(arquivo);   // fechamento do arq.
    return 0;
}
