#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

void menu(){
  printf ("========== MENU ==========\n");
  printf ("1 - Adicionar\n");
  printf ("2 - Consultar Ordem\n");
  printf ("3 - Consultar Proxima Entrega\n");
  printf ("4 - Remover\n");
  printf ("\n");
  printf ("8 - Destruir\n");
  printf ("0 - Sair\n");
  printf ("Informe a opcao desejada: ");
}

main() {
  node *tmp;
  fila *FILA;
  FILA = create();

  int k = -1;
  int op = -1;

  do {
    system("cls || clear");
    menu();
    scanf("%d",&op);

    switch (op) {
      case 1:
        tmp = insertNode(FILA);
        printf("Adicionado: %s %d", tmp->dado.nome, tmp->dado.numero);
        break;
      case 2:
        listar(FILA);
        break;
      case 3:
        first(FILA);
        break;
      case 4:
        tmp = remover(FILA);
        if(tmp != NULL){
            printf("Removido para entrega: %s %d\n\n", tmp->dado.nome, tmp->dado.numero);
        }
        break;
      case 8:
        destroy(FILA);
        FILA = create();
        break;
    }
    //Sequencia de comandos equivalentes ao system("pause");
    getchar();
    scanf("c\n");
  } while (op != 0);
}

