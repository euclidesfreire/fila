
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//CRIAR FILA
fila *create(){
    fila *FILA = (fila *) malloc(sizeof(fila));

    if(!FILA) {
        printf("Sem memoria disponivel\n");
        exit(1);
    } else{
        //INICIALIZA A FILA
        FILA->prox = NULL;
        FILA->sizeF = 0;

        return FILA;
    }

}

//VERIFICA SE A FILA ESTA VAZIA
int qEmpty(fila *f){

    if(f->prox == NULL)
        return 1;
    else
        return 0;
}

//ALOCA MEMORIA PARA OS NODE DA FILA
node *alocar(fila *f){

    node *novo = (node *) malloc(sizeof(node));

    if(!novo) {
        printf("Sem memoria disponivel\n");
        exit(1);
    } else{
        //ATRIBUINDO OS DADOS DA STRUCT DO NODE
        f->sizeF++;
        novo->prox = NULL;
        novo->dado.nome = "Pacote";
        novo->dado.numero = f->sizeF;

        return novo;
    }

}

//INSERIR UM NOVO NODE
node *insertNode(fila *f) {
    node *novo = alocar(f);

    //VERIFICAR SE A FILA ESTA VAZIA
    if(qEmpty(f)){
        f->prox = novo;
    } else {
        //CRIAR UMA VARIALVEL TEMPORARIA DO TIPO NODE E PEGA O PRIMEIRO NODE QUE A FILA APONTA
        node *tmp = f->prox;
        //PROCURA O FINAL DA FILA
        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }

    return novo;
}

//REMOVER NODE
node *remover(fila *f){

     if(qEmpty(f)){
        printf("Fila já esta vazia!\n");
        return NULL;
    } else {
        //CRIAR UMA VARIALVEL TEMPORARIA DO TIPO NODE E PEGA O PRIMEIRO NODE QUE A FILA APONTA
        node *tmp = f->prox;
        //FAZ A FILA APONTAR PARA O PROXIMO DEPOIS DO PRIMEIRO NODE
        f->prox = tmp->prox;

        return tmp;
    }
}

//PEGAR O PRIMEIRO NODE QUE A FILA APONTA
void first(fila *f){
  //O ponteiro p serve para fazer o deslocamento entre os elementos.
  node *tmp = f;

  if (qEmpty(tmp)) {
    printf("A FILA esta vazia!\n");
    return;
  } else {
    //PEGA O PRIMEIRO NODE QUE A FILA APONTA
    tmp = f->prox;
    printf("\n------------------- FILA --------------------\n");
    printf("O proximo pacote a ser entregue = %s %d\n", tmp->dado.nome, tmp->dado.numero);
  }
  printf("---------------------------------------------\n");

}

//
void destroy(fila *f){
  if (qEmpty(f)) {
    printf("A FILA esta vazia!\n");
    return;
  } else {
      //CRIAR UMA VARIALVEL TEMPORARIA DO TIPO NODE E PEGA O PRIMEIRO NODE QUE A FILA APONTA
      node *tmp = f->prox;
      //PROXIMO NODE EM REFERENCIA tmp
      node *proxNode;
      while(tmp->prox != NULL){
        //PEGA O PROXIMO NODE
        proxNode = tmp->prox;
        free(tmp);
        //COLOCA O PROXIMO NODE EM tmp
        tmp = proxNode;
      }

  }
}

void listar(fila *f){
 //A variável i serve apenas para apresentar a ordem dos elemento impressos
  int i = 0;
  //O ponteiro p serve para fazer o deslocamento entre os elementos.
  node *tmp = f;

  if (qEmpty(tmp)) {
    printf("A FILA esta vazia!\n");
    return;
  } else {

    tmp = f->prox;

    printf("\n------ FILA ------\n");

    while (!qEmpty(tmp)){
        i++;
        printf("#Fila[%d] = %s %d\n", i, tmp->dado.nome, tmp->dado.numero);
        //RETORNAR SE CHEGAR NO FNAL DA FILA
        if(tmp->prox == NULL)
            return;

        tmp = tmp->prox;
    }
  }
  printf("-------------------\n");
}
