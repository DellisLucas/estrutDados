#include <stdio.h>

int somatoria(int n) {
    if (n == 1) return 1;
    return n + somatoria(n - 1);
}

int main() {
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("Somatória de 1 a %d: %d\n", n, somatoria(n));
    return 0;
}
