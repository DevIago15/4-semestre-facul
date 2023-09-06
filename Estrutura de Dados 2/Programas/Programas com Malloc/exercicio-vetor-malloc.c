#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, m, i;
	float *v, *v2, *v3;
	
	// -- COMEÇO DO VETOR 1 -- //
	
	// criando o tamanho do vetor 1
	printf("Digite o Tamanho do Vetor: ");
	scanf("%d", &n);
	
	// alocando a memória com o tamanho inserido no vetor 1
	v = (float *) malloc (n * sizeof(float));
	
	// preenchendo o vetor 1
	for(i = 0; i < n; i++){
		printf("\nDigite o Vetor 1 v[%d] = ", i);
		scanf("%f", &v[i]);
	}
	
	// percorrendo o vetor 1 e mostrando-o
	printf("======= VETOR 1 ========\n");
	for(i = 0; i < n; i++)
	{
		printf("%.2f ", v[i]);
	}
	printf("\n========================\n");
	
	// -- FIM DO VETOR 1 -- //
	
	// -- COMEÇO DO VETOR 2 -- //
	
	// criando o tamanho do vetor 2
	printf("\nDigite o Tamanho do Segundo Vetor: ");
	scanf("%d", &m);
	
	// realocando memoria
	v2 = (float *) malloc (m * sizeof(float));
	
	// preenchendo o vetor 2
	for(i = 0; i < m; i++)
	{
		printf("\nDigite o Vetor 2 [%d] = ", i);
		scanf("%f", &v2[i]);	
	}
	// mostrando vetor 2
	printf("\n======= VETOR V2 ========\n");
	for(i = 0; i < m; i++)
	{
		printf("%.2f ", v2[i]);
	}
	printf("\n========================\n");
	
	// -- FIM DO VETOR 2 -- //
	
	// -- COMEÇO DO VETOR 3 -- //
	
	// alocando vetor 3
	v3 = (float *) malloc (m * sizeof(float));
	
	// incluindo vetor 1 no vetor 3
	for (i = 0; i < n; i++)
	{
		v3[i] = v[i];
	}
	
	// incluindo vetor 2 no vetor 3
	for (i = 0; i < m; i++)
	{
		v3[n + i] = v2[i];
	}
	
	// printando o vetor
	printf("\n========= VETOR V3 =======\n");
	for(i = 0; i < (n + m); i++){
		printf("%.2f ", v3[i]);
	}
	printf("\n=============================\n");
	
	// -- FIM DO VETOR 3 -- //
	
	return 0;
}