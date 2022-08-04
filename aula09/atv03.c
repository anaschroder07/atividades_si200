#include <stdio.h>
int main()
{
    char txt[200];
    FILE *arquivo;
    char titulo[50];
    fgets(titulo, 50, stdin);     // leitura do titulo
    fgets(txt, 200, stdin);       // leitura do texto
    arquivo = fopen(titulo, "w"); // abertura do arq.
    fprintf(arquivo, "%s", txt);  // escreve o texto no arq.
    fclose(arquivo);              // fechamento do arq.
    
    return 0;
}
