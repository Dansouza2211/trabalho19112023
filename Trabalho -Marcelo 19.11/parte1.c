#include <stdio.h>
#include <stdbool.h>

bool posicaoValida(int x, int y, int L, int C) {
    return x >= 1 && x <= L && y >= 1 && y <= C;
}

bool ocupadaPorPreta(int x, int y, int P, int pretas[][2]) {
    for (int i = 0; i < P; ++i) {
        if (pretas[i][0] == x && pretas[i][1] == y) {
            return true;
        }
    }
    return false;
}

int contarPecasBrancas(int L, int C, int P, int pretas[][2]) {
    int maxPecasBrancas = 0;

    for (int x = 1; x <= L; ++x) {
        for (int y = 1; y <= C; ++y) {
            if (!ocupadaPorPreta(x, y, P, pretas)) {
                if (posicaoValida(x - 1, y, L, C) && ocupadaPorPreta(x - 1, y, P, pretas)) {
                    maxPecasBrancas++;
                } else if (posicaoValida(x + 1, y, L, C) && ocupadaPorPreta(x + 1, y, P, pretas)) {
                    maxPecasBrancas++;
                } else if (posicaoValida(x, y - 1, L, C) && ocupadaPorPreta(x, y - 1, P, pretas)) {
                    maxPecasBrancas++;
                } else if (posicaoValida(x, y + 1, L, C) && ocupadaPorPreta(x, y + 1, P, pretas)) {
                    maxPecasBrancas++;
                }
            }
        }
    }

    return maxPecasBrancas;
}

int main() {
    int L, C;
    scanf("%d %d", &L, &C);

    int P;
    scanf("%d", &P);

    int pretas[P][2];
    int i;
    for (i = 0; i < P; ++i) {
        scanf("%d %d", &pretas[i][0], &pretas[i][1]);
    }

    int resultado = contarPecasBrancas(L, C, P, pretas);

    printf("%d\n", resultado);

    return 0;
}
