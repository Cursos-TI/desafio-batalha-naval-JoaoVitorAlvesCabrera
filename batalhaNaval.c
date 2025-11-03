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

#define TAM 10       // Tamanho do tabuleiro 10x10
#define TAM_NAVIO 3  // Tamanho de cada navio
#define OCUPADO 3    // Representa navio
#define AGUA 0       // Representa água
#define HABILIDADE 5 // Representa área afetada por habilidade

// === Função auxiliar: verifica se uma posição está dentro do tabuleiro ===

int dentroLimite(int linha, int coluna) {
    return (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM);
}

// === Verifica sobreposição de navios ===

int verificaSobreposicao(int tab[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
for (int i = 0; i < TAM_NAVIO; i++) {
int l = linha + i * dLinha;
int c = coluna + i * dColuna;
if (!dentroLimite(l, c) || tab[l][c] == OCUPADO)
return 1; // Sobreposição ou fora dos limites
}
return 0;
}

// === Posiciona navio no tabuleiro ===

void posicionaNavio(int tab[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
for (int i = 0; i < TAM_NAVIO; i++) {
int l = linha + i * dLinha;
int c = coluna + i * dColuna;
tab[l][c] = OCUPADO;
}
}

// === Função para sobrepor habilidade ao tabuleiro ===

void aplicaHabilidade(int tab[TAM][TAM], int habilidade[5][5], int origemLinha, int origemColuna) {
int tamH = 5; // tamanho da matriz de habilidade
int meio = tamH / 2; // índice central

for (int i = 0; i < tamH; i++) {
for (int j = 0; j < tamH; j++) {
int l = origemLinha - meio + i;
int c = origemColuna - meio + j;

// Checa limites e não sobrescreve navio

if (dentroLimite(l, c) && habilidade[i][j] == 1 && tab[l][c] != OCUPADO) {
tab[l][c] = HABILIDADE;
}}}}

int main() {
    int tabuleiro[TAM][TAM] = {0};

// === Coordenadas dos navios ===

int linhaH = 1, colunaH = 2; // horizontal
int linhaV = 5, colunaV = 6; // vertical
int linhaD1 = 2, colunaD1 = 2; // diagonal principal
int linhaD2 = 6, colunaD2 = 8; // diagonal secundária

    // === Posiciona navios ===

if (!verificaSobreposicao(tabuleiro, linhaH, colunaH, 0, 1))
        posicionaNavio(tabuleiro, linhaH, colunaH, 0, 1);

if (!verificaSobreposicao(tabuleiro, linhaV, colunaV, 1, 0))
        posicionaNavio(tabuleiro, linhaV, colunaV, 1, 0);

if (!verificaSobreposicao(tabuleiro, linhaD1, colunaD1, 1, 1))
        posicionaNavio(tabuleiro, linhaD1, colunaD1, 1, 1);

 if (!verificaSobreposicao(tabuleiro, linhaD2, colunaD2, 1, -1))
        posicionaNavio(tabuleiro, linhaD2, colunaD2, 1, -1);

// === Matriz de habilidade: Cone 5x5 ===

int cone[5][5] = {0};
for (int i = 0; i < 5; i++) { // linhas
for (int j = 0; j < 5; j++) { // colunas
if (j >= 2 - i && j <= 2 + i) { // expandindo para baixo
cone[i][j] = 1;
}}}

// === Matriz de habilidade: Cruz 5x5 ===

int cruz[5][5] = {0};
for (int i = 0; i < 5; i++) {
cruz[2][i] = 1; // linha central
cruz[i][2] = 1; // coluna central
}

    // === Matriz de habilidade: Octaedro 5x5 ===

int octaedro[5][5] = {0};
octaedro[0][2] = 1;
octaedro[1][1] = octaedro[1][2] = octaedro[1][3] = 1;
octaedro[2][0] = octaedro[2][1] = octaedro[2][2] = octaedro[2][3] = octaedro[2][4] = 1;
octaedro[3][1] = octaedro[3][2] = octaedro[3][3] = 1;
octaedro[4][2] = 1;

// === Aplica habilidades no tabuleiro ===

aplicaHabilidade(tabuleiro, cone, 0, 2);      // cone no topo
aplicaHabilidade(tabuleiro, cruz, 7, 7);      // cruz central
aplicaHabilidade(tabuleiro, octaedro, 4, 4);  // octaedro central

// === Exibir tabuleiro com navios e habilidades ===

printf("\n=== TABULEIRO COM HABILIDADES ===\n\n");
for (int i = 0; i < TAM; i++) {
for (int j = 0; j < TAM; j++) {
printf("%d ", tabuleiro[i][j]); // 0 = água, 3 = navio, 5 = habilidade
}
printf("\n");
}

    return 0;
}