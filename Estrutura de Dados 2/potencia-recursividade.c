#include <stdio.h>
#include <string.h>

float Pot(float x, int n){
	if( n == 0){
		return 1;
	}
	else
	{
		return x * Pot(x, n-1);
	}
}

main(){
	int n;
	float x, pot;
	
	printf("Digite o numero base: ");
	scanf("%f", &x);
	
	printf("\nDigite o expoente: ");
	scanf("%d", &n);
	
	if(n >= 0){
		pot = Pot(x, n);
		printf("%.2f ^ %d = %.2f", x, n, pot);
	}
	
	return 0;
}