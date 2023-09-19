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

// função para inserir o nó no inicio da lista
Lista * insereInicio(Lista *p, int x){
	Lista *novo;
	
	// alocar memoria para o novo nó
	novo = (Lista *) malloc(sizeof(Lista));
	
	// armazenar a info no novo nó (novo que aponta para info recebe x)
	
	novo->info = x;
	
	// conectar o novo nó na lista
	novo->prox = p; //(p é o inicio da lista)
	
	// apontar o ponteiro p para o novo elemento jogando o elemento para o o inicio da lista
	p->novo;
	return p;
}

// função para mostrar cada um dos elementos (nós) da lista
void mostrarLista(Lista *p) { 
	
	//	(ponteiro auxiliar para percorrer a lista)
	Lista *aux;  
	
	// testar se está vazio ou com elementos
	bool vazio; 
	vazio = isEmpty(p);
	
	if(vazio == NULL){
		printf("Lista Vazia!!\n");
	} else{
		aux = p;
		// o loop só para quando aux é null, ou seja quando chega no fim da lista
		while(aux != null){
			// (vai mostrar o valor que esta armazenado na info)
			printf("%d -> ", aux->info); 
			//(pra apontar para o proximo elemento da lista)
			aux = aux->prox; 
		}
	}
}

int main(){
	int op = 0, info;
	
	// p é o ponteiro que aponta para o inicio da lista
	Lista *p = NULL; //iniciando a lista vazia (SEMPRE INICIAR VAZIA)
	
	do{
		printf("1 - Inserir no Inicio da Lista\n");
		printf("2 - Mostrar os Elementos da Lista\n");
		printf("3 - Fim do Programa\n");
		printf("Escolha sua Opção: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("\nDigite um Novo Elemento da Lista: ");
				scanf("%d" &info);
				p = insereInicio(p, info); // (recebendo no inicio e enviando para a função)
				break;
			case 2:
				system("cls"); // limpando a tela
				printf("\n ------- Lista -------");
				mostrarLista(p);
				printf("\n ---------------------- ");
				getch();
				break;
			case 3:
				printf("\n Saindo do Programa...");
				break;
			default:
				printf("\n Opção Inválida!! Tente Novamente");
				break;
		}
	} while(op != 3);
	return 0;
}
