#include <stdio.h>
int main()
{
    int opcao, remedio, alimento, perfume, brinquedo, outro;
    printf("Escolha uma opcao:\n");
    printf("1 - Remedios\n");
    printf("2 - Alimentos\n");
    printf("3 - Perfumaria\n");
    printf("4 - Brinquedos\n");
    printf("5 - Outros\n");
    scanf("%d", &opcao); // recebe a opção
    switch (opcao)
    {
    case 1:
        printf("Os remedios estao com 30%% de desconto\n");
        printf("Escolha entre os produtos abaixo: \n"); // mostra os remédios disponíveis
        printf("1 - Dipirona (R$ 2,00)\n");
        printf("2 - Paracetamol (R$ 1,50)\n");
        scanf("%d", &remedio); // recebe a opção de remédio
        switch (remedio)
        {
        case 1:
            printf("Dipirona - R$ 1,40\n"); // mostra o valor com desconto
            break;
        case 2:
            printf("Paracetamol - R$ 1,05"); // mostra o valor com desconto
            break;
        }
        break;
    case 2:
        printf("Os alimentos estão com 15%% de desconto\n");
        printf("Escolha entre os produtos abaixo: \n"); // mostra os alimentos disponíveis
        printf("1 - Arroz 5kg (R$ 18,00)\n");
        printf("2 - Feijao 2kg (R$ 8,50)\n");
        scanf("%d", &alimento); // recebe a opção de alimento
        switch (alimento)
        {
        case 1:
            printf("Arroz 5kg - R$ 15,30\n"); // mostra o valor com desconto
            break;
        case 2:
            printf("Feijao 2kg - R$ 7,25"); // mostra o valor com desconto
            break;
        }
        break;
    case 3:
        printf("Os perfumes estão com 10%% de desconto\n");
        printf("Escolha entre os produtos abaixo: \n"); // mostra os perfumes disponíveis
        printf("1 - Femininos (R$ 75,00)\n");
        printf("2 - Masculinos (R$ 80,00)\n");
        scanf("%d", &perfume); // recebe a opção de perfume
        switch (perfume)
        {
        case 1:
            printf("Femininos - R$ 67,50\n"); // mostra o valor com desconto
            break;
        case 2:
            printf("Masculinos - R$ 72,00\n"); // mostra o valor com desconto
            break;
        }
        break;
    case 4:
        printf("Os brinquedos estão com 7%% de desconto\n");
        printf("Escolha entre os produtos abaixo: \n"); // mostra os brinquedos disponíveis
        printf("1 - Barbies (R$ 55,00)\n");
        printf("2 - Quebra-cabecas 1000 pecas (R$ 30,00)\n");
        scanf("%d", &brinquedo); // recebe a opção de brinquedo
        switch (brinquedo)
        {
        case 1:
            printf("Barbies - R$ 51,15\n"); // mostra o valor com desconto
            break;
        case 2:
            printf("Quebra-cabeca - R$ 27,90"); // mostra o valor com desconto
            break;
        }
        break;
    case 5:
        printf("Outros produtos nao possuem descontos\n");
        printf("Escolha entre os produtos abaixo: \n"); // mostra as opção disponíveis
        printf("1 - Cama, mesa e banho (R$ 100,00 - R$300,00)\n");
        printf("2 - Roupas (R$ 50,00 - R$ 200,00)\n");
        scanf("%d", &outro); // recebe a opção escolhida
        switch (outro)
        {
        case 1:
            printf("Indisponivel\n");                     // produto indisponível
            printf("Escolha novamente: \n");              // pede uma nova opção
            printf("2 - Roupas (R$ 50,00 - R$200,00)\n"); // mostra a opção disponível
            scanf("%d", &outro);                          // recebe a opção
            switch (outro)
            {
            case 2:
                printf("Roupas - R$ 50,00 - R$ 200,00\n"); // mostra o valor com desconto
                break;
            }
            break;
        case 2:
            printf("Roupas - R$ 50,00 - R$200,00\n"); // mostra o valor com desconto
            break;
        }
        break;
    default:
        printf("Opcao invalida\n");
        break;
    }
}