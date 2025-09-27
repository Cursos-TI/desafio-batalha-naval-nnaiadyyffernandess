#include <stdio.h>
#define TAM 10
#define H 5 // tamanho das matrizes de habilidade 5x5

// Função para aplicar habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[H][H], int origemLinha, int origemColuna, int valor) {
    int meio = H / 2;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha + (i - meio);
                int colunaTab = origemColuna + (j - meio);

                if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                    if (tabuleiro[linhaTab][colunaTab] == 0) { // não sobrescreve navio
                        tabuleiro[linhaTab][colunaTab] = valor;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Vetores dos navios
    int navioHorizontal[3] = {3,3,3};
    int navioVertical[3] = {3,3,3};
    int navioDiagonal1[3]  = {3,3,3};
    int navioDiagonal2[3]  = {3,3,3};

    // Posicionamento dos navios
    int linhaH = 5, colunaH = 5;
    int linhaV = 7, colunaV = 9;

    // Coloca navio horizontal
    if (colunaH + 2 < TAM)
        for (int i = 0; i < 3; i++)
            tabuleiro[linhaH][colunaH + i] = 'N';

    // Coloca navio vertical
    if (linhaV + 2 < TAM)
        for (int i = 0; i < 3; i++)
            tabuleiro[linhaV + i][colunaV] = 'N';

    // Coloca navio diagonal 1 (↙️)
    for (int i = 0; i < 3; i++)
        tabuleiro[1 + i][4 - i] = 'N';

    // Coloca navio diagonal 2 (↘️)
    for (int i = 0; i < 3; i++)
        tabuleiro[3 + i][7 + i] = 'N';

    // --- MATRIZES DE HABILIDADES 5x5 ---
    int cone[H][H] = {0};
    int cruz[H][H] = {0};
    int losango[H][H] = {0};

    // Preencher cone (triângulo para baixo)
    for (int i = 0; i < H; i++)
        for (int j = 0; j < H; j++)
            if (j >= H/2 - i && j <= H/2 + i) cone[i][j] = 1;

    // Preencher cruz
    for (int i = 0; i < H; i++)
        for (int j = 0; j < H; j++)
            if (i == H/2 || j == H/2) cruz[i][j] = 1;

    // Preencher losango (octaedro)
    for (int i = 0; i < H; i++)
        for (int j = 0; j < H; j++)
            if (abs(i - H/2) + abs(j - H/2) <= H/2) losango[i][j] = 1;

    // --- APLICAR HABILIDADES ---
    aplicarHabilidade(tabuleiro, cone, 2, 2, 1);      // cone = 1
    aplicarHabilidade(tabuleiro, cruz, 5, 5, 2);      // cruz = 2
    aplicarHabilidade(tabuleiro, losango, 7, 2, 3);   // losango = 3

    // --- EXIBIR TABULEIRO ---
    printf("*** JOGO: BATALHA NAVAL - NIVEL 3 (HABILIDADES NUMERADAS) ***\n");
    printf("   ");
    for (int j = 0; j < TAM; j++) printf("%d ", j);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d  ", i);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) printf("~ ");   // água
            else if (tabuleiro[i][j] == 'N') printf("N "); // navio
            else printf("%d ", tabuleiro[i][j]); // habilidades: 1,2,3
        }
        printf("\n");
    }

    return 0;
}
