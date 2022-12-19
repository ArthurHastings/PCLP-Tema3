#include "./utils.h"

#define MAXVAL_VECT 51

struct test {
    unsigned short poz_x, poz_y;
    unsigned char directie;
    unsigned char tip_a;
    unsigned char cod[4];
    unsigned int viteza;
};

void SolveTask4(void *info, int nr_avioane, int nr_obstacole, int *x, int *y, int N) {
    struct test test[MAXVAL_VECT];
    void *vect = info;
    int aux = 0;
    int marg1_x = 0, marg1_y = 0;
    int marg2_x = 0, marg2_y = 0;
    int CONT_AVIOANE = 0, ok = 1;
    for (int i = 0; i < nr_avioane; i++) {
        ok = 1;
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
        if (test[i].tip_a == '1') {
            if (test[i].directie == 'N') {
                marg1_x = test[i].poz_x+3;
                marg1_y = test[i].poz_y-2;
                marg2_x = test[i].poz_x+3;
                marg2_y = test[i].poz_y+2;
                for (int j = 0; j <= marg1_x; j++) {
                    for (int k = marg1_y; k <=marg2_y; k++) {
                        for (int l = 0; l < nr_obstacole; l++) {
                            if ((j == x[l] && k == y[l]) && (j != marg1_x ||
                            k != marg1_y) && (j != marg2_x || k != marg2_y)
                            && (j != marg1_x-1 || k != marg1_y) &&
                            (j != marg2_x-1 || k != marg2_y)) {
                                ok = 0;
                            }
                        }
                        if (ok == 0) {
                            break;
                        }
                    }
                    if (ok == 0) {
                        break;
                    }
                }

            } else if (test[i].directie == 'S') {
                marg1_x = test[i].poz_x-3;
                marg1_y = test[i].poz_y-2;
                marg2_x = test[i].poz_x-3;
                marg2_y = test[i].poz_y+2;
                for (int j = marg1_x; j <= N-1; j++) {
                    for (int k = marg1_y; k <= marg2_y; k++) {
                        for (int l = 0; l < nr_obstacole; l++) {
                            if ((j == x[l] && k == y[l]) && (j != marg1_x ||
                            k != marg1_y) && (j != marg2_x || k != marg2_y)
                            && (j != marg1_x+1 || k != marg1_y) &&
                            (j != marg2_x+1 || k != marg2_y)) {
                                ok = 0;
                            }
                        }
                        if (ok == 0) {
                            break;
                        }
                    }
                    if (ok == 0) {
                        break;
                    }
                }
            } else if (test[i].directie == 'E') {
                marg1_x = test[i].poz_x-2;
                marg1_y = test[i].poz_y-3;
                marg2_x = test[i].poz_x+2;
                marg2_y = test[i].poz_y-3;
                for (int j = marg1_x; j <= marg2_x; j++) {
                    for (int k = marg1_y; k <= N-1; k++) {
                        for (int l = 0; l < nr_obstacole; l++) {
                            if ((j == x[l] && k == y[l]) && (j != marg1_x ||
                            k != marg1_y) && (j != marg2_x || k != marg2_y)
                            && (j != marg1_x || k != marg1_y+1) &&
                            (j != marg2_x || k != marg2_y+1)) {
                                ok = 0;
                            }
                        }
                        if (ok == 0) {
                            break;
                        }
                    }
                    if (ok == 0) {
                        break;
                    }
                }
            } else if (test[i].directie == 'W') {
                marg1_x = test[i].poz_x-2;
                marg1_y = test[i].poz_y+3;
                marg2_x = test[i].poz_x+2;
                marg2_y = test[i].poz_y+3;
                for (int j = marg1_x; j <= marg2_x; j++) {
                    for (int k = 0; k <= marg2_y; k++) {
                        for (int l = 0; l < nr_obstacole; l++) {
                            if ((j == x[l] && k == y[l]) && (j != marg1_x ||
                            k != marg1_y) && (j != marg2_x || k != marg2_y)
                            && (j != marg1_x || k != marg1_y-1) &&
                            (j != marg2_x || k != marg2_y-1)) {
                                ok = 0;
                            }
                        }
                        if (ok == 0) {
                            break;
                        }
                    }
                    if (ok == 0) {
                        break;
                    }
                }
            }
        } else {
            if (test[i].directie == 'N') {
                marg1_x = test[i].poz_x+4;
                marg1_y = test[i].poz_y-3;
                marg2_x = test[i].poz_x+4;
                marg2_y = test[i].poz_y+3;
                for (int j = 0; j <= marg1_x; j++) {
                    for (int k = marg1_y; k <= marg2_y; k++) {
                        for (int l = 0; l < nr_obstacole; l++) {
                            if ((j == x[l] && k == y[l]) && (j != marg1_x ||
                            k != marg1_y) && (j != marg2_x || k != marg2_y)
                            && (j != marg1_x-1 || k != marg1_y) &&
                            (j != marg2_x-1 || k != marg2_y)) {
                                ok = 0;
                            }
                        }
                        if (ok == 0) {
                            break;
                        }
                    }
                    if (ok == 0) {
                        break;
                    }
                }
            }
            if (test[i].directie == 'S') {
                marg1_x = test[i].poz_x-4;
                marg1_y = test[i].poz_y-3;
                marg2_x = test[i].poz_x-4;
                marg2_y = test[i].poz_y+3;
                for (int j = marg1_x; j <= N-1; j++) {
                    for (int k = marg1_y; k <= marg2_y; k++) {
                        for (int l = 0; l < nr_obstacole; l++) {
                            if ((j == x[l] && k == y[l]) && (j != marg1_x ||
                            k != marg1_y) && (j != marg2_x || k != marg2_y)
                            && (j != marg1_x+1 || k != marg1_y) &&
                            (j != marg2_x+1 || k != marg2_y)) {
                                ok = 0;
                            }
                        }
                        if (ok == 0) {
                            break;
                        }
                    }
                    if (ok == 0) {
                        break;
                    }
                }
            }
            if (test[i].directie == 'E') {
                marg1_x = test[i].poz_x+3;
                marg1_y = test[i].poz_y-4;
                marg2_x = test[i].poz_x-3;
                marg2_y = test[i].poz_y-4;
                for (int j = marg2_x; j <= marg1_x; j++) {
                    for (int k = marg1_y; k <= N-1; k++) {
                        for (int l = 0; l < nr_obstacole; l++) {
                            if ((j == x[l] && k == y[l]) && (j != marg1_x ||
                            k != marg1_y) && (j != marg2_x || k != marg2_y)
                            && (j != marg1_x || k != marg1_y+1) &&
                            (j != marg2_x || k != marg2_y+1)) {
                                ok = 0;
                            }
                        }
                        if (ok == 0) {
                            break;
                        }
                    }
                    if (ok == 0) {
                        break;
                    }
                }
            }
            if (test[i].directie == 'W') {
                marg1_x = test[i].poz_x+3;
                marg1_y = test[i].poz_y+4;
                marg2_x = test[i].poz_x-3;
                marg2_y = test[i].poz_y+4;
                for (int j = marg2_x; j <= marg1_x; j++) {
                    for (int k = 0; k <= marg2_y; k++) {
                        for (int l = 0; l < nr_obstacole; l++) {
                            if ((j == x[l] && k == y[l]) && (j != marg1_x ||
                            k != marg1_y) && (j != marg2_x || k != marg2_y)
                            && (j != marg1_x || k != marg1_y-1) &&
                            (j != marg2_x || k != marg2_y-1)) {
                                ok = 0;
                            }
                        }
                        if (ok == 0) {
                            break;
                        }
                    }
                    if (ok == 0) {
                        break;
                    }
                }
            }
        }
        if (ok == 1) {
            CONT_AVIOANE++;
        }
    }
    printf("%d\n", CONT_AVIOANE);
}
