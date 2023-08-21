#include <stdio.h>

float Pot(float x, int n) {
    if (n == 0) {
        return 1;
    } else if (n < 0) {
        return 1.0 / (x * Pot(x, -n - 1));
    } else {
        return x * Pot(x, n - 1);
    }
}

int main() {
    int n;
    float x, pot;
    
    printf("Digite o numero base: ");
    scanf("%f", &x);
    
    printf("\nDigite o expoente: ");
    scanf("%d", &n);
    
    pot = Pot(x, n);
    printf("%.2f ^ %d = %.2f", x, n, pot);
    
    return 0;
}
