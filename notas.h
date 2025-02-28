#ifndef NOTAS_H
#define NOTAS_H

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

#endif
