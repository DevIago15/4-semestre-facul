#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct No{
	int info;
	struct No *prox;
} Lista;

// essa função serve para verificar se o inicio da lista está vazio ou não, sendo o inicio da lista o ponteiro P
bool isEmpty(Lista *p){
	if(p == NULL){
		return true;	
	} else {
		return false;
	}
}

// essa função serve para inserir no fim da lista, passando elemento por elemento com um ponteiro auxiliar, sendo ele o AUX
Lista *inserirFim(Lista *p, int x){
	Lista *aux, *novo; // o *novo é o ponteiro que apontará para o novo elemento da lista
	
	// alocando um endereço na memoria para a lista ser executada
	Lista = (Lista*)malloc(sizeof(Lista));
	
	novo->info = x; // o ponteiro novo é atribuido a informação (no caso o elemento que será inserido) igual a x que será o valor do elemento
	novo->prox = NULL; // o ponteiro novo é atribuido ao ponteiro próximo que está como nulo
	
	if(p == NULL){
		p = novo; // se o inicio for nulo, então o elemento a ser inserido será colocado no começo da lista
	} else {
		aux = p; // senao o auxiliar vai começar a percorrer no inicio
		while(aux->prox != NULL){ // enquanto o auxiliar que está atribuido ao proximo for diferente de nulo
			aux = aux-> prox; // o auxiliar continuar passando pela lista
		} 
		aux->prox = novo; // no fim do while insere o novo elementor
	}
	return p;
}