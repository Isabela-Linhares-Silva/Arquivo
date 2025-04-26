#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(int qtd_param,char* param[]){
    if (qtd_param == 2)
    {
        FILE * recebe = fopen("arq.txt","rt");
        if (recebe == NULL)
        {
            printf ("Erro ao abrir o arquivo: %s","arq.txt");
            exit(1);
        }

        FILE * saida = fopen("saideira.txt","wt");
        if (saida == NULL)
        {
            printf ("Erro ao abrir o arquivo: %s","arq.txt");
            exit(1);
        }

        int c=0;
        int num_linhas =0;
        while ((c=fgetc(recebe)) != EOF)
        {
           if (c == '\n')
           {
                num_linhas++;
           }
           fputc(toupper(c),saida);
           
        }
        printf("O arquivo tem %d linhas.\n", num_linhas+1);
        

        printf("Abriu com sucesso!");
    }
    
    
    
    return 0;
}