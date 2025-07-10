#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define OCUPADO 3
#define LIVRE 0

// Inicializa o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = LIVRE;
        }
    }
}

// Exibe o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Valida se as posições estão livres para navios horizontais
int podeColocarHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (coluna + TAM_NAVIO > TAM) return 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != LIVRE) return 0;
    }
    return 1;
}

// Valida se as posições estão livres para navios verticais
int podeColocarVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM) return 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != LIVRE) return 0;
    }
    return 1;
}

// Valida diagonal principal 
int podeColocarDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM || coluna + TAM_NAVIO > TAM) return 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != LIVRE) return 0;
    }
    return 1;
}

// Valida diagonal secundária
int podeColocarDiagonalSecundaria(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM || coluna - TAM_NAVIO + 1 < 0) return 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] != LIVRE) return 0;
    }
    return 1;
}

// Coloca o navio nas posições válidas
void colocarHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = OCUPADO;
    }
}

void colocarVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = OCUPADO;
    }
}

void colocarDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = OCUPADO;
    }
}

void colocarDiagonalSecundaria(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = OCUPADO;
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas dos navios (você pode testar com outras)
    int l1 = 0, c1 = 1; // Horizontal
    int l2 = 4, c2 = 6; // Vertical
    int l3 = 2, c3 = 2; // Diagonal principal
    int l4 = 5, c4 = 8; // Diagonal secundária

    // Posicionamento horizontal
    if (podeColocarHorizontal(tabuleiro, l1, c1)) {
        colocarHorizontal(tabuleiro, l1, c1);
    } else {
        printf("Erro: navio horizontal fora dos limites ou sobreposto.\n");
    }

    // Posicionamento vertical
    if (podeColocarVertical(tabuleiro, l2, c2)) {
        colocarVertical(tabuleiro, l2, c2);
    } else {
        printf("Erro: navio vertical fora dos limites ou sobreposto.\n");
    }

    // Posicionamento diagonal 
    if (podeColocarDiagonalPrincipal(tabuleiro, l3, c3)) {
        colocarDiagonalPrincipal(tabuleiro, l3, c3);
    } else {
        printf("Erro: navio diagonal ↘ fora dos limites ou sobreposto.\n");
    }

    // Posicionamento diagonal 
    if (podeColocarDiagonalSecundaria(tabuleiro, l4, c4)) {
        colocarDiagonalSecundaria(tabuleiro, l4, c4);
    } else {
        printf("Erro: navio diagonal ↙ fora dos limites ou sobreposto.\n");
    }

    // Exibe o tabuleiro final
    printf("\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
