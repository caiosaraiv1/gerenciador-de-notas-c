#include <stdio.h>
#include "notas.h"

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
