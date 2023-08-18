// Calcular o somatorio de(i*i) de um numero dado pelo usuario
// Solução: Com recursividade
#include <stdio.h>

//função para calcular o somatorio de um numero recebido 
int Somatorio(int n)
{
	   if(n == 1)
	   {
	   	return 1;
	   }
	   else 
	   {
	   	return n * n + Somatorio(n - 1);
	   }	
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