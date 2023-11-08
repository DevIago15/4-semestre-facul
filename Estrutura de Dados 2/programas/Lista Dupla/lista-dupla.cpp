#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int info;
	struct no *ant, *prox;
}ListaDupla;

ListaDupla * insereInicio (ListaDupla *p, int x){
	novo = (ListaDupla) malloc (sizeof(ListaDupla));
	novo -> info = x;
	
	if(p == NULL){
		novo->prox = NULL;
		novo->Ant = NULL;
		p = novo;
	} else {
		aux = p;
		while(aux->prox != NULL && aux->info < x){
			aux = aux->prox;
		} if(aux->ant == NULL){
			novo->prox = aux;
			novo->ant = NULL;
			aux->ant = novo;
			p = novo;
		} else {
			if(aux->info > x){
				novo->prox = aux;
				novo->ant = aux->ant;
				(aux->ant)->prox = novo;
				aux->ant = novo;
			} else {
				novo->prox = aux->prox;
				novo->ant = aux;
				aux->prox = novo;
			}
		}
		return p;
	}
}

ListaDupla * remove(ListaDupla *p, int x){
	ListaDupla *pe, *pd, *aux;
	if(p!= NULL){
		aux=p;
		while(aux!=NULL && aux->info < x){
			aux=aux->prox;
		} if(aux!= NULL && aux->info == x){
			pe=aux->ant;
			pd=aux->prox;
			if(pe == NULL){
				p=p->prox;
				p->ant=NULL;
			} else {
				pe->prox = pd;
				if(pd != NULL){
					pd->ant=pe;
				}
				free(aux);
			} else{
				printf("Elemento Não Pertence a Lista!\n");
			}
		}
	}
}