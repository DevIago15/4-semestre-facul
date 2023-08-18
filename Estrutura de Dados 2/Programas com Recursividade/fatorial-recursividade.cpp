// calcular o fatorial de um numero dado pelo usuario
// solução: Com recursividade
#include <stdio.h>

//função para calcular o fatorial de um numro recebido 
int Fatorial(int n)
{
	   if(n ==0 || n ==1)
	   {
	   	 return 1;
	   }
	   else 
	   {
	   	return n * Fatorial(n-1);
	   }
	   	
}
int main()
{
	int n, fat;
	printf("\n Digite um numero inteiro: ");
	scanf("%d", &n);
	if(n >= 0)
	{
		fat = Fatorial(n);
		printf("\n %d! = %d \n\n", n,fat);
	}
	else
	{
		printf("\n Voce digitou um numero negativo. Tente novamente.");
	}
	return 0;
}
