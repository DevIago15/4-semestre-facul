#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

typedef struct No {
    int info;
	struct No *ant, *prox;
}ListaDupla;

bool isEmpty(ListaDupla* p) {
    return p == NULL;
}

ListaDupla * inserir(ListaDupla *p, int x){
	ListaDupla* novo, *aux;
	novo = (ListaDupla*)malloc(sizeof(ListaDupla));
	novo -> info = x;
	
	// verificando pra adicionar no inicio
	if(p == NULL){
		novo->prox = NULL;
		novo->ant = NULL;
		p = novo;
	} else {
		// verificando para adicionar durante a passagem de aux 
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

ListaDupla* remove(ListaDupla* p, int x) {
    ListaDupla *pe, *pd, *aux;
	
	// adicionando validação caso a lista esteja vazia
    if (isEmpty(p)) {
        printf("\n[SISTEMA] ERRO: Sua Lista Está Vazia!!\n");
    } else {
        aux = p;

        // buscando o elemento que irá ser removido
        while (aux != NULL && aux->info < x) {
            aux = aux->prox;
        }

        // verificando se o elemento foi encontrado
        if (aux != NULL && aux->info == x) {
            pe = aux->ant;
            pd = aux->prox;

            if (pe == NULL) {
                p = pd;
                if (pd != NULL) {
                    pd->ant = NULL;
                }
            } else {
                pe->prox = pd;
                if (pd != NULL) {
                    pd->ant = pe;
                }
            }

            // liberando a memória do nó que foi removido
            free(aux);
            printf("[SISTEMA] Elemento Removido com Sucesso!\n");
        } else {
            printf("[SISTEMA] ERRO: Elemento Digitado Não Pertence a Lista!\n");
        }
    }
    return p;
}

void mostrarEsquerdaDireita(ListaDupla* p) {
    ListaDupla* aux;

    if (isEmpty(p)) {
        printf("[SISTEMA] ERRO: Sua Lista Está Vazia!!\n");
    } else {
        aux = p;

        while (aux != NULL) {
            printf("%d -> ", aux->info);
            aux = aux->prox;
        }
    }
}

void mostrarDireitaEsquerda(ListaDupla* p) {
    ListaDupla* aux;

    if (isEmpty(p)) {
        printf("\n [SISTEMA] ERRO: Sua Lista Está Vazia!!\n");
    } else {
        aux = p;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        while (aux != NULL) {
            printf("%d -> ", aux->info);
            aux = aux->ant;
        }
    }
}

void esvaziarLista(ListaDupla* p) {
	// adicionado uma verificação caso a lista já esteja vazia
    if(isEmpty(p)){
		printf("\n[SISTEMA] ERRO: Sua Lista Já se Encontra Vazia!\n\n");
	} else {
		// esvaziando a lista elemento por elemento
		while (p != NULL) {
        	ListaDupla* aux = p;
        	p = p->prox;
        	free(aux);
		}
   	    printf("\n\n[SISTEMA] Esvaziando a Lista...\n[SISTEMA] Agora sua Lista Está Vazia!\n\n");
	}
}

int main() {
	// definindo o sistema como portuguese para conseguir visualizar acentos e cedilhas
	setlocale(LC_ALL, "PORTUGUESE");
	int op, info;

	// iniciando a lista vazia
    ListaDupla* p = NULL;

    do {
        printf("1 - Inserir Elemento Ordenadamente\n");
        printf("2 - Remover Elemento Desejado\n");
		printf("3 - Exibir Lista da Esquerda para a Direita\n");
		printf("4 - Exibir Lista da Direita para a Esquerda\n");
        printf("5 - Esvaziar Lista\n");
        printf("6 - Sair do Programa\n");
        printf("Sua Opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("[SISTEMA] Digite o Elemento que Deseja Inserir: ");
                scanf("%d", &info);
                p = inserir(p, info);
		   	   	printf("[SISTEMA] Elemento Inserido com Sucesso!\n\n");
                break;
            case 2:
                printf("[SISTEMA] Digite o Elemento que Deseja Remover: ");
                scanf("%d", &info);
                p = remove(p, info);
                printf("\n");
                break;
            case 3:
        		system("cls");
                printf("\n ------- Lista Ordenada da Esquerda para a Direita -------\n");
                mostrarEsquerdaDireita(p);
                printf("\n ---------------------------------------------------------\n");
                getch();
                break;
            case 4:
                system("cls");
                printf("\n ------- Lista Ordenada da Direita para a Esquerda -------\n");
                mostrarDireitaEsquerda(p);
                printf("\n ---------------------------------------------------------\n");
                getch();
                break;
            case 5: 
                esvaziarLista(p);
                p = NULL;
                break;
       	   case 6:
                printf("\n[SISTEMA] Saindo do Programa...\n");
                break;
            default:
                printf("\n[SISTEMA] ERRO: Opção Inválida.\n[SISTEMA] Sugerimos Digitar Outra Opção...\n\n");
        }
    } while (op != 6);
    return 0;
}
