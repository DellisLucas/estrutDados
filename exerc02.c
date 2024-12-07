#include <stdio.h>

char tabuleiro[3][3];

void inicializarTabuleiro() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = ' ';
}

void mostrarTabuleiro() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

int verificarVencedor() {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return 1;
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            return 1;
    }
    if ((tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') ||
        (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' '))
        return 1;
    return 0;
}

void jogar() {
    int jogador = 1, movimentos = 0, x, y;
    while (movimentos < 9) {
        mostrarTabuleiro();
        printf("Jogador %d (%c), informe linha e coluna (0-2): ", jogador, (jogador == 1) ? 'X' : 'O');
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < 3 && y >= 0 && y < 3 && tabuleiro[x][y] == ' ') {
            tabuleiro[x][y] = (jogador == 1) ? 'X' : 'O';
            movimentos++;
            if (verificarVencedor()) {
                mostrarTabuleiro();
                printf("Parabéns, Jogador %d venceu!\n", jogador);
                return;
            }
            jogador = 3 - jogador; // Alterna entre 1 e 2
        } else {
            printf("Jogada inválida. Tente novamente.\n");
        }
    }
    mostrarTabuleiro();
    printf("Empate!\n");
}

int main() {
    inicializarTabuleiro();
    jogar();
    return 0;
}
