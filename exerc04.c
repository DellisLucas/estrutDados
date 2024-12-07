#include <stdio.h>

int main() {
    float pluviometria[7][6], mediaCidade[7] = {0}, mediaMes[6] = {0};

    // Leitura dos dados
    for (int cidade = 0; cidade < 7; cidade++) {
        printf("Digite os índices pluviométricos para a cidade %d (6 meses):\n", cidade + 1);
        for (int mes = 0; mes < 6; mes++) {
            scanf("%f", &pluviometria[cidade][mes]);
            mediaCidade[cidade] += pluviometria[cidade][mes];
            mediaMes[mes] += pluviometria[cidade][mes];
        }
    }

    // Cálculo das médias
    printf("\nÍndice de pluviosidade médio mensal por cidade:\n");
    for (int cidade = 0; cidade < 7; cidade++) {
        printf("Cidade %d: %.2f\n", cidade + 1, mediaCidade[cidade] / 6);
    }

    printf("\nÍndice de pluviosidade médio por mês na região:\n");
    for (int mes = 0; mes < 6; mes++) {
        printf("Mês %d: %.2f\n", mes + 1, mediaMes[mes] / 7);
    }

    return 0;
}
