#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int qtd_param, char* param[]){

    if (qtd_param == 2){// verifica se foi passado outro argumento fora o programa que esta rodando
        char* nome_arquivo = param[1];// pega o segundo aquivo = arquivo.txt

        FILE* fp = fopen(nome_arquivo, "rt");//lê arquivo de texto "read text"
        
        if(!fp){//se nao conseguir abrir o arquivo
            printf("Erro ao abrir o arquivo: %s", nome_arquivo);
            exit(1);
        }

        //abre um arquivo de saída onde sera escrito o conteudo invertido para maiúscula
        FILE* saida = fopen("saida.txt", "wt");
        if(!saida){
            printf("Erro ao abrir o arquivo: %s", saida);
            exit(1);
        }




        int c=0;// armazenara cada caracter lido
        int numlinhas=0; 
        while ((c=fgetc(fp))!= EOF)//lê caracter por caracter do arquivo até chegar no fim
        {
            if (c =='\n')//quebrou a linha
            {
                numlinhas++;//conta.
            }
            fputc(toupper(c),saida);// escreve o caracter no novo arquivo em maiusculo

            
        }
        printf("Ha %d linhas nesse arquivo!",numlinhas+1);//+1 pois há mais uma linha apos o ultimo \n.
        
        printf("\nArquivo abriu com sucesso!\n");

        fclose(fp);//fecha o arquivo original
        fclose(saida);// fecha a saída (boa prática)
    }
    return 0;
}
