#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
      int id;
      char *titulo;
      char *conteudo;
} Nota;

void criar_nota(Nota **notas, int *qtd);
void editar_nota(Nota **notas, int qtd);
void buscar_nota(Nota *notas, int qtd);
void listar_notas(Nota *notas, int qtd);
void excluir_nota(Nota **notas, int *qtd);
void liberar_memoria(Nota *notas, int qtd);

int main()
{
      Nota *notas = NULL;
      int opcao, qtd = 0;

      do
      {
            printf("\nMenu:\n");
            printf("1 - Criar nota\n");
            printf("2 - Editar nota\n");
            printf("3 - Buscar nota\n");
            printf("4 - Listar notas\n");
            printf("5 - Excluir nota\n");
            printf("0 - Sair\n");
            printf("\nEscolha uma opcao: ");
            scanf("%d", &opcao);
            getchar();

            switch(opcao)
            {
                  case 1: criar_nota(&notas, &qtd); break;
                  case 2: editar_nota(&notas, qtd); break;
                  case 3: buscar_nota(notas, qtd); break;
                  case 4: listar_notas(notas, qtd); break;
                  case 5: excluir_nota(&notas, &qtd); break;
                  case 0: printf("Saindo...!\n"); liberar_memoria(notas, qtd); break;
                  default: printf("Opcao invalida!\n");
            }
      } while(opcao != 0);

      return 0;
}

void criar_nota(Nota **notas, int *qtd)
{
      *notas = (Nota *)realloc(*notas, (*qtd + 1) * (sizeof(Nota)));
      if(*notas == NULL)
      {
            fprintf(stderr, "Erro ao alocar memoria!\n");
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
            fprintf(stderr, "Erro: Nenhuma nota registrada!\n");
            return;
      }

      int id;
      printf("\nDigite o ID: ");
      scanf("%d", &id);
      getchar();

      if(id < 0)
      {
            fprintf(stderr, "Erro: ID invalido!\n");
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
            fprintf(stderr, "Erro: Nenhuma nota registrada!\n");
            return;
      }

      int id;
      printf("\nDigite o ID: ");
      scanf("%d", &id);
      getchar();

      if(id < 0)
      {
            fprintf(stderr, "Erro: ID invalido!\n");
            return;
      }

      for(int i = 0; i < qtd; i++)
      {
            if(notas[i].id == id)
            {
                  printf("\nNota encontrada!\n");
                  printf("-------------------\n");
                  printf("ID: %d\n", notas[i].id);
                  printf("Titulo: %s\n", notas[i].titulo);
                  printf("Conteudo: %s\n", notas[i].conteudo);
                  printf("-------------------\n");
                  return;
            }
      }
     fprintf(stderr, "Nota nao encontrada!\n");
}

void listar_notas(Nota *notas, int qtd)
{
      if(qtd == 0)
      {
            fprintf(stderr, "Erro: Nenhuma nota registrada!\n");
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
      return;
}

void excluir_nota(Nota **notas, int *qtd)
{
      if(*qtd == 0)
      {
            fprintf(stderr, "Erro: Nenhuma nota registrada!\n");
            return;
      }

      int id;
      printf("\nDigite o ID: ");
      scanf("%d", &id);
      getchar();

      if(id < 0)
      {
            fprintf(stderr, "Erro: ID invalido!\n");
            return;
      }

      free((*notas)[id].titulo);
      free((*notas)[id].conteudo);

      for (int i = id; i < (*qtd - 1); i++)
      {
            (*notas)[i] = (*notas)[i + 1];
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
