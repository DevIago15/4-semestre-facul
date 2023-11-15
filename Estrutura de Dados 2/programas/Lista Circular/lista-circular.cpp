#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO{
	int info;
	struct NO *prox;
} ListaC;

ListaC *insereInicioLC(ListaC *p, int x){
	ListaC *aux, *novo;
	novo = (ListaC *) malloc(sizeof(ListaC));
	novo->info = x;
	
	// se lista vazia
	if(p == NULL) {
		novo->prox = novo;
	} else {
		aux = p;
		while(aux->prox != p){
			aux = aux -> prox;
		}
		novo -> prox = p;
		aux -> prox = novo;
	}
	return novo;
}

ListaC *insereFimLC(ListaC *p, int x){
	ListaC *aux, *novo;
	novo = (ListaC *) malloc(sizeof(ListaC));
	novo->info = x;
	
	if(p == NULL) {
		novo->prox = novo;
		p = novo;
	} else {
		aux = p;
		while(aux->prox != p){
			aux = aux -> prox;
		}
		novo -> prox = p;
		aux -> prox = novo;
	}
	return p;
}

ListaC *removeLC(ListaC *p, int x)
{
	ListaC *ant, *aux;
	if( p!= NULL)
	{
		aux = p;
		if (p->info == x)
		{
			while (aux->prox != p)
			{
				aux = aux->prox;
				aux->prox = p->prox;
				ant = p;
				p = p->prox;
				free(ant);	
			}
		} else {
			while(aux->prox != p && aux->info !=x)
			{
				ant = aux;
				aux = aux -> prox;
			}
			ant -> prox = aux->prox;
			free(aux);
		}
	}
	return p;
}

void mostrarListaLC(ListaC *p){
	ListaC *aux;
	if(p == NULL){
		printf("\n Lista Vazia!!");
	} else{
		aux = p;
		printf("p-> ");
		while(aux->prox != p){
			printf("%5d->", aux->info);
			aux = aux->prox;
		}
		printf("%5d-|\n\n", aux->info);
	}
}

int main(){
	ListaC *p = NULL;
	int x, op;
	do{
		printf("\n1 - Insere Inicio");
		printf("\n2 - Insere Antes de X");
		printf("\n3 - Insere Depois de X");
		printf("\n4 - Insere no Fim");
		printf("\n5 - Mostrar Lista");
		printf("\n6 - Sair do Programa");
		printf("\nDigite sua Opcao: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("\nDigite o Valor para Inserir: ");
				scanf("%d", &x);
				p = insereInicioLC(p, x);
				break;
			case 4:
				printf("\nDigite o Valor para Inserir: ");
				scanf("%d", &x);
				p = insereFimLC(p, x);
				break;
			case 5:
				mostrarListaLC(p);
				break;
			case 6:
				printf("\nSaindo do Programa..");
				break;
			default:
				printf("ERRO: Opcao nao Encontrada!\n Sugerimos você tentar novamente...");
				break;
		} 
	}while(op!=6);
	return 0;
}