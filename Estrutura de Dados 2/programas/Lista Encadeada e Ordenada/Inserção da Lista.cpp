#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct NO {
    int info;
    struct NO* prox;
} Lista;

bool isEmpty(Lista* p) {
    return p == NULL;
}

Lista* inserirLista(Lista* p, int x) {
    Lista* novo, * aux = NULL;

    novo = (Lista*)malloc(sizeof(Lista));

    novo->info = x;

    // Lista vazia ou insere no início
    if (p == NULL || p->info >= x) {
        novo->prox = p;
        p = novo;
    } else {
        // Inserção no meio ou no fim da lista
        aux = p;
        while((aux->prox != NULL) && ((p->prox)->info <= x)){
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    return p;
}

Lista *removeLista(Lista *p, int x){
	Lista *aux, *ant = NULL;
	
	if(p!= NULL){
		//remove do inicio
		if(p->info == x){
			aux = p;
			p = p->prox;
			free(aux);
		} else {
			// remove "inicio" ou fim
			aux = p;
			
			while((aux->prox != NULL) && ((aux->prox)->info < x)){
				aux = aux->prox;
			} 
			if(aux->prox != NULL && (aux->prox->info ==x)){
				ant = aux;
				aux = aux->prox;
				ant->prox = aux->prox;
				free(aux);
			}
		}
		return p;
	}		
}

void esvaziarLista(Lista* p) {
    while (p != NULL) {
        Lista* aux = p;
        p = p->prox;
        free(aux);
    }
}

void mostrarLista(Lista* p) {
    Lista* aux;

    if (isEmpty(p)) {
        printf("Lista Vazia!!\n");
    } else {
        aux = p;

        while (aux != NULL) {
            printf("%d -> ", aux->info);
            aux = aux->prox;
        }
    }
}

int main() {
    int op, info;

    Lista* p = NULL;

    do {
        printf("1 - Inserir Elemento Ordenadamente\n");
        printf("2 - Remover Elementos Ordenadamente\n");
        printf("3 - Esvaziar a Lista\n");
        printf("4 - Mostrar Lista Ordenada\n");
        printf("5 - Sair do Programa\n");
        printf("Sua Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Digite o Elemento que Deseja Inserir: ");
                scanf("%d", &info);
                p = inserirLista(p, info);
                printf("\n");
                break;
            case 2:
                printf("Qual elemento deseja retirar: ");
                scanf("%d", &info);
                p = removeLista(p, info);
                printf("\n");
                break;
            case 3:
                printf("Esvaziando Lista...\n");
                esvaziarLista(p);
                p = NULL;
                break;
            case 4:
                system("cls");
                printf("\n ------- Lista -------\n");
                mostrarLista(p);
                printf("\n ----------------------\n");
                getch();
                break;
            case 5:
                printf("Saindo do Programa!\n");
                esvaziarLista(p);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (op != 5);
    return 0;
}