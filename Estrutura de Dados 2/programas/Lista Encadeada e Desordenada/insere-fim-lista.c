#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
	int info;
	struct NO *prox;
} Lista;

// insere no fim da lista
Lista * insereFim(Lista *p, int x){
	Lista *aux, *novo;
	novo = (Lista*) malloc(sizeof(Lista));
	novo -> info = x;
	novo -> prox = NULL;
	
	// verifica se a lista esta vazia
	if(p == NULL){
		printf("\nLista Vazia!");
		p = novo;
	} else {
		aux = p;
		
		// loop usando while porque não sabemos quando irá acabar
		while(aux -> prox != NULL){
			aux = aux -> prox;
			printf("Elementos da Lista: %d", &novo);
		}
			aux -> prox = novo;
	}
	return p;	
}

// mostra a lista
void mostraLista(Lista *p){
	Lista *aux;
	
	// verifica se a lista esta vazia
	if(p == NULL){
		printf("\nLista Vazia!");
	} else {
		aux = p;
		
		// imprime os elementos da lista
		while(aux != NULL){
			printf("Elementos da Lista: %d", aux->info);
			aux = aux -> prox; 
		}
	}
	return p;
}

// localiza elemento na lista
Lista * localizarElemento(Lista *p, int x){
	Lista *aux;
	aux = p;
	while (aux != NULL && aux -> info !=x){
		aux = aux -> prox;
	}
	return aux;
}

// insere o elemento em qualquer lugar da lista
void insereElemento(Lista *e, int y){
	Lista *novo;
	
	novo = (Lista*) malloc(sizeof(Lista));
		
	novo -> info = y;
	novo -> prox = e -> prox;
	e -> prox = novo;
}

main(){
	Lista L; // declara a lista
	int x; // declara uma variavel onde irá ser inserido o valor no fim
	
	insereFim(&L, x);
	mostraLista(&L);
	
	return 0;
}