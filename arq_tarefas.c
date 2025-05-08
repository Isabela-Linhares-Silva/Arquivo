#include<stdio.h>
#include<stdlib.h>
#define TAREFAS "tarefa.txt"

int main(){
    FILE * t = fopen(TAREFAS,"rt");
    int maior_id=0;
    int* vetor= (int*)malloc(sizeof(int));
    if (!t)
    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
    int c=0;
    int n_linhas=0;
    while ((c = fgetc(t) )!= EOF)
    {
        if (c == '\n')
        {
           n_linhas++;
        }
        if (c>maior_id)
        {
            maior_id = c;
        }
          
    }
    
    return 0;
}