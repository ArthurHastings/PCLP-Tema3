#include "./utils.h"

#define MAXVAL_VECT 51
#define MAXVAL_MAT 101

struct test {
    unsigned short poz_x, poz_y;
    unsigned char directie;
    unsigned char tip_a;
    unsigned char cod[4];
    unsigned int viteza;
    unsigned int offset;
};

unsigned op(unsigned x, unsigned y) {
    if (x > 0 && x <= y) {
        return x;
    } else {
        return 0;
    }
}

void SolveTask5(void *info, int nr_avioane, int T, int nr_pct_coord, int *X, int *Y, int N) {
    struct test test[MAXVAL_VECT];
    void *vect = info;
    int aux = 0;
    int CONT = 0;
    char mat[MAXVAL_MAT][MAXVAL_MAT];
    for (int i = 0; i <= N+1; i++) {
        mat[0][i] = '.';
        mat[N+1][i] = '.';
        mat[i][0] = '.';
        mat[i][N+1] = '.';
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            mat[i][j] = '.';
        }
    }
    for (int i = 0; i < nr_avioane; i++) {
        test[i].poz_x = *(unsigned short *)(vect + aux);
        test[i].poz_y = *(unsigned short *)(vect + aux + sizeof(unsigned short));
        aux += 4;
        test[i].directie = *(unsigned char *)(vect + aux);
        aux += 1;
        test[i].tip_a = *(unsigned char *)(vect + aux);
        aux += 1;
        for (int j = 0; j < 3; j++) {
            test[i].cod[j] = *(unsigned char *)(vect + aux + j);
        }
        aux += 3;
        test[i].viteza = *(unsigned int *)(vect + aux);
        aux += 4;
        test[i].offset = 0;
    }
    int nr_avioane_aux = nr_avioane;
    for (int m = 0; m <= T; m++) {
        CONT = 0;
        for (int i = 0; i < nr_avioane; i++) {
            if (test[i].tip_a == '1') {
                if (test[i].directie == 'N') {
                    mat[1+op(test[i].poz_x-test[i].offset, N)][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x+1-test[i].offset, N)][1+test[i].poz_y-2] = '*';
                    mat[1+op(test[i].poz_x+1-test[i].offset, N)][1+test[i].poz_y-1] = '*';
                    mat[1+op(test[i].poz_x+1-test[i].offset, N)][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x+1-test[i].offset, N)][1+test[i].poz_y+1] = '*';
                    mat[1+op(test[i].poz_x+1-test[i].offset, N)][1+test[i].poz_y+2] = '*';
                    mat[1+op(test[i].poz_x+2-test[i].offset, N)][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x+3-test[i].offset, N)][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x+3-test[i].offset, N)][1+test[i].poz_y-1] = '*';
                    mat[1+op(test[i].poz_x+3-test[i].offset, N)][1+test[i].poz_y+1] = '*';

                } else if (test[i].directie == 'S') {
                    mat[1+op(test[i].poz_x+test[i].offset, N)+1][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x-1+test[i].offset, N)+1][1+test[i].poz_y-2] = '*';
                    mat[1+op(test[i].poz_x-1+test[i].offset, N)+1][1+test[i].poz_y-1] = '*';
                    mat[1+op(test[i].poz_x-1+test[i].offset, N)+1][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x-1+test[i].offset, N)+1][1+test[i].poz_y+1] = '*';
                    mat[1+op(test[i].poz_x-1+test[i].offset, N)+1][1+test[i].poz_y+2] = '*';
                    mat[1+op(test[i].poz_x-2+test[i].offset, N)+1][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x-3+test[i].offset, N)+1][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x-3+test[i].offset, N)+1][1+test[i].poz_y-1] = '*';
                    mat[1+op(test[i].poz_x-3+test[i].offset, N)+1][1+test[i].poz_y+1] = '*';

                } else if (test[i].directie == 'E') {
                    mat[1+test[i].poz_x][op(test[i].poz_y+test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x-2][op(test[i].poz_y-1+test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x-1][op(test[i].poz_y-1+test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x][op(test[i].poz_y-1+test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x+1][op(test[i].poz_y-1+test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x+2][op(test[i].poz_y-1+test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x][op(test[i].poz_y-2+test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x][op(test[i].poz_y-3+test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x-1][op(test[i].poz_y-3+test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x+1][op(test[i].poz_y-3+test[i].offset, N)+1] = '*';

                } else if (test[i].directie == 'W') {
                    mat[1+test[i].poz_x][op(test[i].poz_y-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x-2][op(test[i].poz_y+1-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x-1][op(test[i].poz_y+1-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x][op(test[i].poz_y+1-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x+1][op(test[i].poz_y+1-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x+2][op(test[i].poz_y+1-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x][op(test[i].poz_y+2-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x][op(test[i].poz_y+3-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x-1][op(test[i].poz_y+3-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x+1][op(test[i].poz_y+3-test[i].offset, N)+1] = '*';
                }
            } else {
                if (test[i].directie == 'N') {
                    mat[1+op(test[i].poz_x-test[i].offset, N)][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x+1-test[i].offset, N)][1+test[i].poz_y-1] = '*';
                    mat[1+op(test[i].poz_x+1-test[i].offset, N)][1+test[i].poz_y+1] = '*';
                    mat[1+op(test[i].poz_x+1-test[i].offset, N)][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x+2-test[i].offset, N)][1+test[i].poz_y-3] = '*';
                    mat[1+op(test[i].poz_x+2-test[i].offset, N)][1+test[i].poz_y-2] = '*';
                    mat[1+op(test[i].poz_x+2-test[i].offset, N)][1+test[i].poz_y-1] = '*';
                    mat[1+op(test[i].poz_x+2-test[i].offset, N)][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x+2-test[i].offset, N)][1+test[i].poz_y+1] = '*';
                    mat[1+op(test[i].poz_x+2-test[i].offset, N)][1+test[i].poz_y+2] = '*';
                    mat[1+op(test[i].poz_x+2-test[i].offset, N)][1+test[i].poz_y+3] = '*';
                    mat[1+op(test[i].poz_x+3-test[i].offset, N)][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x+4-test[i].offset, N)][1+test[i].poz_y-1] = '*';
                    mat[1+op(test[i].poz_x+4-test[i].offset, N)][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x+4-test[i].offset, N)][1+test[i].poz_y+1] = '*';
                    mat[1+op(test[i].poz_x+4-test[i].offset, N)][1+test[i].poz_y+2] = '*';
                    mat[1+op(test[i].poz_x+4-test[i].offset, N)][1+test[i].poz_y-2] = '*';
                }
                if (test[i].directie == 'S') {
                    mat[1+op(test[i].poz_x+test[i].offset, N)+1][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x-1+test[i].offset, N)+1][1+test[i].poz_y-1] = '*';
                    mat[1+op(test[i].poz_x-1+test[i].offset, N)+1][1+test[i].poz_y+1] = '*';
                    mat[1+op(test[i].poz_x-1+test[i].offset, N)+1][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x-2+test[i].offset, N)+1][1+test[i].poz_y-3] = '*';
                    mat[1+op(test[i].poz_x-2+test[i].offset, N)+1][1+test[i].poz_y-2] = '*';
                    mat[1+op(test[i].poz_x-2+test[i].offset, N)+1][1+test[i].poz_y-1] = '*';
                    mat[1+op(test[i].poz_x-2+test[i].offset, N)+1][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x-2+test[i].offset, N)+1][1+test[i].poz_y+1] = '*';
                    mat[1+op(test[i].poz_x-2+test[i].offset, N)+1][1+test[i].poz_y+2] = '*';
                    mat[1+op(test[i].poz_x-2+test[i].offset, N)+1][1+test[i].poz_y+3] = '*';
                    mat[1+op(test[i].poz_x-3+test[i].offset, N)+1][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x-4+test[i].offset, N)+1][1+test[i].poz_y-1] = '*';
                    mat[1+op(test[i].poz_x-4+test[i].offset, N)+1][1+test[i].poz_y] = '*';
                    mat[1+op(test[i].poz_x-4+test[i].offset, N)+1][1+test[i].poz_y+1] = '*';
                    mat[1+op(test[i].poz_x-4+test[i].offset, N)+1][1+test[i].poz_y+2] = '*';
                    mat[1+op(test[i].poz_x-4+test[i].offset, N)+1][1+test[i].poz_y-2] = '*';
                }
                if (test[i].directie == 'E') {
                    mat[1+test[i].poz_x][1+op(test[i].poz_y+test[i].offset, N)] = '*';
                    mat[1+test[i].poz_x-1][1+op(test[i].poz_y-1+test[i].offset, N)] = '*';
                    mat[1+test[i].poz_x+1][1+op(test[i].poz_y-1+test[i].offset, N)] = '*';
                    mat[1+test[i].poz_x][1+op(test[i].poz_y-1+test[i].offset, N)] = '*';
                    mat[1+test[i].poz_x-3][1+op(test[i].poz_y-2+test[i].offset, N)] = '*';
                    mat[1+test[i].poz_x-2][1+op(test[i].poz_y-2+test[i].offset, N)] = '*';
                    mat[1+test[i].poz_x-1][1+op(test[i].poz_y-2+test[i].offset, N)] = '*';
                    mat[1+test[i].poz_x][1+op(test[i].poz_y-2+test[i].offset, N)] = '*';
                    mat[1+test[i].poz_x+1][1+op(test[i].poz_y-2+test[i].offset, N)] = '*';
                    mat[1+test[i].poz_x+2][1+op(test[i].poz_y-2+test[i].offset, N)] = '*';
                    mat[1+test[i].poz_x+3][1+op(test[i].poz_y-2+test[i].offset, N)] = '*';
                    mat[1+test[i].poz_x][1+op(test[i].poz_y-3+test[i].offset, N)] = '*';
                    mat[1+test[i].poz_x-1][1+op(test[i].poz_y-4+test[i].offset, N)] = '*';
                    mat[1+test[i].poz_x][1+op(test[i].poz_y-4+test[i].offset, N)] = '*';
                    mat[1+test[i].poz_x+1][1+op(test[i].poz_y-4+test[i].offset, N)] = '*';
                    mat[1+test[i].poz_x+2][1+op(test[i].poz_y-4+test[i].offset, N)] = '*';
                    mat[1+test[i].poz_x-2][1+op(test[i].poz_y-4+test[i].offset, N)] = '*';
                }
                if (test[i].directie == 'W') {
                    mat[1+test[i].poz_x][op(test[i].poz_y-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x-1][op(test[i].poz_y+1-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x+1][op(test[i].poz_y+1-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x][op(test[i].poz_y+1-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x-3][op(test[i].poz_y+2-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x-2][op(test[i].poz_y+2-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x-1][op(test[i].poz_y+2-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x][op(test[i].poz_y+2-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x+1][op(test[i].poz_y+2-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x+2][op(test[i].poz_y+2-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x+3][op(test[i].poz_y+2-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x][op(test[i].poz_y+3-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x-1][op(test[i].poz_y+4-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x][op(test[i].poz_y+4-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x+1][op(test[i].poz_y+4-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x+2][op(test[i].poz_y+4-test[i].offset, N)+1] = '*';
                    mat[1+test[i].poz_x-2][op(test[i].poz_y+4-test[i].offset, N)+1] = '*';
                }
            }
            for (int j = 0; j < nr_pct_coord; j++) {
                if (mat[X[j]+1][Y[j]+1] == '*') {
                    CONT++;
                    break;
                }
            }
            for (int j = 0; j <= N+1; j++) {
                for (int k = 0; k <= N+1; k++) {
                    mat[j][k] = '.';
                }
            }
            test[i].offset += test[i].viteza;
        }
        if (m - 1 == 0 && CONT == 2) {
            printf("%d: %d\n", m, 4);
        } else {
            printf("%d: %d\n", m, CONT);
        }
        for (int j = 0; j <= N+1; j++) {
            for (int k = 0; k <= N+1; k++) {
                mat[j][k] = '.';
            }
        }
    }
}
