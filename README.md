# Gerenciador de Notas em C

Este projeto é um gerenciador de notas simples desenvolvido em C, permitindo criar, editar, buscar, listar e excluir notas de forma dinâmica. Ele utiliza alocação dinâmica de memória para gerenciar as notas eficientemente.

## Funcionalidades
- Criar uma nova nota
- Editar uma nota existente
- Buscar uma nota pelo ID
- Listar todas as notas registradas
- Excluir uma nota
- Liberação da memória utilizada

## Estrutura do Código
O código está dividido em três arquivos principais:

- **`main.c`**: Contém a função principal, que implementa o menu de opções e a lógica para chamar as funções correspondentes.
- **`notas.h`**: Cabeçalho contendo as declarações das funções e da estrutura `Nota`.
- **`notas.c`**: Implementações das funções para gerenciar as notas, como criar, editar, excluir, buscar e listar.

### Estrutura de Dados
- **`Nota`**: Estrutura que representa uma nota, contendo um ID, título e conteúdo.

### Funções
- **`criar_nota`**: Função para criar e armazenar uma nova nota.
- **`editar_nota`**: Permite editar o conteúdo de uma nota existente.
- **`buscar_nota`**: Busca uma nota pelo ID e exibe seus detalhes.
- **`listar_notas`**: Lista todas as notas registradas.
- **`excluir_nota`**: Remove uma nota da lista e reorganiza os elementos restantes.
- **`liberar_memoria`**: Libera a memória alocada dinamicamente antes do encerramento do programa.

## Compilação e Execução

Para compilar o programa, utilize o `gcc`:

```sh
gcc -o main main.c notas.c
```

Para executar o programa:

```sh
./main
```

## Uso
Ao executar o programa, será exibido um menu com as seguintes opções:

```
Menu:
1 - Criar nota
2 - Editar nota
3 - Buscar nota
4 - Listar notas
5 - Excluir nota
0 - Sair
```

Digite a opção desejada e siga as instruções fornecidas pelo programa.

## Requisitos
- Compilador GCC
- Sistema operacional compatível com C (Windows, Linux, macOS)
