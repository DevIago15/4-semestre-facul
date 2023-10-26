#include <stdlib.h>
int main()
{
	int n, m, i;
	int *v; // vetor onde ir� apontar para a regi�o de mem�ria dos elementos do vetor
	
	printf("Digite o Tamanho do Vetor: ");
	scanf("%d", &n);
	
	// aloca��o din�mica de memoria para o vetor, o ponteiro v recebe o endere�o de memoria
	// do inicio do bloco que foi alocado pelo malloc, ou seja, v aponta para o bloco de memoria
	v = (int *) malloc (n * sizeof(int));
	
		
	// preenchendo o vetor
	for (i = 0; i < n; i++){
		printf("\nDigite v[%d] = ", i);
		scanf("%d", &v[i]);
	}
	
	// percorrendo o vetor e mostrando-o
	printf("======= VETOR V ========\n");
	for(i = 0; i < n; i++)
	{
		printf("%5d", v[i]);
	}
	printf("\n========================\n");
	
	// preparando para reaclocar a mem�ria, aumentando a quantidade de memoria que foi alocada
	printf("\nDigite a Quantidade de Elementos que Deseja Alocar: ");
	scanf("%d", &m);
	
	// realocar memoria
	v = (int *) (realloc(v,(n + m) * sizeof(int)));
	
	// para aumentar, deve-se come�ar de onde parou, ou seja, n vai at� a memoria total
	// o anterior mais o adicionado agora
	for(i = n; i < n + m; i++)
	{
		printf("\nDigite v[%d] = ", i);
		scanf("%d", &v[i]);	
	}
	printf("======= VETOR V REALOCADO ========\n");
	for(i = 0; i < n + m; i++)
	{
		printf("%5d", v[i]);
	}
	printf("\n========================\n");
	
	// liberando a memoria
	free();
	return 0;
}