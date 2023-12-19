#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct No{
	int info;
	struct No *prox;
} Lista;

// essa fun��o serve para verificar se o inicio da lista est� vazio ou n�o, sendo o inicio da lista o ponteiro P
bool isEmpty(Lista *p){
	if(p == NULL){
		return true;	
	} else {
		return false;
	}
}

// essa fun��o serve para inserir no fim da lista, passando elemento por elemento com um ponteiro auxiliar, sendo ele o AUX
Lista *inserirFim(Lista *p, int x){
	Lista *aux, *novo; // o *novo � o ponteiro que apontar� para o novo elemento da lista
	
	// alocando um endere�o na memoria para a lista ser executada
	Lista = (Lista*)malloc(sizeof(Lista));
	
	novo->info = x; // o ponteiro novo � atribuido a informa��o (no caso o elemento que ser� inserido) igual a x que ser� o valor do elemento
	novo->prox = NULL; // o ponteiro novo � atribuido ao ponteiro pr�ximo que est� como nulo
	
	if(p == NULL){
		p = novo; // se o inicio for nulo, ent�o o elemento a ser inserido ser� colocado no come�o da lista
	} else {
		aux = p; // senao o auxiliar vai come�ar a percorrer no inicio
		while(aux->prox != NULL){ // enquanto o auxiliar que est� atribuido ao proximo for diferente de nulo
			aux = aux-> prox; // o auxiliar continuar passando pela lista
		} 
		aux->prox = novo; // no fim do while insere o novo elementor
	}
	return p;
}