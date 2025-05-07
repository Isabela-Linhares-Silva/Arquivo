#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Filmes "filmes.txt"
typedef struct filminhos
{
    char Titulo[91];
    char Diretor[61];
    char Ano [5];
    char Genero[101];
}Filminhos;

int main(){
    FILE* fp = fopen(Filmes, "rt");
    Filminhos registro[5];
    int qtd_linhas=0;
    char linhas[121];
    int campo_atual=0;
    int qtd_filme=0;
    if (!fp)
    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    while (fgets(linhas,121,fp) != NULL)
    {
        qtd_linhas++;
        if (campo_atual==0)
        {
            strcpy(registro[qtd_filme].Titulo,linhas);
        }
        else if(campo_atual==1){
            strcpy(registro[qtd_filme].Diretor,linhas);
        }
        else if(campo_atual==2){
            strcpy(registro[qtd_filme].Ano,linhas);
        }
        else if(campo_atual==3){
            strcpy(registro[qtd_filme].Genero,linhas);
            qtd_filme++;
        }

        campo_atual++;

        if (campo_atual==4)
        {
           campo_atual=0;
        }
        
        
    }

    for (int i = 0; i < qtd_filme; i++)
    {
        printf("===== FILME %d =====\n",i+1);
        printf("Titulo: %s",registro[i].Titulo);
        printf("Diretor: %s",registro[i].Diretor);
        printf("Ano: %s",registro[i].Ano);
        printf("Genero: %s",registro[i].Genero);
        printf("\n");
    }
    
    
    
    return 0;
}