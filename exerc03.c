#include <stdio.h>

int main() {
    float notas[5][4], mediaAluno[5], somaTurma = 0;
    int i, j;

    // Entrada das notas
    for (i = 0; i < 5; i++) {
        printf("Digite as 4 notas do aluno %d:\n", i + 1);
        for (j = 0; j < 4; j++) {
            scanf("%f", &notas[i][j]);
        }
    }

    // Cálculo das médias
    for (i = 0; i < 5; i++) {
        float soma = 0;
        for (j = 0; j < 4; j++) {
            soma += notas[i][j];
        }
        mediaAluno[i] = soma / 4;
        somaTurma += mediaAluno[i];
    }

    printf("Médias dos alunos:\n");
    for (i = 0; i < 5; i++) {
        printf("Aluno %d: %.2f\n", i + 1, mediaAluno[i]);
    }

    printf("Média da turma: %.2f\n", somaTurma / 5);
    return 0;
}
