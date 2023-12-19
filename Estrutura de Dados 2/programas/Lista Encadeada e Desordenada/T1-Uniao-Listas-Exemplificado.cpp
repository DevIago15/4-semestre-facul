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

// essa função serve para unir as duas listas, iniciando tres listas e duas auxiliares
Lista * unirListas(Lista *p1, Lista *p2) {
    Lista *p3 = NULL; // iniciando uma lista p3 nula
    Lista *aux1 = p1; // iniciando um auxiliar que percorrerá a lista 1
    Lista *aux2 = p2; // iniciando um auxiliar que percorrerá a lista 2
    
    while (aux1 != NULL) { // enquanto o auxiliar da lista 1 for diferente de nulo
        p3 = insereFim(p3, aux1->info); // é inserido no ponteiro inicial da lista 3 apontando auxiliar pra info
        aux1 = aux1->prox; // e o auxiliar é apontado para o proximo até bater nulo
    }
    
    while (aux2 != NULL) { // enquanto o auxiliar da lista 2 for diferente de nulo
        p3 = insereFim(p3, aux2->info); // é inserido no ponteiro inicial da lista 3 apontando auxiliar pra info
        aux2 = aux2->prox; // e o auxiliar é apontado para o próximo até bater nulo
    }
    
    return p3; // retorna o inicio da lista 3
}

// essa função serve para mostrar a lista 
void mostrarLista(Lista *p) {
    Lista *aux; // definindo um auxiliar para a lista
    
    if (p == NULL) { // se p (inicio da lista) for igual a nulo 
        printf("\nLista Vazia!"); // printa lista vazia
    } else { // se não 
        aux = p; // atribui o auxiliar como p (inicio da lista)
        while (aux != NULL) { // e enquanto o auxiliar for diferente de nulo
            printf("%d -> ", aux->info); // printa os elementos apontando auxiliar para a informação
            aux = aux->prox;  // atribui auxiliar apontado para prox até bater nulo
        }
    }
}

// essa função serve para remover um elemento do inicio da lista
Lista * removeInicio(Lista *p){
	Lista *aux; // definindo um auxiliar para a lista
	aux = p; // atribuindo auxiliar a p, ou seja, o aux começa em p
	
	if(isEmpty(p) == false){ // se p vazio(chamando a função para verificar se p é vazio) é igual a falso
		p = p->prox; // p atribui p apontando para o proximo
		free(aux); // limpa o auxiliar
	} 
	return p;
}

// essa função serve para esvaziar a lista
Lista * esvaziarLista(Lista *p){
	while(p != NULL){ // enquanto p for diferente de nulo
		p = removeInicio(p); // p remove do inicio passando p até bater nulo
	}
	return p;
}

// essa função é a main, onde o programa é rodado
int main(){
	int op = 0, x; // declarando op e x
	
	Lista *p1 = NULL; // iniciando a primeira lista como nulo
	Lista *p2 = NULL; // iniciando a segunda lista como nulo
	Lista *p3 = NULL; // iniciando a terceira lista como nulo
	Lista *p; 
	
	do{ // faça
		printf("\n1 - Inserir Elementos\n");
		printf("2 - Mostrar Lista 1\n");
		printf("3 - Mostrar Lista 2\n");
		printf("4 - Mostrar Nova Lista 3\n");
		printf("5 - Esvaziar Listas\n");
		printf("6 - Fim do Programa\n");
		printf("Escolha sua Opcao: ");
		scanf("%d", &op);
		
		switch(op){ // switch para trafegar entre os casos
			case 1: // caso 1 insere elementos na lista
				printf("\nDeseja Inserir o Elemento em Qual Lista? (1/2)"); 
			  	printf("\nOpcao: ");
				scanf("%d", &op);
				
				if(op == 1){ // if transitando pelas opções do usuario para inserir na lista desejada
					printf("\nDigite um Novo Elemento para a Lista 1: ");
				   	scanf("%d", &x); // recebendo o elemento e atribuindo em x
					p1 = insereFim(p1, x); // inserindo na p1
				} else{
					printf("\nDigite um Novo Elemento para a Lista 2: "); // se nao transita pelas opções diferente de 1
				   	scanf("%d", &x); // recebe o elemento e atribui em x
					p2 = insereFim(p2, x); // inserindo na p2
				}				
				break;
			case 2: // caso 2 mostra a lista 1
				system("cls"); // limpando a tela
				printf("\n ------- Lista 1 -------\n");
				mostrarLista(p1); // mostra a lista 1 chamando a função
				printf("\n ----------------------\n");
				getch();
				break;
			case 3: // caso 3 mostra a lista 2
				system("cls"); // limpando a tela
				printf("\n ------- Lista 2 -------\n");
				mostrarLista(p2); // mostra a lsita 2 chamando a função
				printf("\n ----------------------\n");
				getch(); // para travar o usuario e so liberar apos o usuario apertar em outra tecla
				break; 
			case 4: // caso 4 monta a terceira lista e exibe ela
	    		p3 = unirListas(p1, p2); // chama a função de unir listas atribuindo como p3 e passando com p1 e p2 ou seja p1 + p2 = p3
				system("cls"); // limpando a tela
				printf("\n ------- Lista 3 -------\n");
				mostrarLista(p3); // mostra a lista 3 chamando a função
				printf("\n ----------------------\n");
				getch();
				break;
			case 5: // caso 5 esvazia todas as listas
				p1 = esvaziarLista(p1);
				p2 = esvaziarLista(p2);
				p3 = esvaziarLista(p3);
				system("cls");
				printf("\nTodas as Listas Foram Esvaziadas com Sucesso!!\n");
				break;
			case 6: // caso 6 fecha o programa
				printf("\nSaindo do Programa...\n");
				break;
			default: // exibe que opcao nao existe
				printf("\nOpcao Invalida!! Tente Novamente\n");
				break;
		}
	} while(op != 6); // enquanto a transição pelo switch for diferente de 6
	return 0;
}