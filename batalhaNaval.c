#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    #include <stdio.h>

int main() {

#define TAM 10       // Tamanho fixo do tabuleiro (10x10)
#define TAM_NAVIO 3  // Cada navio ocupa 3 posições

    int tabuleiro[TAM][TAM]; // Matriz que representa o tabuleiro
    int i, j;

    // ===  Inicializar o tabuleiro com 0 agua ===

    for (i = 0; i < TAM; i++) {
    for (j = 0; j < TAM; j++) {
    tabuleiro[i][j] = 0;
    }
    }

    // ===  Coordenadas iniciais dos navios ===

    // Navio 1: horizontal

    int linhaNavio1 = 1; // linha inicial
    int colunaNavio1 = 3; // coluna inicial

    // Navio 2: vertical

    int linhaNavio2 = 3; // linha inicial
    int colunaNavio2 = 5; // coluna inicial

    // ===  Validacao de limites ===

    // (Verifica se os navios cabem dentro do tabuleiro)

    if (colunaNavio1 + TAM_NAVIO > TAM) {
    printf("Erro: o navio horizontal ultrapassa os limites do tabuleiro.");
    return 1;
    }
    if (linhaNavio2 + TAM_NAVIO > TAM) {
    printf("Erro: o navio vertical ultrapassa os limites do tabuleiro.\n");
    return 1;
    }

    // ===  Posicionar o navio horizontal ===

    for (i = 0; i < TAM_NAVIO; i++) {
    tabuleiro[linhaNavio1][colunaNavio1 + i] = 3;
    }

    // === Verificar sobreposição antes de posicionar o navio vertical ===

    int sobreposicao = 0;
    for (i = 0; i < TAM_NAVIO; i++) {
    if (tabuleiro[linhaNavio2 + i][colunaNavio2] == 3) {
    sobreposicao = 1;
    }
    }

    if (sobreposicao) {
    printf("Erro: os navios se sobrepõem.\n");
    return 1;
    }

    // === Posicionar o navio vertical ===

    for (i = 0; i < TAM_NAVIO; i++) {
    tabuleiro[linhaNavio2 + i][colunaNavio2] = 3;
    }

    // ===  Exibir o tabuleiro ===

    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n");
    for (i = 0; i < TAM; i++) {
    for (j = 0; j < TAM; j++) {
    printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
    }

    return 0;
}
