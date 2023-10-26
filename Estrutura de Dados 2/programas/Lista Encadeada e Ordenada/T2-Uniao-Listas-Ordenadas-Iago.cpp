#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct NO{
	int info;
	struct NO *prox;	
} Lista;

bool isEmpty(Lista *p){
	if(p == NULL){
		return true;
	} else {
		return false;
	}
}

Lista *insereInicioOrdem(Lista *p, int x){
	Lista *novo, *aux = NULL;
	
	novo = (Lista *)malloc(sizeof(Lista));
	
	novo->info = x;
	
	if(p == NULL || p->info >= x){
		novo->prox = p;
		p = novo;
	} else{
		aux = p;
		while((aux->prox != NULL) && ((p->prox)->info <= x)){
			aux = aux->prox;
		}
		novo->prox = aux->prox;
		aux->prox = novo;
	}
	return p;
}

Lista *removeFimOrdem(Lista *p){
	Lista *aux = NULL, *ant = NULL;
	int x;
	
	if(p!= NULL){
		if(p->info == x){
			aux = p;
			p = p->prox;
			free(aux);
		} else {
			aux = p;
			
			while((aux->prox != NULL) && ((aux->prox)->info < x)){
				aux = aux->prox;
			} if(aux->prox != NULL && (aux->prox->info ==x)){
				ant = aux;
				aux = aux->prox;
				ant->prox = aux->prox;
				free(aux);
			}
		}
		return p;
	}	
}

Lista * esvaziarLista(Lista *p){
	while(p != NULL){
		Lista *aux = p;
		p = p->prox;
		free(aux);	
	}
	return p;
}

void mostrarLista(Lista *p) {
    Lista *aux;
    
    if (p == NULL) {
        printf("Lista Vazia!");
    } else {
        aux = p;
        while (aux != NULL) {
            printf("%d -> ", aux->info);
            aux = aux->prox; 
        }
    }
}

Lista * unirListas(Lista *p1, Lista *p2) {
    Lista *p3 = NULL;
    Lista *aux1 = p1;
    Lista *aux2 = p2;
    
    while (aux1 != NULL) {
        p3 = insereInicioOrdem(p3, aux1->info);
        aux1 = aux1->prox;
    }
    
    while (aux2 != NULL) {
        p3 = insereInicioOrdem(p3, aux2->info);
        aux2 = aux2->prox;
    }
    
    return p3;
}

int main(){
	int op = 0, x, i, y;
	
	Lista *p1 = NULL;
	Lista *p2 = NULL;
	Lista *p3 = NULL;
	Lista *p;
	
	do{
		printf("1 - Inserir Elementos\n");
		printf("2 - Mostrar Lista\n");
		printf("3 - Esvaziar Todas as Listas\n");
		printf("4 - Fim do Programa\n");
		printf("Escolha sua Opcao: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("\nDeseja Inserir o Elemento em Qual Lista? (1/2)");
			  	printf("\nOpcao: ");
				scanf("%d", &i);
				
				switch(i){
					case 1:
						printf("\nDigite um Novo Elemento para a Lista 1: ");
				   		scanf("%d", &x);
						p1 = insereInicioOrdem(p1, x);
						break;
					case 2:
						printf("\nDigite um Novo Elemento para a Lista 2: ");
				   		scanf("%d", &x);
						p2 = insereInicioOrdem(p2, x);
						break;
					default:
						printf("\nUh, oh ERRO: Lista Nao Encontrada!\n");
					   	getch();
						break;
				}
				break;
			case 2:
				printf("\nDeseja Visualizar Qual Lista? (1/2/3)\n");
				printf("Sua Opcao: ");
				scanf("%d", &y);
				
				switch(y){
					case 1:
						system("cls"); // limpando a tela
						printf("\n ------- Lista 1 -------\n");
						mostrarLista(p1);
						printf("\n ----------------------\n");
						getch();
						break;
					case 2:
						system("cls"); // limpando a tela
						printf("\n ------- Lista 2 -------\n");
						mostrarLista(p2);
						printf("\n ----------------------\n");
						getch();	
						break;
					case 3:
						p3 = unirListas(p1, p2);
						system("cls"); // limpando a tela
						printf("\n ------- Lista 3 -------\n");
						mostrarLista(p3);
						printf("\n ----------------------\n");
						getch();
						break;
					default:
						printf("\nUh, oh ERRO: Lista Nao Encontrada!\n");
					   	getch();
						break;
				}
				break;
			case 3:
				p1 = esvaziarLista(p1);
				p2 = esvaziarLista(p2);
				p3 = esvaziarLista(p3);
				system("cls");
				printf("\nTodas as Listas Foram Esvaziadas com Sucesso!!\n");
				break;
			case 4:
				printf("\nSaindo do Programa...\n");
				break;
			default:
				printf("\nOpcao Invalida!! Tente Novamente\n");
				break;
		}
	} while(op != 4);
	return 0;
}