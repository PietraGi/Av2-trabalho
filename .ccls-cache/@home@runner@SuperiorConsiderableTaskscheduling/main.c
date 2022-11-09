#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
  int info;
  struct NO *esquerda, *direita;

} node, *arvore;

arvore root = NULL;

arvore criar();
arvore pesquisar(arvore, int);
void inserir(arvore *, int);
void imprimir(arvore, int);
void excluir(node *);
void del(arvore *, arvore *);
void percorre_preordem(node *);
void percorre_posordem(node *);
void percorre_emordem(node *);
int main(void) {

  int x, y, opcao, op;
  bool existe = false;
  arvore arv;

  do {
    printf("\nEntre com a opcao:");
    printf("\n ---1:criar");
    printf("\n ---2:inserir");
    printf("\n ---3:imprimir altura");
    printf("\n ---4:excluir");
    printf("\n ---5:imprimir a arvore");
    printf("\n ---6:percorrer");
    printf("\n ---7:sair do programa\n");
    printf("\n-> ");
    fflush(stdin);
    scanf("%d", &opcao);
    switch (opcao) {
    case 1: /*criar */
    {
      if (existe) {
        printf("arvore já criada!");
      } else {
        arv = criar();
        existe = true;
      }

      break;
    }
    case 2: /*inserir*/
    {
      printf("\n Informe o valor ->");
      scanf("%d", &x);
      inserir(&root, x);
      imprimir(root, 0);
      break;
    }
    case 3: /*imprimir altura - fazer*/
    {
    }
    case 4: /*excluir*/
    {

      excluir(root);
      imprimir(root, 0);
      break;
    }
    case 5: /*imprimir*/
    {
      imprimir(root, 0);
      break;
    }
    case 6: /*percorrer*/
    {
      system("cls");

      printf("\n¨¨¨¨Selecione para percorrer em: ");
      printf("\n1-->Ordem ");
      printf("\n2-->Pre ordem");
      printf("\n3-->Pos ordem");
      printf("\n---->");
      scanf("%d", &op);
      switch (op) {
      case 1: {
        printf("\nPercorrendo em ordem ->");
        percorre_emordem(root);
        break;
      }
      case 2: {
        printf("\nPercorrendo em pre ordem ->");
        percorre_preordem(root);
        break;
      }
      case 3: {
        printf("\nPercorrendo em pos ordem ->");
        percorre_posordem(root);
        break;
      }
      }
    }
    }
  } while (opcao != 7);
}

/*criar arvore*/
arvore criar() {
  arvore A;
  printf("arvore criada!");
  return A;
}

/*inserir elemento na arvore*/
void inserir(arvore* p, int chave) {
  if (*p == NULL) {
    *p = (arvore)malloc(sizeof(node));
    (*p)->info = chave;
    (*p)->esquerda = NULL;
    (*p)->direita = NULL;
  } else if ((*p)->info < chave) {
    inserir(&((*p)->direita), chave);
  } else {
    inserir(&((*p)->esquerda), chave);
  }
  return;
}

/*imprimir arvore*/
void imprimir(arvore v, int nivel) {
  int i;
  if (v != NULL) {
    imprimir(v->esquerda, nivel + 1);
    for (i = 0; i < nivel; i++) {
      printf(" ");
    }
    printf("%d\n", v->info);
    imprimir(v->direita, nivel + 1);
  }
  return;
}

/* exclusão de elemento da árvore */
void excluir(node *p) {
  if (p==NULL)
    return;
  excluir(p->esquerda);
  excluir(p->direita);
  free(p);
  p = NULL;
  }

/* percorrer uma árvore utilizando o algoritmo de pré-ordem */
void percorre_preordem(node *arvore) {
  if (arvore == NULL) {
    return;
  }
  printf(" %d|", arvore->info);
  printf(" ");
  percorre_preordem(arvore->esquerda);
  percorre_preordem(arvore->direita);
  return;
}

/* percorrer uma árvore utilizando o algoritmo de pós-ordem */
void percorre_posordem(node *arvore) {
  if (arvore == NULL) {

    return;
  }
  percorre_posordem(arvore->esquerda);
  percorre_posordem(arvore->direita);
  printf(" %d|", arvore->info);
  printf(" ");
  return;
}

/* percorrer uma árvore utilizando no modo em-ordem */
void percorre_emordem(node *arvore) {
  if (arvore == NULL) {
    return;
  }
  percorre_emordem(arvore->esquerda);
  printf(" %d|", arvore->info);

  percorre_emordem(arvore->direita);
  return;
}
