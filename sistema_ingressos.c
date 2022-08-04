//Grupo:
//Ana Júlia, Heloisie, Iara, Jorge

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encontrarFilme(FILE *file, char titulo[]);
int qntFilmes(FILE *file);
void perguntaVoltarMenu();
void exibirFilmes(FILE *file);
void buscar(FILE *file);
void alterarFilmes(FILE *file);
void cadastrarFilmes(FILE *file);
void excluirFilme(FILE *file,FILE *file2);
void cadastrarIngressos(FILE *file,FILE *file2);
void alterarIngressos(FILE *file2);
void excluirIngressos(FILE *file);
void comprarIngresso(FILE *file,FILE *file2);
void menu();

int cadastro = 0; //Variavel que ve se foi o CadastrarFilme que chamou outra funcao

int main()
{
    //funcao principal
    menu();
    return 0;
}

int encontrarFilme(FILE *file, char titulo[]){
    int encontrado=0,i;
    file = fopen("BD.txt","r+"); //Abre o arquivo
    if(file==NULL){ //Verifica se o arquivo foi encontrado
        if(cadastro==0){
            printf("\n+----------------------------+\n");
            printf("|   ARQUIVO NÃO ENCONTRADO   |\n");
            printf("|   Talvez não haja nenhum   |\n");
            printf("|   filme cadastrado, tente  |\n");
            printf("| voltar ao menu e seleciona |\n");
            printf("| a opcao: Cadastrar Filmes  |\n");
            printf("+----------------------------+\n");
        }        
    }else{
        char frase[100],frase2[100],frase3[100];
        while(fgets(frase,100,file)!=NULL){ //Pega a linha do arquivo até encontrar o que procura
            fgets(frase2,100,file);
            fgets(frase3,100,file);
            if(strcmp(frase,titulo)==0){ //Verifica se encontrou o que procura
                encontrado=1;
                break;
            }else{         
                i++;
            }  
        }

        if(encontrado==0){
            if(cadastro==0){
                printf("\n+--------------------------------------------+\n"); 
                printf("|           FILME NAO FOI ENCONTRADO         |\n");
                printf("+--------------------------------------------+\n"); 
            }          
        }

        fclose(file); //Fecha o arquivo
    }
    return encontrado;
}

int qntFilmes(FILE *file){
    /*parametros:recebe um ponteiro para file
    retorno: retorna a quantidade de filmes cadastrados*/    
    int qnt=0;
    file = fopen("BD.txt","r"); //Abre o arquivo
    if(file==NULL){ //Verifica se o arquivo foi encontrado
        printf("\n+----------------------------+\n");
        printf("|   ARQUIVO NÃO ENCONTRADO   |\n");
        printf("|   Talvez não haja nenhum   |\n");
        printf("|   filme cadastrado, tente  |\n");
        printf("| voltar ao menu e seleciona |\n");
        printf("| a opcao: Cadastrar Filmes  |\n");
        printf("+----------------------------+\n");
    }else{
        char frase[100];
        while(fgets(frase,100,file)!=NULL){ //Verifica se o arquivo está vazio
            qnt++;
        }
        
        if(qnt==0){
            printf("\n+--------------------------------------------+\n");
            printf("|     NÃO HÁ FILMES EM CARTAZ NO MOMENTO     |\n");
            printf("+--------------------------------------------+\n");
        }

        fclose(file); //Fecha o arquivo
    }
    return qnt;
}

void perguntaVoltarMenu(){
    /*recebe um input do tipo string 's' ou 'n' caso 's' 
    retorna executa a função menu caso 'n' finaliza o programa*/
    char resposta;
    setbuf(stdin,NULL);//limpa o buffer do teclado
    printf("\nVocê deseja voltar ao menu principal? \nDigite S/N: ");
    scanf("%c",&resposta);
    if(resposta=='S'||resposta=='s'){
        printf("\nReentrando no menu principal...\n\n\n");
        menu();
    }else{
        if(resposta=='N'||resposta=='n'){
            printf("\nFinalizando programa...\n\n\n");
        }else{            
            printf("\nResposta inválida\nTente novamente!\n\n");            
            setbuf(stdin,NULL);
            perguntaVoltarMenu();
        }
    }
}

void exibirFilmes(FILE *file){
    /*parametros: recebe um ponteiro para file
    exibe os filmes que foram cadastrados no arquivo BD*/    
    int qnt = qntFilmes(file);        
    if(qnt!=0){
        int i=1;
        char frase[100],frase2[100],frase3[100];
        file = fopen("BD.txt","r");
        printf("\n+--------------------------------------------+\n");
        printf("|              FILMES EM CARTAZ:             |\n");
        printf("|--------------------------------------------|\n");
        while(fgets(frase,100,file)!=NULL){
            frase[strlen(frase)-1] = '\0';
            fgets(frase2,100,file);
            fgets(frase3,100,file);                
            frase2[strlen(frase2)-1] = '\0';
            frase3[strlen(frase3)-1] = '\0';                               
            printf("|--------------------------------------------|\n");
            printf("| Código do filme: %-26i|\n",i);
            printf("| Nome: %-37s|\n",frase);
            printf("| Duração: %-34s|\n",frase2);
            printf("| Classificação Etária: %-21s|\n",frase3);
            printf("|--------------------------------------------|\n");
            i++;         
        }
        printf("+--------------------------------------------+\n");   
        fclose(file);  
    }        
    perguntaVoltarMenu();
}

void buscar(FILE *file){
    /*parametros: recebe um ponteiro para file
    recebe um input com o nome do filme desejado, busca e exibe por     
    filmes cadastrados no arquivo BD*/
    int encontrado;
    char filme[100];  

    printf("\n+--------------------------------------------+\n");
    printf("|                    BUSCA:                  |\n");
    printf("+--------------------------------------------+\n");

    setbuf(stdin,NULL);
    printf("Qual filme você quer buscar?\nDigite o nome: ");
    fgets(filme,100,stdin);

    encontrado = encontrarFilme(file, filme);  //Verifica se o filme existe

    if(encontrado==1){
        file = fopen("BD.txt","r");
        int i=1;
        char frase[100],frase2[100],frase3[100];

        printf("\n+--------------------------------------------+\n");
        printf("|             RESULTADOS DA BUSCA:           |\n");
        printf("|--------------------------------------------|\n");

        while(fgets(frase,100,file)!=NULL){  //Busca os dados
            fgets(frase2,100,file);
            fgets(frase3,100,file);
            if(strcmp(frase,filme)==0){
                frase[strlen(frase)-1] = '\0';
                frase2[strlen(frase2)-1] = '\0';
                frase3[strlen(frase3)-1] = '\0';
                printf("|--------------------------------------------|\n");
                printf("| Código do filme: %-26i|\n",i);
                printf("| Nome: %-37s|\n",frase);
                printf("| Duração: %-34s|\n",frase2);
                printf("| Classificação Etária: %-21s|\n",frase3);
                printf("|--------------------------------------------|\n");
                break;
            }else{         
                i++;
            }  
        }
        printf("+--------------------------------------------+\n"); 
        fclose(file);
    }           
    
    perguntaVoltarMenu();
}

void alterarFilmes(FILE *file){
    int encontrado;
    char filme[100];

    setbuf(stdin,NULL);
    printf("\nDigite o nome do filme que deseja alterar: ");
    fgets(filme,100,stdin);

    encontrado = encontrarFilme(file, filme);

    if(encontrado==1){ //Verifica se esse filme existe
        int i=1;
        char titulo[100],duracao[100],classificacao[100],frase[100],frase2[100],frase3[100];

        FILE *fileTranfere;
        fileTranfere = fopen("BDTransferencia.txt","w");
        file = fopen("BD.txt","r+");

        while(fgets(frase,100,file)!=NULL){ //Mostra os dados atuais do filme a ser alterado
            fgets(frase2,100,file);
            fgets(frase3,100,file);
            
            if(strcmp(frase,filme)==0){
                frase[strlen(frase)-1] = '\0';
                frase2[strlen(frase2)-1] = '\0';
                frase3[strlen(frase3)-1] = '\0';
                printf("\n+--------------------------------------------+\n");
                printf("|          DADOS ATUAIS DESSE FILME:         |\n");
                printf("|--------------------------------------------|\n");
                printf("|--------------------------------------------|\n");
                printf("| Nome: %-37s|\n",frase);
                printf("| Duração: %-34s|\n",frase2);
                printf("| Classificação Etaria: %-21s|\n",frase3);
                printf("+--------------------------------------------+\n");
                break;
            } 
        }

        printf("\nDigite o novo nome do filme:  ");
        fgets(titulo,100,stdin);
        printf("\nDigite a nova duracao do filme:  ");
        fgets(duracao,100,stdin);
        printf("\nDigite a nova classificacao etaria do filme:  ");
        fgets(classificacao,100,stdin);
        
        rewind(file); //Volta pro inicio do arquivo
        while(fgets(frase,100,file)!=NULL){ //Coloca tudo no arquivo de transferencia
            fgets(frase2,100,file);
            fgets(frase3,100,file);
            
            if(strcmp(frase,titulo)!=0){
                fputs(frase,fileTranfere);
                fputs(frase2,fileTranfere);
                fputs(frase3,fileTranfere);
            }else{
                fputs(titulo,fileTranfere);
                fputs(duracao,fileTranfere);
                fputs(classificacao,fileTranfere);
            }
        }

        remove("BD.txt"); //Exclui o arquivo antigo
        rename("BDTransferencia.txt", "BD.txt"); //Renomeia o arquivo novo
        
        printf("\n+--------------------------------------------+\n"); 
        printf("|      ALTERACAO REALIZADA COM SUCESSO       |\n");
        printf("+--------------------------------------------+\n"); 
        fclose(file);
        fclose(fileTranfere);
    }

    perguntaVoltarMenu();
}

void cadastrarFilmes(FILE *file){
    /*parametros: recebe um ponteiro para file
    recebe 3 inputs nome, duracao e classificação do filme e as        
    armazena no arquivo BD*/
    int encontrado=0;
    char titulo[101];
       
    printf("\nDigite o nome do filme que deseja cadastrar: ");
    setbuf(stdin,NULL);
    fgets(titulo,101,stdin); 

    cadastro=1;
    
    encontrado = encontrarFilme(file, titulo);
    
    if(encontrado==0){
        char duracao[10], classificacao[15];
        file = fopen("BD.txt","a+");
        printf("\nDigite a duração do filme: ");
        fgets(duracao,10,stdin);  
        printf("\nDigite a classificação etária do filme: ");
        fgets(classificacao,15,stdin); 

        fflush(stdin);
        fputs(titulo,file);
        fputs(duracao,file);
        fputs(classificacao,file);
        fclose(file);
    }else{
        printf("\n+----------------------------------------------+\n"); 
        printf("|         ESSE FILME JÁ FOI CADASTRADO!!       |\n");
        printf("|  OBS. Se quiser altera-lo volte ao menu e    |\n");
        printf("|  selecione a opcao: Alterar dados de Filmes  |\n");
        printf("+----------------------------------------------+\n"); 
    }

    cadastro=0; 
    
    perguntaVoltarMenu();
}

void excluirFilme(FILE *file,FILE *file2){
    /* parametros: recebe um ponteiro para filme
    recebe  um input com o nome do filme e busca-o no arquivo para excluí-lo.
    Caso o filme seja encontrado ele é deletado, e caso não seja, o usuário é
    informado da inexistência do filme no BD */
    int encontrado=0;
    char titulo[101];
    
    printf("\nDigite o nome do filme que deseja excluir: ");
    setbuf(stdin,NULL);
    fgets(titulo,101,stdin); 

    encontrado = encontrarFilme(file, titulo);

    if(encontrado==0){
        printf("\n+--------------------------------------------+\n"); 
        printf("|  OBS.Para excluir um filme ele deve estar  |\n");
        printf("|              cadastrado.                   |\n");
        printf("+--------------------------------------------+\n"); 
    }else{
        char frase[100],frase2[100],frase3[100],sobra[400];

        FILE *fileTranfere;
        file = fopen("BD.txt","r");
        fileTranfere = fopen("BDTransferencia.txt","w");

        while(fgets(frase,100,file)!=NULL){
            fgets(frase2,100,file);
            fgets(frase3,100,file);
            
            if(strcmp(frase,titulo)!=0){
                fputs(frase,fileTranfere);
                fputs(frase2,fileTranfere);
                fputs(frase3,fileTranfere);
            }
        }

        remove("BD.txt");
        rename("BDTransferencia.txt", "BD.txt");
        
        printf("\n+--------------------------------------------+\n"); 
        printf("|       REMOCAO REALIZADA COM SUCESSO        |\n");
        printf("+--------------------------------------------+\n"); 
        fclose(fileTranfere);
        fclose(file);

        titulo[strlen(titulo)-1] = '\0';
        strcat(titulo, ".txt");

        file2 = fopen(titulo,"r");

        if(file2!=NULL){ //Removendo o arquivo de ingresso se o filme for tirado de exibicao
            remove(titulo);
            fclose(file2);
        }
    }

    perguntaVoltarMenu();
}

void cadastrarIngressos(FILE *file,FILE *file2){
    /*parametros: recebe um ponteiro para file
    recebe  um input com o nome do filme e busca no arquivo BD
    caso o arquivo seja encontrado recebe o input de preco e 
    horario do ingresso e aramazena no arquivo BD*/
    int i,encontrado=0,qntHorarios=0;
    char titulo[101],preco[10];
    char **horarios;
    
    printf("\nDigite o nome do filme: ");
    setbuf(stdin,NULL);
    fgets(titulo,101,stdin); 

    encontrado = encontrarFilme(file, titulo);//Verificando se o filme existe

    if(encontrado==0){
        printf("\n\n+--------------------------------------------+\n"); 
        printf("| OBS.Para cadastrar um ingresso, deve ter o |\n");
        printf("| filme correspondente cadastrado.           |\n");
        printf("+--------------------------------------------+\n"); 
    }else{
        char arq[strlen(titulo)];
        strcpy(arq,titulo);
        arq[strlen(arq)-1] = '\0';
        strcat(arq, ".txt");

        file2 = fopen(arq,"r");
        if(file2==NULL){//Verificando se já há esse ingresso
            file2 = fopen(arq,"a+");
       
            printf("\nDigite o preço do ingresso intregral: ");
            fgets(preco,10,stdin);
            printf("\nHá quantos horários disponíveis para esse filme? ");
            while(qntHorarios<1){  //Evita que digitem letras  
                setbuf(stdin,NULL);//limpa o buffer do teclado
                scanf("%d", &qntHorarios);
                if(qntHorarios<1){
                    printf ("\nDeve ser pelo menos 1 horario!!!\n\nInsira a quantidade:  ");
                }                
            }

            horarios = (char**) malloc(qntHorarios*sizeof(char*));
            for(int i=0;i<qntHorarios;i++){
                horarios[i] = (char*) malloc(10*sizeof(char));
            }  

            setbuf(stdin,NULL);                
            for(int i=0;i<qntHorarios;i++){ 
                printf("\nDigite o %d horário (no formato: hh:mm): ",i+1);
                fgets(horarios[i],10,stdin);
            }

            //Cadastrando no arquivo
            fflush(stdin);
            fputs(titulo,file2);
            fputs(preco,file2);
            for(int i=0;i<qntHorarios;i++){
                fputs(horarios[i],file2);
            }                    
            fclose(file2);
        }else{
            printf("\n+--------------------------------------------+\n"); 
            printf("|      ESSE INGRESSO JÁ FOI CADASTRADO!!     |\n");
            printf("|  OBS. Se quiser altera-lo volte ao menu e  |\n");
            printf("|  selecione a opcao: Alterar Ingressos.     |\n");
            printf("+--------------------------------------------+\n"); 
        }
        
    }   
    perguntaVoltarMenu();
}

void alterarIngressos(FILE *file2){
    char titulo[100],horario[10],frase[100],frase2[100],frase3[100],preco[100];
    int escolha,qnt=0;
    
    setbuf(stdin,NULL);
    printf("\nDigite o nome do filme que deseja alterar: ");
    fgets(titulo,100,stdin);

    titulo[strlen(titulo)-1] = '\0';
    strcat(titulo, ".txt");

    file2 = fopen(titulo,"r+");
    if(file2!=NULL){
        
        fgets(frase,100,file2);
        fgets(frase2,100,file2);        
        frase[strlen(frase)-1] = '\0';
        frase2[strlen(frase2)-1] = '\0';

        printf("\n+--------------------------------------------+\n");
        printf("|             POSSÍVEIS INGRESSOS:           |\n");
        printf("|--------------------------------------------|\n");
        printf("|--------------------------------------------|\n");
        printf("| Nome: %-37s|\n",frase);
        printf("| Preco: R$%-34s|\n",frase2);
        printf("|--------------------------------------------|\n");
        printf("|                  HORARIOS:                 |\n");
        printf("|                                            |\n");

        while(fgets(frase3,100,file2)!=NULL){ 
                frase3[strlen(frase3)-1] = '\0';                
                printf("|                   %-25s|\n",frase3);
        }
        printf("+--------------------------------------------+\n\n\n"); 



        printf("\n+--------------------------------------------+\n");
        printf("|  Ola, para alterar o ingresso você deseja: |\n");
        printf("|    1 - Somente adicionar mais horarios     |\n");
        printf("|                     OU                     |\n");
        printf("|      2 - Alterar os dados já existentes    |\n");
        printf("+--------------------------------------------+\n");
        printf("\n\nEscolha: (Digite 1 ou 2) -   ");
        while(!scanf("%d", &escolha)){  //Evita que digitem letras  
            setbuf(stdin,NULL);//limpa o buffer do teclado
            printf ("\nDeve ser digitado 1 ou 2, nada mais.!!!\n\nInsira o número da sua opção:  ");
        }

        switch(escolha){
            case 1:
                fseek(file2, 0, SEEK_END); //Manda o cursor para o fim do arquivo
                printf("Mais quantos horarios voc deseja adicionar?");
                while(qnt<1){  //Evita que digitem letras  
                    setbuf(stdin,NULL);//limpa o buffer do teclado
                    scanf("%d", &qnt);
                    if(qnt<1){
                        printf ("\nDeve ser pelo menos 1 horario!!!\n\nInsira a quantidade:  ");
                    } 
                }
                for(int i=0;i<qnt;i++){
                    setbuf(stdin,NULL);//limpa o buffer do teclado
                    printf("\nDigite o %d horário (no formato: hh:mm): ",i+1);
                    fgets(horario,10,stdin);
                    fflush(stdin);
                    fputs(horario,file2);
                }
                break;
            case 2:
                fclose(file2);
                file2 = fopen(titulo,"w+");
                setbuf(stdin,NULL);//limpa o buffer do teclado
                printf("\nDigite o novo preco: ");
                fgets(preco,100,stdin);
                printf("\n\nTODOS os horarios antigos serao excluidos\n\nQuantos horarios voce quer colocar dessa vez?\nDigite um numero:  ");
                while(qnt<1){  //Evita que digitem letras  
                    setbuf(stdin,NULL);//limpa o buffer do teclado
                    scanf("%d", &qnt);
                    if(qnt<1){
                        printf ("\nDeve ser pelo menos 1 horario!!!\n\nInsira a quantidade:  ");
                    } 
                }
                fputs(frase,file2);
                fputc('\n',file2);
                fputs(preco,file2);
                for(int i=0;i<qnt;i++){
                    setbuf(stdin,NULL);//limpa o buffer do teclado
                    printf("\nDigite o %d horário (no formato: hh:mm): ",i+1);
                    fgets(horario,10,stdin);
                    fflush(stdin);
                    fputs(horario,file2);
                }
                break;
            default:
                printf("\nNAO FOI POSSIVEL COMPREENDER SUA ESCOLHA.\n TENTE NOVAMENTE DEPOIS.\n");
                break;
        }
        fclose(file2);
    }else{
        printf("\n+-----------------------------------------------------------+\n"); 
        printf("| OS INGRESSOS DO FILME CORRESPONDENTE NÃO ESTÃO CADASTRADOS |\n");
        printf("|          OBS.Para alterar um ingresso, é preciso           |\n");
        printf("|                que ele esteja cadastrado.                  |\n");
        printf("+------------------------------------------------------------+\n"); 
    }

    perguntaVoltarMenu();
}

void excluirIngressos(FILE *file){
    /*parametros: recebe um ponteiro para file
    recebe  um input com o nome do filme e busca o arquivo de ingresso correspondente para excluí-lo.
    Caso o arquivo seja encontrado ele é deletado, e caso não seja, o usuário é
    informado da inexistência de tal arquivo*/
    int a;
    char titulo[101];
    
    printf("\nDigite o nome do filme que deseja excluir os ingressos: ");
    setbuf(stdin,NULL);
    fgets(titulo,101,stdin); 

    titulo[strlen(titulo)-1] = '\0';
    strcat(titulo, ".txt");

    file = fopen(titulo,"r");
    if(file!=NULL){
        a = remove(titulo);//Deletando ingresso

        if(a == 0){
            printf("\nArquivo deletado com sucesso!\n");
        }else{
            printf("\nErro na exclusão do arquivo, tente novamente.\n");           
        } 

        fclose(file);

    }else{
        printf("\n+-----------------------------------------------------------+\n"); 
        printf("| OS INGRESSOS DO FILME CORRESPONDENTE NÃO ESTÃO CADASTRADOS |\n");
        printf("|          OBS.Para deletar um ingresso, é preciso           |\n");
        printf("|                que ele esteja cadastrado.                  |\n");
        printf("+------------------------------------------------------------+\n"); 
    }

    perguntaVoltarMenu();
}

void comprarIngresso(FILE *file,FILE *file2){

    char titulo[101];
    char frase[100],frase1[20],frase2[20];

    printf("\n+--------------------------------------------+\n");
    printf("|   Ola, seja bem vinde a area de comprar    |\n");
    printf("|    ingressos!! Para isso, você terá de     |\n");
    printf("|        1 - digitar o nome do filme         |\n");
    printf("|                     OU                     |\n");
    printf("|        2 - digitar exatamente: FILMES      |\n");
    printf("|     para ver os filmes em cartaz antes.    |\n");
    printf("+--------------------------------------------+\n");
    printf("\n\nEscolha:  ");
    setbuf(stdin,NULL);
    fgets(titulo,101,stdin); 
    titulo[strlen(titulo)-1] = '\0';


    if(strcmp(titulo,"FILMES")==0){ //Verificando se que ver os filmes em cartaz
        exibirFilmes(file);
    }else{
        char arq[strlen(titulo)];
        strcpy(arq,titulo);
        strcat(arq, ".txt");
        file2 = fopen(arq,"r");
        if(file2==NULL){
            printf("\n+--------------------------------------------+\n");
            printf("|           ARQUIVO NÃO ENCONTRADO           |\n");
            printf("|  Não há possibilidades de ingressos        |\n");
            printf("|  para esse filme tente voltar ao menu      |\n");
            printf("|  e selecionar a opcao: Cadastrar Ingressos |\n");
            printf("+--------------------------------------------+\n");
            setbuf(stdin,NULL);
        }else{
            int i = 0,numHor=0;
            char horario[10],nome[100],cpf[20];
            fgets(frase,100,file2);   
            fgets(frase1,20,file2);          
            frase[strlen(frase)-1] = '\0';

            printf("\nFilme encontrado!!\nLista de horários disponíveis para esse Filme:\n");

            printf("\n+--------------------------------------------+\n");
            printf("|    FILME: %-33s|\n",frase);
            printf("|                                            |\n");
            printf("|                  HORARIOS:                 |\n");
            printf("+--------------------------------------------+\n");
            while(fgets(frase2,100,file2)!=NULL){
                frase2[strlen(frase2)-1] = '\0';
                i++;
                printf("|                  %d - %-22s|\n",i,frase2);               
            }
            printf("+--------------------------------------------+\n");

            printf("\nQual dos horários acima você gostaria de comprar o ingresso??\n");
            printf("\nDigite o número correspondente a esse horario: ");
            setbuf(stdin,NULL);//limpa o buffer do teclado
            while(!scanf("%d", &numHor)){  //Evita que digitem letras  
                setbuf(stdin,NULL);//limpa o buffer do teclado
                printf ("\nNao aceitamos letras!!!\n\nDigite o número correspondente a esse horario:  ");
            }           
            rewind(file2);
            if(numHor>=1&&numHor<=i){
                char n1[100],duracao[100],classificacao[100],preco[20];

                fgets(n1,100,file2);
                fgets(preco,20,file2);

                preco[strlen(preco)-1] = '\0';

                for(int j = 0;j<numHor;j++){
                    fgets(horario,10,file2);  
                }
                printf("\nHorário escolhido: %s\n",horario);
                setbuf(stdin,NULL);//limpa o buffer do teclado
                printf("\nAgora, para concluir com a compra do ingresso digite o nome de quem está comprando o ingresso: ");
                fgets(nome,100,stdin); 
                printf("\nDigite o CPF de quem está comprando o ingresso: ");
                fgets(cpf,20,stdin); 
                nome[strlen(nome)-1] = '\0';
                cpf[strlen(cpf)-1] = '\0';
                horario[strlen(horario)-1] = '\0';
               
                file = fopen("BD.txt","r");
                while(fgets(n1,100,file)!=NULL){
                    fgets(duracao,100,file);
                    fgets(classificacao,100,file);
                    n1[strlen(n1)-1] = '\0';
                    if(strcmp(n1,titulo)==0){                        
                        duracao[strlen(duracao)-1] = '\0';
                        classificacao[strlen(classificacao)-1] = '\0';
                        break;
                    }else{         
                        i++;
                    }   
                }
                
                printf("\n\nCOMPRA FOI EFETUADA COM SUCESSO!\n\n");

                printf("\n+--------------------------------------------+\n");
                printf("|                  INGRESSO:                 |\n");
                printf("|--------------------------------------------|\n");
                printf("|--------------------------------------------|\n");
                printf("|                                            |\n");
                printf("|   Filme:  %-33s|\n",titulo);  
                printf("|   Duracao:  %-31s|\n",duracao);
                printf("|   Classificacao Etaria:  %-18s|\n",classificacao);
                printf("|                                            |\n");
                printf("|   Horario da Sessao:  %-21s|\n",horario);
                printf("|                                            |\n");
                printf("|--------------------------------------------|\n");
                printf("|                                            |\n");
                printf("|   Comprador:  %-29s|\n",nome);  
                printf("|   CPF:  %-35s|\n",cpf);
                printf("|                                            |\n");
                printf("|--------------------------------------------|\n");
                printf("|                                            |\n");
                printf("|          VALOR TOTAL:  R$%-18s|\n",preco);
                printf("|                                            |\n");
                printf("|--------------------------------------------|\n");
                printf("|                                            |\n");
                printf("|  OBS. Se dirija a bilheteria para efetuar  |\n");
                printf("|  pagamento e assim, finalizar a compra.    |\n");
                printf("|  Isso deve ser feito antes do inicio da    |\n");
                printf("|  sessao.                                   |\n");
                printf("|                                            |\n");
                printf("+--------------------------------------------+\n");

            }else{
                printf("\n\nAconteceu algum erro!! não foi possível compreeender o número do horário.\n\n");
            }            
            
            fclose(file2);        
        }
        perguntaVoltarMenu();
    }
}

void menu(){ 
    /*recebe um input do usurio com um numero que corresponde a uma 
    funcao a ser executada*/  
    int choice;
    FILE *file;
    FILE *file2;
    printf("+--------------------------------------------+\n");
    printf("|        Seja bem vinda(o) ao popFlix        |\n");
    printf("| Um sistema de venda de ingressos de cinema |\n");
    printf("+--------------------------------------------+\n");
    printf("|                                            |\n");
    printf("|          1. Filmes em exibição             |\n");
    printf("|          2. Buscar Filmes                  |\n");
    printf("|          3. Alterar dados de Filmes        |\n");
    printf("|          4. Cadastrar Filmes               |\n");
    printf("|          5. Excluir Filme                  |\n");
    printf("|          6. Cadastrar Ingressos            |\n");
    printf("|          7. Alterar Ingressos              |\n");
    printf("|          8. Excluir Ingressos              |\n");
    printf("|          9. Comprar Ingressos              |\n");
    printf("|          10. Sair                          |\n");
    printf("|                                            |\n");
    printf("+--------------------------------------------+\n");
    printf("\nInsira o número da sua opção: ");

    while(!scanf("%d", &choice)){  //Evita que digitem letras  
        setbuf(stdin,NULL);//limpa o buffer do teclado
        printf ("\nNao aceitamos letras!!!\n\nInsira o número da sua opção:  ");
    }

    switch(choice)
    {
        case 1 :
            exibirFilmes(file);
            break;
        case 2 :
            buscar(file);
            break;
        case 3 :
            alterarFilmes(file);
            break;
        case 4 :
            cadastrarFilmes(file);
            break;
        case 5 :
            excluirFilme(file,file2);
            break;
        case 6 :
            cadastrarIngressos(file,file2);
            break;
        case 7 :
            alterarIngressos(file2);
            break;
        case 8 :
            excluirIngressos(file);
            break;
        case 9 :
            comprarIngresso(file,file2);
            break;
        case 10 :
            printf("\nEncerrando...");
            break;
        default :
            printf("\n\nEntrada invalida, tente novamente.\n\n");
            menu();

    }
    printf("\n\n");
}
