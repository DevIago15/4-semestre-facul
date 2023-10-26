// IAGO LUCAS VERA FREITAS - 20222345

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct No{
	int info;
	struct No *prox;
}Lista;

bool isEmpty(Lista *p){
	if( p == NULL){
		return true;
	} else
	{
		return false;
	}
}

Lista *insereFim(Lista *p, int x) {
    Lista *aux, *novo;
    
    novo = (Lista*)malloc(sizeof(Lista));
    
    novo->info = x;
    novo->prox = NULL;
    
    if (p == NULL) {
        p = novo;
    } else {
        aux = p;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return p;
}

Lista * unirListas(Lista *p1, Lista *p2) {
    Lista *p3 = NULL;
    Lista *aux1 = p1;
    Lista *aux2 = p2;
    
    while (aux1 != NULL) {
        p3 = insereFim(p3, aux1->info);
        aux1 = aux1->prox;
    }
    
    while (aux2 != NULL) {
        p3 = insereFim(p3, aux2->info);
        aux2 = aux2->prox;
    }
    
    return p3;
}

void mostrarLista(Lista *p) {
    Lista *aux;
    
    if (p == NULL) {
        printf("\nLista Vazia!");
    } else {
        aux = p;
        while (aux != NULL) {
            printf("%d -> ", aux->info);
            aux = aux->prox; 
        }
    }
}

Lista * removeInicio(Lista *p){
	Lista *aux;
	aux = p;
	
	if(isEmpty(p) == false){
		p = p->prox;
		free(aux);
	}
	return p;
}

Lista * esvaziarLista(Lista *p){
	while(p != NULL){
		p = removeInicio(p);
	}
	return p;
}

int main(){
	int op = 0, x;
	
	Lista *p1 = NULL;
	Lista *p2 = NULL;
	Lista *p3 = NULL;
	Lista *p;
	
	do{
		printf("\n1 - Inserir Elementos\n");
		printf("2 - Mostrar Lista 1\n");
		printf("3 - Mostrar Lista 2\n");
		printf("4 - Mostrar Nova Lista 3\n");
		printf("5 - Esvaziar Listas\n");
		printf("6 - Fim do Programa\n");
		printf("Escolha sua Opcao: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("\nDeseja Inserir o Elemento em Qual Lista? (1/2)");
			  	printf("\nOpcao: ");
				scanf("%d", &op);
				
				if(op == 1){
					printf("\nDigite um Novo Elemento da Lista: ");
				   	scanf("%d", &x);
					p1 = insereFim(p1, x);
				} else{
					printf("\nDigite um Novo Elemento da Lista: ");
				   	scanf("%d", &x);
					p2 = insereFim(p2, x);
				}				
				break;
			case 2:
				system("cls"); // limpando a tela
				printf("\n ------- Lista 1 -------\n");
				mostrarLista(p1);
				printf("\n ----------------------\n");
				getch();
				break;
			case 3:
				system("cls"); // limpando a tela
				printf("\n ------- Lista 2 -------\n");
				mostrarLista(p2);
				printf("\n ----------------------\n");
				getch();
				break;
			case 4:
	    		p3 = unirListas(p1, p2);
				system("cls"); // limpando a tela
				printf("\n ------- Lista 3 -------\n");
				mostrarLista(p3);
				printf("\n ----------------------\n");
				getch();
				break;
			case 5:
				p1 = esvaziarLista(p1);
				p2 = esvaziarLista(p2);
				p3 = esvaziarLista(p3);
				system("cls");
				break;
			case 6:
				printf("\nSaindo do Programa...\n");
				break;
			default:
				printf("\nOpcao Invalida!! Tente Novamente\n");
				break;
		}
	} while(op != 6);
	return 0;
}