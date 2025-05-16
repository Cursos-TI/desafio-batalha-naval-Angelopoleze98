#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para verificar se um navio pode ser colocado sem sair do tabuleiro ou sobrepor
int pode_colocar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int d_linha, int d_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * d_linha;
        int c = coluna + i * d_coluna;
        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO)
            return 0; // Fora dos limites
        if (tabuleiro[l][c] != AGUA)
            return 0; // Já ocupado
    }
    return 1;
}

// Função para posicionar navios
void posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int d_linha, int d_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * d_linha;
        int c = coluna + i * d_coluna;
        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {{0}};

    // Navio horizontal em (4,4) → (4,6)
    if (pode_colocar(tabuleiro, 3, 3, 0, 1))
        posicionar_navio(tabuleiro, 3, 3, 0, 1);

    // Navio vertical em (7,2) → (9,2)
    if (pode_colocar(tabuleiro, 6, 2, 1, 0))
        posicionar_navio(tabuleiro, 6, 2, 1, 0);

    // Navio diagonal principal (↘) em (0,0) → (2,2)
    if (pode_colocar(tabuleiro, 0, 0, 1, 1))
        posicionar_navio(tabuleiro, 0, 0, 1, 1);

    // Navio diagonal secundária (↙) em (0,9) → (2,7)
    if (pode_colocar(tabuleiro, 0, 9, 1, -1))
        posicionar_navio(tabuleiro, 0, 9, 1, -1);

    // Exibe o tabuleiro
       printf("     Batalha Naval  ");
       printf("\n   ");
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
