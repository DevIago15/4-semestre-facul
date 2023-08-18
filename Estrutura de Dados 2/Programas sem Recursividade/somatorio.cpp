// Calcular o somatorio de(i*i) de um numero dado pelo usuario
// Solução: Sem recursividade
#include <stdio.h>

//função para calcular o somatorio de um numero recebido 
int Somatorio(int n)
{
	int s = 0;
	for(int i =1; i <= n; i++)
	{
		s = s + (i * i);
	}
	return s;
}
int main()
{
	int n, soma;
	printf("\n Digite um numero inteiro: ");
	scanf("%d", &n);
	if(n >= 0)
	{
		soma = Somatorio(n);
		printf("\n Somatorio(%d) = %d \n\n", n,soma);
	}
	else
	{
		printf("\n Voce digitou um numero negativo. Tente novamente.");
	}
	return 0;
}