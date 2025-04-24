#include <stdio.h>
#include<stdlib.h>
int main(int qtd_param, char* param[]){

    if (qtd_param == 2){
        char* nome_arquivo = param[1];

        FILE* fp = fopen(nome_arquivo, "rt");//lê arquivo de texto "read text"
        
        if(!fp){
            printf("Erro ao abrir o arquivo: %s", nome_arquivo);
            exit(1);
        }
        int c=0;
        int numlinhas=0;
        while ((c=fgetc(fp))!= EOF)//lê caracter por caracter
        {
            if (c =='\n')//quebrou a linha
            {
                numlinhas++;//conta.
            }
            
        }
        printf("Ha %d linhas nesse arquivo!",numlinhas+1);//+1 pois há mais uma linha apos o ultimo \n.
        
        printf("\nArquivo abriu com sucesso!\n");

        fclose(fp);
    }
    return 0;
}
