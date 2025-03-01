#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notas.h"

void criar_nota(Nota **notas, int *qtd)
{
      *notas = (Nota *)realloc(*notas, (*qtd + 1) * (sizeof(Nota)));
      if(*notas == NULL)
      {
            printf("Erro ao alocar memoria!\n");
            return;
      }

      (*notas)[*qtd].id = *qtd;
      char titulo_temp[30], conteudo_temp[250];

      printf("\nDigite o titulo da nota: ");
      fgets(titulo_temp, 30, stdin);
      titulo_temp[strcspn(titulo_temp, "\n")] = '\0';

      printf("Digite o conteudo da nota: ");
      fgets(conteudo_temp, 250, stdin);
      conteudo_temp[strcspn(conteudo_temp, "\n")] = '\0';

      (*notas)[*qtd].titulo = strdup(titulo_temp);
      (*notas)[*qtd].conteudo = strdup(conteudo_temp);

      (*qtd)++;
}

void editar_nota(Nota **notas, int qtd)
{
      if(qtd == 0)
      {
            printf("Erro: Nenhuma nota registrada!\n");
            return;
      }

      int id;
      printf("\nDigite o ID: ");
      scanf("%d", &id);
      getchar();

      if(id < 0)
      {
            printf("Erro: ID invalido!\n");
            return;
      }

      char conteudo_temp[250];

      printf("Digite o conteudo da nota: ");
      fgets(conteudo_temp, 250, stdin);
      conteudo_temp[strcspn(conteudo_temp, "\n")] = '\0';

      if((*notas)[id].conteudo != NULL)
      {
            free((*notas)[id].conteudo);
      }
      (*notas)[id].conteudo = strdup(conteudo_temp);
}

void buscar_nota(Nota *notas, int qtd)
{
      if(qtd == 0)
      {
            printf("Erro: Nenhuma nota registrada!\n");
            return;
      }

      int id;
      printf("\nDigite o ID: ");
      scanf("%d", &id);
      getchar();

      if(id < 0 || id >= qtd)
      {
            printf("Erro: ID invalido!\n");
            return;
      }

      printf("\nNota encontrada!\n");
      printf("-------------------\n");
      printf("ID: %d\n", notas[id].id);
      printf("Titulo: %s\n", notas[id].titulo);
      printf("Conteudo: %s\n", notas[id].conteudo);
      printf("-------------------\n");

}

void listar_notas(Nota *notas, int qtd)
{
      if(qtd == 0)
      {
            printf("Erro: Nenhuma nota registrada!\n");
            return;
      }

      printf("\nNotas encontradas!\n");
      printf("-------------------\n");
      for(int i = 0; i < qtd; i++)
      {
            printf("ID: %d\n", notas[i].id);
            printf("Titulo: %s\n", notas[i].titulo);
            printf("Conteudo: %s\n", notas[i].conteudo);
            printf("-------------------\n");
      }
}

void excluir_nota(Nota **notas, int *qtd)
{
      if(*qtd == 0)
      {
            printf("Erro: Nenhuma nota registrada!\n");
            return;
      }

      int id;
      printf("\nDigite o ID: ");
      scanf("%d", &id);
      getchar();

      if(id < 0)
      {
            printf("Erro: ID invalido!\n");
            return;
      }

      free((*notas)[id].titulo);
      free((*notas)[id].conteudo);

      for (int i = id; i < (*qtd - 1); i++)
      {
            (*notas)[i] = (*notas)[i + 1];
            (*notas)[i].id = i;
      }

      *notas = (Nota *)realloc(*notas, (*qtd - 1) * sizeof(Nota));
      (*qtd)--;
      printf("Nota excluida com sucesso!\n");
}

void liberar_memoria(Nota *notas, int qtd)
{
      for(int i = 0; i < qtd; i++)
      {
            free(notas[i].titulo);
            free(notas[i].conteudo);
      }
      free(notas);
}
