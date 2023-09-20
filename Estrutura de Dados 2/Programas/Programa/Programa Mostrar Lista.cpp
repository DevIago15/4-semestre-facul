// inclusao das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// definir a estrutura do nó da lista (encadeada dinamica simples)
typedef struct No{
	int info;
	struct No *prox;
} Lista; // lista é o tipo da estrutura do nó (toda vez que declararmos o tipo lista, ele segue com a estrutura definida)

// função para verificar se a lista está vazia ou não (p é o ponteiro que aponta para a lista)

bool isEmpty(Lista *p){
	
	if(p == NULL){
		// lista vazia
		return true;
	} else{
		//lista com elementos
		return false;
	}
}

// função para inserir um novo elemento no inicio da lista
Lista * insereInicio(Lista *p, int x){
	Lista *novo;
	
	// alocar memoria para o novo nó
	novo = (Lista *) malloc(sizeof(Lista));
	
	// armazenar a info no novo nó (novo que aponta para info recebe x)
	
	novo->info = x;
	
	// conectar o novo nó na lista
	novo->prox = p; //(p é o inicio da lista)
	
	// apontar o ponteiro p para o novo elemento jogando o elemento para o o inicio da lista
	p = novo;
	return p;
}

// função para inserir um novo elemento no final da lista
Lista * insereFinal(Lista *p, int x){
	
	// declarar dois ponteiros para a lista
	// o ponteiro novo aponta para o novo elemento da lista
	// o ponteiro aux percorre a lista para encontrar seu fim
	Lista *novo, *aux;
	
	//alocar memoria para o ponteiro novo
	novo = (Lista *) malloc(sizeof(Lista));
	
	// armazenar a informação no novo nó da lista
	novo->info = x;
	
	// o ponteiro prox do nó novo apontar para null (será o ultimo elemento da lista)
	novo->prox = NULL;
	
	// considerar lista vazia
	if(isEmpty(p)){
		p = novo;
	} else{
		aux = p;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
	}
	return p;	
}
// função para mostrar cada um dos elementos (nós) da lista
void mostrarLista(Lista *p) { 
	
	//	(ponteiro auxiliar para percorrer a lista)
	Lista *aux;  
	
	if(isEmpty(p)){
		printf("Lista Vazia!!\n");
	} else{
		aux = p;
		// o loop só para quando aux é null, ou seja quando chega no fim da lista
		while(aux != NULL){
			// (vai mostrar o valor que esta armazenado na info)
			printf("%d -> ", aux->info); 
			//(pra apontar para o proximo elemento da lista)
			aux = aux->prox; 
		}
	}
}

// funcao pra localizar um elemento da lista
// caso o elemento pertença a lista, será retornado seu endereco
// caso contrario retornara NULL
Lista * buscaElemento(Lista *p, int x){
	// declarar o ponteiro aux pra percorrer a lista, caso ela tenha elementos
	Lista *aux;
	aux = p; // p é o inicio da lista
	
	while(aux != NULL && aux->info != x){
		aux = aux->prox;
	}
	
	// aux aponta para null significa lista vazia ou o
	// elemento nao pertence a lista
	//aux aponta para o elemento significa que o elemento
	// pertence a lista. portanto, aux retorna null ou o end do elemento
	return aux;
}

int main(){
	int op = 0, info;
	
	// p é o ponteiro que aponta para o inicio da lista
	Lista *p = NULL; //iniciando a lista vazia (SEMPRE INICIAR VAZIA)
	
	do{
		printf("\n1 - Inserir no Inicio da Lista\n");
		printf("2 - Inserir no Fim da Lista\n");
		printf("3 - Mostrar os Elementos da Lista\n");
		printf("4 - Buscar Elemento da Lista\n");
		printf("5 - Fim do Programa\n");
		printf("Escolha sua Opcao: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("\nDigite um Novo Elemento da Lista: ");
				scanf("%d", &info);
				p = insereInicio(p, info); // (recebendo no inicio e enviando para a função)
				break;
			case 2:
				printf("\nDigite um Novo Elemento da Lista: ");
				scanf("%d", &info);
				p = insereFinal(p, info);
				break;
			case 3:
				system("cls"); // limpando a tela
				printf("\n ------- Lista -------\n");
				mostrarLista(p);
				printf("\n ----------------------\n");
				getch();
				break;
			case 4:
				printf("\nDigite o Elemento que Deseja Buscar: ");
				scanf("%d", &info);
				break;
			case 5:
				printf("\nSaindo do Programa...\n");
				break;
			default:
				printf("\nOpcao Invalida!! Tente Novamente\n");
				break;
		}
	} while(op != 5);
	return 0;
}
