#include <stdio.h>
#include <stdlib.h>

int main()
{

    int tabuleiro[10][10] = {0}; // inicializa tudo com 0 (água)

    // Vetores para os navios (tamanho 3 cada)
    int navioHorizontal[3] = {3,3,3};
    int navioVertical[3] = {3,3,3};

      // Posição inicial
    int linhaH = 5, colunaH = 5; // navio horizontal começa em (5,5)
    int linhaV = 7, colunaV = 9; // navio vertical começa em (7,9)

    // Validação simples (se cabem no tabuleiro)
    if (colunaH + 2 < 10) {  //validação se cabe no tabuleiro
        for (int i = 0; i < 3; i++) { //colocando o vetor do navio dentro da matriz
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    }

    if (linhaV + 2 < 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    }


//declarando a matriz de tamanho 10x10 (0-9)
//navio horizontal: linha 5, colunas 5,6,7
//navio na vertical: coluna9, linhas 7,8,9



    int i,j;

    printf("*** JOGO: BATALHA NAVAL ***** \n");
// Exibir tabuleiro
    printf("   ");
    for (int j = 0; j < 10; j++)
    {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d  ", i);
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    return 0;
}
