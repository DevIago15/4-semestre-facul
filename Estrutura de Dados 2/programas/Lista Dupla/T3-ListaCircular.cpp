#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct No {
    char info;
    struct No *prox;
} ListaC; 

ListaC *inserirFim(ListaC *p, char x) {
    ListaC *aux, *novo;
    novo = (ListaC *)malloc(sizeof(ListaC));
    novo->info = x;

    if (p == NULL) {
        novo->prox = novo;
        p = novo;
    } else {
        aux = p;
        while (aux->prox != p) {
            aux = aux->prox;
        }
        novo->prox = p;
        aux->prox = novo;
    }
    return p;
}

// Função para Girar a Lista para a Direita
ListaC *girarDireita(ListaC *p, int x) {
    if (p == NULL) {
        return NULL;
    }

    for (int i = 0; i < x; i++) {
        p = p->prox;
    }

    return p;
}

// Função para Girar a Lista para a Esquerda
ListaC *girarEsquerda(ListaC *p, int x) {
    if (p == NULL) {
        return NULL;
    }

    ListaC *e = p;
    while (e->prox != p) {
        e = e->prox;
    }

    for (int i = 0; i < -x; i++) {
        p = e;
        e = e->prox;
    }

    return p;
}

// Função para Mostrar a Lista
void exibirLista(ListaC *p) {
    if (p == NULL) {
        return;
    }

    ListaC *m = p;
    do {
        printf("%c", m->info);
        m = m->prox;
    } while (m != p);

    printf("\n");
}

// Programa Principal
int main() {
    ListaC *p = NULL;
    char frase[100];
    int n;

    printf("[SISTEMA] Digite a Frase que Deseja Criptografar: ");
    scanf("%99[^\n]", frase); // utilizamos esse padrao de scanf porque a variavel é uma string com 100 caracteres

    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] >= 'A' && frase[i] <= 'Z') {
            p = inserirFim(p, frase[i]);
        }
    }

	// Entrada do Valor para Girar
    printf("[SISTEMA] Digite o Valor de N: ");
    scanf("%d", &n);

    if (n > 0) {
        p = girarDireita(p, n);
    } else if (n < 0) {
        p = girarEsquerda(p, n);
    }

	// Saída do Programa
    printf("\n[SISTEMA] Frase Descriptografada: %s\n", frase);
    printf("[SISTEMA] Frase Criptografada: ");
    exibirLista(p);

    return 0;
}