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

#define TAM 10       // Tamanho fixo do tabuleiro (10x10)
#define TAM_NAVIO 3  // Cada navio ocupa 3 posições
#define OCUPADO 3    // Valor para representar partes de navios
#define AGUA 0       // Valor para representar água

// === Função auxiliar: verifica se uma posição está dentro do tabuleiro ===

int dentroLimite(int linha, int coluna) {
return (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM);
}

// === Função para verificar sobreposição antes de posicionar ===

int verificaSobreposicao(int tab[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
for (int i = 0; i < TAM_NAVIO; i++) {
int l = linha + i * dLinha;
int c = coluna + i * dColuna;
if (!dentroLimite(l, c) || tab[l][c] == OCUPADO)
return 1; // Sobreposição ou fora dos limites
}
 return 0;
}

// === Função para posicionar navio com segurança ===

void posicionaNavio(int tab[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
for (int i = 0; i < TAM_NAVIO; i++) {
int l = linha + i * dLinha;
int c = coluna + i * dColuna;
tab[l][c] = OCUPADO;
}
}

int main() {
int tabuleiro[TAM][TAM] = {0};

// === Coordenadas iniciais dos navios ===

int linhaH = 1, colunaH = 2; // horizontal 
int linhaV = 5, colunaV = 6; // vertical 
int linhaD1 = 2, colunaD1 = 2; // diagonal principal 
int linhaD2 = 6, colunaD2 = 8; // diagonal secundária 

// === Navio horizontal ===

if (!verificaSobreposicao(tabuleiro, linhaH, colunaH, 0, 1))
posicionaNavio(tabuleiro, linhaH, colunaH, 0, 1);
else
printf("não foi possível posicionar navio horizontal (sobreposição ou fora dos limites).\n");

// === Navio vertical ===

if (!verificaSobreposicao(tabuleiro, linhaV, colunaV, 1, 0))
posicionaNavio(tabuleiro, linhaV, colunaV, 1, 0);
else
printf("não foi possível posicionar navio vertical.\n");

// === Navio diagonal principal ===

if (!verificaSobreposicao(tabuleiro, linhaD1, colunaD1, 1, 1))
posicionaNavio(tabuleiro, linhaD1, colunaD1, 1, 1);
else
printf("não foi possível posicionar navio diagonal principal.\n");

// === Navio diagonal secundária ===

if (!verificaSobreposicao(tabuleiro, linhaD2, colunaD2, 1, -1))
posicionaNavio(tabuleiro, linhaD2, colunaD2, 1, -1);
else
printf("não foi possível posicionar navio diagonal secundária.\n");

// === Exibir o tabuleiro ===

printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");for (int i = 0; i < TAM; i++) {
for (int j = 0; j < TAM; j++) {
printf("%d ", tabuleiro[i][j]);
}
printf("\n");
}

    return 0;
}