#include <stdio.h>

// Definindo constantes para tamanhos fixos
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Matriz 10x10 representando o tabuleiro: 0 = água, 3 = parte do navio
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Vetores unidimensionais representando os navios (valores simbólicos)
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3}; // Navio horizontal
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};   // Navio vertical

    // Inicializa todas as posições do tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas iniciais dos navios (definidas no código)
    int linhaH = 2, colunaH = 1; // Começo do navio horizontal
    int linhaV = 5, colunaV = 4; // Começo do navio vertical

    // Verifica se o navio horizontal cabe no tabuleiro e não sobrepõe outro navio
    int podeColocarHorizontal = 1;
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                podeColocarHorizontal = 0;
                break;
            }
        }
    } else {
        podeColocarHorizontal = 0;
    }

    // Se válido, posiciona o navio horizontal no tabuleiro
    if (podeColocarHorizontal) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro: navio horizontal fora dos limites ou sobreposto.\n");
    }

    // Verifica se o navio vertical cabe no tabuleiro e não sobrepõe outro navio
    int podeColocarVertical = 1;
    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                podeColocarVertical = 0;
                break;
            }
        }
    } else {
        podeColocarVertical = 0;
    }

    // Se válido, posiciona o navio vertical no tabuleiro
    if (podeColocarVertical) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    } else {
        printf("Erro: navio vertical fora dos limites ou sobreposto.\n");
    }

    // Exibe o tabuleiro no console
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
