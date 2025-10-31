#include <stdio.h>

// Função recursiva para mover a torre
void moverTorre(int casas) {
    if (casas == 0) {
        return; // caso base
    }
    printf("A torre se moveu uma casa.\n");
    moverTorre(casas - 1); // chamada recursiva
}


// Função recursiva para mover a rainha
void moverRainha(int casas, char direcao) {
    if (casas == 0) {
        return; 
    }

    // Mostra o tipo de movimento
    if (direcao == 'v') {
        printf("A rainha andou uma casa para cima/baixo (vertical).\n");
    } else if (direcao == 'h') {
        printf("A rainha andou uma casa para o lado (horizontal).\n");
    } else if (direcao == 'd') {
        printf("A rainha andou uma casa na diagonal.\n");
    } else {
        printf("Direção inválida!\n");
        return;
    }

    moverRainha(casas - 1, direcao); // chamada recursiva
}

int main() {
    int movimentos;
    char direcao; // (sem acento — C não aceita nomes de variáveis com acento)

    // Movimento da torre em recursividade

    printf("Quantas casas a torre deve mover? ");
    scanf("%d", &movimentos);
    moverTorre(movimentos);
    printf("A torre terminou o movimento!\n\n");


    // Movimento da rainha em recursividade
    printf("Quantas casas a rainha deve mover? ");
    scanf("%d", &movimentos);

    printf("Escolha a direcao (v = vertical, h = horizontal, d = diagonal): ");
    scanf(" %c", &direcao); // espaço antes do %c pra ignorar enter anterior

    moverRainha(movimentos, direcao);

    printf("A rainha terminou o movimento!\n");

    //Movimento do cavalo em loops aninhados

    int linha, coluna;

    printf("Digite a posicao inicial do cavalo (linha e coluna, entre 1 e 8): ");
    scanf("%d %d", &linha, &coluna);

    printf("O cavalo pode se mover para as seguintes posicoes:\n");

    
    int movLinha[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int movColuna[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // loops aninhados para testar todos os movimentos
    for (int i = 0; i < 8; i++) {          // loop das 8 possibilidades
        for (int j = 0; j < 1; j++) {      // loop “interno” só para demonstrar estrutura
            int novaLinha = linha + movLinha[i];
            int novaColuna = coluna + movColuna[i];

            // verifica se o movimento é válido (dentro do tabuleiro)
            if (novaLinha >= 1 && novaLinha <= 8 && novaColuna >= 1 && novaColuna <= 8) {
                printf("Movimento %d: linha %d, coluna %d\n", i + 1, novaLinha, novaColuna);
            }
        }
    }

  // Movimento do Bispo em loop aninhados 
    int linha1, coluna1;

    printf("Digite a posicao inicial do bispo (linha e coluna, entre 1 e 8): ");
    scanf("%d %d", &linha1, &coluna1);

    printf("\nO bispo pode se mover para as seguintes posicoes:\n");

    // Percorre o tabuleiro 8x8 com loops aninhados
    for (int i = 1; i <= 8; i++) {           // linhas
        for (int j = 1; j <= 8; j++) {       // colunas

            // A condição da diagonal: diferença entre linha e coluna é igual
            if (i != linha1 && j != coluna1 && (i - linha1 == j - coluna1 || i - linha1 == coluna1 - j)) {
                printf("(%d, %d)\n", i, j);
            }
        }
    }

    return 0;
}


