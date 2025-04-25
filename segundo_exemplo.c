#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARQUIVO_ENTRADA "arquivo.txt"

typedef struct pessoa
{
    char nome[121];
    char idade[10];
    char profissao[51];
}Pessoa;

 
int main(){
    FILE* arquivo_entrada = fopen(ARQUIVO_ENTRADA,"rt"); 
    char linha[121];//buffer do programa
    int qtd_linha=0;
    int i=0;
    int qtd_arq=0;


    Pessoa registro[5];

    if (!arquivo_entrada)
    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    printf("Arquivo abriu com sucesso!\n");

    while (fgets(linha,121,arquivo_entrada)!= NULL)
    {
        qtd_linha++;
        switch (i%3)
        {
        case 0:
            strcpy(registro[qtd_arq].nome,linha);//utiliza-se "." pois não é ponteiro, esta mechendo diretamente nele.
            break;
        case 1:
            strcpy(registro[qtd_arq].idade,linha);//utiliza-se "." pois não é ponteiro, esta mechendo diretamente nele.
            break;
        case 2:
            strcpy(registro[qtd_arq].profissao,linha);//utiliza-se "." pois não é ponteiro, esta mechendo diretamente nele.
            qtd_arq++;
            break;
        
        
        }
        i++;
    }
    for ( i = 0; i < qtd_arq; i++)
    {
        printf("===========Registro %d===========\n",i);
        printf("Nome: %s\n",registro[i].nome);
        printf("Idade: %s\n",registro[i].idade);
        printf("Profissao: %s\n",registro[i].profissao);
    }
    
    
    fclose(arquivo_entrada);
    return 0;
}